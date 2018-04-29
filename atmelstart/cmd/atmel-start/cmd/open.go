package cmd

import (
	"encoding/json"
	"fmt"

	"context"

	"io/ioutil"

	"time"

	"os"
	"os/signal"

	"bytes"
	"net/http"

	"github.com/chromedp/cdproto/runtime"
	"github.com/chromedp/chromedp"
	"github.com/chromedp/chromedp/runner"
	"github.com/pkg/errors"
	"github.com/sirupsen/logrus"
	"github.com/spf13/cobra"
)

func runApp(path string) runner.CommandLineOption {
	return runner.Flag("app", path)
}

func runDefaultUser() runner.CommandLineOption {
	return runner.Flag("user-data-dir", "")
}

func runMaximized() runner.CommandLineOption {
	return runner.Flag("start-maximized", "")
}

const jsLoadConfiguration = `
(function(){
	if(!ACME.Project.isReady() && !ACME.Project.isLoading()) {
		ACME.Start.openProject(%s);
	}
	return ACME.Project.isReady();
})();
`

func voidLogger(format string, a ...interface{}) {}

var chrome *chromedp.CDP

var configFile string

var prevConfigJSON []byte
var currConfigJSON []byte

// openCmd represents the open command
var openCmd = &cobra.Command{
	Use:  "open",
	Args: cobra.MaximumNArgs(1),
	Run: func(cmd *cobra.Command, args []string) {
		if len(args) != 1 {
			logrus.Fatal(errors.New("missing .atstart"))
		}
		configFile = args[0]

		configYAML, err := ioutil.ReadFile(configFile)
		if err != nil {
			logrus.Fatal(errors.Wrap(err, "read .atstart"))
		}

		EscapedConfigYAML, err := json.Marshal(string(configYAML))
		if err != nil {
			logrus.Fatal(errors.Wrap(err, "escape .atstart"))
		}

		// Create cancellable context
		ctxt, cancel := context.WithCancel(context.Background())
		defer cancel()

		logrus.Info("open new chrome instance")

		// Open Atmel Start in Chrome (disable logs, app mode, maximized).
		chrome, err = chromedp.New(ctxt, chromedp.WithLog(voidLogger), chromedp.WithRunnerOptions(runApp("http://start.atmel.com"), runMaximized()))
		if err != nil {
			logrus.Fatal(err)
		}

		closed := make(chan struct{})

		go func() {
			// Wait for chrome to finish
			err = chrome.Wait()
			close(closed)
			if err != nil {
				logrus.Fatal(err)
			}
		}()

		interrupt := make(chan os.Signal)

		// Wait for an interrupt signal.
		signal.Notify(interrupt, os.Interrupt)

		var isReady bool

		ticker := time.NewTicker(100 * time.Millisecond)

		logrus.Info("start loading configuration")

		for {
			select {
			case <-ticker.C:
				if !isReady {
					err = chrome.Run(ctxt, chromedp.Tasks{
						// Load the project with the provided config.
						chromedp.Evaluate(fmt.Sprintf(jsLoadConfiguration, EscapedConfigYAML), &isReady),
					})
					if err != nil {
						if _, ok := err.(*runtime.ExceptionDetails); ok {
							// An exception is thrown if ACME.Start does not exists yet.
							continue
						}
						logrus.Fatal(errors.Wrap(err, "loading configuration"))
					}
					if isReady {
						logrus.Info("done loading configuration")

						// Lower the ticker frequency.
						ticker = time.NewTicker(time.Second)

						logrus.Info("start watching for configuration change")
					}
				} else {
					compareAndSave(ctxt)
				}
			case <-interrupt:
				logrus.Info("interrupt signal catched")
				compareAndSave(ctxt)
				logrus.Info("configuration saved")
				return

			case <-closed:
				logrus.Info("chrome instance closed")
				return
			}
		}
	},
}

func compareAndSave(ctxt context.Context) {
	err := chrome.Run(ctxt, chromedp.Tasks{
		// Get the current configuration in raw JSON.
		chromedp.Evaluate(`ACME.ProjectSession.save()`, &currConfigJSON),
	})
	if err != nil {
		logrus.Fatal(errors.Wrap(err, "read configuration"))
	}
	if bytes.Compare(prevConfigJSON, currConfigJSON) != 0 {
		if prevConfigJSON != nil {
			logrus.Info("configuration change detected")
			response, err := http.Post(`http://start.atmel.com/api/v1/project_format/storage/latest`, `application/json`, bytes.NewReader(currConfigJSON))
			if err != nil {
				logrus.Fatal(errors.Wrap(err, "format configuration"))
			}
			if response.StatusCode != http.StatusOK {
				logrus.Fatal(errors.New("format configuration"))
			}
			formatted, err := ioutil.ReadAll(response.Body)
			if err != nil {
				logrus.Fatal(errors.Wrap(err, "write configuration"))
			}
			if err := ioutil.WriteFile(configFile, formatted, 666); err != nil {
				logrus.Fatal(errors.Wrap(err, "write configuration"))
			}

			logrus.Info("configuration file updated")
		}
		prevConfigJSON = currConfigJSON
		currConfigJSON = make([]byte, 0, len(prevConfigJSON))
	}
}

func init() {
	rootCmd.AddCommand(openCmd)
}
