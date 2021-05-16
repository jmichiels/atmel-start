cmake_minimum_required(VERSION 3.13)
include_guard()

# Atmel Start root directory.
set(ATMEL_START_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to .atstart" FORCE)

# Atmel Start code as static library
add_library(atstart STATIC
    # Source files extracted from 'gcc/Makefile'.
    {{- range .SourceFiles}}
    "${ATMEL_START_DIR}/{{.}}"
    {{- end}}
)

# Include directories extracted from 'gcc/Makefile'.
target_include_directories(atstart PUBLIC
    {{- range .IncludeDirs}}
    "${ATMEL_START_DIR}/{{.}}"
    {{- end}}
)

# Bare minimum compiler options
target_compile_options(atstart PUBLIC
   -mthumb
   -mcpu={{.CPU}}
   -D__{{.Device}}__
)

# Apply the default flags that used to be in the toolchain.cmake file previously
# by calling this macro
macro(atstart_use_default_flags)
   target_compile_options(atstart PUBLIC
      -ffunction-sections
      -fdata-sections
      -mlong-calls
      $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
      $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
      $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
   )
   target_link_options(atstart PUBLIC
      LINKER:--start-group
      -lm
      LINKER:--end-group
      --specs=nano.specs
      LINKER:--gc-sections
      "-T${ATMEL_START_DIR}/{{.LinkerScript}}"
   )
endmacro()

# Have CMake generate an object file out of your ELF file
# by calling this macro and passing the name of your target
macro(atstart_create_bin target)
   add_custom_command(
      TARGET ${target} POST_BUILD
      COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${target}> $<TARGET_FILE_BASE_NAME:${target}>.bin
      WORKING_DIRECTORY $<TARGET_FILE_DIR:${target}>
   )
endmacro()

# Have CMake generate a HEX file out of your ELF file
# by calling this macro and passing the name of your target
macro(atstart_create_hex target)
   add_custom_command(
      TARGET ${target} POST_BUILD
      COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${target}> $<TARGET_FILE_BASE_NAME:${target}>.hex
      WORKING_DIRECTORY $<TARGET_FILE_DIR:${target}>
   )
endmacro()

# Macro kept for backwards compatibility
macro(atstart_add_executable target_name)
    atstart_use_default_flags()
    add_executable(${target_name} ${ARGN})
    target_link_libraries(${target_name} atstart)
    atstart_create_bin(${target_name})
endmacro(atstart_add_executable)