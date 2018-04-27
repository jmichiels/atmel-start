cmake_minimum_required(VERSION 3.3)
project (AtmelStartCmake)

# Include the generated CMakeLists.
add_subdirectory(lib/atmel_start)

add_executable(example src/main.c)
target_link_libraries(example atmel_start_lib)
