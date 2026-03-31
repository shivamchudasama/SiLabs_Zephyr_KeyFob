/**
 * @file          DeviceProvisioning.c
 * @brief         Source file containing GATT database for Device Provisioning service.
 * @date          09/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "DeviceProvisioning.h"

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
/**
 * @enum          DeviceProvisioningStep_E
 * @brief         Ordered steps for the device provisioning protocol.
 */
typedef enum
{
   eDPS_WAIT_CSR_GENERATION_STATUS_READ = 0, /**< CSR generation status must be read first */
   eDPS_WAIT_CSR_DATA_READ,                  /**< CSR data read may start */
   eDPS_CSR_DATA_READ_IN_PROGRESS,           /**< CSR data is being read in-order */
   eDPS_WAIT_DEVICE_CERT_DATA_WRITE,         /**< Device certificate write may start */
   eDPS_DEVICE_CERT_DATA_WRITE_IN_PROGRESS,  /**< Device certificate is being written in-order */
   eDPS_COMPLETE,                            /**< Provisioning flow completed for this connection */
} DeviceProvisioningStep_E;

/**
 * @enum          DeviceProvisioningChar_E
 * @brief         Internal identifiers for device provisioning characteristics.
 */
typedef enum
{
   eDPC_CSR_DATA = 0,                        /**< CSR data characteristic */
   eDPC_DEVICE_CERT_DATA,                    /**< Device certificate data characteristic */
   eDPC_CSR_GENERATION_STATUS,               /**< CSR generation status characteristic */
   eDPC_DEVICE_CERT_RECEIVED_STATUS,         /**< Device certificate received status characteristic */
} DeviceProvisioningChar_E;

/******************************************************************************/
/*                                                                            */
/*                                 STRUCTURES                                 */
/*                                                                            */
/******************************************************************************/
/**
 * @struct        DeviceProvisioningFlowCtx_T
 * @brief         Runtime context owned by the device provisioning flow.
 */
typedef struct
{
   uint16_t u16_nextCSRReadOffset;           /**< Next CSR offset expected from client */
   uint16_t u16_nextDeviceCertWriteOffset;   /**< Next certificate write offset expected from client */
   uint16_t u16_receivedDeviceCertLength;    /**< Total certificate bytes received so far */
} DeviceProvisioningFlowCtx_T;

/******************************************************************************/
/*                                                                            */
/*                       PRIVATE FUNCTION DECLARATIONS                        */
/*                                                                            */
/******************************************************************************/
static void sv_DeviceProvisioningFlowEnsureInitialized(void);
static void sv_DeviceProvisioningConnected(struct bt_conn *stpt_connHandle, uint8_t u8_err);
static void sv_DeviceProvisioningDisconnected(struct bt_conn *stpt_connHandle, uint8_t u8_reason);
static const char *scpt_GetProvisioningStepName(uint8_t u8_step);
static ssize_t st_DeviceCertDataWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags);
static ssize_t st_DeviceCertReceivedStatusWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags);

/******************************************************************************/
/*                                                                            */
/*                             PRIVATE VARIABLES                              */
/*                                                                            */
/******************************************************************************/
/**
 * @var           su8ar_csrData
 * @brief         Local GATT database buffer for 'CSR Data' characteristic.
 *                Application pushes generated CSR data into this buffer via
 *                gt_GATT_LocalWrite(&gst_CSRDataDesc, ...).
 */
static uint8_t su8ar_csrData[CSR_MAX_DER_LEN] = { 0 };

/**
 * @var           su8ar_deviceCertData
 * @brief         Local GATT database buffer for 'Device Cert Data' characteristic.
 *                Remote client writes certificate chunks into this buffer.
 *                Application retrieves data via
 *                gt_GATT_LocalRead(&gst_deviceCertDataDesc, ...).
 */
static uint8_t su8ar_deviceCertData[DEVICE_CERT_MAX_DER_LEN] = { 0 };

