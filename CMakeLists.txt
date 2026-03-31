# CMakeLists.txt — Application Build Configuration
#
# =============================================================================
# WHAT THIS FILE DOES
# =============================================================================
#
# This is your application's top-level CMake file. It tells Zephyr:
# 1. Where to find your custom board definition (BOARD_ROOT)
# 2. To load the Zephyr build system
# 3. What source files to compile
#
# The BOARD_ROOT line is crucial — it tells the build system to look for
# board definitions in THIS directory (in addition to Zephyr's built-in
# boards). Without it, 'west build -b my_bg24_keyless' will fail with
# "board not found."
#
# With BOARD_ROOT set here, you can build the application directly with:
#   west build -p always -b my_bg24_keyless .
# from this directory, without needing -DBOARD_ROOT on the command line.
#
# Sysbuild is different: it evaluates <app>/sysbuild/CMakeLists.txt first, so
# BOARD_ROOT must also be defined there for sysbuild builds to find this board.
# =============================================================================

cmake_minimum_required(VERSION 3.20.0)

# Tell Zephyr where to find our custom board definition.
# CMAKE_CURRENT_SOURCE_DIR points to the directory containing this file.
# Our board files are in ./boards/mycompany/my_bg24_keyless/
list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(BATL_VCU_KeyFob)

target_sources(app PRIVATE main.c)
