/**
 * @file          GATTFlow.h
 * @brief         Header file containing reusable step-based GATT flow framework.
 * @date          19/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _GATT_FLOW_H
#define _GATT_FLOW_H

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include "AppLog.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           GATT_FLOW_INVALID_STEP
 * @brief         Sentinel value indicating that no automatic step transition is
 *                configured for a rule.
 */
#define GATT_FLOW_INVALID_STEP               (0xFFu)

/**
 * @def           GATT_FLOW_STEP_MASK
 * @brief         Build a bit-mask for the provided flow step.
 */
#define GATT_FLOW_STEP_MASK(u8_step)         ((uint32_t)1u << (uint8_t)(u8_step))

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/
/**
 * @enum          GattFlowOp_E
 * @brief         Supported ATT access types for a characteristic rule.
 */
typedef enum
{
   eGFO_READ = 0,                            /**< GATT Read operation */
   eGFO_WRITE,                               /**< GATT Write operation */
} GattFlowOp_E;

/******************************************************************************/
/*                                                                            */
/*                                 STRUCTURES                                 */
/*                                                                            */
/******************************************************************************/
struct GattFlowInstance;

/**
 * @typedef       GattFlowStepNameHook_F
 * @brief         Optional hook used for printing step names in logs.
 */
typedef const char *(*GattFlowStepNameHook_F)(uint8_t u8_step);

/**
 * @typedef       GattFlowContextResetHook_F
 * @brief         Optional hook used to initialize service-specific runtime
 *                context after it is zeroed.
 */
typedef void (*GattFlowContextResetHook_F)(void *vpt_context);

/**
 * @struct        GattFlowRule_T
 * @brief         Rule for one characteristic access within a service flow.
 */
typedef struct
{
   uint8_t u8_charId;                        /**< Service-specific characteristic identifier */
   GattFlowOp_E e_op;                        /**< ATT access operation */
   uint32_t u32_allowedStepsMask;            /**< Steps in which this access is allowed */
   uint8_t u8_nextStep;                      /**< Automatic next step after success */
   const char *cpt_transitionReason;         /**< Log reason for automatic step transition */
} GattFlowRule_T;

/**
 * @struct        GattFlowConfig_T
 * @brief         Static configuration for one service flow instance.
 */
typedef struct
{
   const char *cpt_name;                     /**< Flow name used in logs */
   uint8_t u8_initialStep;                   /**< Step restored on connect/reset */
   void *vpt_context;                        /**< Pointer to service-owned runtime context */
   size_t t_contextLen;                      /**< Length of service-owned runtime context */
   const GattFlowRule_T *stpt_rules;         /**< Rule table */
   size_t t_ruleCnt;                         /**< Number of rules in rule table */
   GattFlowStepNameHook_F fpt_stepNameHook;  /**< Optional step name hook */
   GattFlowContextResetHook_F fpt_contextResetHook;
                                             /**< Optional context reset hook */
} GattFlowConfig_T;

/**
 * @struct        GattFlowInstance
 * @brief         Runtime state for one step-based GATT flow.
 */
typedef struct GattFlowInstance
{
   const GattFlowConfig_T *stpt_config;      /**< Static configuration */
   struct bt_conn *stpt_connHandle;          /**< Owning connection handle */
   uint8_t u8_step;                          /**< Current step */
} GattFlowInstance_T;

/******************************************************************************/
/*                                                                            */
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/
extern void GattFlow_Init(GattFlowInstance_T *stpt_instance,
   const GattFlowConfig_T *stpt_config);
extern void GattFlow_Reset(GattFlowInstance_T *stpt_instance,
   struct bt_conn *stpt_connHandle);
extern void GattFlow_Release(GattFlowInstance_T *stpt_instance,
   struct bt_conn *stpt_connHandle);
extern ssize_t GattFlow_Check(GattFlowInstance_T *stpt_instance,
   struct bt_conn *stpt_connHandle, uint8_t u8_charId, GattFlowOp_E e_op,
   const GattFlowRule_T **stppt_rule);
extern void GattFlow_Advance(GattFlowInstance_T *stpt_instance,
   const GattFlowRule_T *stpt_rule);
extern void GattFlow_SetStep(GattFlowInstance_T *stpt_instance, uint8_t u8_nextStep,
   const char *cpt_reason);
extern uint8_t GattFlow_GetStep(const GattFlowInstance_T *stpt_instance);
extern const char *GattFlow_GetStepName(const GattFlowInstance_T *stpt_instance,
   uint8_t u8_step);
extern void *GattFlow_GetContext(GattFlowInstance_T *stpt_instance);
extern bool GattFlow_IsOwnedByConn(const GattFlowInstance_T *stpt_instance,
   const struct bt_conn *stpt_connHandle);

#endif //!_GATT_FLOW_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
