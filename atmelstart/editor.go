package atmelstart

import (
	"bytes"
	"context"
	"fmt"
	"os"
	"os/signal"
	"time"

	"github.com/chromedp/chromedp"
	"github.com/chromedp/chromedp/runner"
	"github.com/pkg/errors"
	"github.com/sirupsen/logrus"
)

func Init() error {
	return open(nil)
}

func Open() error {
	var confYAML configYAML
	if err := confYAML.ReadFromFile(configFileName); err != nil {
		return errors.Wrap(err, "read configuration file")
	}
	return open(&confYAML)
}

const (
	// New project home.
	urlNewProject = urlAtmelStart + `#project`

	// Returns 'true' the required javascript components are done loading.
	jsIsReady = `typeof ACME !== 'undefined' && typeof ACME.Start !== 'undefined' && typeof ACME.Project !== 'undefined'`

	// Returns 'true' when the project is ready.
	jsIsProjectReady = jsIsReady + ` && ACME.Project.isReady()`
)

// Returns 'true' when the project is ready. If the project is not ready and not loading, also request to load it.
const jsLoadConfig = `
(function(){
	if(` + jsIsReady + ` && !ACME.Project.isReady() && !ACME.Project.isLoading()) {
		ACME.Start.openProject(%s);
	}
	return ` + jsIsProjectReady + `;
})();
`

// Returns the project configuration.
const jsSaveConfig = `ACME.ProjectSession.save()`

type editor struct {
	ctxt context.Context

	configYAML *configYAML

	prevConfJSON configJSON
	currConfJSON configJSON

	// Chrome instance.
	chrome *chromedp.CDP

	// Channel for interrupt signal.
	interrupt chan os.Signal

	// Channel closed when chrome instance close.
	closed chan struct{}

	ticker *time.Ticker
	ready  bool
}

func open(configYAML *configYAML) (err error) {
	e := &editor{configYAML: configYAML}

	// Init context.
	cancel := e.initContext()
	defer cancel()

	// Open atmel start in chrome.
	if err := e.openChrome(); err != nil {
		return errors.Wrap(err, "open chrome")
	}

	// Setup notification on interrupt signal.
	e.initNotifyInterrupt()

	// Setup notification on chrome closed.
	e.initNotifyChromeClose()

	// Init ticker.
	e.initTicker(250 * time.Millisecond)

	logrus.Info("start loading configuration")

	for {
		select {
		case <-e.ticker.C:
			if err := e.callbackTicker(); err != nil {
				return err
			}
		case <-e.interrupt:
			logrus.Info("interrupt signal caught")
			if err := e.callbackSave(); err != nil {
				return err
			}
			return nil
		case <-e.closed:
			logrus.Info("chrome instance closed")
			return nil
		}
	}
}

// Init cancellable context and returns cancel function.
func (e *editor) initContext() (cancel context.CancelFunc) {
	e.ctxt, cancel = context.WithCancel(context.Background())
	return cancel
}

// Init load ticker (running while the project is not ready).
func (e *editor) initTicker(duration time.Duration) {
	e.ticker = time.NewTicker(duration)
}

// Callback on 'load' tick.
func (e *editor) callbackTicker() (err error) {
	if !e.ready {
		return e.callbackLoad()
	} else {
		return e.callbackSave()
	}
}

// Returns whteter we work on a new project.
func (e *editor) isNewProject() bool {
	return e.configYAML == nil
}

// Callback on 'load' tick.
func (e *editor) callbackLoad() (err error) {
	if !e.isNewProject() {
		e.ready, err = e.requestLoadConfig()
		if err != nil {
			return errors.Wrap(err, "loading configuration")
		}
	} else {
		e.ready, err = e.requestIsProjectReady()
		if err != nil {
			return errors.Wrap(err, "waiting configuration")
		}
	}
	if e.ready {

		logrus.Info("done loading configuration")

		// Slow down the ticker.
		e.initTicker(time.Second)
	}
	return nil
}

// Request to load the config (if not already loading), and return if the project is ready.
func (e *editor) requestLoadConfig() (ready bool, err error) {
	return e.evaluateBoolean(fmt.Sprintf(jsLoadConfig, string(e.configYAML.escape())))
}

// Request to know if the project is ready.
func (e *editor) requestIsProjectReady() (bool, error) {
	return e.evaluateBoolean(jsIsProjectReady)
}

// Callback on 'save' tick.
func (e *editor) callbackSave() error {
	if err := e.requestSaveConfig(); err != nil {
		errors.Wrap(err, "save project")
	}
	if bytes.Compare(e.prevConfJSON.Bytes(), e.currConfJSON.Bytes()) != 0 {
		if e.prevConfJSON.Bytes() != nil || (e.prevConfJSON.Bytes() == nil && e.isNewProject()) {

			logrus.Info("configuration change detected")

			// Request to the backend to validate and format the project.
			confYAML, err := e.currConfJSON.requestYAML()
			if err != nil {
				return errors.Wrap(err, "format configuration")
			}
			if err := confYAML.WriteToFile(configFileName); err != nil {
				return errors.Wrap(err, "save configuration")
			}

			logrus.Info("configuration file written")
		}
		e.prevConfJSON = e.currConfJSON
		e.currConfJSON = configJSON{}
	}
	return nil
}

// Request to save the configuration.
func (e *editor) requestSaveConfig() error {
	return e.chrome.Run(e.ctxt, chromedp.Tasks{
		chromedp.Evaluate(jsSaveConfig, (*[]byte)(&(e.currConfJSON.byteSlice))),
	})
}

// Returns start URL.
func (e *editor) getStartURL() string {
	if !e.isNewProject() {
		// Open an existing project.
		return urlAtmelStart
	} else {
		// Start a new project.
		return urlNewProject
	}
}

// Opens new Chrome instance.
func (e *editor) openChrome() (err error) {
	e.chrome, err = chromedp.New(e.ctxt,
		chromedp.WithLog(voidLogger),
		chromedp.WithRunnerOptions(
			runApp(e.getStartURL()),
			runMaximized()))
	if err != nil {
		return err
	}
	return nil
}

// Wait from chrome to close.
func (e *editor) initNotifyChromeClose() {
	e.closed = make(chan struct{})
	go func() {
		_ = e.chrome.Wait()
		close(e.closed)
	}()
}

// Wait for an interrupt signal.
func (e *editor) initNotifyInterrupt() {
	e.interrupt = make(chan os.Signal, 1)
	signal.Notify(e.interrupt, os.Interrupt)
}

func (e *editor) evaluateBoolean(js string) (bool, error) {
	var result bool
	err := e.chrome.Run(e.ctxt, chromedp.Tasks{
		chromedp.Evaluate(js, &result),
	})
	return result, err
}

// Custom logger which does nothing.
func voidLogger(string, ...interface{}) {}

// Runner option to run chrome in app mode.
func runApp(path string) runner.CommandLineOption {
	return runner.Flag("app", path)
}

// Runner option to run chrome maximized.
func runMaximized() runner.CommandLineOption {
	return runner.Flag("start-maximized", "")
}
