# Setting Up Zephyr for a Custom EFR32BG24 Board

## A Complete Guide for Your BLE Vehicle Keyless Access System

**Target SoC:** EFR32BG24A010F1024IM48  
**HFXO:** 40 MHz (Channel Sounding support)  
**LFXO:** None (will use LFRCO with precision mode)  
**Flash:** 1024 KB | **RAM:** 256 KB  
**Package:** QFN48  

---

## Part 1: Understanding Device Tree and Kconfig (Concepts)

Since you're new to Device Tree and Kconfig, let's build your mental model before touching any files. These two systems together replace what you'd traditionally do with `#define` macros, `init()` functions, and board support packages (BSPs) in bare-metal or RTOS projects.

### 1.1 What is Device Tree?

Think of the Device Tree as a **structured hardware description file** — a blueprint of your PCB, written in a human-readable format. Instead of scattering hardware information across C header files, init functions, and HAL calls, Zephyr puts it all in one place.

A Device Tree is literally a tree data structure. At the top is the "root node" (`/`), and every piece of hardware hangs off it as a "node." Each node has "properties" — key-value pairs that describe that hardware.

Here's the simplest possible example:

```dts
/dts-v1/;       /* Declares this as a Device Tree Source file */

/ {              /* Root node */
    model = "My Custom Board";

    leds {
        compatible = "gpio-leds";    /* Tells Zephyr which driver to use */
        led0: my_led {
            gpios = <&gpiob 0 GPIO_ACTIVE_HIGH>;  /* Port B, Pin 0, active high */
            label = "Status LED";
        };
    };
};
```

**Key concepts:**

- **`compatible`** — This is the most important property. It's a string that tells Zephyr: "Use THIS driver for THIS hardware." When Zephyr sees `compatible = "gpio-leds"`, it knows to use its built-in GPIO LED driver. Think of it as a matching key between hardware and software.

- **`status`** — Can be `"okay"` or `"disabled"`. Peripherals defined in the SoC-level file are usually disabled by default. Your board file's job is to enable the ones you actually use. If you don't set `status = "okay"`, the driver for that peripheral won't be instantiated.

- **Node labels** (like `led0:`) — These are shortcuts you can use elsewhere to reference a node. When you write `&gpiob`, you're referencing a node labeled `gpiob` that's defined in the SoC's Device Tree file.

- **`chosen`** — A special node where you tell Zephyr which specific hardware to use for system-level functions. For example, `zephyr,console = &usart0` says "use USART0 for printf output." Without this, Zephyr doesn't know where to send console output.

- **`aliases`** — Human-readable names that Zephyr samples reference. The Blinky sample looks for `led0`. If your board defines `aliases { led0 = &my_led; }`, then Blinky works on your board without modification.

### 1.2 How Device Tree Files Layer Together

Zephyr uses a layered approach with three types of files:

1. **`.dtsi` (DT Source Include)** — The SoC-level file. Defines everything inside the chip: CPU, flash, RAM, all peripherals (UART, SPI, GPIO ports, etc.). Silicon Labs provides this for BG24. You NEVER edit this file. Most peripherals are `status = "disabled"` here.

2. **`.dts` (DT Source)** — Your board-level file. It `#include`s the SoC `.dtsi` and then overrides properties: enabling peripherals, setting pin assignments, defining LEDs/buttons, configuring clocks. This is the file you write.

3. **`.overlay`** — Application-level overrides. If your app needs to tweak something beyond what the board file defines (e.g., change baud rate for a specific test), you put it in an overlay. You don't need this right now.

At build time, Zephyr's build system combines all three layers (SoC `.dtsi` → board `.dts` → app `.overlay`) into a single merged file called `zephyr.dts` in your build directory. This is incredibly useful for debugging — if something isn't working, open `build/zephyr/zephyr.dts` and check whether the final merged tree looks correct.

### 1.3 Pin Control (pinctrl) in Device Tree

On Silicon Labs Series 2 devices, pin routing is done through the **Digital Bus (DBUS)**. In Zephyr, all pin assignments are centralized in the `&pinctrl` node rather than being scattered across peripheral init code.

The Simplicity SDK for Zephyr provides a header file `<dt-bindings/pinctrl/silabs/xg24-pinctrl.h>` that defines macros for every valid pin-to-peripheral mapping. These macros have the form `<PERIPHERAL>_<SIGNAL>_<PIN>`.

For example, `USART0_TX_PA8` means "route USART0's TX signal to Port A, Pin 8."

You group pins that share the same electrical properties (like push-pull output) into "groups" within a pinctrl state:

```dts
&pinctrl {
    usart0_default: usart0_default {
        group0 {
            pins = <USART0_TX_PA8>;
            drive-push-pull;
            output-high;
        };
        group1 {
            pins = <USART0_RX_PA9>;
            input-enable;
        };
    };
};
```

