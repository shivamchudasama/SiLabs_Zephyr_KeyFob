/**
 * @file          main.c
 * @brief         Source file containing the main function which performs all initialization
 *                activity.
 * @date          16/02/26
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include <zephyr/drivers/gpio.h>
// #include "CSR_Generator.h"
// #include "DeviceCert.h"
#include "ConnectionHandling.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                             PRIVATE VARIABLES                              */
/*                                                                            */
/******************************************************************************/
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
static const struct gpio_dt_spec sst_led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

/******************************************************************************/
/*                                                                            */
/*                       PRIVATE FUNCTION DEFINITIONS                          */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        PUBLIC FUNCTION DEFINITIONS                         */
/*                                                                            */
/******************************************************************************/
/**
 * @public        main
 * @brief         Initializes the BLE stack and starts advertising.
 * @return        0 upon successful execution.
 */
int main(void)
{
   // Check if the GPIO port is ready for the LED GPIO pin
	if (!gpio_is_ready_dt(&sst_led))
   {
		return -ENODEV;
	}
	gpio_pin_configure_dt(&sst_led, GPIO_OUTPUT_ACTIVE);

   // while (1)
   // {
	// 	gpio_pin_toggle_dt(&sst_led);
   //    LOG_INF("Custom board LED toggled!!");
	// 	k_msleep(1000);
	// }

   // Turn on LED to indicate device is powered on
   gpio_pin_set_dt(&sst_led, 1);
   LOG_INF("Custom board turned ON!!");

   // // Check if loading the device certificate from ITS completed successfully
   // if (PSA_SUCCESS == gt_LoadStoredDeviceCert())
   // {
   //    // As the device certificate is already stored, directly verify it against
   //    // the CA certificate.

   //    // Note: Verify the stored device certificate against the CA certificate
   // }
   // else
   // {
   //    LOG_INF("Generating or loading CSR as there is no valid device certificate available.");
   //    // Generate/ Load CSR
   //    gv_GenerateOrLoadCSR();
   // }

   // Init and start BLE advertising
   gv_BLEInitStartAdv();

   return 0;
}

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Yash Sunil Giramkar [YSG], Shivam Chudasama [SC]
 */
