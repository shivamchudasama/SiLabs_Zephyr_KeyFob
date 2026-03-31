/**
 * @file          DeviceInfo.c
 * @brief         Source file containing GATT database for Device Information service
 * @date          09/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "DeviceInfo.h"

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
static ssize_t st_ManufacturerNameRead(struct bt_conn *stpt_conn, const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len, uint16_t u16_offset);
static ssize_t st_HWRevisionRead(struct bt_conn *stpt_conn,	const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len, uint16_t u16_offset);
static ssize_t st_FWRevisionRead(struct bt_conn *stpt_conn,	const struct bt_gatt_attr *stpt_att,
   void *vpt_buff, uint16_t u16_len, uint16_t u16_offset);

/******************************************************************************/
/*                                                                            */
/*                             PRIVATE VARIABLES                              */
/*                                                                            */
/******************************************************************************/
/**
 * @var           scar_manufacturerName
 * @brief         Name of the manufacturer.
 */
static const char scar_manufacturerName[] = "Bajaj Auto Technology Limited";

/**
 * @var           scar_HWRevision
 * @brief         Revision of the hardware.
 */
static const char scar_HWRevision[] = "0.1.1";

/**
 * @var           scar_FWRevision
 * @brief         Revision of the firmware.
 */
static const char scar_FWRevision[] = "0.1.2";

/**
 * @var           sstar_deviceInfoSvc
 * @brief         GAP service instance. Creates a structure of bt_gatt_attr type.
 *                It statically define and register this GATT service.
 */
BT_GATT_SERVICE_DEFINE(sstar_deviceInfoSvc,
	// Primary service declaration with device information service UUID
	BT_GATT_PRIMARY_SERVICE(
		// UUID
		BT_UUID_DECLARE_16(BLE_SERVICE_DEVICE_INFORMATION_UUID)
	),
	// Characteristic declaration for manufacturer name
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_DECLARE_16(BLE_CHAR_MANUFACTURER_NAME_STRING_UUID),
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_ManufacturerNameRead
		st_ManufacturerNameRead,
		// Write callback - NULL
		NULL,
		// User data - scar_manufacturerName
		scar_manufacturerName
	),
	BT_GATT_CUD(
		"Manufacturer Name",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for HW revision
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_DECLARE_16(BLE_CHAR_HARDWARE_REVISION_STRING_UUID),
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_HWRevisionRead
		st_HWRevisionRead,
		// Write callback - NULL
		NULL,
		// User data - scar_HWRevision
		scar_HWRevision
	),
	BT_GATT_CUD(
		"Hardware Revision",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for FW revision
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_DECLARE_16(BLE_CHAR_FIRMWARE_REVISION_STRING_UUID),
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_FWRevisionRead
		st_FWRevisionRead,
		// Write callback - NULL
		NULL,
		// User data - scar_FWRevision
		scar_FWRevision
	),
	BT_GATT_CUD(
		"Firmware Revision",
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
 * @private       st_ManufacturerNameRead
 * @brief         Callback for reading manufacturer name.
 * @param[in]     stpt_conn Connection handler.
 * @param[in]     stpt_att Attribute handler.
 * @param[inout]  vpt_buff Buffer where the data is to be read.
 * @param[in]     u16_len Total bytes to read.
 * @param[in]     u16_offset Offset from where to read.
 * @return        After successful read, it should return number of bytes read.
 */
static ssize_t st_ManufacturerNameRead(struct bt_conn *stpt_conn, const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len, uint16_t u16_offset)
{
	const char *cpt_value = stpt_att->user_data;
	uint16_t u16_valueLen = (uint16_t)strlen(cpt_value);

	LOG_INF("Manufacturer Name read requested, UUID is: %x", (BT_UUID_16(stpt_att->uuid))->val);
	LOG_INF("Manufacturer Name read requested, Handle is: %u", bt_gatt_attr_get_handle(stpt_att));

	return bt_gatt_attr_read(stpt_conn, stpt_att, vpt_buff, u16_len, u16_offset,
      cpt_value, u16_valueLen);
}

/**
 * @private       st_HWRevisionRead
 * @brief         Callback for reading HW revision.
 * @param[in]     stpt_conn Connection handler.
 * @param[in]     stpt_att Attribute handler.
 * @param[inout]  vpt_buff Buffer where the data is to be read.
 * @param[in]     u16_len Total bytes to read.
 * @param[in]     u16_offset Offset from where to read.
 * @return        After successful read, it should return number of bytes read.
 */
static ssize_t st_HWRevisionRead(struct bt_conn *stpt_conn,
	const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len,
	uint16_t u16_offset)
{
	const char *cpt_value = stpt_att->user_data;
	uint16_t u16_valueLen = (uint16_t)strlen(cpt_value);

	LOG_INF("Hardware Revision read requested, UUID is: %x", (BT_UUID_16(stpt_att->uuid))->val);
	LOG_INF("Hardware Revision read requested, Handle is: %u", bt_gatt_attr_get_handle(stpt_att));

	return bt_gatt_attr_read(stpt_conn, stpt_att, vpt_buff, u16_len, u16_offset,
      cpt_value, u16_valueLen);
}

/**
 * @private       st_FWRevisionRead
 * @brief         Callback for reading SW revision.
 * @param[in]     stpt_conn Connection handler.
 * @param[in]     stpt_att Attribute handler.
 * @param[inout]  vpt_buff Buffer where the data is to be read.
 * @param[in]     u16_len Total bytes to read.
 * @param[in]     u16_offset Offset from where to read.
 * @return        After successful read, it should return number of bytes read.
 */
static ssize_t st_FWRevisionRead(struct bt_conn *stpt_conn,
	const struct bt_gatt_attr *stpt_att,
	void *vpt_buff, uint16_t u16_len,
	uint16_t u16_offset)
{
	const char *cpt_value = stpt_att->user_data;
	uint16_t u16_valueLen = (uint16_t)strlen(cpt_value);

	LOG_INF("Firmware Revision read requested, UUID is: %x", (BT_UUID_16(stpt_att->uuid))->val);
	LOG_INF("Firmware Revision read requested, Handle is: %u", bt_gatt_attr_get_handle(stpt_att));

	return bt_gatt_attr_read(stpt_conn, stpt_att, vpt_buff, u16_len, u16_offset,
      cpt_value, u16_valueLen);
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
