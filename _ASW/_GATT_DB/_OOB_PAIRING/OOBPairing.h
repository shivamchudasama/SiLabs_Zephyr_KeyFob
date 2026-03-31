/**
 * @file          OOBPairing.h
 * @brief         Header file containing GATT database for OOB Pairing service.
 * @date          18/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _OOB_PAIRING_H
#define _OOB_PAIRING_H

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/gatt.h>
#include <string.h>
#include "BaseUUIDs.h"
#include "ConnectionHandling.h"
#include "GATT_DB_Types.h"
// #include "CSR_Generator.h"
#include "DeviceCert.h"
#include "AppLog.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
// Service UUID
/**
 * @def           PART_UUID_SERVICE_OOB_PAIRING
 * @brief         OOB pairing service.
 */
#define PART_UUID_SERVICE_OOB_PAIRING        (0x02)

/**
 * @def           OOB_PAIRING_SERVICE_UUID_FIRST_PART_32BIT
 * @brief         First part of OOB pairing service UUID (32-bits).
 */
#define OOB_PAIRING_SERVICE_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_OOB_PAIRING, \
                                                0x0000))

/**
 * @def           BT_UUID_OOB_PAIRING_SERVICE_VAL
 * @brief         128-bit value encoding for OOB pairing characteristic UUID.
 */
#define BT_UUID_OOB_PAIRING_SERVICE_VAL      BT_UUID_128_ENCODE( \
                                                OOB_PAIRING_SERVICE_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_OOB_PAIRING_SERVICE
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 * 					OOB pairing characteristic.
 */
#define BT_UUID_OOB_PAIRING_SERVICE          BT_UUID_DECLARE_128(BT_UUID_OOB_PAIRING_SERVICE_VAL)

// Characteristic UUID
/**
 * @def           PART_UUID_CHAR_IS_READY_TO_PAIR
 * @brief         UUID 'is ready to pair' characteristic.
 */
#define PART_UUID_CHAR_IS_READY_TO_PAIR      (0x0001)

/**
 * @def           IS_READY_TO_PAIR_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'is ready to pair' characteristic UUID (32-bits).
 */
#define IS_READY_TO_PAIR_CHAR_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_OOB_PAIRING, \
                                                PART_UUID_CHAR_IS_READY_TO_PAIR))

/**
 * @def           BT_UUID_IS_READY_TO_PAIR_CHAR_VAL
 * @brief         128-bit value encoding for 'is ready to pair' characteristic UUID.
 */
#define BT_UUID_IS_READY_TO_PAIR_CHAR_VAL    BT_UUID_128_ENCODE( \
                                                IS_READY_TO_PAIR_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_IS_READY_TO_PAIR_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 * 					'is ready to pair' characteristic.
 */
#define BT_UUID_IS_READY_TO_PAIR_CHAR        BT_UUID_DECLARE_128(BT_UUID_IS_READY_TO_PAIR_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_IS_PAIRING_TRIGGERED
 * @brief         UUID 'is pairing triggered' characteristic.
 */
#define PART_UUID_CHAR_IS_PAIRING_TRIGGERED  (0x0002)

/**
 * @def           IS_PAIRING_TRIGGERED_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'is pairing triggered' characteristic UUID (32-bits).
 */
#define IS_PAIRING_TRIGGERED_CHAR_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_OOB_PAIRING, \
                                                PART_UUID_CHAR_IS_PAIRING_TRIGGERED))

/**
 * @def           BT_UUID_IS_PAIRING_TRIGGERED_CHAR_VAL
 * @brief         128-bit value encoding for 'is pairing triggered' characteristic UUID.
 */
#define BT_UUID_IS_PAIRING_TRIGGERED_CHAR_VAL \
                                             BT_UUID_128_ENCODE( \
                                                IS_PAIRING_TRIGGERED_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_IS_PAIRING_TRIGGERED_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 * 					'is pairing triggered' characteristic.
 */
#define BT_UUID_IS_PAIRING_TRIGGERED_CHAR    BT_UUID_DECLARE_128(BT_UUID_IS_PAIRING_TRIGGERED_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_TARGET_DEVICE_TO_PAIR
 * @brief         UUID 'target device to pair' characteristic.
 */
#define PART_UUID_CHAR_TARGET_DEVICE_TO_PAIR (0x0003)

/**
 * @def           TARGET_DEVICE_TO_PAIR_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'target device to pair' characteristic UUID (32-bits).
 */
#define TARGET_DEVICE_TO_PAIR_CHAR_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_OOB_PAIRING, \
                                                PART_UUID_CHAR_TARGET_DEVICE_TO_PAIR))

