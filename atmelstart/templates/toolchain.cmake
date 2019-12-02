# GENERATED FILE - DO NOT EDIT

cmake_minimum_required(VERSION 3.0)

# Find compiler.
find_program(ARM_CC arm-none-eabi-gcc)
find_program(ARM_CXX arm-none-eabi-g++)
find_program(ARM_OBJCOPY arm-none-eabi-objcopy)

# 'Generic' for embedded system without an OS.
set(CMAKE_SYSTEM_NAME Generic)

# Set C compiler.
set(CMAKE_C_COMPILER ${ARM_CC})
# Set C++ compiler.
set(CMAKE_C++_COMPILER ${ARM_CXX})
# Set objcopy utility.
set(CMAKE_OBJCOPY ${ARM_OBJCOPY})

# Prevents linking issue while testing compiler.
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Set CMAKE_SYSROOT as find_program() root.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Set CMAKE_FIND_ROOT_PATH as find_library() root.
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# Set CMAKE_FIND_ROOT_PATH as find_file()/find_path() root.
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# Set CMAKE_FIND_ROOT_PATH as find_package() root.
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Atmel Start root directory.
set(ATMEL_START_DIR ${CMAKE_CURRENT_LIST_DIR})

# Linker script.
set(LINKER_SCRIPT "${ATMEL_START_DIR}/{{.LinkerScript}}")
# Common compiler and linker flags.
set(COMMON_BUILD_LINK_FLAGS "-mthumb -mcpu={{.CPU}}")
# Common c and c++ flags.
set(COMMON_C_CXX_FLAGS "${COMMON_FLAGS} -Os -ffunction-sections -fdata-sections -mlong-calls  -g3 -Wall -D__{{.Device}}__")
# Set C compiler flags.
set(CMAKE_C_FLAGS  "${COMMON_C_CXX_FLAGS} -std=gnu99 ")
# Set C++ compiler flags.
set(CMAKE_CXX_FLAGS  "${COMMON_C_CXX_FLAGS} -std=gnu++14 -fno-threadsafe-statics -fno-rtti -fno-exceptions")
# Set linker flags.
set(CMAKE_EXE_LINKER_FLAGS "${COMMON_BUILD_LINK_FLAGS} -Wl,--start-group -lm -Wl,--end-group --specs=nano.specs -Wl,--gc-sections -T${LINKER_SCRIPT}")

# Source files extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_SOURCE_FILES
    {{- range .SourceFiles}}
    "${ATMEL_START_DIR}/{{.}}"
    {{- end}}
)

# Include directories extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_INCLUDE_DIRS
    {{- range .IncludeDirs}}
    "${ATMEL_START_DIR}/{{.}}"
    {{- end}}
)

macro(atstart_add_executable target_name)

	set(elf_name ${target_name}.elf)
	set(bin_name ${target_name}.bin)

	set(elf_path ${CMAKE_BINARY_DIR}/${elf_name})
	set(bin_path ${CMAKE_BINARY_DIR}/${bin_name})

    # Outputs elf file.
    add_executable(${target_name} ${ARGN} ${ATMEL_START_SOURCE_FILES})

	# Rename the elf file.
	set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${elf_name})

    # Directories to include to compile the elf.
    target_include_directories(${target_name} PUBLIC ${ATMEL_START_INCLUDE_DIRS})

    # Generate bin file.
	add_custom_command(
		TARGET ${target_name} POST_BUILD
		COMMAND ${CMAKE_OBJCOPY} -O binary ${elf_path} ${bin_path}
	)

endmacro(atstart_add_executable)