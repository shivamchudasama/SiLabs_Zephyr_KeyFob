/**
 * @file          ConnectionHandling.c
 * @brief         Source file containing all the connection handling related functions.
 * @date          21/02/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "ConnectionHandling.h"
#include <errno.h>

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           TARGET_PHY
 * @brief         Target PHY for connection.
 */
#define TARGET_PHY                           (BT_GAP_LE_PHY_2M)

/**
 * @def           TARGET_DLE
 * @brief         Target DLE value.
 */
#define TARGET_DLE                           (251)

/**
 * @def           TARGET_MTU
 * @brief         Target MTU value.
 */
#define TARGET_MTU                           (247)

/**
 * @def           NEGOTIATION_RETRY_DELAY_MS
 * @brief         Delay for retrying a busy negotiation procedure.
 */
#define NEGOTIATION_RETRY_DELAY_MS           (200)

/**
 * @def           MAX_NEGOTIATION_RETRY_CNT
 * @brief         Maximum number of retries for a negotiation procedure.
 */
#define MAX_NEGOTIATION_RETRY_CNT            (3)

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/
/**
 * @enum          ConnNegotiationStep_E
 * @brief         Enums to track which link-layer optimization is currently being
 *                negotiated.
 */
typedef enum
{
   eCNS_PHY = 0,                             /**< PHY update */
   eCNS_DLE,                                 /**< Data Length Extention */
   eCNS_MTU,                                 /**< MTU exchange */
   eCNS_COMPLETE,                            /**< Negotiation complete */
} ConnNegotiationStep_E;

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
static void sv_ConnParamNegotiation(struct k_work *stpt_work);
static void sv_MTUExchangeCallback(struct bt_conn *stpt_conn, uint8_t u8_err,
   struct bt_gatt_exchange_params *stpt_exchangeParams);
static void sv_Connected(struct bt_conn *stpt_conn, uint8_t u8_err);
static void sv_Disconnected(struct bt_conn *stpt_conn, uint8_t reason);
static void sv_Recycled(void);
static void sv_PHYUpdated(struct bt_conn *stpt_conn, struct bt_conn_le_phy_info *stpt_PHYInfo);
static void sv_DataLengthUpdated(struct bt_conn *stpt_conn,
   struct bt_conn_le_data_len_info *stpt_dataLenInfo);
static void sv_ResetConnNegotiationState(void);

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
 * @var           gst_connParamNegotiationWork
 * @brief         Initialize a delayable work item for BLE negotiation.
 */
K_WORK_DELAYABLE_DEFINE(gst_connParamNegotiationWork, sv_ConnParamNegotiation);

/**
 * @var           gstpt_currentConn
 * @brief         Pointer to current connection handle.
 */
struct bt_conn *gstpt_currentConn;

/******************************************************************************/
/*                                                                            */
/*                             PRIVATE VARIABLES                              */
/*                                                                            */
/******************************************************************************/
/**
 * @var           sb_isSelfNegotiation
 * @brief         Flag to indicate if self negotiation has been performed.
 */
static bool sb_isSelfNegotiation = false;

/**
 * @var           sb_waitingForProcedure
 * @brief         Flag to indicate if a local negotiation procedure is pending.
 */
static bool sb_waitingForProcedure = false;

/**
 * @var           se_connNegotiationStep
 * @brief         Current negotiation step.
 */
static ConnNegotiationStep_E se_connNegotiationStep = eCNS_PHY;

/**
 * @var           sstar_advData
 * @brief         Create advertising data structure array.
 */
static struct bt_data sstar_advData[] =
{
   // AD Type: Flags - general discoverable and no BR/EDR support
   BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
   // AD Type: 128-bit UUID, all listed UUIDs available
   // BT_DATA_BYTES(BT_DATA_UUID128_ALL, BT_UUID_FOTA_SERVICE_VAL),
};

/**
 * @var           sstar_scanRespData
 * @brief         Create scan response data structure array.
 */
