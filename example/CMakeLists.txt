cmake_minimum_required(VERSION 3.13)
project(example)

add_subdirectory(.atstart)
atstart_use_default_flags()

add_executable(example main.c)
target_link_libraries(example atstart)

# Set the offset for the start of the application to leave room for the bootloader.
target_link_options(example PUBLIC -Wl,--section-start=.text=0x2000)

# Create BIN and HEX files out of the ELF file
atstart_create_bin(example)
atstart_create_hex(example)

# Target to upload BIN file using bossac.
add_custom_target(
    upload
    COMMAND echo bossac -i -d -e -w -R -v $<TARGET_FILE_BASE_NAME:example>.bin
    WORKING_DIRECTORY $<TARGET_FILE_DIR:example>
    DEPENDS example
)