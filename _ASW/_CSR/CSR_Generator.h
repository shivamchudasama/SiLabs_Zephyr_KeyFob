/**
 * @file          CSR_Generator.h
 * @brief         Header file containing CSR generator functionality.
 * @date          27/08/2025
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _CSR_GENERATOR_H
#define _CSR_GENERATOR_H

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include <psa/crypto.h>
#include <zephyr/drivers/hwinfo.h>
#include <psa/internal_trusted_storage.h>

#if defined(CONFIG_TRUSTED_STORAGE_BACKEND_AEAD_KEY_DERIVE_FROM_HUK)
#include <hw_unique_key.h>
#endif // CONFIG_TRUSTED_STORAGE_BACKEND_AEAD_KEY_DERIVE_FROM_HUK

#if defined(CONFIG_TRUSTED_STORAGE_STORAGE_BACKEND_SETTINGS)
#include <zephyr/settings/settings.h>
#endif // CONFIG_TRUSTED_STORAGE_STORAGE_BACKEND_SETTINGS

#include "CSR_Generator_Config.h"
#include "CSR_Generator_Types.h"
#include "AppLog.h"
#include "DER.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           CRYPTO_SHA_1_LEN
 * @brief         Length of SHA-1.
 */
#define CRYPTO_SHA_1_LEN                     (20)

/**
 * @def           UUID_LEN
 * @brief         Length of UUID.
 */
#define UUID_LEN                             (16)

/**
 * @def           UUID_STRING_LEN
 * @brief         Length of UUID string representation without terminator.
 */
#define UUID_STRING_LEN                      ((UUID_LEN * 2) + 4)

/**
 * @def           CRYPTO_EC_PUBLIC_KEY_LEN
 * @brief         Length of 256-bits EC public key (in bytes).
 */
#define CRYPTO_EC_PUBLIC_KEY_LEN             (64)

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/
/**
 * @enum          <Enum name>
 * @brief         <Enum details>.
 */

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
/**
 * @union         <Union name>
 * @brief         <Union details>.
 */

/******************************************************************************/
/*                                                                            */
/*                              EXTERN VARIABLES                              */
/*                                                                            */
/******************************************************************************/
extern CSRConfig_T gst_CSRConfig;
extern CSRData_T gst_CSRData;

/******************************************************************************/
/*                                                                            */
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/
extern psa_status_t gt_CalculateSHA1(const uint8_t *u8pt_data, size_t t_len,
   uint8_t *u8pt_hash);
extern void gv_GenerateOrLoadCSR(void);

#endif //!_CSR_GENERATOR_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
