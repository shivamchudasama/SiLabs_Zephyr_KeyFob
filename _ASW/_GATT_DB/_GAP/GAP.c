/**
 * @file          GAP.c
 * @brief         Source file containing GATT database for GAP service
 * @date          12/02/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "GAP.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                       PRIVATE FUNCTION DECLARATIONS                        */
/*                                                                            */
/******************************************************************************/
static ssize_t st_DeviceNameRead(struct bt_conn *stpt_conn, const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len, uint16_t u16_offset);
static ssize_t st_AppearanceRead(struct bt_conn *stpt_conn, const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len, uint16_t u16_offset);

/******************************************************************************/
/*                                                                            */
/*                              PUBLIC VARIABLES                              */
/*                                                                            */
/******************************************************************************/
/**
 * @var           su8ar_deviceName
 * @brief         Name of the device.
 */
static const uint8_t su8ar_deviceName[] = "BATL KeyFob";

/**
 * @var           su16_appearance
 * @brief         Appearance of the device.
 */
static const uint16_t su16_appearance = BLE_APPEARANCE_MOTORIZED_VEHICLE_2_WHEELED_VEHICLE;

/**
 * @var           sstar_GAPSvc
 * @brief         GAP service instance. Creates a structure of bt_gatt_attr type.
 *                It statically define and register this GATT service.
 */
BT_GATT_SERVICE_DEFINE(sstar_GAPSvc,
	// Primary service declaration with GAP service UUID
	BT_GATT_PRIMARY_SERVICE(
		// UUID
		BT_UUID_DECLARE_16(BLE_SERVICE_GAP_UUID)
	),
	// Characteristic declaration for device name
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_DECLARE_16(BLE_CHAR_DEVICE_NAME_UUID),
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_DeviceNameRead
		st_DeviceNameRead,
		// Write callback - NULL
		NULL,
		// User data - su8ar_deviceName
		su8ar_deviceName
	),
	BT_GATT_CUD(
		"Device Name",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for appearance
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_DECLARE_16(BLE_CHAR_APPEARANCE_UUID),
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_AppearanceRead
		st_AppearanceRead,
		// Write callback - NULL
		NULL,
		// User data - su16_appearance
		&su16_appearance
	),
	BT_GATT_CUD(
		"Appearance",
		BT_GATT_PERM_READ
	),
);

/******************************************************************************/
/*                                                                            */
/*                                   UNIONS                                   */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                              EXTERN VARIABLES                              */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                              PUBLIC VARIABLES                              */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        PRIVATE FUNCTION DEFINITIONS                        */
/*                                                                            */
/******************************************************************************/
/**
 * @private       st_DeviceNameRead
 * @brief         Callback for reading device name.
 * @param[in]     stpt_conn Connection handler.
 * @param[in]     stpt_att Attribute handler.
 * @param[inout]  vpt_buff Buffer where the data is to be read.
 * @param[in]     u16_len Total bytes to read.
 * @param[in]     u16_offset Offset from where to read.
 * @return        After successful read, it should return number of bytes read.
 */
static ssize_t st_DeviceNameRead(struct bt_conn *stpt_conn, const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len, uint16_t u16_offset)
{
	const char *cpt_value = stpt_att->user_data;
	uint16_t u16_valueLen = sizeof(su8ar_deviceName);

	LOG_INF("Device Name read requested, UUID is: %x", (BT_UUID_16(stpt_att->uuid))->val);
	LOG_INF("Device Name read requested, Handle is: %u", bt_gatt_attr_get_handle(stpt_att));

	return bt_gatt_attr_read(stpt_conn, stpt_att, vpt_buff, u16_len, u16_offset, cpt_value, u16_valueLen);
}

/**
 * @private       st_AppearanceRead
 * @brief         Callback for reading appearance.
 * @param[in]     stpt_conn Connection handler.
 * @param[in]     stpt_att Attribute handler.
 * @param[inout]  vpt_buff Buffer where the data is to be read.
 * @param[in]     u16_len Total bytes to read.
 * @param[in]     u16_offset Offset from where to read.
 * @return        After successful read, it should return number of bytes read.
 */
static ssize_t st_AppearanceRead(struct bt_conn *stpt_conn, const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len, uint16_t u16_offset)
{
	const char *cpt_value = stpt_att->user_data;
	uint16_t u16_valueLen = sizeof(su16_appearance);

	LOG_INF("Appearance read requested, UUID is: %x", (BT_UUID_16(stpt_att->uuid))->val);
	LOG_INF("Appearance read requested, Handle is: %u", bt_gatt_attr_get_handle(stpt_att));

	return bt_gatt_attr_read(stpt_conn, stpt_att, vpt_buff, u16_len, u16_offset, cpt_value, u16_valueLen);
}

/******************************************************************************/
/*                                                                            */
/*                        PUBLIC FUNCTION DEFINITIONS                         */
/*                                                                            */
/******************************************************************************/

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
