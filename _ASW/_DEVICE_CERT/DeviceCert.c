/**
 * @file          DeviceCert.c
 * @brief         Source file containing device certificate
 * @date          05/09/2025
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "DeviceCert.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           DEVICE_CERT_STORAGE_UID_BASE
 * @brief         Base UID for device certificate storage. First 7 bytes are ASCII "DEVCERT",
 *                last 1 bytes are for specific entries.
 */
#define DEVICE_CERT_STORAGE_UID_BASE         ((psa_storage_uid_t)0x4445564345525400ULL)

/**
 * @def           DEVICE_CERT_PERSISTED_OUTPUT_BASE_LEN
 * @brief         Base length for persisted device certificate output.
 */
#define DEVICE_CERT_PERSISTED_OUTPUT_BASE_LEN \
                                             (offsetof(DeviceCertData_T, u8ar_DeviceCert))

/**
 * @def           DEVICE_CERT_PERSISTED_OUTPUT_LEN
 * @brief         Output length for persisted device certificate output.
 */
#define DEVICE_CERT_PERSISTED_OUTPUT_LEN(t_csrLen) \
                                             (DEVICE_CERT_PERSISTED_OUTPUT_BASE_LEN + (size_t)(t_csrLen))

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
/*                       PRIVATE FUNCTION DECLARATIONS                        */
/*                                                                            */
/******************************************************************************/
static psa_storage_uid_t st_GetDeviceCertStorageUID(void);
static void sv_ClearDeviceCertOutput(void);
static psa_status_t st_RemoveStoredDeviceCert(void);

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
 * @var           gst_deviceCertData
 * @brief         Instance of DeviceCertData_T structure. The generated or loaded (from secure valut)
 *                device certificate data.
 */
DeviceCertData_T gst_deviceCertData = { 0 };

/******************************************************************************/
/*                                                                            */
/*                             PRIVATE VARIABLES                              */
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
 * @private       st_GetDeviceCertStorageUID
 * @brief         Get the PSA storage UID used for the persisted device certificate blob.
 * @return        PSA storage UID for the device certificate object.
 */
static psa_storage_uid_t st_GetDeviceCertStorageUID(void)
{
   return (DEVICE_CERT_STORAGE_UID_BASE |
      (psa_storage_uid_t)gst_CSRConfig.u8_certPositionOnITS);
}

/**
 * @private       sv_ClearDeviceCertOutput
 * @brief         Reset the in-RAM device certificate output cache.
 * @return        None.
 */
static void sv_ClearDeviceCertOutput(void)
{
   memset(&gst_deviceCertData, 0, sizeof(gst_deviceCertData));
}

/**
 * @private       st_RemoveStoredDeviceCert
 * @brief         Delete the persisted device certificate object from trusted storage.
 * @return        PSA_SUCCESS if the object is removed or not present.
 */
static psa_status_t st_RemoveStoredDeviceCert(void)
{
   psa_status_t t_status;

   t_status = psa_its_remove(st_GetDeviceCertStorageUID());

   // Check if the stored device certificate object doesn't exist
   if (t_status == PSA_ERROR_DOES_NOT_EXIST)
   {
      t_status = PSA_SUCCESS;
   }
   // Check if the stored device certificate object isn't removed successfully
   else if (t_status != PSA_SUCCESS)
   {
      LOG_ERR("Failed to remove stored device certificate: %d", t_status);
   }

   return t_status;
}

/******************************************************************************/
/*                                                                            */
/*                        PUBLIC FUNCTION DEFINITIONS                         */
/*                                                                            */
/******************************************************************************/
/**
 * @public        gt_StoreDeviceCert
 * @brief         Persist the generated device certificate into trusted storage.
 * @return        PSA_SUCCESS if the device certificate is stored successfully.
 */
psa_status_t gt_StoreDeviceCert(void)
{
   psa_status_t t_status = PSA_ERROR_GENERIC_ERROR;
   size_t t_storageLen = 0;

   // Check if the in-RAM device certificate output is valid for storage
   if ((gst_deviceCertData.u8_isDeviceCertGenerated != 1u) ||
      (gst_deviceCertData.u16_deviceCertLen == 0u) ||
      (gst_deviceCertData.u16_deviceCertLen > DEVICE_CERT_MAX_DER_LEN))
   {
      t_status = PSA_ERROR_INVALID_ARGUMENT;
      LOG_ERR("Device certificate is not valid for persistent storage");
   }
   else
   {
      t_storageLen = DEVICE_CERT_PERSISTED_OUTPUT_LEN(gst_deviceCertData.u16_deviceCertLen);

      // Store the device certificate in trusted storage
      t_status = psa_its_set(st_GetDeviceCertStorageUID(), t_storageLen,
         &gst_deviceCertData, PSA_STORAGE_FLAG_NONE);

      // Check if the device certificate was stored successfully
      if (t_status == PSA_SUCCESS)
      {
         LOG_INF("Device certificate stored in trusted storage (%u bytes)",
            gst_deviceCertData.u16_deviceCertLen);
      }
      else
      {
         LOG_ERR("Failed to store device certificate in trusted storage: %d", t_status);
      }
   }

   return t_status;
}

