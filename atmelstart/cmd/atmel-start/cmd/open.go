package cmd

import (
	"encoding/json"
	"fmt"

	"context"
	"log"

	"os"

	"path/filepath"

	"io/ioutil"

	"github.com/chromedp/chromedp"
	"github.com/chromedp/chromedp/runner"
	"github.com/pkg/errors"
	"github.com/spf13/cobra"
)

func runApp(path string) runner.CommandLineOption {
	return func(m map[string]interface{}) error {
		m["app"] = path
		return nil
	}
}

func runMaximized() runner.CommandLineOption {
	return func(m map[string]interface{}) error {
		m["start-maximized"] = ""
		return nil
	}
}

// openCmd represents the open command
var openCmd = &cobra.Command{
	Use:  "open",
	Args: cobra.MaximumNArgs(1),
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("open called")

		if len(args) != 1 {
			fatal(errors.New("missing .atstart"))
		}

		configYAMLReader, err := os.Open(args[0])
		if err != nil {
			fatal(errors.Wrap(err, "open .atstart"))
		}

		configYAML, err := ioutil.ReadAll(configYAMLReader)
		if err != nil {
			fatal(errors.Wrap(err, "read .atstart"))
		}

		EscapedConfigYAML, err := json.Marshal(string(configYAML))
		if err != nil {
			fatal(errors.Wrap(err, "escape .atstart"))
		}

		//fmt.Printf(`ACME.Start.openProject(%s);`, EscapedConfigYAML)
		//
		//return
		//
		//fmt.Println(string(escapedProject))

		//
		//response, err := http.Post("http://start.atmel.com/api/v2/project_format/transport/latest", "application/json", request)
		//if err != nil {
		//	fatal(errors.Wrap(err, "post .atstart"))
		//}
		//
		//decodedResponse := make(map[string]interface{})
		//if err := json.NewDecoder(response.Body).Decode(&decodedResponse); err != nil {
		//	fatal(errors.Wrap(err, "decode json"))
		//}
		//
		//decodedResponseResult, ok := decodedResponse["result"]
		//if !ok {
		//	fatal(errors.New("malformed response"))
		//}
		//decodedResponseResultMap, ok := decodedResponseResult.(map[string]interface{})
		//if !ok {
		//	fatal(errors.New("malformed response"))
		//}
		//decodedResponseProject, ok := decodedResponseResultMap["project"]
		//if !ok {
		//	fatal(errors.New("malformed response"))
		//}
		//
		//encodedProject, err := json.Marshal(decodedResponseProject)
		//if err != nil {
		//	fatal(errors.Wrap(err, "encode json"))
		//}
		//
		//fmt.Println(string(encodedProject))
		//
		//escapedProject, err := json.Marshal(string(encodedProject))
		//if err != nil {
		//	fatal(errors.Wrap(err, "escape json"))
		//}
		//
		//fmt.Println(string(escapedProject))

		// create context
		ctxt, cancel := context.WithCancel(context.Background())
		defer cancel()

		//r, err := runner.New(func(i map[string]interface{}) error {
		//	i["app"] = "http://start.atmel.com/"
		//	i["start-maximized"] = ""
		//	return nil
		//})
		//if err != nil {
		//	fatal(err)
		//}
		//if err := r.Start(ctxt); err != nil {
		//	fatal(err)
		//}

		//runner.Run

		abs, err := filepath.Abs(os.Args[1])
		if err != nil {
			fatal(err)
		}
		fmt.Println(abs)

		// Open in chrome.
		c, err := chromedp.New(ctxt, chromedp.WithLog(log.Printf), chromedp.WithRunnerOptions(runApp("http://start.atmel.com"), runMaximized()))
		if err != nil {
			fatal(err)
		}
		var result []byte

		err = c.Run(ctxt, chromedp.Tasks{
			chromedp.Evaluate(fmt.Sprintf(`ACME.Start.openProject(%s);`, EscapedConfigYAML), &result),

			//chromedp.Evaluate(fmt.Sprintf(`localStorage.setItem("projects-currentProject",%s);`, string(escapedProject)), &result),
			//chromedp.Navigate(`http://start.atmel.com/#dashboard`),
		})
		if err != nil {
			fatal(err)
		}

		//chromedp.Action()

		// wait for chrome to finish
		err = c.Wait()
		if err != nil {
			fatal(err)
		}

		//fmt.Println(resp)
	},
}

func init() {
	rootCmd.AddCommand(openCmd)
}