static struct bt_data sstar_scanRespData[] =
{
   // AD Type: Complete local name
   BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME,
      sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

/**
 * @var           sst_connCallbacks
 * @brief         Connection callbacks.
 */
BT_CONN_CB_DEFINE(sst_connCallbacks) = {
	.connected = sv_Connected,                // Callback for handling new connections
	.disconnected = sv_Disconnected,          // Callback for handling disconnections
   .recycled = sv_Recycled,                  // Callback for handling recycled connections
   .le_phy_updated = sv_PHYUpdated,          // Callback to be called upon PHY updated
   .le_data_len_updated = sv_DataLengthUpdated,
                                             // Callback to be called upon data length updated
};

/**
 * @var           sst_exchangeParams
 * @brief         Structure for GATT exchange parameters.
 */
static struct bt_gatt_exchange_params sst_exchangeParams;

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
 * @private       sv_ResetConnNegotiationState
 * @brief         Reset negotiation state for a new connection lifecycle.
 * @return        None.
 */
static void sv_ResetConnNegotiationState(void)
{
   sb_isSelfNegotiation = false;
   sb_waitingForProcedure = false;
   se_connNegotiationStep = eCNS_PHY;
}

/**
 * @private       sv_ConnParamNegotiation
 * @brief         Negotiation for PHY update, MTU exchange, and data length
 *                update after connection.
 * @param[in]     stpt_work Pointer to the work item for this negotiation process.
 * @return        None.
 */
static void sv_ConnParamNegotiation(struct k_work *stpt_work)
{
   ARG_UNUSED(stpt_work);

   struct bt_conn_le_phy_param st_PHYParam = {
      .options = BT_CONN_LE_PHY_OPT_NONE,
      .pref_tx_phy = TARGET_PHY,
      .pref_rx_phy = TARGET_PHY,
   };
   struct bt_conn_info st_connInfo;
   int i_err;
   uint16_t u16_MTU;
   static uint8_t slu8_retryCnt = 0;

   // Check if we have a valid connection handle
   if (!gstpt_currentConn)
   {
      LOG_ERR("No valid connection handle for negotiation");
   }
   else
   {
      // Track first entry after the 1-second delay to mark start of self negotiation.
      if (!sb_isSelfNegotiation)
      {
         sb_isSelfNegotiation = true;
         LOG_INF("Starting self negotiation after a delay...");
      }

      // Loop through negotiation steps until complete, handling busy responses with retries
      while (se_connNegotiationStep != eCNS_COMPLETE)
      {
         // Get the current connection info for the connection handle
         i_err = bt_conn_get_info(gstpt_currentConn, &st_connInfo);

         // Check if getting connection info failed
         if (i_err)
         {
            LOG_ERR("Failed to get connection info (err %x)", i_err);
            return;
         }

         // Switch through negotiation steps and perform necessary actions for each step
         switch (se_connNegotiationStep)
         {
            case eCNS_PHY:
            {
               // Check if PHY is already at target for both TX and RX
               if ((st_connInfo.le.phy->tx_phy == TARGET_PHY) &&
                  (st_connInfo.le.phy->rx_phy == TARGET_PHY))
               {
                  LOG_INF("PHY already at target (TX:%d RX:%d), skipping PHY request",
                     st_connInfo.le.phy->tx_phy, st_connInfo.le.phy->rx_phy);
                  se_connNegotiationStep = eCNS_DLE;
                  sb_waitingForProcedure = false;
                  continue;
               }

               // Check if we are already waiting for a procedure to complete
               if (sb_waitingForProcedure)
               {
                  return;
               }

               LOG_INF("Requesting PHY 2M...");
               i_err = bt_conn_le_phy_update(gstpt_currentConn, &st_PHYParam);

               // Check if there was an error initiating PHY update
               if (i_err)
               {
                  // Check if we haven't exceeded max retry count
                  if (slu8_retryCnt < MAX_NEGOTIATION_RETRY_CNT)
                  {
                     slu8_retryCnt++;
                     LOG_WRN("PHY update request failed (err %d), retrying...", i_err);
                     k_work_schedule(&gst_connParamNegotiationWork, K_MSEC(NEGOTIATION_RETRY_DELAY_MS));
                     return;
                  }
                  else
                  {
                     LOG_WRN("PHY update request failed, proceeding without it...");
                     se_connNegotiationStep = eCNS_DLE;
                     continue;
                  }
               }

               sb_waitingForProcedure = true;
               return;
            }

            case eCNS_DLE:
            {
               // Check if DLE is already at target for both TX and RX
               if ((st_connInfo.le.data_len->tx_max_len >= TARGET_DLE) &&
                  (st_connInfo.le.data_len->rx_max_len >= TARGET_DLE))
               {
                  LOG_INF("DLE already at target (TX:%d RX:%d), skipping DLE request",
                     st_connInfo.le.data_len->tx_max_len, st_connInfo.le.data_len->rx_max_len);
                  se_connNegotiationStep = eCNS_MTU;
                  sb_waitingForProcedure = false;
                  continue;
               }

               // Check if we are already waiting for a procedure to complete
               if (sb_waitingForProcedure)
               {
                  return;
               }

               LOG_INF("Requesting DLE 251...");
               i_err = bt_conn_le_data_len_update(gstpt_currentConn, NULL);

               // Check if there was an error initiating PHY update
               if (i_err)
               {
                  // Check if we haven't exceeded max retry count
                  if (slu8_retryCnt < MAX_NEGOTIATION_RETRY_CNT)
                  {
                     slu8_retryCnt++;
                     LOG_WRN("DLE update request failed (err %d), retrying...", i_err);
                     k_work_schedule(&gst_connParamNegotiationWork, K_MSEC(NEGOTIATION_RETRY_DELAY_MS));
                     return;
                  }
                  else
                  {
                     LOG_WRN("DLE update request failed, proceeding without it...");
                     se_connNegotiationStep = eCNS_MTU;
                     continue;
                  }
               }

               sb_waitingForProcedure = true;
               return;
            }

            case eCNS_MTU:
            {
               u16_MTU = bt_gatt_get_mtu(gstpt_currentConn);

               // Check if MTU is already at target
               if (u16_MTU >= TARGET_MTU)
               {
                  LOG_INF("MTU already at target (%d bytes), skipping MTU request", u16_MTU);
                  se_connNegotiationStep = eCNS_COMPLETE;
                  sb_waitingForProcedure = false;
                  continue;
               }

               // Check if we are already waiting for a procedure to complete
               if (sb_waitingForProcedure)
               {
                  return;
               }

               LOG_INF("Requesting MTU %d...", TARGET_MTU);
               sst_exchangeParams.func = sv_MTUExchangeCallback;
               i_err = bt_gatt_exchange_mtu(gstpt_currentConn, &sst_exchangeParams);

               // Check if there was an error initiating PHY update
               if (i_err)
               {
                  // Check if we haven't exceeded max retry count
                  if (slu8_retryCnt < MAX_NEGOTIATION_RETRY_CNT)
                  {
                     slu8_retryCnt++;
                     LOG_WRN("MTU exchange request failed (err %d), retrying...", i_err);
                     k_work_schedule(&gst_connParamNegotiationWork, K_MSEC(NEGOTIATION_RETRY_DELAY_MS));
                     return;
                  }
                  else
                  {
                     LOG_WRN("MTU exchange request failed, proceeding without it...");
                     se_connNegotiationStep = eCNS_COMPLETE;
                     continue;
                  }
               }

               sb_waitingForProcedure = true;
               return;
            }

            case eCNS_COMPLETE:
            default:
               break;
         }
      }

      LOG_INF("Negotiation complete.");
   }
}

/**
 * @private       sv_MTUExchangeCallback
 * @brief         Callback function to be called after exchanging MTU
 * @param[in]     stpt_conn Connection handle
 * @param[in]     u8_err Error code of the MTU exchange procedure
 * @param[in]     stpt_exchangeParams Pointer to the exchange parameters structure
 * @return        None.
 */
static void sv_MTUExchangeCallback(struct bt_conn *stpt_conn, uint8_t u8_err,
   struct bt_gatt_exchange_params *stpt_exchangeParams)
{
   ARG_UNUSED(stpt_exchangeParams);

