
# Atmel Start

This projects consists in a command-line tool to streamline work with the [Atmel Start](http://start.atmel.com/) code generator, as well as a CMake toolchain generator which allows to integrate code generated using Atmel Start in a CMake project (for use in the [JetBrains CLion](https://www.jetbrains.com/clion/) IDE for example)

## Quick Start

**Install the command line tool**
```
$ go get -u github.com/jmichiels/AtmelStart/atmelstart/...
```
**Initialize the Atmel Start configuration**
```
$ atstart init
```
This will open a Chrome window and create a new configuration file `atstart.yaml` in the current directory. This file is the same as the one you would get using *Save Configuration* in Atmel Start. This file will automatically be kept in sync with the changes you make to the configuration as long as the Chrome window stays open.

**Generate the Atmel Start code and download it**
```
$ atstart pull
``` 
This will generate the code, download it and extract in a `.atstart` directory. The code is the same as the one you would get using *Export Project* in Atmel Start. This will also generate ` toolchain.cmake` which you can then use to build your project:

```
$ cd build
$ cmake -DCMAKE_TOOLCHAIN_FILE="../.atstart/toolchain.cmake" ..
```
See `CMakeLists.txt` in the [example](example).

**Edit the Atmel Start configuration**

You can edit an existing Atmel Start `atstart.yaml` configuration file (to add software drivers, edit parameters...) using:
```
$ atstart open
``` 
As for `init`, this will open Atmel Start in a new Chrome Window. You will have to call `pull` again in order for the code to reflect the updated configuration.
