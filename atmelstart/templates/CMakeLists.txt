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

# Target to use the generated code as a library (excludes 'main.c').
add_library(atmel_start STATIC ${ATMEL_START_SOURCE_FILES})

# Directories to include when building the library.
target_include_directories(atmel_start PUBLIC ${ATMEL_START_INCLUDE_DIRS})

# Target to use the generated code as an executable (uses default 'main.c').
add_executable(atmel_start_app "main.c" ${ATMEL_START_SOURCE_FILES})

# Link executable against the library.
target_link_libraries(atmel_start_app atmel_start_lib)
