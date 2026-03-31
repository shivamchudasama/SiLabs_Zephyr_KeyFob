/**
 * @file          GATTFlow.c
 * @brief         Source file containing reusable step-based GATT flow framework.
 * @date          19/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "GATTFlow.h"

/******************************************************************************/
/*                                                                            */
/*                       PRIVATE FUNCTION DECLARATIONS                        */
/*                                                                            */
/******************************************************************************/
static const GattFlowRule_T *stpt_FindRule(const GattFlowInstance_T *stpt_instance,
   uint8_t u8_charId, GattFlowOp_E e_op);
static void sv_ResetContext(const GattFlowConfig_T *stpt_config);

/******************************************************************************/
/*                                                                            */
/*                        PRIVATE FUNCTION DEFINITIONS                        */
/*                                                                            */
/******************************************************************************/
/**
 * @private       stpt_FindRule
 * @brief         Find the matching rule for a characteristic access request.
 * @param[in]     stpt_instance Flow instance.
 * @param[in]     u8_charId Service-specific characteristic identifier.
 * @param[in]     e_op ATT access operation.
 * @return        Pointer to the matching rule, or NULL if none exists.
 */
static const GattFlowRule_T *stpt_FindRule(const GattFlowInstance_T *stpt_instance,
   uint8_t u8_charId, GattFlowOp_E e_op)
{
   const GattFlowRule_T *stpt_rule = NULL;
   size_t t_idx;

   // Check if the instance is initialized with configuration
   if ((!stpt_instance) || (!stpt_instance->stpt_config))
   {
      return NULL;
   }

   // Loop through all the rules to get the matchin rule for given characteristic
   for (t_idx = 0u; t_idx < stpt_instance->stpt_config->t_ruleCnt; t_idx++)
   {
      stpt_rule = &stpt_instance->stpt_config->stpt_rules[t_idx];

      // Check if the rule matches with the given characteristic & operation
      if ((stpt_rule->u8_charId == u8_charId) &&
         (stpt_rule->e_op == e_op))
      {
         return stpt_rule;
      }
   }

   return NULL;
}

/**
 * @private       sv_ResetContext
 * @brief         Reset service-owned runtime context.
 * @param[in]     stpt_config Flow configuration.
 * @return        None.
 */
static void sv_ResetContext(const GattFlowConfig_T *stpt_config)
{
   // Check if a valid configuration has passed
   if (!stpt_config)
   {
      return;
   }

   // Check if a valid context is attached to the configuration
   if ((stpt_config->vpt_context) && (stpt_config->t_contextLen > 0u))
   {
      memset(stpt_config->vpt_context, 0, stpt_config->t_contextLen);
   }

   // Check if any context reset hook registered
   if (stpt_config->fpt_contextResetHook)
   {
      stpt_config->fpt_contextResetHook(stpt_config->vpt_context);
   }
}

/******************************************************************************/
/*                                                                            */
/*                        PUBLIC FUNCTION DEFINITIONS                         */
/*                                                                            */
/******************************************************************************/
/**
 * @public        GattFlow_Init
 * @brief         Initialize a reusable GATT flow instance with static config.
 * @param[inout]  stpt_instance Flow instance.
 * @param[in]     stpt_config Static flow configuration.
 * @return        None.
 */
void GattFlow_Init(GattFlowInstance_T *stpt_instance,
   const GattFlowConfig_T *stpt_config)
{
   // Check if a valid instance and configuration passed
   if ((!stpt_instance) || (!stpt_config))
   {
      return;
   }

   // Clear the instance and attach configuration to the instance
   memset(stpt_instance, 0, sizeof(*stpt_instance));
   stpt_instance->stpt_config = stpt_config;
   stpt_instance->u8_step = stpt_config->u8_initialStep;

   // reset the context to give a clean start
   sv_ResetContext(stpt_config);
}

/**
 * @public        GattFlow_Reset
 * @brief         Reset a flow instance for a new BLE connection lifecycle.
 * @param[inout]  stpt_instance Flow instance.
 * @param[in]     stpt_connHandle Owning connection handle.
 * @return        None.
 */