/**
 * @def           BT_UUID_TARGET_DEVICE_TO_PAIR_CHAR_VAL
 * @brief         128-bit value encoding for 'target device to pair' characteristic UUID.
 */
#define BT_UUID_TARGET_DEVICE_TO_PAIR_CHAR_VAL \
                                             BT_UUID_128_ENCODE( \
                                                TARGET_DEVICE_TO_PAIR_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_TARGET_DEVICE_TO_PAIR_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 * 					'target device to pair' characteristic.
 */
#define BT_UUID_TARGET_DEVICE_TO_PAIR_CHAR    BT_UUID_DECLARE_128(BT_UUID_TARGET_DEVICE_TO_PAIR_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_PAIRING_STATUS
 * @brief         UUID 'pairing status' characteristic.
 */
#define PART_UUID_CHAR_PAIRING_STATUS        (0x0004)

/**
 * @def           PAIRING_STATUS_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'pairing status' characteristic UUID (32-bits).
 */
#define PAIRING_STATUS_CHAR_UUID_FIRST_PART_32BIT \
                                             (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_OOB_PAIRING, \
                                                PART_UUID_CHAR_PAIRING_STATUS))

/**
 * @def           BT_UUID_PAIRING_STATUS_CHAR_VAL
 * @brief         128-bit value encoding for 'pairing status' characteristic UUID.
 */
#define BT_UUID_PAIRING_STATUS_CHAR_VAL      BT_UUID_128_ENCODE( \
                                                PAIRING_STATUS_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_PAIRING_STATUS_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 * 					'pairing status' characteristic.
 */
#define BT_UUID_PAIRING_STATUS_CHAR          BT_UUID_DECLARE_128(BT_UUID_PAIRING_STATUS_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_ECU_ROLE
 * @brief         UUID 'ECU role' characteristic.
 */
#define PART_UUID_CHAR_ECU_ROLE              (0x0005)

/**
 * @def           ECU_ROLE_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'ECU role' characteristic UUID (32-bits).
 */
#define ECU_ROLE_CHAR_UUID_FIRST_PART_32BIT  (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_OOB_PAIRING, \
                                                PART_UUID_CHAR_ECU_ROLE))

/**
 * @def           BT_UUID_ECU_ROLE_CHAR_VAL
 * @brief         128-bit value encoding for 'ECU role' characteristic UUID.
 */
#define BT_UUID_ECU_ROLE_CHAR_VAL            BT_UUID_128_ENCODE( \
                                                ECU_ROLE_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_ECU_ROLE_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 * 					'ECU role' characteristic.
 */
#define BT_UUID_ECU_ROLE_CHAR                BT_UUID_DECLARE_128(BT_UUID_ECU_ROLE_CHAR_VAL)

/**
 * @def           PART_UUID_CHAR_OOB_DATA
 * @brief         UUID 'OOB data' characteristic.
 */
#define PART_UUID_CHAR_OOB_DATA              (0x0006)

/**
 * @def           OOB_DATA_CHAR_UUID_FIRST_PART_32BIT
 * @brief         First part of 'OOB data' characteristic UUID (32-bits).
 */
#define OOB_DATA_CHAR_UUID_FIRST_PART_32BIT  (UUID_FIRST_PART_32BIT( \
                                                PART_UUID_DOMAIN_PAIRING, \
                                                PART_UUID_SERVICE_OOB_PAIRING, \
                                                PART_UUID_CHAR_OOB_DATA))

/**
 * @def           BT_UUID_OOB_DATA_CHAR_VAL
 * @brief         128-bit value encoding for 'OOB data' characteristic UUID.
 */
#define BT_UUID_OOB_DATA_CHAR_VAL            BT_UUID_128_ENCODE( \
                                                OOB_DATA_CHAR_UUID_FIRST_PART_32BIT, \
                                                BASE_UUID_SECOND_PART_16BIT, \
                                                BASE_UUID_THIRD_PART_16BIT, \
                                                BASE_UUID_FOURTH_PART_16BIT, \
                                                BASE_UUID_FIFTH_PART_48BIT)

/**
 * @def           BT_UUID_OOB_DATA_CHAR
 * @brief         Creating UUID structure pointer (const struct bt_uuid *) for
 * 					'OOB data' characteristic.
 */
#define BT_UUID_OOB_DATA_CHAR                BT_UUID_DECLARE_128(BT_UUID_OOB_DATA_CHAR_VAL)

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
extern uint8_t gu8_isPairingTriggered;
extern uint8_t gu8ar_targetDevice2Pair[6];
extern uint8_t gu8_pairingStatus;
extern uint8_t gu8_ECURole;
extern uint8_t gu8ar_OOBData[96];

/******************************************************************************/
/*                                                                            */
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/

#endif //!_OOB_PAIRING_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
