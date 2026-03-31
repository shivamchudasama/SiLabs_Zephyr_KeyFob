/**
 * @file          GATT_DB_Types.h
 * @brief         Header file containing typedefines for GATT database.
 * @date          16/03/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _GATT_DB_TYPES_H
#define _GATT_DB_TYPES_H

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
 * @def           MAX_CP_BLOCK_SIZE
 * @brief         Maximum size of a control packet block in bytes.
 */
#define MAX_CP_BLOCK_SIZE                    (128U)

/**
 * @def           MAX_CP_BLOCKS
 * @brief         Maximum number of control packet blocks in one transport packet.
 */
#define MAX_CP_BLOCKS                        (10U)

/**
 * @def           MAX_MTU_SIZE_WITH_DLE
 * @brief         Maximum size of a MTU (Maximum Transmission Unit) with
 *                DLE (Data Length Extension) in bytes.
 */
#define MAX_MTU_SIZE_WITH_DLE                (244U)

/**
 * @def           MAX_GATT_DATA_SIZE_WITH_DLE
 * @brief         Maximum size of a GATT (MTU + Headers) with DLE in bytes.
 */
#define MAX_GATT_DATA_SIZE_WITH_DLE          (251U)

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/
/**
 * @enum          CPTypes_E
 * @brief         Enumeration of different control packet types.
 */
typedef enum
{
   eCPT_UNKNOWN = 0x00,                      /**< Unknown CP type */
   // More CP types can be added here as needed
} CPTypes_E;

/******************************************************************************/
/*                                                                            */
/*                                 STRUCTURES                                 */
/*                                                                            */
/******************************************************************************/
/**
 * @struct        CPBlock_T
 * @brief         Structure containing information of different parameters of
 *                control packet data block.
 */
typedef struct
{
   CPTypes_E e_CPType;                       /**< Control packet data type */
   uint8_t u8_CPBlockLength;                 /**< Length of Control Packet block */
   uint8_t u8ar_CPData[MAX_CP_BLOCK_SIZE];   /**< Actual Control Packet data */
} CPBlock_T;

/**
 * @struct        CPList_T
 * @brief         Structure containing list of all CP blocks parsed from received
 *                GATT characteristic data.
 */
typedef struct
{
   CPBlock_T star_CPBlocks[MAX_CP_BLOCKS];   /**< All the individual CP blocks */
   uint8_t u8_count;                         /**< Count of total CP blocks */
} CPList_T;

/**
 * @struct        CharCtx_T
 * @brief         Structure containing information of characteristic context.
 */
typedef struct
{
   CPList_T *stpt_data;                      /**< Pointer to the data buffer */
   uint16_t u16_maxLen;                      /**< Maximum length of the data buffer */
   uint16_t u16_curLen;                      /**< Current length of valid data in the buffer */
} CharCtx_T;

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
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/

#endif //!_GATT_DB_TYPES_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