void GattFlow_Reset(GattFlowInstance_T *stpt_instance,
   struct bt_conn *stpt_connHandle)
{
   // Check if a valid instance and configuration passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config))
   {
      return;
   }

   // Re-assign connection handle, reset the current step to initial step and reset
   // the context
   stpt_instance->stpt_connHandle = stpt_connHandle;
   stpt_instance->u8_step = stpt_instance->stpt_config->u8_initialStep;
   sv_ResetContext(stpt_instance->stpt_config);
}

/**
 * @public        GattFlow_Release
 * @brief         Release a flow instance owned by the specified connection.
 * @param[inout]  stpt_instance Flow instance.
 * @param[in]     stpt_connHandle Connection handle.
 * @return        None.
 */
void GattFlow_Release(GattFlowInstance_T *stpt_instance,
   struct bt_conn *stpt_connHandle)
{
   // Check if a valid instance and configuration passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config))
   {
      return;
   }

   // Check if the current connection handle is assigned to the instance 
   if (stpt_instance->stpt_connHandle == stpt_connHandle)
   {
      // Remove the connection handle and push the current step to an initial step
      stpt_instance->stpt_connHandle = NULL;
      stpt_instance->u8_step = stpt_instance->stpt_config->u8_initialStep;
      sv_ResetContext(stpt_instance->stpt_config);
   }
}

/**
 * @public        GattFlow_Check
 * @brief         Check if a characteristic access is allowed in the current step.
 * @param[inout]  stpt_instance Flow instance.
 * @param[in]     stpt_connHandle Connection handle that issued the access.
 * @param[in]     u8_charId Service-specific characteristic identifier.
 * @param[in]     e_op ATT access operation.
 * @param[out]    stppt_rule Optional pointer to receive the matching rule.
 * @return        0 if access is allowed, else BT_GATT_ERR().
 */
ssize_t GattFlow_Check(GattFlowInstance_T *stpt_instance,
   struct bt_conn *stpt_connHandle, uint8_t u8_charId, GattFlowOp_E e_op,
   const GattFlowRule_T **stppt_rule)
{
   const GattFlowRule_T *stpt_rule = NULL;

   // Check if the matching rule has requested 
   if (stppt_rule)
   {
      *stppt_rule = NULL;
   }

   // Check if a valid instance, configuration and connection handle passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config) || (!stpt_connHandle))
   {
      return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
   }

   // Check if the connection handle matches with the instance's connection handle
   if (stpt_instance->stpt_connHandle != stpt_connHandle)
   {
      LOG_WRN("%s rejected access for unexpected connection handle %p",
         stpt_instance->stpt_config->cpt_name, stpt_connHandle);
      return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
   }

   // Get the requested rule
   stpt_rule = stpt_FindRule(stpt_instance, u8_charId, e_op);

   // Check if we've got the rule
   if (!stpt_rule)
   {
      LOG_WRN("%s rejected access because no flow rule exists for characteristic id %u",
         stpt_instance->stpt_config->cpt_name, u8_charId);
      return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
   }

   // Check if current step matches with the rule
   if ((stpt_rule->u32_allowedStepsMask & GATT_FLOW_STEP_MASK(stpt_instance->u8_step)) == 0u)
   {
      LOG_WRN("%s rejected access in step %s",
         stpt_instance->stpt_config->cpt_name,
         GattFlow_GetStepName(stpt_instance, stpt_instance->u8_step));
      return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
   }

   // Check if the matching rule has requested
   if (stppt_rule)
   {
      *stppt_rule = stpt_rule;
   }

   return 0;
}

/**
 * @public        GattFlow_Advance
 * @brief         Advance the flow using the automatic next step defined by a rule.
 * @param[inout]  stpt_instance Flow instance.
 * @param[in]     stpt_rule Matching rule for the successful access.
 * @return        None.
 */