/**
 * @var           su8_csrGenerationStatus
 * @brief         Local GATT database buffer for 'CSR Generation Status' characteristic.
 *                Application pushes the CSR generation flag via
 *                gt_GATT_LocalWrite(&gst_CSRGenerationStatusDesc, ...).
 */
static uint8_t su8_csrGenerationStatus = 0;

/**
 * @var           su8_deviceCertReceivedStatus
 * @brief         Local GATT database buffer for 'Device Cert Received Status' characteristic.
 *                Remote client writes the status byte into this buffer.
 */
static uint8_t su8_deviceCertReceivedStatus = 0;

/**
 * @var           sst_deviceProvisioningFlowCtx
 * @brief         Runtime context for device provisioning flow.
 */
static DeviceProvisioningFlowCtx_T sst_deviceProvisioningFlowCtx;

/**
 * @var           sstar_deviceProvisioningFlowRules
 * @brief         Table defining allowed step transitions for device provisioning
 *                characteristics.
 */
static const GattFlowRule_T sstar_deviceProvisioningFlowRules[] = {
   [eDPC_CSR_DATA] = {
      .u8_charId = eDPC_CSR_DATA,
      .e_op = eGFO_READ,
      .u32_allowedStepsMask = (GATT_FLOW_STEP_MASK(eDPS_WAIT_CSR_DATA_READ) |
         GATT_FLOW_STEP_MASK(eDPS_CSR_DATA_READ_IN_PROGRESS)),
      .u8_nextStep = GATT_FLOW_INVALID_STEP,
      .cpt_transitionReason = NULL,
   },
   [eDPC_DEVICE_CERT_DATA] = {
      .u8_charId = eDPC_DEVICE_CERT_DATA,
      .e_op = eGFO_WRITE,
      .u32_allowedStepsMask = (GATT_FLOW_STEP_MASK(eDPS_WAIT_DEVICE_CERT_DATA_WRITE) |
         GATT_FLOW_STEP_MASK(eDPS_DEVICE_CERT_DATA_WRITE_IN_PROGRESS)),
      .u8_nextStep = eDPS_DEVICE_CERT_DATA_WRITE_IN_PROGRESS,
      .cpt_transitionReason = "Device certificate data write started",
   },
   [eDPC_CSR_GENERATION_STATUS] = {
      .u8_charId = eDPC_CSR_GENERATION_STATUS,
      .e_op = eGFO_READ,
      .u32_allowedStepsMask = GATT_FLOW_STEP_MASK(eDPS_WAIT_CSR_GENERATION_STATUS_READ),
      .u8_nextStep = GATT_FLOW_INVALID_STEP,
      .cpt_transitionReason = "CSR generation status read",
   },
   [eDPC_DEVICE_CERT_RECEIVED_STATUS] = {
      .u8_charId = eDPC_DEVICE_CERT_RECEIVED_STATUS,
      .e_op = eGFO_WRITE,
      .u32_allowedStepsMask = GATT_FLOW_STEP_MASK(eDPS_DEVICE_CERT_DATA_WRITE_IN_PROGRESS),
      .u8_nextStep = eDPS_COMPLETE,
      .cpt_transitionReason = "Device certificate received status written",
   },
};

/**
 * @var           sst_deviceProvisioningFlowConfig
 * @brief         Static configuration for reusable device provisioning flow.
 */
static const GattFlowConfig_T sst_deviceProvisioningFlowConfig = {
   .cpt_name = "Device Provisioning",
   .u8_initialStep = eDPS_WAIT_CSR_GENERATION_STATUS_READ,
   .vpt_context = &sst_deviceProvisioningFlowCtx,
   .t_contextLen = sizeof(sst_deviceProvisioningFlowCtx),
   .stpt_rules = sstar_deviceProvisioningFlowRules,
   .t_ruleCnt = ARRAY_SIZE(sstar_deviceProvisioningFlowRules),
   .fpt_stepNameHook = scpt_GetProvisioningStepName,
   .fpt_contextResetHook = NULL,
};

