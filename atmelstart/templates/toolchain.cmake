cmake_minimum_required(VERSION 3.0)

# 'Generic' for embedded system without an OS.
set(CMAKE_SYSTEM_NAME Generic)

# Set C compiler.
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
# Set C++ compiler.
set(CMAKE_C++_COMPILER arm-none-eabi-g++)
# Set objcopy utility.
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)

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
set(COMMON_FLAGS "-mthumb -mcpu={{.CPU}}")
# Set compiler flags.
set(CMAKE_C_FLAGS  "${COMMON_FLAGS} -Os -ffunction-sections -mlong-calls -g3 -Wall -std=gnu99 -D__{{.Device}}__")
# Set linker flags.
set(CMAKE_EXE_LINKER_FLAGS "${COMMON_FLAGS} -Wl,--start-group -lm -Wl,--end-group --specs=nano.specs -Wl,--gc-sections -T${LINKER_SCRIPT}")

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

# Target to use the generated code as a library (without 'main.c').
#add_library(atmel_start STATIC ${ATMEL_START_SOURCE_FILES})

# Directories to include when building the library.
#target_include_directories(atmel_start PUBLIC ${ATMEL_START_INCLUDE_DIRS})

macro(add_atmel_start_executable target_name)

    set(elf_file ${target_name}.elf)
    set(bin_file ${target_name}.bin)

    # Outputs '.elf' file.
    add_executable(${elf_file} ${ARGN} ${ATMEL_START_SOURCE_FILES})

    # Directories to include.
    target_include_directories(${elf_file} PUBLIC ${ATMEL_START_INCLUDE_DIRS})

    # Outputs '.bin' file.
	add_custom_command(
		OUTPUT ${bin_file}
		COMMAND ${CMAKE_OBJCOPY} -O binary ${elf_file} ${bin_file}
		DEPENDS ${elf_file}
	)

	# build the intel hex file for the device
    add_custom_target(
        ${target_name}
        ALL
        DEPENDS ${bin_file}
    )
    set_target_properties(
    		${target_name}
    		PROPERTIES
    			OUTPUT_NAME ${elf_file}
    )

endmacro()