cmake_minimum_required(VERSION 3.6)

# Toolchain file to configure the GCC ARM compiler
# ------------------------------------------------------------------------------------
# Inspired by the NXP MCUXpresso toolchain file,
# as well as the one from https://github.com/vpetrigo/arm-cmake-toolchains

# In order to use a specific version of GCC ARM rather than the one on the PATH, you
# can pass the installation path to CMake using -DTOOLCHAIN_DIR=my/custom/path

set(TOOLCHAIN_TRIPLET arm-none-eabi)
if(WIN32)
    set(TOOLCHAIN_EXT .exe)
else()
    set(TOOLCHAIN_EXT)
endif()

# Determine TOOLCHAIN_DIR (path to GCC ARM installation)
if (NOT DEFINED TOOLCHAIN_DIR)
   # If TOOLCHAIN_DIR is already set in the cache or via the command line, do not try to determine it's location
   find_program(GCC_ARM_COMPILER_BIN ${TOOLCHAIN_TRIPLET}-gcc REQUIRED)
   if (NOT GCC_ARM_COMPILER_BIN)
      message(FATAL_ERROR "Unable to find ${TOOLCHAIN_TRIPLET}gcc. Please configure the TOOLCHAIN_DIR variable manually.")
   endif()

   # Find location where arm-none-eabi-gcc is installed
   get_filename_component(TOOLCHAIN_DIR_TEMP ${GCC_ARM_COMPILER_BIN} REALPATH)
   get_filename_component(TOOLCHAIN_DIR_TEMP ${TOOLCHAIN_DIR_TEMP} DIRECTORY)
   get_filename_component(TOOLCHAIN_DIR_TEMP ${TOOLCHAIN_DIR_TEMP}/.. ABSOLUTE)
   if (EXISTS ${TOOLCHAIN_DIR_TEMP})
      set(TOOLCHAIN_DIR ${TOOLCHAIN_DIR_TEMP} CACHE PATH "GCC ARM compiler installation path")
      message(STATUS "Using GCC ARM from: ${TOOLCHAIN_DIR}")
   else()
      message(FATAL_ERROR "Failed to determine GCC ARM location: ${TOOLCHAIN_DIR}")
   endif()
   unset(ARM_GCC CACHE)
   unset(TOOLCHAIN_DIR_TEMP CACHE)
endif()
if (NOT DEFINED TOOLCHAIN_DIR OR NOT EXISTS ${TOOLCHAIN_DIR})
   message(FATAL_ERROR "GCC ARM location not configured correctly: ${TOOLCHAIN_DIR}")
endif()

# Configure CMake variables
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)
set(CMAKE_EXECUTABLE_SUFFIX_C .elf)
set(CMAKE_EXECUTABLE_SUFFIX_CXX .elf)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_SYSROOT ${TOOLCHAIN_DIR}/${TARGET_TRIPLET})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Configure compilers
set(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_DIR}/bin CACHE PATH "GCC ARM compiler bin path")
set(CMAKE_C_COMPILER ${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_TRIPLET}-gcc${TOOLCHAIN_EXT})
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
if (EXISTS ${CMAKE_C_COMPILER})
   set(CMAKE_C_FLAGS_DEBUG_INIT "-g3 -Og -gdwarf -Wall -pedantic -DDEBUG")
   set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG_INIT}" CACHE STRING "" FORCE)
   set(CMAKE_C_FLAGS_RELEASE_INIT "-O3 -Wall")
   set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE_INIT}" CACHE STRING "" FORCE)
   set(CMAKE_C_FLAGS_MINSIZEREL_INIT "-Os -Wall")
   set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL_INIT}" CACHE STRING "" FORCE)
   set(CMAKE_C_FLAGS_RELWITHDEBINFO_INIT  "-O2 -g -Wall")
   set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_ASM_FLAGS_RELWITHDEBINFO_INIT}" CACHE STRING "" FORCE)
   set(CMAKE_ASM_FLAGS_DEBUG_INIT "-g" CACHE INTERNAL "ASM compiler flags Debug")
else()
   message(WARNING "C / ASM compiler not found: ${CMAKE_C_COMPILER}")
endif()

set(CMAKE_CXX_COMPILER ${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_TRIPLET}-g++${TOOLCHAIN_EXT})
if (EXISTS ${CMAKE_CXX_COMPILER})
   set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g3 -Og -gdwarf -Wall -pedantic -DDEBUG")
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG_INIT}" CACHE STRING "" FORCE)
   set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3 -Wall")
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE_INIT}" CACHE STRING "" FORCE)
   set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT "-Os -Wall")
   set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL_INIT}" CACHE STRING "" FORCE)
   set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT  "-O2 -g -Wall")
   set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_ASM_FLAGS_RELWITHDEBINFO_INIT}" CACHE STRING "" FORCE)
else()
   message(WARNING "C++ compiler not found: ${CMAKE_C_COMPILER}")
endif()