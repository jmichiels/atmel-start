package cmd

import (
	"github.com/jmichiels/AtmelStart/atmelstart"
	"github.com/sirupsen/logrus"
	"github.com/spf13/cobra"
)

// pullCmd represents the pull command
var pullCmd = &cobra.Command{
	Use:   "pull",
	Short: "Generate code given the configuration",
	Run: func(cmd *cobra.Command, args []string) {
		if err := atmelstart.Generate(); err != nil {
			logrus.Fatal(err)
		}
		if err := atmelstart.GenerateCMakeToolchain(); err != nil {
			logrus.Fatal(err)
		}
	},
}

func init() {
	rootCmd.AddCommand(pullCmd)
}