/**
 * @var           sst_deviceProvisioningFlow
 * @brief         Runtime flow instance for device provisioning.
 */
static GattFlowInstance_T sst_deviceProvisioningFlow;

/**
 * @var           sst_deviceProvisioningConnCallbacks
 * @brief         Connection callbacks used to manage device provisioning flow state.
 */
BT_CONN_CB_DEFINE(sst_deviceProvisioningConnCallbacks) = {
   .connected = sv_DeviceProvisioningConnected,
   .disconnected = sv_DeviceProvisioningDisconnected,
};

/**
 * @var           sstar_deviceProvisioningSvc
 * @brief         Device provisioning service instance. Creates a structure of bt_gatt_attr type.
 *                It statically define and register this GATT service.
 */
BT_GATT_SERVICE_DEFINE(sstar_deviceProvisioningSvc,
   // Primary service declaration with Device Provisioning service UUID
   BT_GATT_PRIMARY_SERVICE(
      // UUID
      BT_UUID_DEVICE_PROVISIONING_SERVICE
   ),
   // Characteristic declaration for 'CSR Data'
   BT_GATT_CHARACTERISTIC(
      // UUID
      BT_UUID_CSR_DATA_CHAR,
      // Properties - Read
      BT_GATT_CHRC_READ,
      // Permissions - Read
      BT_GATT_PERM_READ,
      // Read callback - gt_GATT_GenericRead
      gt_GATT_GenericRead,
      // Write callback - NULL
      NULL,
      // User data - gst_CSRDataDesc
      &gst_CSRDataDesc
   ),
   BT_GATT_CUD(
      "CSR Data",
      BT_GATT_PERM_READ
   ),
   // Characteristic declaration for 'Device Cert Data'
   BT_GATT_CHARACTERISTIC(
      // UUID
      BT_UUID_DEVICE_CERT_DATA_CHAR,
      // Properties - Write
      BT_GATT_CHRC_WRITE,
      // Permissions - Write
      BT_GATT_PERM_WRITE,
      // Read callback - NULL
      NULL,
      // Write callback - gt_GATT_GenericWrite
      gt_GATT_GenericWrite,
      // User data - gst_deviceCertDataDesc
      &gst_deviceCertDataDesc
   ),
   BT_GATT_CUD(
      "Device Cert Data",
      BT_GATT_PERM_READ
   ),
   // Characteristic declaration for 'CSR Generation Status'
   BT_GATT_CHARACTERISTIC(
      // UUID
      BT_UUID_CSR_GENERATION_STATUS_CHAR,
      // Properties - Read
      BT_GATT_CHRC_READ,
      // Permissions - Read
      BT_GATT_PERM_READ,
      // Read callback - gt_GATT_GenericRead
      gt_GATT_GenericRead,
      // Write callback - NULL
      NULL,
      // User data - gst_CSRGenerationStatusDesc
      &gst_CSRGenerationStatusDesc
   ),
   BT_GATT_CUD(
      "CSR Generation Status",
      BT_GATT_PERM_READ
   ),
   // Characteristic declaration for 'Device Cert Received Status'
   BT_GATT_CHARACTERISTIC(
      // UUID
      BT_UUID_DEVICE_CERT_RECEIVED_STATUS_CHAR,
      // Properties - Write
      BT_GATT_CHRC_WRITE,
      // Permissions - Write
      BT_GATT_PERM_WRITE,
      // Read callback - NULL
      NULL,
      // Write callback - gt_GATT_GenericWrite
      gt_GATT_GenericWrite,
      // User data - gst_deviceCertReceivedStatusDesc
      &gst_deviceCertReceivedStatusDesc
   ),
   BT_GATT_CUD(
      "Device Cert Received Status",
      BT_GATT_PERM_READ
   ),
);

/**
 * @var           su16_receivedDeviceCertLength
 * @brief         Total device certificate length received till now.
 */
