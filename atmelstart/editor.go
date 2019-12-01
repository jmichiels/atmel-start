package atmelstart

import (
	"bytes"
	"fmt"
	"os"
	"os/signal"
	"time"

	"github.com/pkg/errors"
	"github.com/sirupsen/logrus"
	"github.com/zserge/lorca"
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
const jsSaveConfig = `JSON.stringify(ACME.ProjectSession.save())`

type editor struct {
	chrome lorca.UI

	configYAML *configYAML

	prevConfJSON configJSON
	currConfJSON configJSON

	// Channel for interrupt signal.
	interrupt chan os.Signal

	ticker *time.Ticker
	ready  bool
}

func open(configYAML *configYAML) (err error) {
	e := &editor{configYAML: configYAML}

	// Open Atmel START in Chrome.
	if err != e.openChrome() {
		return errors.Wrap(err, "open chrome")
	}
	defer e.chrome.Close()

	// Setup notification on interrupt signal.
	e.initNotifyInterrupt()

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
		case <-e.chrome.Done():
			logrus.Info("chrome window closed")
			return nil
		}
	}
}

// Opens Chrome.
func (e *editor) openChrome() (err error) {
	e.chrome, err = lorca.New(e.getStartURL(), "", 1170+2*40, 800)
	return err
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

// Returns whether we work on a new project.
func (e *editor) isNewProject() bool {
	return e.configYAML == nil
}

// Callback on 'load' tick.
func (e *editor) callbackLoad() (err error) {
	if !e.isNewProject() {
		e.ready = e.requestLoadConfig()
	} else {
		e.ready = e.requestIsProjectReady()
	}
	if e.ready {

		logrus.Info("done loading configuration")

		// Slow down the ticker.
		e.initTicker(time.Second)
	}
	return nil
}

// Request to load the config (if not already loading), and return if the project is ready.
func (e *editor) requestLoadConfig() (ready bool) {
	return e.evaluateBoolean(fmt.Sprintf(jsLoadConfig, string(e.configYAML.escape())))
}

// Request to know if the project is ready.
func (e *editor) requestIsProjectReady() bool {
	return e.evaluateBoolean(jsIsProjectReady)
}

// Callback on 'save' tick.
func (e *editor) callbackSave() error {
	e.requestSaveConfig()
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
func (e *editor) requestSaveConfig() {
	e.currConfJSON.byteSlice = []byte(e.chrome.Eval(jsSaveConfig).String())
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

// Wait for an interrupt signal.
func (e *editor) initNotifyInterrupt() {
	e.interrupt = make(chan os.Signal, 1)
	signal.Notify(e.interrupt, os.Interrupt)
}

func (e *editor) evaluateBoolean(js string) bool {
	return e.chrome.Eval(js).Bool()
}