/**
 * @public        gt_LoadStoredDeviceCert
 * @brief         Load a previously stored device certificate from trusted storage into RAM.
 * @return        PSA_SUCCESS if a valid device certificate is restored.
 */
psa_status_t gt_LoadStoredDeviceCert(void)
{
   psa_status_t t_status = PSA_ERROR_GENERIC_ERROR;
   struct psa_storage_info_t st_storageInfo = { 0 };
   size_t t_bytesRead = 0;
   size_t t_expectedLen = 0;

   // Clear the in-RAM device certificate output cache before loading
   sv_ClearDeviceCertOutput();

   // Get the information of the stored device certificate object
   t_status = psa_its_get_info(st_GetDeviceCertStorageUID(), &st_storageInfo);

   // Check if the stored device certificate object does not exist
   if (t_status != PSA_SUCCESS)
   {
      LOG_ERR("No stored device certificate available.");
      return t_status;
   }

   // Check if the stored device certificate size is valid
   if ((st_storageInfo.size <= DEVICE_CERT_PERSISTED_OUTPUT_BASE_LEN) ||
      (st_storageInfo.size > sizeof(gst_deviceCertData)))
   {
      LOG_ERR("Stored device certificate has invalid size: %u",
         (unsigned int)st_storageInfo.size);

      // Remove the stored device certificate object as the size is invalid
      (void)st_RemoveStoredDeviceCert();
      return PSA_ERROR_DATA_CORRUPT;
   }

   // Load the stored device certificate object into RAM
   t_status = psa_its_get(st_GetDeviceCertStorageUID(), 0u, st_storageInfo.size,
      &gst_deviceCertData, &t_bytesRead);

   // Check if the stored device certificate object isn't read successfully
   if (t_status != PSA_SUCCESS)
   {
      LOG_ERR("Failed to load stored device certificate: %d", t_status);

      // Clear the in-RAM device certificate output cache
      sv_ClearDeviceCertOutput();

      // Check if either the stored device certificate is corrupted or has an invalid signature
      if ((t_status == PSA_ERROR_DATA_CORRUPT) ||
         (t_status == PSA_ERROR_INVALID_SIGNATURE))
      {
         // Remove the stored device certificate object as it is corrupted or has an invalid signature
         (void)st_RemoveStoredDeviceCert();
      }

      return t_status;
   }

   // Check if the read length doesn't match the stored device certificate size
   if (t_bytesRead != st_storageInfo.size)
   {
      LOG_ERR("Stored device certificate read length mismatch: %u/%u",
         (unsigned int)t_bytesRead, (unsigned int)st_storageInfo.size);

      // Clear the in-RAM device certificate output cache
      sv_ClearDeviceCertOutput();

      // Remove the stored device certificate object as it is corrupted or has an invalid signature
      (void)st_RemoveStoredDeviceCert();
      return PSA_ERROR_DATA_CORRUPT;
   }

   // Update the in-RAM device certificate expected length
   t_expectedLen = DEVICE_CERT_PERSISTED_OUTPUT_LEN(gst_deviceCertData.u16_deviceCertLen);

   // Check if the loaded device certificate content isn't valid
   if ((gst_deviceCertData.u8_isDeviceCertGenerated != 1u) ||
      (gst_deviceCertData.u16_deviceCertLen == 0u) ||
      (gst_deviceCertData.u16_deviceCertLen > CSR_MAX_DER_LEN) ||
      (st_storageInfo.size != t_expectedLen))
   {
      LOG_ERR("Stored device certificate content is invalid. Removing persisted copy.");

      // Clear the in-RAM device certificate output cache
      sv_ClearDeviceCertOutput();

      // Remove the stored device certificate object as it is corrupted or has an invalid signature
      (void)st_RemoveStoredDeviceCert();
      return PSA_ERROR_DATA_CORRUPT;
   }

   LOG_INF("Device certificate restored from trusted storage (%u bytes).",
      gst_deviceCertData.u16_deviceCertLen);
   LOG_HEXDUMP_INF(gst_deviceCertData.u8ar_DeviceCert, gst_deviceCertData.u16_deviceCertLen, "Stored device certificate: ");

   return PSA_SUCCESS;
}