static uint16_t su16_receivedDeviceCertLength = 0;

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
 * @var           gst_CSRDataDesc
 * @brief         Descriptor for 'CSR Data' characteristic.
 *                Points to the local GATT database buffer su8ar_csrData.
 *                Variable-length, up to CSR_MAX_DER_LEN bytes.
 */
GATTCharDescriptor_T gst_CSRDataDesc = {
   .vpt_data = su8ar_csrData,
   .u16_dataLen = sizeof(su8ar_csrData),
   .u16_actualLen = 0,
   .b_variableLength = true,
   .stpt_mutex = NULL,
   .fpt_customReadCb = NULL,
   .fpt_customWriteCb = NULL,
};

/**
 * @var           gst_deviceCertDataDesc
 * @brief         Descriptor for 'Device Cert Data' characteristic.
 *                Points to the local GATT database buffer su8ar_deviceCertData.
 *                Variable-length, up to DEVICE_CERT_MAX_DER_LEN bytes.
 */
GATTCharDescriptor_T gst_deviceCertDataDesc = {
   .vpt_data = su8ar_deviceCertData,
   .u16_dataLen = sizeof(su8ar_deviceCertData),
   .u16_actualLen = 0,
   .b_variableLength = true,
   .stpt_mutex = NULL,
   .fpt_customReadCb = NULL,
   .fpt_customWriteCb = st_DeviceCertDataWrite,
};

/**
 * @var           gst_CSRGenerationStatusDesc
 * @brief         Descriptor for 'CSR Generation Status' characteristic.
 *                Points to the local GATT database buffer su8_csrGenerationStatus.
 *                Fixed-length, 1 byte.
 */
GATTCharDescriptor_T gst_CSRGenerationStatusDesc = {
   .vpt_data = &su8_csrGenerationStatus,
   .u16_dataLen = sizeof(su8_csrGenerationStatus),
   .u16_actualLen = sizeof(su8_csrGenerationStatus),
   .b_variableLength = false,
   .stpt_mutex = NULL,
   .fpt_customReadCb = NULL,
   .fpt_customWriteCb = NULL,
};

/**
 * @var           gst_deviceCertReceivedStatusDesc
 * @brief         Descriptor for 'Device Cert Received Status' characteristic.
 *                Points to the local GATT database buffer
 *                su8_deviceCertReceivedStatus. Fixed-length, 1 byte.
 */
GATTCharDescriptor_T gst_deviceCertReceivedStatusDesc = {
   .vpt_data = &su8_deviceCertReceivedStatus,
   .u16_dataLen = sizeof(su8_deviceCertReceivedStatus),
   .u16_actualLen = sizeof(su8_deviceCertReceivedStatus),
   .b_variableLength = false,
   .stpt_mutex = NULL,
   .fpt_customReadCb = NULL,
   .fpt_customWriteCb = st_DeviceCertReceivedStatusWrite,
};

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
 * @private       sv_DeviceProvisioningFlowEnsureInitialized
 * @brief         Ensure reusable device provisioning flow is initialized once.
 *                If it is not initiated, then it would initiate the same.
 * @return        None.
 */
static void sv_DeviceProvisioningFlowEnsureInitialized(void)
{
   // Check if the current instance of GATT flow is not configured with device provisioning flow
   if (sst_deviceProvisioningFlow.stpt_config != &sst_deviceProvisioningFlowConfig)
   {
      // Attach the config to an instance
      GattFlow_Init(&sst_deviceProvisioningFlow, &sst_deviceProvisioningFlowConfig);
   }
}

/**
 * @private       sv_DeviceProvisioningConnected
 * @brief         Reset device provisioning flow for a new BLE connection.
 * @param[in]     stpt_connHandle Connection handle.
 * @param[in]     u8_err Connection error code.
 * @return        None.
 */
