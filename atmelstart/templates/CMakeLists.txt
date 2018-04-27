cmake_minimum_required(VERSION 3.0)

# Source files extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_SOURCE_FILES
    {{- range .SourceFiles}}
    "./{{.}}"
    {{- end}}
)

# Include directories extracted from 'gcc/Makefile'.
list(APPEND ATMEL_START_INCLUDE_DIRS
    {{- range .IncludeDirs}}
    "./{{.}}"
    {{- end}}
)

# Target to use the generated code as a library (without 'main.c').
add_library(atmel_start STATIC ${ATMEL_START_SOURCE_FILES})

# Directories to include when building the library.
target_include_directories(atmel_start PUBLIC ${ATMEL_START_INCLUDE_DIRS})

