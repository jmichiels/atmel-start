cmake_minimum_required(VERSION 3.3)
project(example)

# Set the offset for the start of the application to leave room for the bootloader.
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--section-start=.text=0x2000")

#
add_atmel_start_executable(example src/main.c)

# Target to upload binary using bossac.
add_custom_target(
    upload
    COMMAND bossac -i -d -e -w -R -v example.bin
    DEPENDS example.bin
)