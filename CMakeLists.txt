cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME lkey)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)
add_subdirectory(tinyusb/src)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ./tinyusb/src
    # Add user defined library search paths
)

file(GLOB MBEDTRLS_LIBRARY_SRC ./Mbedtls/library/*.c)

set(TINYUSB_DIR ./tinyusb)

aux_source_directory(${TINYUSB_DIR}/src TINYUSB_SOURCES)
aux_source_directory(${TINYUSB_DIR}/src/class/hid TINYUSB_SOURCES)
aux_source_directory(${TINYUSB_DIR}/src/portable TINYUSB_SOURCES)
aux_source_directory(${TINYUSB_DIR}/src/portable/common TINYUSB_SOURCES)
aux_source_directory(${TINYUSB_DIR}/src/portable/synopsys/dwc2 TINYUSB_SOURCES)
aux_source_directory(${TINYUSB_DIR}/src/device TINYUSB_SOURCES)

tinyusb_target_add(${CMAKE_PROJECT_NAME})
# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
        ${MBEDTRLS_LIBRARY_SRC}
        ${TINYUSB_SOURCES}
        ./Core/Src/lkey/crypto/crypto.c
        ./Core/Src/lkey/lkey.c
        ./Core/Src/lkey/crypto/hash.c
        ./Core/Src/lkey/crypto/rsa.c
        ./Core/Src/lkey/crypto/ecc.c
        ./Core/Src/lkey/utils/utils.c
        ./Core/Src/usb_descriptors.c
        ./tinyusb/src/portable/st/stm32_fsdev/dcd_stm32_fsdev.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
        ./Mbedtls/include
        ./Mbedtls/include/psa
        ./Mbedtls/include/mbedtls
        ./Mbedtls/library/
        ./Core/Inc/lkey
        ${TINYUSB_DIR}/src
        ${TINYUSB_DIR}/src/class/hid
        ${TINYUSB_DIR}/src/portable
        ${TINYUSB_DIR}/src/portable/common
        ${TINYUSB_DIR}/src/portable/st/stm32_fsdev
        ${TINYUSB_DIR}/src/device
)
# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