Then you connect this pinctrl state to the peripheral:

```dts
&usart0 {
    pinctrl-0 = <&usart0_default>;
    pinctrl-names = "default";
    status = "okay";
};
```

The GPIO mode maps to pinctrl properties as follows:

| GPIO Mode         | Pinctrl Properties                       |
|-------------------|------------------------------------------|
| DISABLED          | `input-disable` (or no properties)       |
| INPUT             | `input-enable`                           |
| INPUT w/pull-up   | `input-enable` + `bias-pull-up`          |
| INPUT w/filter    | `input-enable` + `silabs,input-filter`   |
| PUSH-PULL         | `drive-push-pull`                        |
| PUSH-PULL + high  | `drive-push-pull` + `output-high`        |
| OPEN-DRAIN        | `drive-open-drain`                       |

### 1.4 What is Kconfig?

While Device Tree describes **hardware**, Kconfig describes **software configuration** — which drivers to compile, which subsystems to enable, stack sizes, feature flags, etc.

If you've used Linux, it's the same system (`menuconfig`). In Zephyr, Kconfig files come in several flavors:

- **`prj.conf`** — Your application's configuration. This is the most common file you'll edit. It's just `CONFIG_SOMETHING=y` lines.

- **`<board>_defconfig`** — Default configuration baked into your board definition. When someone builds for your board, these options are automatically applied. Think of it as "what should always be true for this board."

- **`Kconfig.<board>`** — Defines the board's identity in the Kconfig tree and selects the SoC.

- **`Kconfig.defconfig`** — Overrides default values of existing Kconfig symbols specifically for your board.

**How Kconfig and Device Tree interact:** They're complementary. Device Tree says "USART0 exists on these pins at this baud rate." Kconfig says "compile the UART driver" (`CONFIG_SERIAL=y`). You need BOTH — if you enable USART0 in Device Tree but don't have `CONFIG_SERIAL=y`, the driver won't be compiled and the peripheral won't work.

### 1.5 Clock Configuration for Your Board

This is critical for your 40 MHz HFXO setup. The Simplicity SDK for Zephyr documentation explains that the clock tree is configured through Device Tree.

By default, the SoC DTS configures the HFRCODPLL free-running at 19 MHz. Since your board has a 40 MHz HFXO, you need to:

1. Enable the HFXO and set its frequency to 40 MHz
2. Configure the DPLL to lock to the HFXO and produce a higher system clock
3. Since you have NO LFXO, enable LFRCO precision mode for BLE timing

The DPLL formula is: `fout = fref × (n + 1) / (m + 1)`

For a 40 MHz input and 80 MHz output:
- `fout = 40 × (n+1) / (m+1) = 80`
- `(n+1) / (m+1) = 2`
- Using high values for low jitter: `n = 3999`, `m = 1999`

Since you have no LFXO, you MUST enable LFRCO precision mode. The SDK documentation states that precision mode periodically synchronizes the LFRCO to the HFXO, improving timing accuracy. This is essential for BLE operation, which requires approximately 500 ppm precision on the low-frequency timer.

---

## Part 2: Your Board Definition Files

Your custom board definition needs these files. I've provided the complete content for each below based on your EFR32BG24A010F1024IM48 with a 40 MHz crystal, no LFXO, one LED on PB00, no buttons, and J-Link debugging.

### 2.1 Directory Structure

Place these files in your application repo (out-of-tree board, recommended):

```
my_keyless_app/
├── boards/
│   └── mycompany/
│       └── my_bg24_keyless/
│           ├── board.yml
│           ├── board.cmake
│           ├── my_bg24_keyless.dts
│           ├── my_bg24_keyless_defconfig
│           ├── Kconfig.my_bg24_keyless
│           └── Kconfig.defconfig
├── src/
│   └── main.c
├── prj.conf
└── CMakeLists.txt
```

### 2.2 File-by-File Explanation

Each file is provided separately below, with detailed commentary.

---

## Part 3: Building and Flashing

### 3.1 Verify Your SoC Exists in Zephyr

Before building, check that the EFR32BG24 SoC family is defined in your workspace. Navigate to:

```
<your_workspace>/zephyr/soc/silabs/
```

Look for a directory containing BG24 or xG24 SoC definitions. The BG24 and MG24 share the same silicon, so you may find it under a combined family name. If the exact part number `efr32bg24a010f1024im48` isn't listed, look for the closest match — the key differences between BG24 variants are flash/RAM size and package, not peripherals.

Run this from your workspace root to see all Silicon Labs boards currently defined:

```bash
west boards | grep -i silabs
```

And check for SoC definitions:

```bash
find zephyr/soc/silabs -name "*.yml" | head -20
```

### 3.2 Fetch BLE Binary Blobs

