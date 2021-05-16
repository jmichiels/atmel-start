
# Atmel START

This projects consists in a command-line tool to streamline work with the [Atmel Start](http://start.atmel.com/) code generator, as well as a CMake generator which allows to integrate code generated using Atmel Start in a CMake project.
CMake projects can easily be used in [JetBrains CLion](https://www.jetbrains.com/clion/), [Visual Studio Code](https://code.visualstudio.com/) (using [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)) and other well-known IDEs.

## Quick Start

**Install the command line tool**
```sh
$ go get -u github.com/jmichiels/AtmelStart/atmelstart/...
```

**Initialize the Atmel Start configuration**
```sh
$ atstart init
```
This will open a Chrome window and create a new configuration file `atstart.yaml` in the current directory. This file is the same as the one you would get using *Save Configuration* in Atmel Start. This file will automatically be kept in sync with the changes you make to the configuration as long as the Chrome window stays open.

**Generate the Atmel Start code and download it**
```sh
$ atstart pull
``` 
This will generate the code, download it and extract in a `.atstart` directory. The code is the same as the one you would get using *Export Project* in Atmel Start. This will also generate ` CMakeLists.txt` that defines a static library called `atstart` and include `toolchain.cmake` for the GCC ARM compiler.

**Create your project files**
Create a main code file for your project. You can copy `.atstart/main.c` down to your project directory as a starter if you wish.

Create a `CMakeLists.txt` file to defines your project, similar to the following example:

```cmake
cmake_minimum_required(VERSION 3.13)

project(example)

# Add the Atmel Start code
add_subdirectory(.atstart)

# Use recommended default compiler flags
atstart_use_default_flags()

# Define your executable
add_executable(myprogram
   src/main.c)

# Link your executable with the Atmel Start code
target_link_libraries(myprogram atstart)

# Configure CMake to create a BIN file out of the ELF
atstart_create_bin(myprogram)
```

Be sure to have a look at the [example](example) as well.

**Build your project**

```sh
$ cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=".atstart/toolchain.cmake" -DCMAKE_BUILD_TYPE=Debug
$ cmake --build build
```

**Edit the Atmel Start configuration**

You can edit an existing Atmel Start `atstart.yaml` configuration file (to add software drivers, edit parameters...) using:
```
$ atstart open
``` 
As with `init`, this will open Atmel Start in a new Chrome Window. You will have to call `pull` again in order for the code to reflect the updated configuration.
