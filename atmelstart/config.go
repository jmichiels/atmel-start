package atmelstart

import (
	"bytes"
	"net/http"

	"io/ioutil"

	"io"

	"os"

	"encoding/json"

	"github.com/pkg/errors"
)

const (
	// Atmel Start home.
	urlAtmelStart = `http://start.atmel.com/`

	// Backend API v1.
	urlAPIv1 = urlAtmelStart + `api/v1/`
	// Backend API v2.
	urlAPIv2 = urlAtmelStart + `api/v2/`

	// Endpoint to request the conversion from YAML ("storage") to JSON ("transport")
	urlAPILatestStorage = urlAPIv1 + `project_format/storage/latest`

	// Endpoint to request the conversion from JSON ("transport") to YAML ("storage")
	urlAPILatestTransport = urlAPIv2 + `project_format/transport/latest`

	// Endpoint to request to generate the project code given the JSON config.
	urlAPIGenerate = urlAPIv1 + `generate/?format=atzip&compilers=[atmel_studio,make]&file_name_base=My%20Project`

	// Fields to add the the JSON for the generate request to work.
	jsonTweak = `"jsonForm":"=1"`
)

type ConfigFile string

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
	f, err := os.OpenFile(path, os.O_WRONLY, 666)
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

type configJSON struct{ byteSlice }

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

//type ConfigFileEditor struct {
//}
//
//func (editor *ConfigFileEditor) Open() {
//
//}
//
//func (editor *ConfigFileEditor) Close() {
//
//}
//
//func (editor *ConfigFileEditor) Save() {
//
//}
