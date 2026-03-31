/**
 * @file          DeviceProvisioning.h
 * @brief         Header file containing GATT database for Device Provisioning service.
 * @date          09/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _DEVICE_PROVISIONING_H
#define _DEVICE_PROVISIONING_H

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/gatt.h>
#include <string.h>
#include <zephyr/sys/__assert.h>
#include "BaseUUIDs.h"
#include "ConnectionHandling.h"
#include "GATT_GenericCallbacks.h"
#include "GattFlow.h"
#include "CSR_Generator.h"
#include "DeviceCert.h"
#include "AppLog.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
// Service UUID
/**
 * @def           PART_UUID_SERVICE_DEVICE_PROVISIONING
 * @brief         Device Provisioning service.
 */
#define PART_UUID_SERVICE_DEVICE_PROVISIONING \
                                             (0x01)

/**
 * @def           DEVICE_PROVISIONING_SERVICE_UUID_FIRST_PART_32BIT
 * @brief         First part of Device Provisioning service UUID (32-bits).
 */
#define DEVICE_PROVISIONING_SERVICE_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_DEVICE_PROVISIONING, \
                                                0x0000))

/**
 * @def           BT_UUID_DEVICE_PROVISIONING_SERVICE_VAL
 * @brief         128-bit value encoding for Device Provisioning characteristic UUID.
 */
#define BT_UUID_DEVICE_PROVISIONING_SERVICE_VAL \
                                             BT_UUID_128_ENCODE( \
                                                DEVICE_PROVISIONING_SERVICE_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_DEVICE_PROVISIONING_SERVICE
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 *                Device Provisioning characteristic.
 */
#define BT_UUID_DEVICE_PROVISIONING_SERVICE  BT_UUID_DECLARE_128(BT_UUID_DEVICE_PROVISIONING_SERVICE_VAL)

// Characteristic UUID
/**
 * @def           PART_UUID_CHAR_CSR_DATA
 * @brief         UUID 'CSR Data' characteristic.
 */
#define PART_UUID_CHAR_CSR_DATA              (0x0001)

/**
 * @def           CSR_DATA_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'CSR Data' characteristic UUID (32-bits).
 */
#define CSR_DATA_CHAR_UUID_FIRST_PART_32BIT  (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_DEVICE_PROVISIONING, \
                                                PART_UUID_CHAR_CSR_DATA))

/**
 * @def           BT_UUID_CSR_DATA_CHAR_VAL
 * @brief         128-bit value encoding for 'CSR Data' characteristic UUID.
 */
#define BT_UUID_CSR_DATA_CHAR_VAL            BT_UUID_128_ENCODE( \
                                                CSR_DATA_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_CSR_DATA_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 *                'CSR Data' characteristic.
 */
#define BT_UUID_CSR_DATA_CHAR                BT_UUID_DECLARE_128(BT_UUID_CSR_DATA_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_DEVICE_CERT_DATA
 * @brief         UUID 'Device Cert Data' characteristic.
 */
#define PART_UUID_CHAR_DEVICE_CERT_DATA      (0x0002)

/**
 * @def           DEVICE_CERT_DATA_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'Device Cert Data' characteristic UUID (32-bits).
 */
#define DEVICE_CERT_DATA_CHAR_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_DEVICE_PROVISIONING, \
                                                PART_UUID_CHAR_DEVICE_CERT_DATA))

/**
 * @def           BT_UUID_DEVICE_CERT_DATA_CHAR_VAL
 * @brief         128-bit value encoding for 'Device Cert Data' characteristic UUID.
 */
#define BT_UUID_DEVICE_CERT_DATA_CHAR_VAL    BT_UUID_128_ENCODE( \
                                                DEVICE_CERT_DATA_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_DEVICE_CERT_DATA_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 *                'Device Cert Data' characteristic.
 */
#define BT_UUID_DEVICE_CERT_DATA_CHAR        BT_UUID_DECLARE_128(BT_UUID_DEVICE_CERT_DATA_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_CSR_GENERATION_STATUS
 * @brief         UUID 'CSR Generation Status' characteristic.
 */
#define PART_UUID_CHAR_CSR_GENERATION_STATUS (0x0003)

/**
 * @def           CSR_GENERATION_STATUS_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'CSR Generation Status' characteristic UUID (32-bits).
 */
#define CSR_GENERATION_STATUS_CHAR_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_DEVICE_PROVISIONING, \
                                                PART_UUID_CHAR_CSR_GENERATION_STATUS))

/**
 * @def           BT_UUID_CSR_GENERATION_STATUS_CHAR_VAL
 * @brief         128-bit value encoding for 'CSR Generation Status' characteristic UUID.
 */
#define BT_UUID_CSR_GENERATION_STATUS_CHAR_VAL \
                                             BT_UUID_128_ENCODE( \
                                                CSR_GENERATION_STATUS_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_CSR_GENERATION_STATUS_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 *                'CSR Generation Status' characteristic.
 */
#define BT_UUID_CSR_GENERATION_STATUS_CHAR   BT_UUID_DECLARE_128(BT_UUID_CSR_GENERATION_STATUS_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_DEVICE_CERT_RECEIVED_STATUS
 * @brief         UUID 'Device Cert Received Status' characteristic.
 */
#define PART_UUID_CHAR_DEVICE_CERT_RECEIVED_STATUS \
                                             (0x0004)

/**
 * @def           DEVICE_CERT_RECEIVED_STATUS_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'Device Cert Received Status' characteristic UUID (32-bits).
 */
#define DEVICE_CERT_RECEIVED_STATUS_CHAR_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_DEVICE_PROVISIONING, \
                                                PART_UUID_CHAR_DEVICE_CERT_RECEIVED_STATUS))

/**
 * @def           BT_UUID_DEVICE_CERT_RECEIVED_STATUS_CHAR_VAL
 * @brief         128-bit value encoding for 'Device Cert Received Status' characteristic UUID.
 */
#define BT_UUID_DEVICE_CERT_RECEIVED_STATUS_CHAR_VAL \
                                             BT_UUID_128_ENCODE( \
                                                DEVICE_CERT_RECEIVED_STATUS_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_DEVICE_CERT_RECEIVED_STATUS_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 *                'Device Cert Received Status' characteristic.
 */
#define BT_UUID_DEVICE_CERT_RECEIVED_STATUS_CHAR \
                                             BT_UUID_DECLARE_128(BT_UUID_DEVICE_CERT_RECEIVED_STATUS_CHAR_VAL)

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/

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
extern GATTCharDescriptor_T gst_CSRDataDesc;
extern GATTCharDescriptor_T gst_deviceCertDataDesc;
extern GATTCharDescriptor_T gst_CSRGenerationStatusDesc;
extern GATTCharDescriptor_T gst_deviceCertReceivedStatusDesc;

/******************************************************************************/
/*                                                                            */
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/

#endif //!_DEVICE_PROVISIONING_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF Bajaj Auto Technology Limited (BATL).
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * Bajaj Auto Technology Limited (BATL) IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
