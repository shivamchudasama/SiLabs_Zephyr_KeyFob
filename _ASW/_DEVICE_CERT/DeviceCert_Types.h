/**
 * @file          DeviceCert_Types.h
 * @brief         Header file containing device certificate types.
 * @date          05/09/2025
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _DEVICE_CERT_TYPES_H
#define _DEVICE_CERT_TYPES_H

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include <stdint.h>
#include <stddef.h>

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           DEVICE_CERT_MAX_DER_LEN
 * @brief         Maximum length of generated device certificate in DER format.
 */
#define DEVICE_CERT_MAX_DER_LEN              (1024)

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
/**
 * @struct        DeviceCertData_T
 * @brief         Structure containing the device certificate.
 */
typedef struct __attribute__((__packed__))
{
   uint8_t u8_isDeviceCertGenerated;         /**< Flag indicating if the device
                                                   certificate is generated */
   uint16_t u16_deviceCertLen;               /**< Length of generated device certificate.
                                                   DER is binary format so length is
                                                   required */
   uint8_t u8ar_DeviceCert[DEVICE_CERT_MAX_DER_LEN];
                                             /**< Device certificate max length */
} DeviceCertData_T;

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

/******************************************************************************/
/*                                                                            */
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/

#endif //!_DEVICE_CERT_TYPES_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