   // Check if the callback is for the current connection
   if ((gstpt_currentConn == NULL) || (stpt_conn != gstpt_currentConn))
   {
      return;
   }

   LOG_INF("MTU exchange %s", (u8_err == 0 ? "successful" : "failed"));

   // Check if no error
   if (!u8_err)
   {
      // Get the current MTU size
      uint16_t u16_payloadMTU = bt_gatt_get_mtu(stpt_conn) - 3;  /* 3 bytes ATT header */
      LOG_INF("New MTU payload: %d bytes", u16_payloadMTU);
   }

   if ((sb_isSelfNegotiation) && (se_connNegotiationStep == eCNS_MTU))
   {
      sb_waitingForProcedure = false;
      se_connNegotiationStep = eCNS_COMPLETE;
      k_work_schedule(&gst_connParamNegotiationWork, K_NO_WAIT);
   }
}

/**
 * @private       sv_Connected
 * @brief         Callback for handling new connections. This function is called when a
 *                new connection is established.
 * @param[in]     stpt_conn Connection handle.
 * @param[in]     u8_err Error code of the connection attempt.
 * @return        Number of bytes written.
 */
static void sv_Connected(struct bt_conn *stpt_conn, uint8_t u8_err)
{
   int i_err;

   // Check if there was an error during connection
	if (u8_err)
   {
		LOG_ERR("Connection failed (err %x)", u8_err);
		return;
	}
	LOG_INF("Connected");

   // Note: We should cancel any ongoing negotiation work and reset state here to
   // ensure a clean slate for the next connection.
   k_work_cancel_delayable(&gst_connParamNegotiationWork);
   sv_ResetConnNegotiationState();

   // Note: Ideally we should not have a valid connection handle at this point
   // since we should have cleared it on disconnection, but we will check and
   // clear it just in case to avoid any potential issues with stale connection handles.

   // Check if the current connection is not cleared
   if (gstpt_currentConn)
   {
      bt_conn_unref(gstpt_currentConn);
      gstpt_currentConn = NULL;
   }

   // Get the current connection handle and store it for future use
   gstpt_currentConn = bt_conn_ref(stpt_conn);

   // Schedule work to negotiate PHY update, MTU exchange, and DLE after a short delay
   // to allow connection to stabilize
   i_err = k_work_schedule(&gst_connParamNegotiationWork, K_SECONDS(2));

   // Check if scheduling the negotiation work failed
   if (i_err < 0)
   {
      LOG_WRN("Failed to schedule negotiation work (err %x)", i_err);
   }
}

/**
 * @private       sv_Disconnected
 * @brief         Callback for handling disconnections. This function is called when a
 *                connection is disconnected.
 * @param[in]     stpt_conn Connection handle.
 * @param[in]     reason Reason for disconnection.
 * @return        Number of bytes written.
 */
static void sv_Disconnected(struct bt_conn *stpt_conn, uint8_t reason)
{
	LOG_INF("Disconnected (reason 0x%x)", reason);

   // Note: We should cancel any ongoing negotiation work and reset state here to
   // ensure a clean slate for the next connection.
   k_work_cancel_delayable(&gst_connParamNegotiationWork);
   sv_ResetConnNegotiationState();

   // Check if the current connection is not cleared
   if (gstpt_currentConn)
   {
      bt_conn_unref(gstpt_currentConn);
      gstpt_currentConn = NULL;
   }
}

/**
 * @private       sv_Recycled
 * @brief         Callback for handling recycled connections. This function is called when a
 *                connection is recycled.
 * @return        Number of bytes written.
 */
static void sv_Recycled(void)
{
   int i_err;

   LOG_INF("Let's restart advertising after connection recycle");

   // Start advertising by setting advertisement data, scan response data,
   // and advertisement parameters.
   i_err = bt_le_adv_start(
      BT_LE_ADV_CONN_FAST_1,                 // Advertising parameters: Connectable undirected advertising
      sstar_advData,                         // Advertising data
      ARRAY_SIZE(sstar_advData),             // Length of advertising data
      sstar_scanRespData,                    // Scan response data
      ARRAY_SIZE(sstar_scanRespData)         // Length of scan response data
   );

   // Check if advertising start wasn't successful
	if (i_err)
   {
		LOG_ERR("Advertising failed to start (err %x)", i_err);
		return;
	}

   LOG_INF("Advertising restarted");
}

/**
 * @private       sv_PHYUpdated
 * @brief         Callback to be called upon PHY updated.
 * @param[in]     stpt_conn Connection handle.
 * @param[in]     stpt_PHYInfo PHY information.
 * @return        None.
 */
static void sv_PHYUpdated(struct bt_conn *stpt_conn, struct bt_conn_le_phy_info *stpt_PHYInfo)
{
   // Check if the callback is for the current connection
   if ((gstpt_currentConn == NULL) || (stpt_conn != gstpt_currentConn))
   {
      return;
   }

   LOG_INF("PHY updated TX:%d RX:%d", stpt_PHYInfo->tx_phy, stpt_PHYInfo->rx_phy);

   // Check if we have initiated the negotiation
   if (sb_isSelfNegotiation)
   {
      // Check if we were waiting for PHY update to complete
      if ((se_connNegotiationStep == eCNS_PHY) && (sb_waitingForProcedure))
      {
         sb_waitingForProcedure = false;
         se_connNegotiationStep = eCNS_DLE;
      }

      LOG_INF("Running next negotiation step after PHY update...");
      k_work_schedule(&gst_connParamNegotiationWork, K_NO_WAIT);
   }
}

/**
 * @private       sv_DataLengthUpdated
 * @brief         Callback to be called upon data length updated.
 * @param[in]     stpt_conn Connection handle.
 * @param[in]     stpt_dataLenInfo Data length information.
 * @return        None.
 */
static void sv_DataLengthUpdated(struct bt_conn *stpt_conn,
   struct bt_conn_le_data_len_info *stpt_dataLenInfo)
{
   // Check if the callback is for the current connection
   if ((gstpt_currentConn == NULL) || (stpt_conn != gstpt_currentConn))
   {
      return;
   }