void GattFlow_Advance(GattFlowInstance_T *stpt_instance,
   const GattFlowRule_T *stpt_rule)
{
   // Check if a valid instance, configuration and rule passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config) || (!stpt_rule))
   {
      return;
   }

   // Check if the next step is not an invalid one
   if (stpt_rule->u8_nextStep != GATT_FLOW_INVALID_STEP)
   {
      GattFlow_SetStep(stpt_instance, stpt_rule->u8_nextStep,
         stpt_rule->cpt_transitionReason);
   }
}

/**
 * @public        GattFlow_SetStep
 * @brief         Explicitly move a flow instance to a new step.
 * @param[inout]  stpt_instance Flow instance.
 * @param[in]     u8_nextStep Next flow step.
 * @param[in]     cpt_reason Reason for transition.
 * @return        None.
 */
void GattFlow_SetStep(GattFlowInstance_T *stpt_instance, uint8_t u8_nextStep,
   const char *cpt_reason)
{
   // Check if a valid instance or configuration passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config))
   {
      return;
   }

   // Check if the current step and the next step is not the same
   if (stpt_instance->u8_step != u8_nextStep)
   {
      LOG_INF("%s step %s -> %s (%s)",
         stpt_instance->stpt_config->cpt_name,
         GattFlow_GetStepName(stpt_instance, stpt_instance->u8_step),
         GattFlow_GetStepName(stpt_instance, u8_nextStep),
         (cpt_reason ? cpt_reason : "No reason"));
      stpt_instance->u8_step = u8_nextStep;
   }
}

/**
 * @public        GattFlow_GetStep
 * @brief         Get the current step of a flow instance.
 * @param[in]     stpt_instance Flow instance.
 * @return        Current flow step.
 */
uint8_t GattFlow_GetStep(const GattFlowInstance_T *stpt_instance)
{
   // Check if valid instance and configuration passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config))
   {
      return GATT_FLOW_INVALID_STEP;
   }

   return stpt_instance->u8_step;
}

/**
 * @public        GattFlow_GetStepName
 * @brief         Get the printable name for a flow step.
 * @param[in]     stpt_instance Flow instance.
 * @param[in]     u8_step Flow step.
 * @return        Printable step name.
 */
const char *GattFlow_GetStepName(const GattFlowInstance_T *stpt_instance,
   uint8_t u8_step)
{
   const char *cpt_stepName = "UNKNOWN";

   // Check if a valid instance or the connection handle passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config))
   {
      return cpt_stepName;
   }

   // Check if the valid step name written
   if (stpt_instance->stpt_config->fpt_stepNameHook)
   {
      cpt_stepName = stpt_instance->stpt_config->fpt_stepNameHook(u8_step);

      if (!cpt_stepName)
      {
         cpt_stepName = "UNKNOWN";
      }
   }

   return cpt_stepName;
}

/**
 * @public        GattFlow_GetContext
 * @brief         Get service-owned runtime context from a flow instance.
 * @param[inout]  stpt_instance Flow instance.
 * @return        Pointer to service-owned runtime context.
 */
void *GattFlow_GetContext(GattFlowInstance_T *stpt_instance)
{
   // Check if a valid instance or configuration passed
   if ((!stpt_instance) || (!stpt_instance->stpt_config))
   {
      return NULL;
   }

   return stpt_instance->stpt_config->vpt_context;
}

/**
 * @public        GattFlow_IsOwnedByConn
 * @brief         Check if a flow instance belongs to the provided connection.
 * @param[in]     stpt_instance Flow instance.
 * @param[in]     stpt_connHandle Connection handle.
 * @return        True if the flow instance belongs to the connection.
 */
bool GattFlow_IsOwnedByConn(const GattFlowInstance_T *stpt_instance,
   const struct bt_conn *stpt_connHandle)
{
   // Check if a valid instance passed
   if (!stpt_instance)
   {
      return false;
   }

   return (stpt_instance->stpt_connHandle == stpt_connHandle);
}

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
