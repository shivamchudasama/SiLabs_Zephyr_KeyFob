# App_KeyFob — LED Blink Test

This application is a **minimal validation test** for the custom `batl_vcu_keyfob` board (EFR32BG24A010F1024IM48). It blinks the LED on **PB00** at a 1-second interval to confirm that GPIO, Device Tree, and clock configuration are correct.

> BLE advertising code is present in `main.c` but commented out. The current build only exercises GPIO.

---

## Project Structure

```
App_KeyFob/
├── boards/
│   └── batl_vcu_keyfob/        # Out-of-tree custom board definition
│       ├── board.yml
│       ├── board.cmake
│       ├── batl_vcu_keyfob.dts
│       ├── batl_vcu_keyfob_defconfig
│       ├── Kconfig.batl_vcu_keyfob
│       └── Kconfig.defconfig
├── build/                      # Generated build output (not committed)
├── main.c                      # Application source
├── prj.conf                    # Kconfig overrides (CONFIG_GPIO=y)
├── CMakeLists.txt              # Sets BOARD_ROOT and project name
└── README.md
```

---

## Build

Open a terminal with the Zephyr environment activated (i.e., `west` and `ZEPHYR_BASE` are set).

From the workspace root (`d:\SiLabsZephyrWorkspace`):

```bash
west build -p always -b batl_vcu_keyfob App_KeyFob
```

- `-p always` — pristine build (cleans before building); use `-p auto` to skip clean when nothing changed
- `-b batl_vcu_keyfob` — selects the custom board defined in `App_KeyFob/boards/`
- `App_KeyFob` — path to the application (contains `CMakeLists.txt`)

The `CMakeLists.txt` already sets `BOARD_ROOT` to the app directory, so no extra `-DBOARD_ROOT` flag is needed.

Build output is placed in `App_KeyFob/build/`.

---

## Flash

Connect the J-Link debugger, then from the workspace root:

```bash
west flash --runner jlink
```

After flashing, the LED on PB00 should blink at 1-second intervals. There is no UART console output — the LED is the only indicator.

**If the LED does not blink:**
1. Check that `west flash` reported success (no error in output).
2. Open `App_KeyFob/build/zephyr/zephyr.dts` and verify the LED node has `gpios = <&gpiob 0 ...>` and `status = "okay"`.
3. Confirm `CONFIG_GPIO=y` is in the final config: `cat App_KeyFob/build/zephyr/.config | grep GPIO`.

---

## Debug

Debugging uses the **Cortex-Debug** VS Code extension with a J-Link GDB server.

### Prerequisites

| Tool | Location |
|------|----------|
| VS Code extension | [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug) |
| SEGGER J-Link Software | `C:\Program Files\SEGGER\JLink\JLinkGDBServerCL.exe` |
| Zephyr SDK GDB | `C:\Users\<user>\zephyr-sdk-0.17.4\arm-zephyr-eabi\bin\arm-zephyr-eabi-gdb.exe` |

Build the application first — the debug configuration points to `App_KeyFob/build/zephyr/zephyr.elf`.

### Starting a Debug Session

1. Open the workspace root (`d:\SiLabsZephyrWorkspace`) in VS Code.
2. Ensure `.vscode/launch.json` and `.vscode/settings.json` exist (see below).
3. Go to **Run and Debug** (Ctrl+Shift+D).
4. Select **Debug Standalone App** or **Debug App** from the dropdown.
5. Press **F5**.

The debugger will halt at reset. Press **F5** again to run to your breakpoint or `main`.

---

## VS Code Configuration Files

These files live at the **workspace root** (`.vscode/`), not inside `App_KeyFob/`.

### `.vscode/settings.json`

Tells Cortex-Debug where to find the GDB binary:

```json
{
  "cortex-debug.gdbPath": "C:\\Users\\<user>\\zephyr-sdk-0.17.4\\arm-zephyr-eabi\\bin\\arm-zephyr-eabi-gdb.exe"
}
```

Replace `<user>` with your Windows username (e.g., `sdchudasama1`).

### `.vscode/launch.json`

One debug configuration is provided:

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug Standalone App",
      "type": "cortex-debug",
      "request": "launch",
      "servertype": "jlink",
      "serverpath": "C:\\Program Files\\SEGGER\\JLink\\JLinkGDBServerCL.exe",
      "showDevDebugOutput": "raw",
      "device": "EFR32BG24A010F1024IM48",
      "interface": "swd",
      "cwd": "${workspaceFolder}",
      "executable": "${workspaceFolder}/App_KeyFob/build/zephyr/zephyr.elf",
      "gdbPath": "C:\\Users\\sdchudasama1\\zephyr-sdk-0.17.4\\arm-zephyr-eabi\\bin\\arm-zephyr-eabi-gdb.exe",
      "svdFile": "",
      "breakAfterReset": true
    }
  ]
}
```

**Debug Standalone App** — launches the J-Link GDB server, flashes the ELF, and halts at reset. Press **F5** to continue to your breakpoint or through `main`.

- `showDevDebugOutput: "raw"` — prints raw GDB server output in the Debug Console, useful for diagnosing J-Link connection issues.
- `svdFile` — leave empty or point to an EFR32BG24 `.svd` file to enable peripheral register inspection in the Cortex-Debug panel.
- `breakAfterReset: true` — the debugger halts immediately after reset so you can set breakpoints before execution begins.
