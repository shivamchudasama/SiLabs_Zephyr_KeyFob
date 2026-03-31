/*
 * main.c — Minimal test application for custom BG24 board
 *
 * This program does two things:
 * 1. Blinks the LED on PB00 to confirm GPIO and the board definition work
 * 2. Starts BLE advertising to confirm the radio stack works
 *
 * If the LED blinks: your Device Tree, clock config, and GPIO are correct.
 * If a BLE scanner (nRF Connect app) sees "BATL VCU KeyFob": your BLE
 * stack, RAIL blobs, and HFXO/DPLL configuration are correct.
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>

/* Get the LED node from the Device Tree.
 *
 * DT_ALIAS(led0) looks up the 'led0' alias we defined in the DTS file.
 * GPIO_DT_SPEC_GET() extracts the gpio controller, pin number, and flags
 * from the 'gpios' property of that node.
 *
 * This is how Device Tree connects to your C code — you never hardcode
 * port/pin numbers. If you move the LED to a different pin, you only
 * change the DTS file, not the C code.
 */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

/* BLE advertisement data */
static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
};

int main(void)
{
	int err;

	/* Configure the LED GPIO pin */
	if (!gpio_is_ready_dt(&led)) {
		return -ENODEV;
	}
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

	// /* Initialize Bluetooth */
	// err = bt_enable(NULL);
	// if (err) {
	// 	/* If BLE init fails, fast-blink the LED as error indicator */
	// 	while (1) {
	// 		gpio_pin_toggle_dt(&led);
	// 		k_msleep(100);
	// 	}
	// }

	// /* Start advertising — scannable from phone with nRF Connect / EFR Connect */
	// err = bt_le_adv_start(BT_LE_ADV_CONN_FAST_1, ad, ARRAY_SIZE(ad), NULL, 0);
	// if (err) {
	// 	/* Advertising failed — double-blink pattern */
	// 	while (1) {
	// 		gpio_pin_toggle_dt(&led);
	// 		k_msleep(200);
	// 		gpio_pin_toggle_dt(&led);
	// 		k_msleep(200);
	// 		k_msleep(600);
	// 	}
	// }

	/* Success — slow blink indicates everything is working */
	while (1) {
		gpio_pin_toggle_dt(&led);
		k_msleep(1000);
	}

	return 0;
}
