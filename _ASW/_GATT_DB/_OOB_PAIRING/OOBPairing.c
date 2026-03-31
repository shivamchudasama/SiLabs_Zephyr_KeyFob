/**
 * @file          OOBPairing.c
 * @brief         Source file containing GATT database for OOB Pairing service.
 * @date          18/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "OOBPairing.h"

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
static ssize_t st_IsReady2PairRead(struct bt_conn *stpt_connHandle,
	const struct bt_gatt_attr *stpt_attr, void *vpt_buf, uint16_t u16_length,
	uint16_t u16_offset);
static ssize_t st_IsPairingTriggeredWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags);
static ssize_t st_TargetDevice2PairWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags);
static ssize_t st_PairingStatusRead(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset);
static ssize_t st_ECURoleWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags);
static ssize_t st_OOBDataRead(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset);

/******************************************************************************/
/*                                                                            */
/*                             PRIVATE VARIABLES                              */
/*                                                                            */
/******************************************************************************/
/**
 * @var           sstar_OOBPairingSvc
 * @brief         OOB pairing service instance. Creates a structure of bt_gatt_attr type.
 *                It statically define and register this GATT service.
 */
BT_GATT_SERVICE_DEFINE(sstar_OOBPairingSvc,
	// Primary service declaration with OOB pairing service UUID
	BT_GATT_PRIMARY_SERVICE(
		// UUID
		BT_UUID_OOB_PAIRING_SERVICE
	),
	// Characteristic declaration for 'is ready to pair'
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_IS_READY_TO_PAIR_CHAR,
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_IsReady2PairRead
		st_IsReady2PairRead,
		// Write callback - NULL
		NULL,
		// User data - gst_deviceCertData
		&gst_deviceCertData
	),
	BT_GATT_CUD(
		"Is Ready To Pair",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for 'is pairing triggered'
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_IS_PAIRING_TRIGGERED_CHAR,
		// Properties - Write
		BT_GATT_CHRC_WRITE,
		// Permissions - Write
		BT_GATT_PERM_WRITE,
		// Read callback - NULL
		NULL,
		// Write callback - st_IsPairingTriggeredWrite
		st_IsPairingTriggeredWrite,
		// User data - gu8_isPairingTriggered
		&gu8_isPairingTriggered
	),
	BT_GATT_CUD(
		"Is Pairing Triggered",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for 'target device to pair'
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_TARGET_DEVICE_TO_PAIR_CHAR,
		// Properties - Write
		BT_GATT_CHRC_WRITE,
		// Permissions - Write
		BT_GATT_PERM_WRITE,
		// Read callback - NULL
		NULL,
		// Write callback - st_TargetDevice2PairWrite
		st_TargetDevice2PairWrite,
		// User data - gu8ar_targetDevice2Pair
		gu8ar_targetDevice2Pair
	),
	BT_GATT_CUD(
		"Target Device To Pair",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for 'pairing status'
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_PAIRING_STATUS_CHAR,
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_PairingStatusRead
		st_PairingStatusRead,
		// Write callback - NULL
		NULL,
		// User data - gu8_pairingStatus
		&gu8_pairingStatus
	),
	BT_GATT_CUD(
		"Pairing Status",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for 'ECU role'
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_ECU_ROLE_CHAR,
		// Properties - Write
		BT_GATT_CHRC_WRITE,
		// Permissions - Write
		BT_GATT_PERM_WRITE,
		// Read callback - NULL
		NULL,
		// Write callback - st_ECURoleWrite
		st_ECURoleWrite,
		// User data - gu8_ECURole
		&gu8_ECURole
	),
	BT_GATT_CUD(
		"ECU Role",
		BT_GATT_PERM_READ
	),
	// Characteristic declaration for 'OOB data'
	BT_GATT_CHARACTERISTIC(
		// UUID
		BT_UUID_OOB_DATA_CHAR,
		// Properties - Read
		BT_GATT_CHRC_READ,
		// Permissions - Read
		BT_GATT_PERM_READ,
		// Read callback - st_OOBDataRead
		st_OOBDataRead,
		// Write callback - NULL
		NULL,
		// User data - gu8ar_OOBData
		gu8ar_OOBData
	),
	BT_GATT_CUD(
		"OOB Data",
		BT_GATT_PERM_READ
	),
);

