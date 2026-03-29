# board.cmake — Flash and Debug Runner Configuration
#
# =============================================================================
# WHAT THIS FILE DOES
# =============================================================================
#
# This file tells Zephyr's build system HOW to flash and debug your board.
# When you run 'west flash' or 'west debug', the build system reads this
# file to know which tool (runner) to use.
#
# 'jlink' is the SEGGER J-Link runner. It uses the J-Link software to
# communicate with the chip's SWD debug port.
#
# 'BOARD_RUNNER_ARGS' passes extra arguments to the runner. Here we tell
# J-Link which specific device it's talking to, so it knows the correct
# flash algorithm and memory map.
#
# If you also want to support Simplicity Commander as an alternative runner,
# you can add:
#   include(${ZEPHYR_BASE}/boards/common/silabs_commander.board.cmake)
# =============================================================================

board_runner_args(jlink "--device=EFR32BG24A010F1024IM48")
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
