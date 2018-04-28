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
set(LINKER_SCRIPT "${ATMEL_START_DIR}/samd21a/gcc/gcc/samd21g18a_flash.ld")
# Common compiler and linker flags.
set(COMMON_FLAGS "-mthumb -mcpu=cortex-m0plus")
# Set compiler flags.
set(CMAKE_C_FLAGS  "${COMMON_FLAGS} -Os -ffunction-sections -mlong-calls -g3 -Wall -std=gnu99 -D__SAMD21G18A__")
# Set linker flags.
set(CMAKE_EXE_LINKER_FLAGS "${COMMON_FLAGS} -Wl,--start-group -lm -Wl,--end-group --specs=nano.specs -Wl,--gc-sections -T${LINKER_SCRIPT}")

# Source files extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_SOURCE_FILES
    "${ATMEL_START_DIR}/atmel_start.c"
    "${ATMEL_START_DIR}/driver_init.c"
    "${ATMEL_START_DIR}/examples/driver_examples.c"
    "${ATMEL_START_DIR}/hal/src/hal_atomic.c"
    "${ATMEL_START_DIR}/hal/src/hal_delay.c"
    "${ATMEL_START_DIR}/hal/src/hal_gpio.c"
    "${ATMEL_START_DIR}/hal/src/hal_init.c"
    "${ATMEL_START_DIR}/hal/src/hal_io.c"
    "${ATMEL_START_DIR}/hal/src/hal_sleep.c"
    "${ATMEL_START_DIR}/hal/utils/src/utils_assert.c"
    "${ATMEL_START_DIR}/hal/utils/src/utils_event.c"
    "${ATMEL_START_DIR}/hal/utils/src/utils_list.c"
    "${ATMEL_START_DIR}/hal/utils/src/utils_syscalls.c"
    "${ATMEL_START_DIR}/hpl/core/hpl_core_m0plus_base.c"
    "${ATMEL_START_DIR}/hpl/core/hpl_init.c"
    "${ATMEL_START_DIR}/hpl/dmac/hpl_dmac.c"
    "${ATMEL_START_DIR}/hpl/gclk/hpl_gclk.c"
    "${ATMEL_START_DIR}/hpl/pm/hpl_pm.c"
    "${ATMEL_START_DIR}/hpl/sysctrl/hpl_sysctrl.c"
    "${ATMEL_START_DIR}/samd21a/gcc/gcc/startup_samd21.c"
    "${ATMEL_START_DIR}/samd21a/gcc/system_samd21.c"
)

# Include directories extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_INCLUDE_DIRS
    "${ATMEL_START_DIR}/"
    "${ATMEL_START_DIR}/CMSIS/Include"
    "${ATMEL_START_DIR}/config"
    "${ATMEL_START_DIR}/examples"
    "${ATMEL_START_DIR}/hal/include"
    "${ATMEL_START_DIR}/hal/utils/include"
    "${ATMEL_START_DIR}/hpl/core"
    "${ATMEL_START_DIR}/hpl/dmac"
    "${ATMEL_START_DIR}/hpl/gclk"
    "${ATMEL_START_DIR}/hpl/pm"
    "${ATMEL_START_DIR}/hpl/port"
    "${ATMEL_START_DIR}/hpl/sysctrl"
    "${ATMEL_START_DIR}/hri"
    "${ATMEL_START_DIR}/samd21a/include"
)

macro(add_atmel_start_executable target_name)

    set(elf_file ${target_name}.elf)
    set(bin_file ${target_name}.bin)

    # Outputs '.elf' file.
    add_executable(${elf_file} ${ARGN} ${ATMEL_START_SOURCE_FILES})

    # Directories to include to compile the '.elf'.
    target_include_directories(${elf_file} PUBLIC ${ATMEL_START_INCLUDE_DIRS})

    # Outputs '.bin' file.
	add_custom_target(
		${bin_file}
		COMMAND ${CMAKE_OBJCOPY} -O binary ${elf_file} ${bin_file}
		DEPENDS ${elf_file}
	)

	# Outputs all files.
    add_custom_target(
        ${target_name}
        DEPENDS ${elf_file} ${bin_file}
    )

endmacro(add_atmel_start_executable)