/******************************************************************************/
/*                                                                            */
/*                                 STRUCTURES                                 */
/*                                                                            */
/******************************************************************************/

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
/**
 * @var           gu8_isPairingTriggered
 * @brief         Flag to indicate pairing triggered.
 */
uint8_t gu8_isPairingTriggered = 0;

/**
 * @var           gu8ar_targetDevice2Pair
 * @brief         Target device's BLE MAC address.
 */
uint8_t gu8ar_targetDevice2Pair[6] = { 0 };

/**
 * @var           gu8_pairingStatus
 * @brief         Flag to indicate pairing status.
 */
uint8_t gu8_pairingStatus = 0;

/**
 * @var           gu8_ECURole
 * @brief         Flag to indicate current device's ECU role.
 */
uint8_t gu8_ECURole = 0;

/**
 * @var           gu8ar_OOBData
 * @brief         OOB pairing related data received from other BLE.
 */
uint8_t gu8ar_OOBData[96] = { 0 };

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
 * @private       st_IsReady2PairRead
 * @brief         Callback function for read operation on 'is ready to pair' characteristic.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]    	stpt_attr The attribute being written to.
 * @param[in]    	vpt_buf The buffer containing the data being written.
 * @param[in]    	u16_length The length of the data being written.
 * @param[in]    	u16_offset The offset at which the data is being written.
 * @return        Either BT_GATT_ERR() or the number of bytes written.
 */
static ssize_t st_IsReady2PairRead(struct bt_conn *stpt_connHandle,
	const struct bt_gatt_attr *stpt_attr, void *vpt_buf, uint16_t u16_length,
	uint16_t u16_offset)
{
	ssize_t t_retVal = 0;

	// Take a pointer to the user data of this attribute and consider it as a byte array,
	//	as we are expecting byte array input for this characteristic.
	DeviceCertData_T *stpt_deviceCertData = stpt_attr->user_data;

	// Perform all the basic checks for the incoming read request parameters before processing the data.
	// Check if the connection handle, attribute pointer, input buffer pointer or
	// characteristic data pointer is not NULL.
	if (!stpt_connHandle || !stpt_attr || !vpt_buf || !stpt_deviceCertData)
	{
		t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		LOG_INF("Invalid parameters in Is Ready To Pair characteristic read."
			"Connection Handle: %p, Attribute: %p, Buffer: %p", stpt_connHandle, stpt_attr, vpt_buf);
	}
   // Check if the offset is non-zero
   else if (u16_offset != 0)
   {
      t_retVal = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
      LOG_INF("Non-zero offset for Is Ready To Pair characteristic read."
			"Received offset: %u", u16_offset);
   }
   else
	{
		// Read the local attribute value from the local database.
		t_retVal = bt_gatt_attr_read(stpt_connHandle, stpt_attr, vpt_buf, u16_length,
			u16_offset, &stpt_deviceCertData->u8_isDeviceCertGenerated, 1);
	}

	return t_retVal;
}

/**
 * @private       st_IsPairingTriggeredWrite
 * @brief         Callback function for write operation on 'is pairing triggered'
 *                characteristic.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]    	stpt_attr The attribute being written to.
 * @param[in]    	vpt_buf The buffer containing the data being written.
 * @param[in]    	u16_length The length of the data being written.
 * @param[in]    	u16_offset The offset at which the data is being written.
 * @param[in]    	u8_flags Write flags, see @ref bt_gatt_attr_write_flag.
 * @return        Either BT_GATT_ERR() or the number of bytes written.
 */
static ssize_t st_IsPairingTriggeredWrite(struct bt_conn *stpt_connHandle,
	const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
	uint16_t u16_offset, uint8_t u8_flags)
{
   ssize_t t_retVal = 0;

   // Perform all the basic checks for the incoming write request parameters before processing the data.
	// Check if the connection handle, attribute pointer, input buffer pointer or
	// characteristic data pointer is NULL.
	if (!stpt_connHandle || !stpt_attr || !vpt_buf)
	{
		t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		LOG_INF("Invalid parameters in Is Pairing Triggered characteristic write."
			"Connection Handle: %p, Attribute: %p, Buffer: %p", stpt_connHandle, stpt_attr, vpt_buf);
	}
   // Check if the offset is non-zero
   else if (u16_offset != 0)
   {
      t_retVal = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
      LOG_INF("Non-zero offset for Is Pairing Triggered characteristic read."
			"Received offset: %u", u16_offset);
   }
   else
   {
      *(uint8_t *)(stpt_attr->user_data) = *(uint8_t *)vpt_buf;
      t_retVal = u16_length;
   }

   return t_retVal;
}