static void sv_DeviceProvisioningConnected(struct bt_conn *stpt_connHandle, uint8_t u8_err)
{
   ARG_UNUSED(u8_err);

   sv_DeviceProvisioningFlowEnsureInitialized();

   // Check if a valid connection handle is available
   if (stpt_connHandle)
   {
      GattFlow_Reset(&sst_deviceProvisioningFlow, stpt_connHandle);
      LOG_INF("Initialized device provisioning flow for connection %p", stpt_connHandle);
      LOG_INF("Current device provisioning step is: %s",
         GattFlow_GetStepName(&sst_deviceProvisioningFlow,
            GattFlow_GetStep(&sst_deviceProvisioningFlow)));
   }
}

/**
 * @private       sv_DeviceProvisioningDisconnected
 * @brief         Release device provisioning flow for a disconnected BLE connection.
 * @param[in]     stpt_connHandle Connection handle.
 * @param[in]     u8_reason Disconnection reason.
 * @return        None.
 */
static void sv_DeviceProvisioningDisconnected(struct bt_conn *stpt_connHandle, uint8_t u8_reason)
{
   ARG_UNUSED(u8_reason);

   sv_DeviceProvisioningFlowEnsureInitialized();

   // Check if the GATT flow is corrently owned by the current connection
   if (GattFlow_IsOwnedByConn(&sst_deviceProvisioningFlow, stpt_connHandle))
   {
      GattFlow_Release(&sst_deviceProvisioningFlow, stpt_connHandle);
      LOG_INF("Released device provisioning flow for connection %p", stpt_connHandle);
   }
}

/**
 * @private       scpt_GetProvisioningStepName
 * @brief         Get a printable name for a device provisioning step.
 * @param[in]     u8_step Provisioning step.
 * @return        Printable step name.
 */
static const char *scpt_GetProvisioningStepName(uint8_t u8_step)
{
   const char *cpt_stepName = "UNKNOWN";

   switch ((DeviceProvisioningStep_E)u8_step)
   {
      case eDPS_WAIT_CSR_GENERATION_STATUS_READ:
         cpt_stepName = "WAIT_CSR_GENERATION_STATUS_READ";
         break;

      case eDPS_WAIT_CSR_DATA_READ:
         cpt_stepName = "WAIT_CSR_DATA_READ";
         break;

      case eDPS_CSR_DATA_READ_IN_PROGRESS:
         cpt_stepName = "CSR_DATA_READ_IN_PROGRESS";
         break;

      case eDPS_WAIT_DEVICE_CERT_DATA_WRITE:
         cpt_stepName = "WAIT_DEVICE_CERT_DATA_WRITE";
         break;

      case eDPS_DEVICE_CERT_DATA_WRITE_IN_PROGRESS:
         cpt_stepName = "DEVICE_CERT_DATA_WRITE_IN_PROGRESS";
         break;

      case eDPS_COMPLETE:
         cpt_stepName = "COMPLETE";
         break;

      default:
         break;
   }

   return cpt_stepName;
}

/**
 * @private       st_DeviceCertDataWrite
 * @brief         Post-write hook for Device Cert Data characteristic.
 *                Called after gt_GATT_GenericWrite has written data into the local
 *                GATT database buffer. Enforces GattFlow step ordering, sequential
 *                offset tracking, and flow advancement for certificate writes.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]     stpt_attr The attribute being written to.
 * @param[in]     vpt_buf The buffer containing the data being written.
 * @param[in]     u16_length The length of the data being written.
 * @param[in]     u16_offset The offset at which the data is being written.
 * @param[in]     u8_flags Write flags, see @ref bt_gatt_attr_write_flag.
 * @return        0 to keep the generic callback's return value, or
 *                BT_GATT_ERR() to override it.
 */
static ssize_t st_DeviceCertDataWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags)
{
   ssize_t t_retVal = 0;

   ARG_UNUSED(stpt_connHandle);
   ARG_UNUSED(stpt_attr);
   ARG_UNUSED(vpt_buf);
   ARG_UNUSED(u16_offset);
   ARG_UNUSED(u8_flags);

   // Increase the device certificate length received till now
   su16_receivedDeviceCertLength += u16_length;

   return t_retVal;
}

