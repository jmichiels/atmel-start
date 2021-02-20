package atmelstart

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
	"os/exec"
	"path"
	"path/filepath"
	"strings"

	"archive/zip"

	"github.com/pkg/errors"
	"github.com/sirupsen/logrus"
)

const (
	// Atmel Start home.
	urlAtmelStart = `http://start.atmel.com/`

	// Backend API v1.
	urlAPIv1 = urlAtmelStart + `api/v1/`
	// Backend API v2.
	urlAPIv2 = urlAtmelStart + `api/v2/`

	// Endpoint to request the conversion from YAML ("storage") to JSON ("transport")
	urlAPILatestTransport = urlAPIv2 + `project_format/transport/latest`

	// Endpoint to request the conversion from JSON ("transport") to YAML ("storage")
	urlAPILatestStorage = urlAPIv1 + `project_format/storage/latest`

	// Endpoint to request to generate the project code given the JSON config.
	urlAPIGenerate = urlAPIv1 + `generate/?format=atzip&compilers=[atmel_studio,make]&file_name_base=My%20Project`

	// Fields to add the the JSON for the generate request to work.
	jsonTweak = `"jsonForm":"=1"`

	// Hidden directory.
	hiddenDirName = `.atstart`

	// Default name of the configuration file.
	configFileName = `atstart.yaml`
)

func findParentDirWith(startDir string, searchedFile string, maxDepth int) (string, error) {
	if maxDepth == 0 {
		return ``, errors.Errorf("'%s' not found, max depth reached")
	}
	files, err := ioutil.ReadDir(startDir)
	if err != nil {
		return ``, errors.Wrap(err, "read directory")
	}
	for _, file := range files {
		if file.Name() == searchedFile {
			return startDir, nil
		}
	}
	return findParentDirWith(filepath.Dir(startDir), searchedFile, maxDepth-1)
}

func findProjectRootPath(startDir string) (string, error) {
	root, err := findParentDirWith(startDir, configFileName, 10)
	if err != nil {
		return ``, errors.Wrap(err, "find project root")
	}
	return root, nil
}

func findToolchainFilePath(startDir string) (string, error) {
	rootPath, err := findProjectRootPath(startDir)
	if err != nil {
		return ``, errors.Wrap(err, "find toolchain file")
	}
	return filepath.Join(rootPath, hiddenDirName, "toolchain.cmake"), nil
}

func CMake(args []string) error {
	wd, err := os.Getwd()
	if err != nil {
		return errors.Wrap(err, "get working directory")
	}
	toolchainAbs, err := findToolchainFilePath(wd)
	if err != nil {
		return err
	}
	cmd := exec.Command(`cmake`, append([]string{fmt.Sprintf(`-DCMAKE_TOOLCHAIN_FILE="%s"`, toolchainAbs)}, args...)...)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return errors.Wrap(cmd.Run(), "run CMake")
}

func Generate() error {
	var configYAML configYAML
	if err := configYAML.ReadFromFile(configFileName); err != nil {
		return errors.Wrap(err, "read configuration file")
	}
	generatedZIPReader, err := configYAML.requestGenerate()
	if err != nil {
		return err
	}
	generatedZIP, err := ioutil.ReadAll(generatedZIPReader)
	if err != nil {
		return errors.Wrap(err, "read generated archive")
	}
	zipReader, err := zip.NewReader(bytes.NewReader(generatedZIP), int64(len(generatedZIP)))
	if err != nil {
		return errors.Wrap(err, "open generated archive")
	}
	if err := os.RemoveAll(hiddenDirName); err != nil {
		return errors.Wrap(err, "remove generated code")
	}
	for _, file := range zipReader.File {

		logrus.Debugf("write %s", file.Name)

		fileReader, err := file.Open()
		if err != nil {
			return err
		}
		defer fileReader.Close()
		filePath := path.Join(hiddenDirName, file.Name)
		if err := os.MkdirAll(path.Dir(filePath), os.ModePerm); err != nil {
			return err
		}
		fileWriter, err := os.Create(filePath)
		if err != nil {
			return err
		}
		defer fileWriter.Close()
		if _, err := io.Copy(fileWriter, fileReader); err != nil {
			return err
		}
	}
	return nil
}

