package cmd

import (
	"github.com/jmichiels/AtmelStart/atmelstart"
	"github.com/sirupsen/logrus"
	"github.com/spf13/cobra"
)

// cmakeCmd represents the cmake command
var cmakeCmd = &cobra.Command{
	Use:   "cmake",
	Short: "Build the Atmel Start project using CMake",
	Run: func(cmd *cobra.Command, args []string) {
		if err := atmelstart.CMake(args); err != nil {
			logrus.Fatal(err)
		}
	},
}

func init() {
	rootCmd.AddCommand(cmakeCmd)
}