/**
 * @private       st_TargetDevice2PairWrite
 * @brief         Callback function for write operation on 'target device to pair' characteristic.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]    	stpt_attr The attribute being written to.
 * @param[in]    	vpt_buf The buffer containing the data being written.
 * @param[in]    	u16_length The length of the data being written.
 * @param[in]    	u16_offset The offset at which the data is being written.
 * @param[in]    	u8_flags Write flags, see @ref bt_gatt_attr_write_flag.
 * @return        Either BT_GATT_ERR() or the number of bytes written.
 */
static ssize_t st_TargetDevice2PairWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags)
{
	// ssize_t t_retVal = 0;

	// // Take a pointer to the user data of this attribute and consider it as a byte array,
	// //	as we are expecting byte array input for this characteristic.
	// CSRData_T *stpt_CSRData = stpt_attr->user_data;

	// // Perform all the basic checks for the incoming read request parameters before processing the data.
	// // Check if the connection handle, attribute pointer, input buffer pointer or
	// // characteristic context pointer is not NULL.
	// if (!stpt_connHandle || !stpt_attr || !vpt_buf || !stpt_CSRData)
	// {
	// 	t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
	// 	LOG_INF("Invalid parameters in CSR generation status characteristic read. "
	// 		"Connection Handle: %p, Attribute: %p, Buffer: %p", stpt_connHandle, stpt_attr, vpt_buf);
	// }
   // // Check if the offset is non-zero
   // else if (u16_offset != 0)
   // {
   //    t_retVal = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
   //    LOG_INF("Offset read not supported for CSR generation status characteristic read. "
	// 		"Received offset: %u", u16_offset);
   // }
   // else
	// {
	// 	// Read the local attribute value from the local database.
	// 	t_retVal = bt_gatt_attr_read(stpt_connHandle, stpt_attr, vpt_buf, u16_length,
	// 		u16_offset, &(stpt_CSRData->u8_isCSRGenerated), sizeof(stpt_CSRData->u8_isCSRGenerated));
	// }

	// return t_retVal;
}

/**
 * @private       st_PairingStatusRead
 * @brief         Callback function for read operation on 'pairing status' characteristic.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]    	stpt_attr The attribute being written to.
 * @param[in]    	vpt_buf The buffer containing the data being written.
 * @param[in]    	u16_length The length of the data being written.
 * @param[in]    	u16_offset The offset at which the data is being written.
 * @return        Either BT_GATT_ERR() or the number of bytes written.
 */
static ssize_t st_PairingStatusRead(struct bt_conn *stpt_connHandle,
	const struct bt_gatt_attr *stpt_attr, void *vpt_buf, uint16_t u16_length,
	uint16_t u16_offset)
{
   // ssize_t t_retVal = 0;

   // // Take a pointer to the user data of this attribute and consider it as a byte array,
	// //	as we are expecting byte array input for this characteristic.
   // DeviceCertData_T *stpt_deviceCertData = stpt_attr->user_data;

   // // Perform all the basic checks for the incoming write request parameters before processing the data.
	// // Check if the connection handle, attribute pointer, input buffer pointer or
	// // characteristic data pointer is NULL.
	// if (!stpt_connHandle || !stpt_attr || !vpt_buf || !stpt_deviceCertData)
	// {
	// 	t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
	// 	LOG_INF("Invalid parameters in device certificate data characteristic write. "
	// 		"Connection Handle: %p, Attribute: %p, Buffer: %p", stpt_connHandle, stpt_attr, vpt_buf);
	// }
   // // Check if the offset is non-zero
   // else if (u16_offset != 0)
   // {
   //    t_retVal = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
   //    LOG_INF("Invalid offset for device certificate data characteristic read. "
	// 		"Received offset: %u", u16_offset);
   // }
   // else
   // {
   //    // Update the device certificate generation status and length
   //    stpt_deviceCertData->u8_isDeviceCertGenerated = *(uint8_t *)vpt_buf;
   //    stpt_deviceCertData->u16_deviceCertLen = su16_receivedDeviceCertLength;

   //    // Note: Verify the received certificate against the CA certificate. Only after
   //    // verification, store it to ITS.

   //    // Store the received device certificate
   //    gt_StoreDeviceCert();
   //    t_retVal = u16_length;
   // }

   // return t_retVal;
}