func removeAllExceptConfigFile(dir string) error {
	entries, err := ioutil.ReadDir(dir)
	if err != nil {
		return errors.Wrap(err, "read directory")
	}
	for _, entry := range entries {
		if entry.Name() != configFileName {
			if err := os.RemoveAll(path.Join(dir, entry.Name())); err != nil {
				return errors.Wrap(err, "remove directory content")
			}
		}
	}
	return nil
}

type byteSlice []byte

func (b byteSlice) Bytes() []byte {
	return []byte(b)
}

func (b byteSlice) String() string {
	return string(b)
}

func (b *byteSlice) ReadFrom(r io.Reader) (err error) {
	*b, err = ioutil.ReadAll(r)
	return err
}

func (b *byteSlice) ReadFromFile(path string) (err error) {
	f, err := os.Open(path)
	if err != nil {
		return err
	}
	return b.ReadFrom(f)
}

func (b byteSlice) GetReader() io.Reader {
	return bytes.NewReader([]byte(b))
}

func (b byteSlice) WriteTo(w io.Writer) (err error) {
	_, err = w.Write(b)
	return err
}

func (b *byteSlice) WriteToFile(path string) (err error) {
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	return b.WriteTo(f)
}

type configYAML struct{ byteSlice }

func (conf *configYAML) requestJSON() (*configJSON, error) {
	resp, err := http.Post(urlAPILatestTransport, `application/json`, conf.GetReader())
	if err == nil && resp.StatusCode != http.StatusOK {
		err = errors.New(resp.Status)
	}
	if err != nil {
		return nil, errors.Wrap(err, "post request")
	}
	type response struct {
		Result struct {
			Project map[string]interface{} `json:"project"`
		} `json:"result"`
	}
	var decoded response
	if err := json.NewDecoder(resp.Body).Decode(&decoded); err != nil {
		return nil, errors.Wrap(err, "read response")
	}
	if decoded.Result.Project == nil {
		return nil, errors.New("missing 'project' field in response")
	}
	encoded, err := json.Marshal(decoded.Result.Project)
	if err != nil {
		return nil, errors.Wrap(err, "encode json")
	}
	encoded = []byte(strings.Replace(string(encoded), `"external":false,"external_frequency":0,`, "", -1))
	encoded = append([]byte(`{`+jsonTweak+`,`), encoded[1:]...)
	return &configJSON{byteSlice(encoded)}, nil
}

func (conf *configYAML) requestGenerate() (io.Reader, error) {
	configJSON, err := conf.requestJSON()
	if err != nil {
		return nil, errors.Wrap(err, "request json")
	}
	resp, err := configJSON.requestGenerate()
	if err != nil {
		return nil, errors.Wrap(err, "request generate")
	}
	return resp, nil
}

func (conf *configYAML) escape() []byte {
	escaped, _ := json.Marshal(conf.String())
	return escaped
}

type configJSON struct{ byteSlice }

func (conf *configJSON) requestYAML() (*configYAML, error) {
	resp, err := http.Post(urlAPILatestStorage, `application/json`, conf.GetReader())
	if err == nil && resp.StatusCode != http.StatusOK {
		err = errors.New(resp.Status)
	}
	if err != nil {
		return nil, errors.Wrap(err, "post request")
	}
	var confYAML configYAML
	if err := confYAML.ReadFrom(resp.Body); err != nil {
		return nil, errors.Wrap(err, "read response")
	}
	return &confYAML, nil
}

func (conf *configJSON) requestGenerate() (io.Reader, error) {
	resp, err := http.Post(urlAPIGenerate, `text/plain`, conf.GetReader())
	if err == nil && resp.StatusCode != http.StatusOK {
		err = errors.New(resp.Status)
	}
	if err != nil {
		return nil, errors.Wrap(err, "post request")
	}
	return resp.Body, nil
}