This step is mandatory for BLE. Silicon Labs' Bluetooth link layer runs as proprietary pre-compiled RAIL libraries:

```bash
west blobs fetch hal_silabs
```

Without this, you'll get linker errors about missing radio/BLE symbols.

### 3.3 Build

From your workspace root:

```bash
west build -p always \
    -b my_bg24_keyless \
    -DBOARD_ROOT=/path/to/my_keyless_app/boards \
    zephyr/samples/basic/blinky
```

Alternatively, if your CMakeLists.txt sets BOARD_ROOT (see the provided CMakeLists.txt below), you can simply:

```bash
west build -p always -b my_bg24_keyless /path/to/my_keyless_app
```

### 3.4 Debug the Device Tree

If the build succeeds, inspect the generated Device Tree to verify everything merged correctly:

```bash
cat build/zephyr/zephyr.dts | less
```

Look for your HFXO frequency, DPLL settings, LED definition, and that `bt_hci_silabs` is enabled. If something looks wrong here, fix it in your `.dts` file — the generated `zephyr.dts` is read-only and regenerated every build.

### 3.5 Flash via J-Link

```bash
west flash --runner jlink
```

Make sure your J-Link is connected and the J-Link software is installed. If `west flash` doesn't find the runner, you may need to install the J-Link Software Pack from SEGGER and ensure `JLinkExe` is in your PATH.

### 3.6 Verify

Since you're not configuring UART right now, you won't see console output. But with the Blinky sample, your LED on PB00 should be blinking. If it's not:

1. Check that J-Link successfully programmed the device (west flash output should show success)
2. Open `build/zephyr/zephyr.dts` and verify the LED node has `gpios = <&gpiob 0 ...>` and `status = "okay"`
3. Check that `CONFIG_GPIO=y` is in your build's `.config` file: `cat build/zephyr/.config | grep GPIO`

### 3.7 Next Step: BLE

Once Blinky works, try a BLE sample:

```bash
west build -p always \
    -b my_bg24_keyless \
    -DBOARD_ROOT=/path/to/my_keyless_app/boards \
    zephyr/samples/bluetooth/beacon
```

The beacon sample doesn't require UART console — it just starts advertising. You can verify it's working by scanning for BLE advertisements from your phone (using nRF Connect app or EFR Connect app).

If BLE doesn't work, the most likely causes are:
- Missing `west blobs fetch hal_silabs`
- Incorrect HFXO frequency or DPLL settings
- `bt_hci_silabs` not enabled in the DTS
- Missing `CONFIG_BT=y` and `CONFIG_BT_SILABS_HCI=y` in Kconfig

---

## Part 4: Important Notes for Your Project

### 4.1 LFRCO Precision Mode Is Essential

Since your board has no LFXO crystal, the LFRCO precision mode is critical. It periodically calibrates the internal RC oscillator against the HFXO, achieving the ~500 ppm accuracy that BLE requires for connection timing. Without it, BLE connections will be unreliable or fail entirely.

This is configured in the Device Tree with `precision-mode;` on the `&lfrco` node (included in the provided DTS file).

### 4.2 Channel Sounding and the 40 MHz Crystal

Your 40 MHz HFXO was chosen specifically for Channel Sounding support. Make sure your DPLL configuration produces a valid system clock frequency. The provided configuration targets 80 MHz (2× the HFXO), which is within the BG24's operating range.

### 4.3 Flash Partition Layout

Your BG24 has 1024 KB (1 MB) of flash. The provided DTS includes a partition layout suitable for MCUboot-based OTA updates:

| Partition          | Address      | Size         | Purpose                     |
|--------------------|--------------|--------------|------------------------------|
| `boot_partition`   | 0x00000000   | 48 KB        | MCUboot bootloader           |
| `slot0_partition`  | 0x0000C000   | 472 KB       | Primary application slot     |
| `slot1_partition`  | 0x00082000   | 472 KB       | Secondary slot (OTA updates) |
| `storage_partition`| 0x000F8000   | 32 KB        | NVS / settings storage       |

If you don't need OTA updates initially, you can simplify this, but having the layout defined from the start saves rework later — especially for a vehicle keyless access system where field updates are important.

### 4.4 Interrupt Priority Note

The Simplicity SDK HAL requires that the ARM Cortex-M33 base priority register (BASEPRI) is set to 3. This means interrupt priorities 0–2 are not blocked by Zephyr's `irq_lock()` or spinlocks. The BLE link layer runs as a meta-IRQ cooperative thread, using these high priorities. This is configured automatically by the SoC Kconfig defaults (`CONFIG_ZERO_LATENCY_IRQS` and `CONFIG_ZERO_LATENCY_LEVELS=2`), so you don't need to do anything — but it's good to understand this if you write ISR-heavy application code.
