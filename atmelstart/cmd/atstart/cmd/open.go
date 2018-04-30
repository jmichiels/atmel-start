package cmd

import (
	"github.com/jmichiels/AtmelStart/atmelstart"
	"github.com/sirupsen/logrus"
	"github.com/spf13/cobra"
)

// openCmd represents the open command
var openCmd = &cobra.Command{
	Use:   "open",
	Short: "Open an existing Atmel Start project",
	Run: func(cmd *cobra.Command, args []string) {
		if err := atmelstart.Open(); err != nil {
			logrus.Fatal(err)
		}
	},
}

func init() {
	rootCmd.AddCommand(openCmd)
}