// /**
//  * @private       gt_LoadStoredDeviceCert
//  * @brief         Load a previously stored device certificate from trusted storage
//  *                into RAM.
//  * @return        PSA_SUCCESS if a valid device certificate is restored.
//  */
// psa_status_t gt_LoadStoredDeviceCert(void)
// {
//    psa_status_t t_status = PSA_ERROR_GENERIC_ERROR;
//    struct psa_storage_info_t st_storageInfo = { 0 };
//    size_t t_bytesRead = 0;
//    size_t t_expectedLen = 0;

//    // Clear the in-RAM CSR output cache before loading
//    sv_ClearCSROutput();

//    // Get the information of the stored CSR object
//    t_status = psa_its_get_info(st_GetCSRStorageUID(), &st_storageInfo);

//    // Check if the stored CSR object does not exist
//    if (t_status != PSA_SUCCESS)
//    {
//       // Remove the stored CSR object if it is corrupted or has an invalid signature
//       (void)st_RemoveStoredCSR();

//       return t_status;
//    }

//    // Check if the stored CSR size is valid
//    if ((st_storageInfo.size <= CSR_PERSISTED_OUTPUT_BASE_LEN) ||
//       (st_storageInfo.size > sizeof(gst_CSRData)))
//    {
//       LOG_ERR("Stored CSR has invalid size: %u",
//          (unsigned int)st_storageInfo.size);

//       // Remove the stored CSR object as the size is invalid
//       (void)st_RemoveStoredCSR();
//       return PSA_ERROR_DATA_CORRUPT;
//    }

//    // Load the stored CSR object into RAM
//    t_status = psa_its_get(st_GetCSRStorageUID(), 0u, st_storageInfo.size,
//       &gst_CSRData, &t_bytesRead);

//    // Check if the stored CSR object isn't read successfully
//    if (t_status != PSA_SUCCESS)
//    {
//       LOG_ERR("Failed to load stored CSR: %d", t_status);

//       // Clear the in-RAM CSR output cache
//       sv_ClearCSROutput();

//       // Check if either the stored CSR is corrupted or has an invalid signature
//       if ((t_status == PSA_ERROR_DATA_CORRUPT) ||
//          (t_status == PSA_ERROR_INVALID_SIGNATURE))
//       {
//          // Remove the stored CSR object as it is corrupted or has an invalid signature
//          (void)st_RemoveStoredCSR();
//       }

//       return t_status;
//    }

//    // Check if the read length doesn't match the stored CSR size
//    if (t_bytesRead != st_storageInfo.size)
//    {
//       LOG_ERR("Stored CSR read length mismatch: %u/%u",
//          (unsigned int)t_bytesRead, (unsigned int)st_storageInfo.size);

//       // Clear the in-RAM CSR output cache
//       sv_ClearCSROutput();

//       // Remove the stored CSR object as it is corrupted or has an invalid signature
//       (void)st_RemoveStoredCSR();
//       return PSA_ERROR_DATA_CORRUPT;
//    }

//    // Update the in-RAM CSR expected length
//    t_expectedLen = CSR_PERSISTED_OUTPUT_LEN(gst_CSRData.u16_CSRLen);

//    // Check if the loaded CSR content isn't valid
//    if ((gst_CSRData.u8_isCSRGenerated != 1u) ||
//       (gst_CSRData.u16_CSRLen == 0u) ||
//       (gst_CSRData.u16_CSRLen > CSR_MAX_DER_LEN) ||
//       (st_storageInfo.size != t_expectedLen))
//    {
//       LOG_ERR("Stored CSR content is invalid. Removing persisted copy");

//       // Clear the in-RAM CSR output cache
//       sv_ClearCSROutput();

//       // Remove the stored CSR object as it is corrupted or has an invalid signature
//       (void)st_RemoveStoredCSR();
//       return PSA_ERROR_DATA_CORRUPT;
//    }

//    LOG_INF("CSR restored from trusted storage (%u bytes)",
//       gst_CSRData.u16_CSRLen);
//    LOG_HEXDUMP_INF(gst_CSRData.u8ar_CSR, gst_CSRData.u16_CSRLen, "Stored CSR: ");

//    return PSA_SUCCESS;
// }

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
