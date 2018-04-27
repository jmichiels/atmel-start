cmake_minimum_required(VERSION 3.0)

# Source files extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_SOURCE_FILES
    "./atmel_start.c"
    "./driver_init.c"
    "./examples/driver_examples.c"
    "./hal/src/hal_atomic.c"
    "./hal/src/hal_delay.c"
    "./hal/src/hal_gpio.c"
    "./hal/src/hal_init.c"
    "./hal/src/hal_io.c"
    "./hal/src/hal_sleep.c"
    "./hal/utils/src/utils_assert.c"
    "./hal/utils/src/utils_event.c"
    "./hal/utils/src/utils_list.c"
    "./hal/utils/src/utils_syscalls.c"
    "./hpl/core/hpl_core_m0plus_base.c"
    "./hpl/core/hpl_init.c"
    "./hpl/dmac/hpl_dmac.c"
    "./hpl/gclk/hpl_gclk.c"
    "./hpl/pm/hpl_pm.c"
    "./hpl/sysctrl/hpl_sysctrl.c"
    "./samd21a/gcc/gcc/startup_samd21.c"
    "./samd21a/gcc/system_samd21.c"
)

# Include directories extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_INCLUDE_DIRS
    "./"
    "./CMSIS/Include"
    "./config"
    "./examples"
    "./hal/include"
    "./hal/utils/include"
    "./hpl/core"
    "./hpl/dmac"
    "./hpl/gclk"
    "./hpl/pm"
    "./hpl/port"
    "./hpl/sysctrl"
    "./hri"
    "./samd21a/include"
)

# Target to use the generated code as a library (without 'main.c').
add_library(atmel_start STATIC ${ATMEL_START_SOURCE_FILES})

# Directories to include when building the library.
target_include_directories(atmel_start PUBLIC ${ATMEL_START_INCLUDE_DIRS})

