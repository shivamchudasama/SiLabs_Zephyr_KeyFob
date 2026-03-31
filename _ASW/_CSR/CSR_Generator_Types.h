/**
 * @file          CSR_Generator_Types.h
 * @brief         Header file containing types used in CSR generator.
 * @date          05/09/2025
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _CSR_GENERATOR_TYPES_H
#define _CSR_GENERATOR_TYPES_H

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include <stdint.h>

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           CRYPTO_AUTH_256_LEN
 * @brief         Length of 256-bits authentication data (in bytes).
 */
#define CRYPTO_AUTH_256_LEN                  (32)

/**
 * @def           CSR_MAX_DER_LEN
 * @brief         Maximum length of generated CSR in DER format.
 */
#define CSR_MAX_DER_LEN                      (1024)

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
// /**
//  * @struct        DeviceProvisioningRCB_T
//  * @brief         Structure containing device provisioning record control block.
//  */
// typedef struct __attribute__((__packed__))
// {
//   uint32_t u32_bitmap;                       /**< Bitmap */
//   uint8_t u8ar_positionNVM3[NVM3_ID_CNT];    /**< NVM3 positions array */
//   uint16_t u16_maxLinkDataLen;               /**< Max link data length */
// } DeviceProvisioningRCB_T;
/**
 * @struct        SubjectNameField_T
 * @brief         Structure containing the subject name field.
 */
typedef struct
{
   size_t t_nameLen;                         /**< Length of the subject name */
   size_t t_valueLen;                        /**< Length of the subject value */
   const char *cpt_name;                     /**< Pointer to the subject name */
   char *cpt_value;                          /**< Pointer to the subject value */
} SubjectNameField_T;

/**
 * @struct        CSRConfig_T
 * @brief         Structure containing the CSR configuration.
 */
typedef struct
{
   bool b_isStaticAuth2Generated;            /**< If True, generate 256-bit
                                                   static authentication data */
   bool b_isStaticAuthOnDevice;              /**< If True, mark static authentication
                                                   data presence on device in control block */
   bool b_isKey2Generated;                   /**< If True, generate device EC key
                                                   and corresponding CSR */
   bool b_isKeyAvailable;                    /**< If True, mark device EC key
                                                   presence on device in control block */
   bool b_isCertAvailable;                   /**< If True, mark certificate presence
                                                   on device in control block */
   bool b_isCSRAvailable;                    /**< If true, mark CSR presence on
                                                   device in control block */
   uint8_t u8_certPositionOnITS;             /**< For recording certificate position
                                                   in ITS to control block */
   uint8_t u8_CSRPositionOnITS;              /**< For recording CSR position in
                                                   ITS to control block */
   size_t t_subjectNameFieldCnt;             /**< CSR subject name, excluding CN (see below) */
   const SubjectNameField_T *stpt_subjectNameField;
                                             /**< Pointer to the subject name fields */
} CSRConfig_T;

/**
 * @struct        CSRData_T
 * @brief         Structure containing the generated CSR.
 */
typedef struct __attribute__((__packed__))
{
   uint8_t u8_isCSRGenerated;                /**< Flag indicating if the CSR is
                                                   generated */
   uint8_t u8ar_staticAuthData[CRYPTO_AUTH_256_LEN];
                                             /**< Static authentication data */
   uint16_t u16_CSRLen;                      /**< Length of generated CSR data.
                                                   DER is binary format so length is
                                                   required */
   uint8_t u8ar_CSR[CSR_MAX_DER_LEN];        /**< Generated CSR */
} CSRData_T;

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

#endif //!_CSR_GENERATOR_TYPES_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