/**
 * @private       st_ECURoleWrite
 * @brief         Callback function for write operation on 'ECU role' characteristic.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]    	stpt_attr The attribute being written to.
 * @param[in]    	vpt_buf The buffer containing the data being written.
 * @param[in]    	u16_length The length of the data being written.
 * @param[in]    	u16_offset The offset at which the data is being written.
 * @param[in]    	u8_flags Write flags, see @ref bt_gatt_attr_write_flag.
 * @return        Either BT_GATT_ERR() or the number of bytes written.
 */
static ssize_t st_ECURoleWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags)
{
   // ssize_t t_retVal = 0;

   // // Take a pointer to the user data of this attribute and consider it as a byte array,
	// //	as we are expecting byte array input for this characteristic.
   // DeviceCertData_T *stpt_deviceCertData = stpt_attr->user_data;

   // // Perform all the basic checks for the incoming write request parameters before processing the data.
	// // Check if the connection handle, attribute pointer, input buffer pointer or
	// // characteristic data pointer is NULL.
	// if (!stpt_connHandle || !stpt_attr || !vpt_buf || !stpt_deviceCertData)
	// {
	// 	t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
	// 	LOG_INF("Invalid parameters in device certificate data characteristic write. "
	// 		"Connection Handle: %p, Attribute: %p, Buffer: %p", stpt_connHandle, stpt_attr, vpt_buf);
	// }
   // // Check if the offset is non-zero
   // else if (u16_offset != 0)
   // {
   //    t_retVal = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
   //    LOG_INF("Invalid offset for device certificate data characteristic read. "
	// 		"Received offset: %u", u16_offset);
   // }
   // else
   // {
   //    // Update the device certificate generation status and length
   //    stpt_deviceCertData->u8_isDeviceCertGenerated = *(uint8_t *)vpt_buf;
   //    stpt_deviceCertData->u16_deviceCertLen = su16_receivedDeviceCertLength;

   //    // Note: Verify the received certificate against the CA certificate. Only after
   //    // verification, store it to ITS.

   //    // Store the received device certificate
   //    gt_StoreDeviceCert();
   //    t_retVal = u16_length;
   // }

   // return t_retVal;
}

/**
 * @private       st_OOBDataRead
 * @brief         Callback function for read operation on 'OOB data' characteristic.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]    	stpt_attr The attribute being written to.
 * @param[in]    	vpt_buf The buffer containing the data being written.
 * @param[in]    	u16_length The length of the data being written.
 * @param[in]    	u16_offset The offset at which the data is being written.
 * @return        Either BT_GATT_ERR() or the number of bytes written.
 */
static ssize_t st_OOBDataRead(struct bt_conn *stpt_connHandle,
	const struct bt_gatt_attr *stpt_attr, void *vpt_buf, uint16_t u16_length,
	uint16_t u16_offset)
{
   // ssize_t t_retVal = 0;

   // // Take a pointer to the user data of this attribute and consider it as a byte array,
	// //	as we are expecting byte array input for this characteristic.
   // DeviceCertData_T *stpt_deviceCertData = stpt_attr->user_data;

   // // Perform all the basic checks for the incoming write request parameters before processing the data.
	// // Check if the connection handle, attribute pointer, input buffer pointer or
	// // characteristic data pointer is NULL.
	// if (!stpt_connHandle || !stpt_attr || !vpt_buf || !stpt_deviceCertData)
	// {
	// 	t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
	// 	LOG_INF("Invalid parameters in device certificate data characteristic write. "
	// 		"Connection Handle: %p, Attribute: %p, Buffer: %p", stpt_connHandle, stpt_attr, vpt_buf);
	// }
   // // Check if the offset is non-zero
   // else if (u16_offset != 0)
   // {
   //    t_retVal = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
   //    LOG_INF("Invalid offset for device certificate data characteristic read. "
	// 		"Received offset: %u", u16_offset);
   // }
   // else
   // {
   //    // Update the device certificate generation status and length
   //    stpt_deviceCertData->u8_isDeviceCertGenerated = *(uint8_t *)vpt_buf;
   //    stpt_deviceCertData->u16_deviceCertLen = su16_receivedDeviceCertLength;

   //    // Note: Verify the received certificate against the CA certificate. Only after
   //    // verification, store it to ITS.

   //    // Store the received device certificate
   //    gt_StoreDeviceCert();
   //    t_retVal = u16_length;
   // }

   // return t_retVal;
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
