//go:generate esc -o templates.go -pkg $GOPACKAGE templates

package atmelstart

import (
	"io"
	"io/ioutil"
	"regexp"
	"sort"
	"text/template"

	"path"

	"os"

	"github.com/pkg/errors"
)

var templateCMakeLists *template.Template
var templateToolchain *template.Template

func init() {
	templateCMakeLists = templateMustParse("CMakeLists.txt")
	templateToolchain = templateMustParse("toolchain.cmake")
}

func GenerateCMakeFiles() error {
	pathMakefile := path.Join(hiddenDirName, `gcc/Makefile`)
	pathCMakeLists := path.Join(hiddenDirName, `CMakeLists.txt`)
	pathToolchain := path.Join(hiddenDirName, `toolchain.cmake`)

	makefile, err := os.Open(pathMakefile)
	if err != nil {
		return errors.Wrap(err, "open makefile")
	}
	defer makefile.Close()

	data := Data{}
	if err := data.ReadMakefile(makefile); err != nil {
		return errors.Wrap(err, "read makefile")
	}

	cMakeListsFile, err := os.Create(pathCMakeLists)
	if err != nil {
		return errors.Wrap(err, "open CMakeLists")
	}
	defer cMakeListsFile.Close()
	if err := data.WriteCMakeLists(cMakeListsFile); err != nil {
		return errors.Wrap(err, "write CMakeLists")
	}

	toolchainFile, err := os.Create(pathToolchain)
	if err != nil {
		return errors.Wrap(err, "open toolchain")
	}
	defer toolchainFile.Close()
	if err := data.WriteToolchain(toolchainFile); err != nil {
		return errors.Wrap(err, "write toolchain")
	}
	return nil
}

func templateMustParse(name string) *template.Template {
	tmpl, err := template.New(name).Parse(FSMustString(false, "/templates/"+name))
	if err != nil {
		panic(err)
	}
	return tmpl
}

// Contains all the data we need from 'gcc/Makefile' to create 'CMakeLists.txt'.
type Data struct {

	// Source files to compile.
	SourceFiles []string

	// Paths to the directories to include.
	IncludeDirs []string

	// Path to the linker script.
	LinkerScript string

	// CPU: 'cortex-m0plus'
	CPU string

	// Device: 'SAMD21G18A'
	Device string
}

// ReadFromMakefile reads the data from the Makefile.
func (data *Data) ReadMakefile(r io.Reader) error {
	text, err := ioutil.ReadAll(r)
	if err != nil {
		return err
	}
	str := string(text)

	data.parseSourceFiles(str)
	data.parseIncludeDirs(str)

	if data.LinkerScript, err = find(`"\.\./(\S+\.ld)"`, str); err != nil {
		return errors.Wrap(err, "find linker script")
	}
	if data.CPU, err = find(`-mcpu=(\S*)`, str); err != nil {
		return errors.Wrap(err, "find cpu")
	}
	if data.Device, err = find(`-D__(\S+)__`, str); err != nil {
		return errors.Wrap(err, "find device")
	}
	return nil
}

// WriteCMakeLists writes the 'CMakeLists.txt' to the provided writer.
func (data *Data) WriteCMakeLists(w io.Writer) error {
	return templateCMakeLists.Execute(w, data)
}

// WriteToolchain writes the 'toolchain.cmake' to the provided writer.
func (data *Data) WriteToolchain(w io.Writer) error {
	return templateToolchain.Execute(w, data)
}

func find(regex, text string) (string, error) {
	c, err := regexp.Compile(regex)
	if err != nil {
		return ``, errors.Wrap(err, "compile regex")
	}
	f := c.FindStringSubmatch(text)
	if len(f) < 2 {
		return ``, errors.Wrap(err, "no match")
	}
	return f[1], nil
}

var regexSourceFiles *regexp.Regexp

func init() {
	regexSourceFiles = regexp.MustCompile(`"(\S+?)\.d"`)
}

func (data *Data) parseSourceFiles(text string) {
	found := regexSourceFiles.FindAllStringSubmatch(text, -1)
	for _, f := range found {
		if len(f) > 1 {
			if f[1] != "main" {
				data.SourceFiles = append(data.SourceFiles, f[1]+`.c`)
			}
		}
	}
	removeDuplicates(&data.IncludeDirs)
	sort.Strings(data.SourceFiles)
}

var regexIncludeDirs *regexp.Regexp

func init() {
	regexIncludeDirs = regexp.MustCompile(`-I"\.\./(\S*?)"`)
}

func (data *Data) parseIncludeDirs(text string) {
	found := regexIncludeDirs.FindAllStringSubmatch(text, -1)
	for _, f := range found {
		if len(f) > 1 {
			data.IncludeDirs = append(data.IncludeDirs, f[1])
		}
	}
	removeDuplicates(&data.IncludeDirs)
	sort.Strings(data.IncludeDirs)
}

func removeDuplicates(list *[]string) {
	buffer := make(map[string]struct{}, len(*list))
	j := 0
	for i, str := range *list {
		if _, ok := buffer[str]; !ok {
			buffer[str] = struct{}{}
			(*list)[j] = (*list)[i]
			j++
		}
	}
	*list = (*list)[:j]
}
