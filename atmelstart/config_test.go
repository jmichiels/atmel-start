package atmelstart

import (
	"path"
	"testing"

	"io"
	"os"

	. "github.com/smartystreets/goconvey/convey"
)

var pathGeneratedZIP = path.Join(`testdata`, `generated.zip`)
var pathConfigJSON = path.Join(`testdata`, `config.json`)
var pathConfigYAML = path.Join(`testdata`, `config.yaml`)

func TestFormat(t *testing.T) {

	Convey("Given a example configuration in YAML and JSON", t, func() {
		var goldenConfigYAML configYAML
		err := goldenConfigYAML.ReadFromFile(pathConfigYAML)
		So(err, ShouldBeNil)

		var goldenConfigJSON configJSON
		err = goldenConfigJSON.ReadFromFile(pathConfigJSON)
		So(err, ShouldBeNil)

		Convey("Requesting the backend for the JSON given the YAML", func() {
			configJSON, err := goldenConfigYAML.requestJSON()
			So(err, ShouldBeNil)

			if len(goldenConfigJSON.Bytes()) == 0 {
				// Populate JSON test data if not present.
				if err := configJSON.WriteToFile(pathConfigJSON); err != nil {
					panic(err)
				}
			} else {
				Convey("The JSON should match", func() {
					So(configJSON.String(), ShouldResemble, goldenConfigJSON.String())
				})
			}
		})

		Convey("Requesting the backend for the YAML given the JSON", func() {
			configYAML, err := goldenConfigJSON.requestYAML()
			So(err, ShouldBeNil)

			Convey("The YAML should match", func() {
				So(configYAML.String(), ShouldResemble, goldenConfigYAML.String())
			})
		})
	})
}

func TestGenerate(t *testing.T) {
	Convey("Given a example configuration in YAML and JSON", t, func() {
		var goldenConfigYAML configYAML
		err := goldenConfigYAML.ReadFromFile(pathConfigYAML)
		So(err, ShouldBeNil)

		var goldenConfigJSON configJSON
		err = goldenConfigJSON.ReadFromFile(pathConfigJSON)
		So(err, ShouldBeNil)

		Convey("Requesting the backend to generate the project given the JSON", func() {
			response, err := goldenConfigJSON.requestGenerate()
			So(err, ShouldBeNil)

			f, err := os.Create(pathGeneratedZIP)
			So(err, ShouldBeNil)

			_, err = io.Copy(f, response)
			So(err, ShouldBeNil)
		})

		Convey("Requesting the backend to generate the project given the YAML", func() {
			response, err := goldenConfigYAML.requestGenerate()
			So(err, ShouldBeNil)

			f, err := os.Create(pathGeneratedZIP)
			So(err, ShouldBeNil)

			_, err = io.Copy(f, response)
			So(err, ShouldBeNil)
		})
	})
}