   LOG_INF("Data length updated. Len TX/ RX: %d/ %d bytes, time TX/ RX: %d/ %d us",
      stpt_dataLenInfo->tx_max_len, stpt_dataLenInfo->rx_max_len,
      stpt_dataLenInfo->tx_max_time, stpt_dataLenInfo->rx_max_time);

   // Check if we have initiated the negotiation
   if (sb_isSelfNegotiation)
   {
      // Check if we were waiting for DLE update to complete
      if ((se_connNegotiationStep == eCNS_DLE) && (sb_waitingForProcedure))
      {
         sb_waitingForProcedure = false;
         se_connNegotiationStep = eCNS_MTU;
      }

      LOG_INF("Running next negotiation step after DLE update...");
      k_work_schedule(&gst_connParamNegotiationWork, K_NO_WAIT);
   }
}

/******************************************************************************/
/*                                                                            */
/*                        PUBLIC FUNCTION DEFINITIONS                         */
/*                                                                            */
/******************************************************************************/
/**
 * @public        gv_BLEInitStartAdv
 * @brief         Initialize BLE module and start advertising.
 * @return        None.
 */
void gv_BLEInitStartAdv(void)
{
   int i_err;
   bt_addr_le_t st_addr = { 0 };
   size_t t_count = 1;
   char c_addr[BT_ADDR_LE_STR_LEN] = { 0 };

   LOG_INF("Initializing Bluetooth...");

   // Enable Bluetooth
   i_err = bt_enable(NULL);

   // Check if Bluetooth initialization wasn't successful
	if (i_err)
   {
		LOG_ERR("Bluetooth init failed (err %x)", i_err);
	}
   else
   {
      LOG_INF("Bluetooth initialized");
      LOG_INF("Starting BLE advertising...");

      // Get the BLE MAC address
      bt_id_get(&st_addr, &t_count);
      bt_addr_le_to_str(&st_addr, c_addr, sizeof(c_addr));
      LOG_INF("BLE MAC address: %s", c_addr);

      // Advertise with name and custom service UUID
      // Start advertising by setting advertisement data, scan response data,
      // and advertisement parameters.
      i_err = bt_le_adv_start(
         BT_LE_ADV_CONN_FAST_1,              // Advertising parameters: Connectable undirected advertising
         sstar_advData,                      // Advertising data
         ARRAY_SIZE(sstar_advData),          // Length of advertising data
         sstar_scanRespData,                 // Scan response data
         ARRAY_SIZE(sstar_scanRespData)      // Length of scan response data
      );

      // Check if advertising start wasn't successful
      if (i_err)
      {
         LOG_ERR("Advertising failed to start (err %x)", i_err);
      }
      else
      {
         LOG_INF("Advertising started");
      }
   }
}

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shviam Chudasama [SC]
 */