/**
 * @private       st_DeviceCertReceivedStatusWrite
 * @brief         Post-write hook for Device Cert Received Status characteristic.
 *                Called after gt_GATT_GenericWrite has written the status byte into
 *                the local GATT database buffer. Validates the written value,
 *                copies certificate data from the local GATT database to the
 *                application structure, stores it to ITS, and advances the flow.
 * @param[inout]  stpt_connHandle Connection handle.
 * @param[in]     stpt_attr The attribute being written to.
 * @param[in]     vpt_buf The buffer containing the data being written.
 * @param[in]     u16_length The length of the data being written.
 * @param[in]     u16_offset The offset at which the data is being written.
 * @param[in]     u8_flags Write flags, see @ref bt_gatt_attr_write_flag.
 * @return        0 to keep the generic callback's return value, or
 *                BT_GATT_ERR() to override it.
 */
static ssize_t st_DeviceCertReceivedStatusWrite(struct bt_conn *stpt_connHandle,
   const struct bt_gatt_attr *stpt_attr, const void *vpt_buf, uint16_t u16_length,
   uint16_t u16_offset, uint8_t u8_flags)
{
   ssize_t t_retVal = 0;
   uint8_t u8_receivedStatus = 0u;
   uint16_t u16_certBytesRead = 0u;
   uint16_t u16_deviceCertReceivedStatusBytesRead = 0u;
   psa_status_t t_storeStatus;

   ARG_UNUSED(stpt_connHandle);
   ARG_UNUSED(stpt_attr);
   ARG_UNUSED(vpt_buf);
   ARG_UNUSED(u16_length);
   ARG_UNUSED(u16_offset);
   ARG_UNUSED(u8_flags);

   // Copy certificate data from local GATT database to application structure
   gt_GATT_LocalRead(&gst_deviceCertReceivedStatusDesc, &u8_receivedStatus,
      gst_deviceCertReceivedStatusDesc.u16_actualLen, &u16_deviceCertReceivedStatusBytesRead);

   // Check if the device certificate received status has been read and its 1
   if ((u16_deviceCertReceivedStatusBytesRead == 1) && (u8_receivedStatus == 1))
   {
      // Copy certificate data from local GATT database to application structure
      gt_GATT_LocalRead(&gst_deviceCertDataDesc, gst_deviceCertData.u8ar_DeviceCert,
         sizeof(gst_deviceCertData.u8ar_DeviceCert), &u16_certBytesRead);

      // Check if the total bytes read from the local GATT database and the same
      // over the GATT characteristic are same
      if (u16_certBytesRead == su16_receivedDeviceCertLength)
      {
         gst_deviceCertData.u16_deviceCertLen = u16_certBytesRead;
         gst_deviceCertData.u8_isDeviceCertGenerated = u8_receivedStatus;

         // Store the received device certificate to ITS
         t_storeStatus = gt_StoreDeviceCert();

         // Check if the earlier ITS store operation completed successfully
         if (t_storeStatus != PSA_SUCCESS)
         {
            t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
            LOG_ERR("Failed to store received device certificate: %d", t_storeStatus);
         }
      }
      else
      {
         t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
         LOG_WRN("Total bytes received over GATT was: %u, but the same read form
            local GATT database was: %u", su16_receivedDeviceCertLength, u16_certBytesRead);
      }
   }
   else
   {
      t_retVal = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
      LOG_WRN("Rejected device certificate received status value: %u", u8_receivedStatus);
   }

   return t_retVal;
}

/******************************************************************************/
/*                                                                            */
/*                        PUBLIC FUNCTION DEFINITIONS                         */
/*                                                                            */
/******************************************************************************/

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF Bajaj Auto Technology Limited (BATL).
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * Bajaj Auto Technology Limited (BATL) IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
