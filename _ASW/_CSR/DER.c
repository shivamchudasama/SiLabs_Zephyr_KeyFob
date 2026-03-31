/**
 * @file          DER.c
 * @brief         Source file containing DER encoding functionality.
 *                This file implements an incomplete DER encoder which provides
 *                just enough functionality to construct a CBP certificate signing
 *                request on device, using PSA ctypto API only for key generation,
 *                SHA-1 calculation, and ECDSA signing.
 *                In general, see X.690 for reference on the encoding syntax; and see
 *                RFCs 2986, 5280, 5430, and 5758 for particular details on values and
 *                encodings to use.
 * @date          29/08/2025
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */
/*******************************************************************************
* # License
* <b>Copyright 2022 Silicon Laboratories Inc. www.silabs.com</b>
********************************************************************************
*
* SPDX-License-Identifier: Zlib
*
* The licensor of this software is Silicon Laboratories Inc.
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*
*******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/
#include "DER.h"

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           <Define name>
 * @brief         <Define details>.
 */
#define X520_DN_MAX_ATTRIBUTES (8) /**< Artificial upper limit to DN components */

#define DER_INTEGER_LEN (4) /**< Internal limit */

/*
 * OIDs are represented merely as strings prefixed with e_type and length bytes;
 * the string length is given in the 2nd byte for each.
 */

// X.509 st_ext components are under 2.5.29
#define X509_EXT_OID_PREFIX "\x06\x03\x55\x1d"
#define X509_EXT_OID(o) ((const uint8_t *)(X509_EXT_OID_PREFIX o))
#define X509_EXT_OID_SUBJECT_KEY_IDENTIFIER X509_EXT_OID("\x0e")
#define X509_EXT_OID_KEY_USAGE X509_EXT_OID("\x0f")
#define X509_EXT_OID_BASIC_CONSTRAINT X509_EXT_OID("\x13")

// X.520 DN components are under 2.5.4
#define X520_DN_OID_PREFIX "\x06\x03\x55\x04"
#define X520_DN_OID(o) ((const uint8_t *)(X520_DN_OID_PREFIX o))
#define X520_DN_OID_CN X520_DN_OID("\x03")
#define X520_DN_OID_COUNTRY X520_DN_OID("\x06")
#define X520_DN_OID_LOCALITY X520_DN_OID("\x07")
#define X520_DN_OID_STATE_OR_PROVINCE X520_DN_OID("\x08")
#define X520_DN_OID_ORGANIZATION X520_DN_OID("\x0a")
#define X520_DN_OID_ORGANIZATIONAL_UNIT X520_DN_OID("\x0b")

// PKCS#9 email address is under 1.2.840.113549.1.9
#define PKCS9_OID_PREFIX "\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x09"
#define PKCS9_OID(o) ((const uint8_t *)(PKCS9_OID_PREFIX o))
#define PKCS9_OID_EMAIL_ADDRESS PKCS9_OID("\x01")
#define PKCS9_OID_EXTENSION_REQUEST PKCS9_OID("\x0e")

// ECC algorithm identifiers are under 1.2.840.10045.2
#define ECC_ALG_OID_PREFIX "\x06\x07\x2a\x86\x48\xce\x3d\x02"
#define ECC_ALG_OID(o) ((const uint8_t *)(ECC_ALG_OID_PREFIX o))
#define ECC_ALG_OID_EC_PUBLIC_KEY ECC_ALG_OID("\x01")

// ECC named curves are under 1.2.840.10045.3.1
#define ECC_CURVE_OID_PREFIX "\x06\x08\x2a\x86\x48\xce\x3d\x03\x01"
#define ECC_CURVE_OID(o) ((const uint8_t *)(ECC_CURVE_OID_PREFIX o))
#define ECC_CURVE_OID_PRIME256V1 ECC_CURVE_OID("\x07")

// ECC signatures are under 1.2.840.10045.4.3
#define ECC_SIGNATURE_OID_PREFIX "\x06\x08\x2a\x86\x48\xce\x3d\x04\x03"
#define ECC_SIGNATURE_OID(o) ((const uint8_t *)(ECC_SIGNATURE_OID_PREFIX o))
#define ECC_SIGNATURE_OID_ECDSA_WITH_SHA256 ECC_SIGNATURE_OID("\x02")

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/
/**
 * @enum          DERVersion_E
 * @brief         <Enum details>.
 */
typedef enum
{
   eDV_VERSION_1 = 0,                        /**< Version 1 */
} DERVersion_E;

/**
 * @enum          DERType_E
 * @brief         <Enum details>.
 */
typedef enum
{
   eDT_PRIMITIVE_BOOLEAN = 0x01,
   eDT_PRIMITIVE_INTEGER = 0x02,
   eDT_PRIMITIVE_BIT_STRING = 0x03,
   eDT_PRIMITIVE_OCTET_STRING = 0x04,
   eDT_PRIMITIVE_OID = 0x06,
   eDT_PRIMITIVE_UTF8_STRING = 0x0c,
   eDT_PRIMITIVE_PRINTABLE_STRING = 0x13,
   eDT_PRIMITIVE_IA5_STRING = 0x16,
   eDT_CONSTRUCT_SEQUENCE = 0x30,
   eDT_CONSTRUCT_SET = 0x31,
   eDT_CONSTRUCT_CSR_ATTRIBUTES = 0xa0,
   eDT_PRIMITIVE_BIG_INTEGER = 0x102, // Same as eDT_PRIMITIVE_INTEGER but represented as a byte array
} DERType_E;

/******************************************************************************/
/*                                                                            */
/*                                 STRUCTURES                                 */
/*                                                                            */
/******************************************************************************/
/**
 * @struct        der_int_t
 * @brief         <Structure details>.
 */
typedef int32_t der_int_t;

/**
 * @struct        DERValue_T
 * @brief         A single DER stpt_value that gets encoded as tag-length-contents;
 *                for constructed values the contents will be recursively written out
 */
typedef struct
{
   DERType_E e_type;                         /**< Type of the DER st_value */
   union                                     /**<  */
   {
      bool b_boolean;
      der_int_t t_integer;
      struct
      {
         size_t t_len;
         uint8_t *u8pt_data;
      } st_bigInteger;
      const uint8_t *u8pt_OID;
      struct
      {
         size_t t_bitLen;
         uint8_t *u8pt_data;
      } st_bitString;
      struct
      {
         size_t t_len;
         uint8_t *u8pt_data;
      } st_octetString;
      struct
      {
         size_t t_len;
         uint8_t *u8pt_data;
      } st_UTF8String;
      struct
      {
         size_t t_len;
         uint8_t *u8pt_data;
      } st_printableString;
      struct
      {
         size_t t_len;
         uint8_t *u8pt_data;
      } st_IA5String;
      struct
      {
          size_t t_count;
          struct DERValue_T *stpt_data;
       } st_collection;
    } u_data;
} DERValue_T;

/**
 * @struct        X520DNComponent_T
 * @brief
 */
typedef struct
{
   const uint8_t *u8pt_OID;
   DERValue_T st_value;
} X520DNComponent_T;

/**
 * @struct        X520DN_T
 * @brief
 */
typedef struct
{
   size_t t_count;
   X520DNComponent_T *stpt_component;
} X520DN_T;

/**
 * @struct        DERWorkBuffer_T
 * @brief         Shared scratch storage used during CSR construction to keep
 *                the main-thread stack small.
 */
typedef struct
{
   X520DNComponent_T star_DNComponent[X520_DN_MAX_ATTRIBUTES];
   DERValue_T star_attr[X520_DN_MAX_ATTRIBUTES];
   DERValue_T star_attrPair[X520_DN_MAX_ATTRIBUTES][2];
   DERValue_T star_set[X520_DN_MAX_ATTRIBUTES];
   DERValue_T star_infoSequence[4];
} DERWorkBuffer_T;

/******************************************************************************/
/*                                                                            */
/*                                   UNIONS                                   */
/*                                                                            */
/******************************************************************************/
// Definition of all the unions
/**
 * @union         <Union name>
 * @brief         <Union details>.
 */

// Declarations of all the union variables
/**
 * @var           <Variable name>
 * @brief         <Variable details>.
 */

/******************************************************************************/
/*                                                                            */
/*                       PRIVATE FUNCTION DECLARATIONS                        */
/*                                                                            */
/******************************************************************************/
static psa_status_t st_EncodeOID(const uint8_t *u8pt_OID, uint8_t *u8pt_buff,
   size_t t_buffLen, size_t *tpt_writeLen);
static psa_status_t st_EncodeString(DERType_E e_type, size_t t_len,
   const uint8_t *u8pt_data, uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen);
static psa_status_t st_EncodeBitString(DERType_E e_type, size_t t_bitLen,
   const uint8_t *u8pt_data, uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen);
static psa_status_t st_EncodeCollection(DERType_E e_type, const DERValue_T *stpt_value,
   size_t t_valueCount, uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen);
static size_t st_IntLength(der_int_t t_lpIdx);
static psa_status_t st_EncodeHeader(DERType_E e_type, size_t length,
   uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen);

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
 * @var           sst_derWorkBuffer
 * @brief         DER work buffer structure.
 */
static DERWorkBuffer_T sst_derWorkBuffer = { 0 };
K_MUTEX_DEFINE(st_DERWorkBufferMutex);

/******************************************************************************/
/*                                                                            */
/*                             PRIVATE VARIABLES                              */
/*                                                                            */
/******************************************************************************/
/**
 * @var           <Variable name>
 * @brief         <Variable details>.
 */

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
 * @private       st_IntLength
 * @brief
 * @param[in]     t_int The integer to encode.
 * @return        The length of the DER-encoded integer.
 */
static size_t st_IntLength(der_int_t t_int)
{
   der_int_t t_absolute = abs(t_int);
   uint8_t u8_temp[DER_INTEGER_LEN];
   size_t t_size;

   for (t_size = DER_INTEGER_LEN; t_size; t_size--)
   {
      u8_temp[t_size - 1] = t_absolute & 0xff;
      t_absolute >>= 8;
   }

   for (t_size = 0; t_size < DER_INTEGER_LEN - 1; t_size++)
   {
      if (u8_temp[t_size] != 0x00 || (u8_temp[t_size + 1] & 0x80))
      {
      return DER_INTEGER_LEN - t_size;
      }
   }

   return 1;
}

/**
 * @private       st_EncodeHeader
 * @brief         All st_Encode functions work with and without buffer; without buffer they merely return
 *                the length of the would-be-constructed encoding. This is needed so that constructed values
 *                can be recursively encoded.
 * @param[in]     e_type The type of the DER element.
 * @param[in]     t_length The length of the DER element.
 * @param[out]    u8pt_buff Pointer to the output buffer.
 * @param[inout]  t_buffLen The length of the output buffer.
 * @return
 */
static psa_status_t st_EncodeHeader(DERType_E e_type, size_t t_length,
   uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen)
{
   size_t t_headerLen;

   if (t_length < 0x80)
   { // may use short form
      t_headerLen = 2;
   }
   else if (t_length < 0x100)
   { // definite long form with 2 octets
      t_headerLen = 3;
   }
   else if (t_length < 0x10000)
   { // definite long form with 3 octets
      t_headerLen = 4;
   }
   else
   { // too long for practical purposes, not supported
      return PSA_ERROR_NOT_SUPPORTED;
   }

   if (t_buffLen < t_headerLen)
   {
      return PSA_ERROR_BUFFER_TOO_SMALL;
   }

   if (u8pt_buff)
   {
      u8pt_buff[0] = e_type;
      if (t_length < 0x80)
      {
         u8pt_buff[1] = t_length;
      }
      else if (t_length < 0x100)
      {
         u8pt_buff[1] = 0x81;
         u8pt_buff[2] = t_length & 0xff;
      }
      else
      {
         u8pt_buff[1] = 0x82;
         u8pt_buff[2] = (t_length >> 8) & 0xff;
         u8pt_buff[3] = t_length & 0xff;
      }
   }

   *tpt_writeLen = t_headerLen;
   return PSA_SUCCESS;
}

/**
 * @private       st_Encode
 * @brief
 * @param[in]
 * @param[in]
 * @param[out]
 * @param[inout]
 * @return
 */
static psa_status_t st_Encode(const DERValue_T *stpt_value, uint8_t *u8pt_buff,
   size_t t_buffLen, size_t *tpt_writeLen)
{
   size_t t_len;

   switch (stpt_value->e_type)
   {
      case eDT_PRIMITIVE_BOOLEAN:
      {
         if (t_buffLen < 3)
         {
            return PSA_ERROR_BUFFER_TOO_SMALL;
         }
         if (u8pt_buff)
         {
            u8pt_buff[0] = eDT_PRIMITIVE_BOOLEAN;
            u8pt_buff[1] = 1;
            u8pt_buff[2] = stpt_value->u_data.b_boolean;
         }

         *tpt_writeLen = 3;
         return PSA_SUCCESS;
      }

      case eDT_PRIMITIVE_INTEGER:
      {
         t_len = st_IntLength(stpt_value->u_data.t_integer);
         if (t_len > DER_INTEGER_LEN)
         {
            return PSA_ERROR_NOT_SUPPORTED;
         }
         if (t_buffLen < 2 + t_len)
         {
            return PSA_ERROR_BUFFER_TOO_SMALL;
         }
         if (u8pt_buff)
         {
            size_t pos;
            u8pt_buff[0] = eDT_PRIMITIVE_INTEGER;
            u8pt_buff[1] = t_len;
            for (pos = 0; pos < t_len; pos++)
            {
               uint8_t byte = (stpt_value->u_data.t_integer >> (8 * (DER_INTEGER_LEN - 1 - pos))) & 0xff;
               u8pt_buff[2 + pos] = byte;
            }
         }
         *tpt_writeLen = 2 + t_len;
         return PSA_SUCCESS;
      }

      case eDT_PRIMITIVE_BIG_INTEGER:
      {
         t_len = stpt_value->u_data.st_bigInteger.t_len;
         if (stpt_value->u_data.st_bigInteger.u8pt_data[0] > 0x7f)
         {
            t_len++;
         }
         if (t_buffLen < 2 + t_len)
         {
            return PSA_ERROR_BUFFER_TOO_SMALL;
         }
         if (u8pt_buff)
         {
            size_t pos = 0;
            u8pt_buff[pos++] = eDT_PRIMITIVE_INTEGER;
            u8pt_buff[pos++] = t_len;
            if (stpt_value->u_data.st_bigInteger.u8pt_data[0] > 0x7f)
            {
               u8pt_buff[pos++] = 0x00;
            }
            memcpy(u8pt_buff + pos,
            stpt_value->u_data.st_bigInteger.u8pt_data,
            stpt_value->u_data.st_bigInteger.t_len);
         }
         *tpt_writeLen = 2 + t_len;
         return PSA_SUCCESS;
      }

      case eDT_PRIMITIVE_OID:
      {
         return st_EncodeOID(stpt_value->u_data.u8pt_OID, u8pt_buff, t_buffLen,
            tpt_writeLen);
      }

      case eDT_PRIMITIVE_BIT_STRING:
      {
         return st_EncodeBitString(stpt_value->e_type, stpt_value->u_data.st_bitString.t_bitLen,
            stpt_value->u_data.st_bitString.u8pt_data, u8pt_buff, t_buffLen, tpt_writeLen);
      }

      case eDT_PRIMITIVE_OCTET_STRING:
      {
         return st_EncodeString(stpt_value->e_type, stpt_value->u_data.st_octetString.t_len,
            stpt_value->u_data.st_octetString.u8pt_data, u8pt_buff, t_buffLen,
            tpt_writeLen);
      }

      case eDT_PRIMITIVE_UTF8_STRING:
      {
         return st_EncodeString(stpt_value->e_type, stpt_value->u_data.st_UTF8String.t_len,
            stpt_value->u_data.st_UTF8String.u8pt_data, u8pt_buff, t_buffLen, tpt_writeLen);
      }

      case eDT_PRIMITIVE_PRINTABLE_STRING:
      {
         return st_EncodeString(stpt_value->e_type, stpt_value->u_data.st_printableString.t_len,
            stpt_value->u_data.st_printableString.u8pt_data, u8pt_buff, t_buffLen,
            tpt_writeLen);
      }

      case eDT_PRIMITIVE_IA5_STRING:
      {
         return st_EncodeString(stpt_value->e_type, stpt_value->u_data.st_IA5String.t_len,
            stpt_value->u_data.st_IA5String.u8pt_data, u8pt_buff, t_buffLen, tpt_writeLen);
      }

      case eDT_CONSTRUCT_SEQUENCE:
      case eDT_CONSTRUCT_SET:
      case eDT_CONSTRUCT_CSR_ATTRIBUTES:
      {
         return st_EncodeCollection(stpt_value->e_type, stpt_value->u_data.st_collection.stpt_data,
            stpt_value->u_data.st_collection.t_count, u8pt_buff, t_buffLen,
            tpt_writeLen);
      }

      default:
      return PSA_ERROR_NOT_SUPPORTED;
   }
}

/**
 * @private       st_EncodeOID
 * @brief
 * @param[in]
 * @param[in]
 * @param[out]
 * @param[inout]
 * @return
 */
static psa_status_t st_EncodeOID(const uint8_t *u8pt_OID, uint8_t *u8pt_buff,
   size_t t_buffLen, size_t *tpt_writeLen)
{
   // This is ugly; but we know that it works as all OIDs we use are
   // encoded using a single octet length
   size_t t_len = 2 + u8pt_OID[1];

   if (t_buffLen < t_len)
   {
      return PSA_ERROR_BUFFER_TOO_SMALL;
   }
   if (u8pt_buff)
   {
      memcpy(u8pt_buff, u8pt_OID, t_len);
   }

   *tpt_writeLen = t_len;
   return PSA_SUCCESS;
}

/**
 * @private       st_EncodeBitString
 * @brief
 * @param[in]
 * @param[in]
 * @param[out]
 * @param[inout]
 * @return
 */
static psa_status_t st_EncodeBitString(DERType_E e_type, size_t t_bitLen,
   const uint8_t *u8pt_data, uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen)
{
   size_t t_headerLen, t_len;
   psa_status_t t_retVal;

   t_len = (t_bitLen + 7) / 8;

   t_retVal = st_EncodeHeader(e_type, 1 + t_len, NULL, t_buffLen, &t_headerLen);
   if (t_retVal != PSA_SUCCESS)
   {
      return t_retVal;
   }

   if (t_buffLen < t_headerLen + 1 + t_len)
   {
      return PSA_ERROR_BUFFER_TOO_SMALL;
   }

   if (u8pt_buff)
   {
      t_retVal = st_EncodeHeader(e_type, 1 + t_len, u8pt_buff, t_buffLen, &t_headerLen);
      if (t_retVal != PSA_SUCCESS)
      {
         return t_retVal;
      }
      u8pt_buff[t_headerLen] = t_bitLen % 8;
      memcpy(u8pt_buff + t_headerLen + 1, u8pt_data, t_len);
   }

   *tpt_writeLen = t_headerLen + 1 + t_len;
   return PSA_SUCCESS;
}

/**
 * @private       st_EncodeString
 * @brief
 * @param[in]
 * @param[in]
 * @param[out]
 * @param[inout]
 * @return
 */
static psa_status_t st_EncodeString(DERType_E e_type, size_t t_len, const uint8_t *u8pt_data,
   uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen)
{
   size_t t_headerLen;
   psa_status_t t_retVal;

   t_retVal = st_EncodeHeader(e_type, t_len, NULL, t_buffLen, &t_headerLen);
   if (t_retVal != PSA_SUCCESS)
   {
      return t_retVal;
   }

   if (t_buffLen < t_headerLen + t_len)
   {
      return PSA_ERROR_BUFFER_TOO_SMALL;
   }

   if (u8pt_buff)
   {
      t_retVal = st_EncodeHeader(e_type, t_len, u8pt_buff, t_buffLen, &t_headerLen);
      if (t_retVal != PSA_SUCCESS)
      {
         return t_retVal;
      }

      memcpy(u8pt_buff + t_headerLen, u8pt_data, t_len);
   }

   *tpt_writeLen = t_headerLen + t_len;
   return PSA_SUCCESS;
}

/**
 * @private       st_EncodeCollection
 * @brief
 * @param[in]
 * @param[in]
 * @param[out]
 * @param[inout]
 * @return
 */
static psa_status_t st_EncodeCollection(DERType_E e_type, const DERValue_T *stpt_value,
   size_t t_valueCount, uint8_t *u8pt_buff, size_t t_buffLen, size_t *tpt_writeLen)
{
   size_t t_writePosition, t_headerLen, t_lpIdx;
   psa_status_t t_retVal;

   // First, figure out the length needed for encoding the contents
   for (t_writePosition = 0, t_lpIdx = 0; t_lpIdx < t_valueCount; t_lpIdx++)
   {
      size_t t_chunk;
      t_retVal = st_Encode(&stpt_value[t_lpIdx], NULL, ~0, &t_chunk);
      if (t_retVal != PSA_SUCCESS)
      {
         return t_retVal;
      }
      t_writePosition += t_chunk;
   }

   // Check header encoding as well
   t_retVal = st_EncodeHeader(e_type, t_writePosition, NULL, t_buffLen, &t_headerLen);
   if (t_retVal != PSA_SUCCESS)
   {
      return t_retVal;
   }

   if (t_buffLen < t_headerLen + t_writePosition)
   {
      return PSA_ERROR_BUFFER_TOO_SMALL;
   }

   if (u8pt_buff)
   {
      t_retVal = st_EncodeHeader(e_type, t_writePosition, u8pt_buff, t_buffLen, &t_headerLen);
      if (t_retVal != PSA_SUCCESS)
      {
         return t_retVal;
      }

      for (t_writePosition = 0, t_lpIdx = 0; t_lpIdx < t_valueCount; t_lpIdx++)
      {
         size_t t_chunk;
         t_retVal = st_Encode(&stpt_value[t_lpIdx], u8pt_buff + t_headerLen + t_writePosition, \
            t_buffLen - t_headerLen - t_writePosition, &t_chunk);
         if (t_retVal != PSA_SUCCESS)
         {
            return t_retVal;
         }
         t_writePosition += t_chunk;
      }
   }

   *tpt_writeLen = t_headerLen + t_writePosition;
   return PSA_SUCCESS;
}

/**
 * @private       st_ConstructAndSign
 * @brief
 * @param[in]
 * @param[in]
 * @param[out]
 * @param[inout]
 * @return
 */
static psa_status_t st_ConstructAndSign(DERVersion_E e_version, const X520DN_T *stpt_DN,
   mbedtls_svc_key_id_t t_deviceKey, uint8_t *u8pt_pubKey, size_t t_pubKeyBitLen,
   uint8_t *u8pt_subjectKeyIdentifier, size_t t_subjectKeyIdentifierLen, uint8_t *u8pt_buff,
   size_t t_buffLen, size_t *tpt_writeLen, DERWorkBuffer_T *stpt_workBuffer)
{
   uint8_t u8ar_signBuff[64] = { 0 };
   size_t t_signLen = 0;
   uint8_t u8ar_sigBuff[72] = { 0 };
   size_t t_sigLen = 0;
   psa_algorithm_t t_signAlgo = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
   size_t t_tbsLen = 0;
   uint8_t u8ar_skiBuff[2 + CRYPTO_SHA_1_LEN] = { 0 };
   size_t t_skiLen = 0;
   DERValue_T *stpt_attr = stpt_workBuffer->star_attr;
   DERValue_T (*stpt_attrPair)[2] = stpt_workBuffer->star_attrPair;
   DERValue_T *stpt_set = stpt_workBuffer->star_set;
   DERValue_T st_DNSequence;
   DERValue_T *stpt_infoSequence = stpt_workBuffer->star_infoSequence;
   psa_status_t t_retVal;
   size_t t_s = 0;
   size_t t_lpIdx;

   if (t_pubKeyBitLen != 520)
   {
      return PSA_ERROR_INVALID_ARGUMENT;
   }

   if (t_subjectKeyIdentifierLen != CRYPTO_SHA_1_LEN)
   {
      return PSA_ERROR_INVALID_ARGUMENT;
   }

   if (stpt_DN->t_count > X520_DN_MAX_ATTRIBUTES)
   {
      return PSA_ERROR_INVALID_ARGUMENT;
   }

   // 1)
   // version is just an integer

   DERValue_T st_version =
   {
      .e_type = eDT_PRIMITIVE_INTEGER,
      .u_data.t_integer = e_version,
   };

   stpt_infoSequence[t_s++] = st_version;

   // 2)
   // Name in RFC 5280 is a SEQUENCE of RDNs; each RDN is a stpt_set; each
   // stpt_set is a sequence of e_type and st_value

   // First create an stpt_attr for each DN stpt_component and fill
   // the stpt_set with the st_attr. Note: does not check that
   // there are no duplicate entries
   for (t_lpIdx = 0; t_lpIdx < stpt_DN->t_count; t_lpIdx++)
   {
      stpt_attrPair[t_lpIdx][0].e_type = eDT_PRIMITIVE_OID;
      stpt_attrPair[t_lpIdx][0].u_data.u8pt_OID = stpt_DN->stpt_component[t_lpIdx].u8pt_OID;
      stpt_attrPair[t_lpIdx][1].e_type = stpt_DN->stpt_component[t_lpIdx].st_value.e_type;
      stpt_attrPair[t_lpIdx][1].u_data = stpt_DN->stpt_component[t_lpIdx].st_value.u_data;
      stpt_attr[t_lpIdx].e_type = eDT_CONSTRUCT_SEQUENCE;
      stpt_attr[t_lpIdx].u_data.st_collection.t_count = 2;
      stpt_attr[t_lpIdx].u_data.st_collection.stpt_data = stpt_attrPair[t_lpIdx];
      stpt_set[t_lpIdx].e_type = eDT_CONSTRUCT_SET;
      stpt_set[t_lpIdx].u_data.st_collection.t_count = 1;
      stpt_set[t_lpIdx].u_data.st_collection.stpt_data = &stpt_attr[t_lpIdx];
   }

   // Then create the overall sequence
   st_DNSequence.e_type = eDT_CONSTRUCT_SEQUENCE;
   st_DNSequence.u_data.st_collection.t_count = stpt_DN->t_count;
   st_DNSequence.u_data.st_collection.stpt_data = stpt_set;

   stpt_infoSequence[t_s++] = st_DNSequence;

   // 3)
   // Add the public key; ECC named curve and bit string

   DERValue_T star_algoContents[2] =
   {
      {
         .e_type = eDT_PRIMITIVE_OID,
         .u_data =
         {
            .u8pt_OID = ECC_ALG_OID_EC_PUBLIC_KEY
         }
      },
      {
         .e_type = eDT_PRIMITIVE_OID,
         .u_data =
         {
            .u8pt_OID = ECC_CURVE_OID_PRIME256V1
         }
      }
   };

   DERValue_T star_spkiContents[2] =
   {
      {
         .e_type = eDT_CONSTRUCT_SEQUENCE,
         .u_data =
         {
            .st_collection =
            {
               .t_count = 2,
               .stpt_data = star_algoContents
            }
         }
      },
      {
         .e_type = eDT_PRIMITIVE_BIT_STRING,
         .u_data =
         {
            .st_bitString =
            {
               .t_bitLen = t_pubKeyBitLen,
               .u8pt_data = u8pt_pubKey,
            }
         }
      }
   };

   DERValue_T st_spkiSequence =
   {
      .e_type = eDT_CONSTRUCT_SEQUENCE,
      .u_data =
      {
         .st_collection =
         {
            .t_count = 2,
            .stpt_data = star_spkiContents
         }
      }
   };

   stpt_infoSequence[t_s++] = st_spkiSequence;

   // 4) Add requested extensions

   // The level of complication here is just lovely. Each extension
   // is a pairing of OID and an octet string, which contains the
   // DER-encoded object instead of the plain object. Even if the
   // stpt_value would be an octet string, it still needs to be encoded
   // into a wrapping octet string ...

   // 4.1) Add CA=FALSE basic constraint
   // CA=FALSE is the default so the parameter sequence can be empty

   uint8_t u8ar_emptySeq[2] = { 0x30, 0x00 };

   DERValue_T star_ExtBasicConstraintsConsts[2] =
   {
      {
         .e_type = eDT_PRIMITIVE_OID,
         .u_data =
         {
         .u8pt_OID = X509_EXT_OID_BASIC_CONSTRAINT,
         }
      },
      {
         .e_type = eDT_PRIMITIVE_OCTET_STRING,
         .u_data =
         {
            .st_octetString =
            {
               .t_len = sizeof(u8ar_emptySeq),
               .u8pt_data = u8ar_emptySeq,
            }
         }
      }
   };

   // 4.2) Add key agreement key usage

   uint8_t u8ar_keyAgreementBitString[4] = { 0x03, 0x02, 0x03, 0x08 };

   DERValue_T star_extKeyUsageConsts[2] =
   {
      {
         .e_type = eDT_PRIMITIVE_OID,
         .u_data =
         {
            .u8pt_OID = X509_EXT_OID_KEY_USAGE,
         }
      },
      {
         .e_type = eDT_PRIMITIVE_OCTET_STRING,
         .u_data =
         {
            .st_octetString =
            {
               .t_len = sizeof(u8ar_keyAgreementBitString),
               .u8pt_data = u8ar_keyAgreementBitString,
            }
         }
      }
   };

   // 4.3) Add subject key identifier (?)

   DERValue_T st_subjectKeyIdentifier =
   {
      .e_type = eDT_PRIMITIVE_OCTET_STRING,
      .u_data =
      {
         .st_octetString =
         {
            .t_len = t_subjectKeyIdentifierLen,
            .u8pt_data = u8pt_subjectKeyIdentifier,
         }
      }
   };

   t_retVal = st_Encode(&st_subjectKeyIdentifier, u8ar_skiBuff, sizeof(u8ar_skiBuff), &t_skiLen);
   if (t_retVal != PSA_SUCCESS)
   {
      return t_retVal;
   }

   DERValue_T star_extSubjectKeyIdentifierContents[2] =
   {
      {
         .e_type = eDT_PRIMITIVE_OID,
         .u_data =
         {
            .u8pt_OID = X509_EXT_OID_SUBJECT_KEY_IDENTIFIER,
         }
      },
      {
         .e_type = eDT_PRIMITIVE_OCTET_STRING,
         .u_data =
         {
            .st_octetString =
            {
               .t_len = t_skiLen,
               .u8pt_data = u8ar_skiBuff,
            }
         }
      }
   };

   DERValue_T star_extSeqContents[4] =
   {
      {
         .e_type = eDT_CONSTRUCT_SEQUENCE,
         .u_data =
         {
            .st_collection =
            {
               .t_count = 2,
               .stpt_data = star_ExtBasicConstraintsConsts,
            }
         }
      },
      {
         .e_type = eDT_CONSTRUCT_SEQUENCE,
         .u_data =
         {
            .st_collection =
            {
               .t_count = 2,
               .stpt_data = star_extKeyUsageConsts,
            }
         }
      },
      {
         .e_type = eDT_CONSTRUCT_SEQUENCE,
         .u_data =
         {
            .st_collection =
            {
               .t_count = 2,
               .stpt_data = star_extSubjectKeyIdentifierContents,
            }
         }
      }
   };

   DERValue_T st_extSeq =
   {
      .e_type = eDT_CONSTRUCT_SEQUENCE,
      .u_data =
      {
         .st_collection =
         {
            .t_count = 3,
            .stpt_data = star_extSeqContents
         }
      }
   };

   DERValue_T star_extContents[2] =
   {
      {
         .e_type = eDT_PRIMITIVE_OID,
         .u_data =
         {
            .u8pt_OID = PKCS9_OID_EXTENSION_REQUEST,
         }
      },
      {
         .e_type = eDT_CONSTRUCT_SET,
         .u_data =
         {
            .st_collection =
            {
               .t_count = 1,
               .stpt_data = &st_extSeq,
            }
         }
      }
   };

   DERValue_T st_ext =
   {
      .e_type = eDT_CONSTRUCT_SEQUENCE,
      .u_data =
      {
         .st_collection =
         {
            .t_count = 2,
            .stpt_data = star_extContents,
         }
      }
   };

   DERValue_T st_attr =
   {
      .e_type = eDT_CONSTRUCT_CSR_ATTRIBUTES,
      .u_data =
      {
         .st_collection =
         {
            .t_count = 1,
            .stpt_data = &st_ext,
         }
      }
   };

   stpt_infoSequence[t_s++] = st_attr;

   // 5) Encode request information into temporary buffer

   DERValue_T st_infoEnvelope =
   {
      .e_type = eDT_CONSTRUCT_SEQUENCE,
      .u_data =
      {
         .st_collection =
         {
            .t_count = t_s,
            .stpt_data = stpt_infoSequence,
         }
      }
   };

   t_retVal = st_Encode(&st_infoEnvelope, u8pt_buff, t_buffLen, &t_tbsLen);
   if (t_retVal != PSA_SUCCESS)
   {
      LOG_ERR("Failed to DER-encode certificate request information");
      return t_retVal;
   }

   // 6) Self-sign the request information
   t_retVal = psa_sign_message(t_deviceKey, t_signAlgo,
      u8pt_buff, t_tbsLen, u8ar_signBuff, sizeof(u8ar_signBuff), &t_signLen);
   if (t_retVal != PSA_SUCCESS)
   {
      LOG_ERR("Failed to sign certificate request information");
      return t_retVal;
   }

   // 7) Construct DER sequence for the signature

   // No parameters for the signature algorithm

   DERValue_T st_signAlgo =
   {
      .e_type = eDT_PRIMITIVE_OID,
      .u_data =
      {
         .u8pt_OID = ECC_SIGNATURE_OID_ECDSA_WITH_SHA256,
      }
   };

   DERValue_T st_signAlgoEnvelope =
   {
      .e_type = eDT_CONSTRUCT_SEQUENCE,
      .u_data =
      {
         .st_collection =
         {
            .t_count = 1,
            .stpt_data = &st_signAlgo,
         }
      }
   };

   // Signature itself is represented as a pair of numbers (r,t_s)
   // which will yet again be encoded into a wrapping construct,
   // this time bit string

   DERValue_T star_signPair[2] =
   {
      {
         .e_type = eDT_PRIMITIVE_BIG_INTEGER,
         .u_data =
         {
            .st_bigInteger =
            {
               .t_len = t_signLen / 2,
               .u8pt_data = u8ar_signBuff,
            }
         }
      },
      {
         .e_type = eDT_PRIMITIVE_BIG_INTEGER,
         .u_data =
         {
            .st_bigInteger =
            {
               .t_len = t_signLen / 2,
               .u8pt_data = u8ar_signBuff + t_signLen / 2,
            }
         }
      }
   };

   DERValue_T star_signEnvelope =
   {
      .e_type = eDT_CONSTRUCT_SEQUENCE,
      .u_data =
      {
         .st_collection =
         {
            .t_count = 2,
            .stpt_data = star_signPair,
         }
      }
   };

   t_retVal = st_Encode(&star_signEnvelope, u8ar_sigBuff, sizeof(u8ar_sigBuff), &t_sigLen);
   if (t_retVal != PSA_SUCCESS)
   {
      return t_retVal;
   }

   DERValue_T star_signBitString =
   {
      .e_type = eDT_PRIMITIVE_BIT_STRING,
      .u_data =
      {
         .st_bitString =
         {
            .t_bitLen = 8 * t_sigLen,
            .u8pt_data = u8ar_sigBuff,
         }
      }
   };

   // 8) Construct the final request

   DERValue_T st_CSRSequence[3] =
   {
      st_infoEnvelope,
      st_signAlgoEnvelope,
      star_signBitString
   };

   DERValue_T st_CSR =
   {
      .e_type = eDT_CONSTRUCT_SEQUENCE,
      .u_data =
      {
         .st_collection =
         {
            .t_count = 3,
            .stpt_data = st_CSRSequence,
         }
      }
   };

   t_retVal = st_Encode(&st_CSR, u8pt_buff, t_buffLen, tpt_writeLen);
   if (t_retVal != PSA_SUCCESS)
   {
      LOG_ERR("Failed to construct certificate request");
      return t_retVal;
   }

   return PSA_SUCCESS;
}


/******************************************************************************/
/*                                                                            */
/*                        PUBLIC FUNCTION DEFINITIONS                         */
/*                                                                            */
/******************************************************************************/
/**
 * @public        gt_DER_EncodeCSR
 * @brief         <Function details>.
 * @param[in]     stpt_subjectName Pointer to the subject name fields.
 * @param[in]     t_subjectNameLen The number of subject name fields.
 * @param[in]     t_deviceKey The key identifier of the device key to be used.
 * @param[out]    u8pt_buff Pointer to the output buffer for the DER-encoded CSR.
 * @param[in]     t_buffLen The length of the output buffer.
 * @param[inout]  tpt_writeLen Pointer to the variable that will receive the
 *                length of the written data.
 * @return        PSA_SUCCESS on success, or an error code on failure.
 */
psa_status_t gt_DER_EncodeCSR(const SubjectNameField_T *stpt_subjectName,
   size_t t_subjectNameLen, mbedtls_svc_key_id_t t_deviceKey, uint8_t *u8pt_buff,
   size_t t_buffLen, size_t *tpt_writeLen)
{
   uint8_t u8ar_pubKey[1 + CRYPTO_EC_PUBLIC_KEY_LEN] = { 0 };
   uint8_t u8ar_pubKeyDigest[CRYPTO_SHA_1_LEN] = { 0 };
   X520DNComponent_T *stpt_DNComponent = sst_derWorkBuffer.star_DNComponent;
   X520DN_T st_DN =
   {
      t_subjectNameLen,
      stpt_DNComponent,
   };
   size_t t_pubKeyLen = 0, t_lpIdx;
   psa_status_t t_retVal = PSA_SUCCESS;
   int i_lockStatus;

   // Prepare for encoding Certificate Request Info:
   // * Construct subject name ASN.1 structures
   // * Export public key data into octet array
   // * Construct subject public key identifier

   if ((stpt_subjectName == NULL) || (u8pt_buff == NULL) || (tpt_writeLen == NULL))
   {
      return PSA_ERROR_INVALID_ARGUMENT;
   }

   if (t_subjectNameLen > X520_DN_MAX_ATTRIBUTES)
   {
      return PSA_ERROR_BUFFER_TOO_SMALL;
   }

   i_lockStatus = k_mutex_lock(&st_DERWorkBufferMutex, K_FOREVER);
   if (i_lockStatus != 0)
   {
      LOG_ERR("Failed to lock DER work buffer");
      return PSA_ERROR_GENERIC_ERROR;
   }

   memset(&sst_derWorkBuffer, 0, sizeof(sst_derWorkBuffer));

   // Limited support for DN components; add more as necessary
   for (t_lpIdx = 0; t_lpIdx < t_subjectNameLen; t_lpIdx++)
   {
      if (stpt_subjectName[t_lpIdx].t_nameLen == 1 && strncmp(stpt_subjectName[t_lpIdx].cpt_name, "C", 1) == 0)
      {
         stpt_DNComponent[t_lpIdx].u8pt_OID = X520_DN_OID_COUNTRY;
      }
      else if (stpt_subjectName[t_lpIdx].t_nameLen == 2 && strncmp(stpt_subjectName[t_lpIdx].cpt_name, "ST", 2) == 0)
      {
         stpt_DNComponent[t_lpIdx].u8pt_OID = X520_DN_OID_STATE_OR_PROVINCE;
      }
      else if (stpt_subjectName[t_lpIdx].t_nameLen == 1 && strncmp(stpt_subjectName[t_lpIdx].cpt_name, "L", 1) == 0)
      {
         stpt_DNComponent[t_lpIdx].u8pt_OID = X520_DN_OID_LOCALITY;
      }
      else if (stpt_subjectName[t_lpIdx].t_nameLen == 1 && strncmp(stpt_subjectName[t_lpIdx].cpt_name, "O", 1) == 0)
      {
         stpt_DNComponent[t_lpIdx].u8pt_OID = X520_DN_OID_ORGANIZATION;
      }
      else if (stpt_subjectName[t_lpIdx].t_nameLen == 2 && strncmp(stpt_subjectName[t_lpIdx].cpt_name, "OU", 2) == 0)
      {
         stpt_DNComponent[t_lpIdx].u8pt_OID = X520_DN_OID_ORGANIZATIONAL_UNIT;
      }
      else if (stpt_subjectName[t_lpIdx].t_nameLen == 2 && strncmp(stpt_subjectName[t_lpIdx].cpt_name, "CN", 2) == 0)
      {
         stpt_DNComponent[t_lpIdx].u8pt_OID = X520_DN_OID_CN;
      }
      else
      {
         t_retVal = PSA_ERROR_NOT_SUPPORTED;
         goto gt_DER_EncodeCSR_Exit;
      }
      stpt_DNComponent[t_lpIdx].st_value.e_type = eDT_PRIMITIVE_UTF8_STRING;
      stpt_DNComponent[t_lpIdx].st_value.u_data.st_UTF8String.t_len = stpt_subjectName[t_lpIdx].t_valueLen;
      stpt_DNComponent[t_lpIdx].st_value.u_data.st_UTF8String.u8pt_data = (uint8_t *)stpt_subjectName[t_lpIdx].cpt_value;
   }

   t_retVal = psa_export_public_key(t_deviceKey, u8ar_pubKey, sizeof(u8ar_pubKey), &t_pubKeyLen);
   if (t_retVal != PSA_SUCCESS)
   {
      LOG_ERR("Failed to export public key");
      goto gt_DER_EncodeCSR_Exit;
   }

   // Skip 0x04 header byte, calculate digest only the the key data
   t_retVal = gt_CalculateSHA1(u8ar_pubKey + 1, CRYPTO_EC_PUBLIC_KEY_LEN, u8ar_pubKeyDigest);
   if (t_retVal != PSA_SUCCESS)
   {
      LOG_ERR("Failed to calculate subject key identifier");
      goto gt_DER_EncodeCSR_Exit;
   }

   t_retVal = st_ConstructAndSign(eDV_VERSION_1, &st_DN, t_deviceKey,
      u8ar_pubKey, (8 * t_pubKeyLen), u8ar_pubKeyDigest, sizeof(u8ar_pubKeyDigest),
      u8pt_buff, t_buffLen, tpt_writeLen, &sst_derWorkBuffer);
   if (t_retVal != PSA_SUCCESS)
   {
      LOG_ERR("Failed to construct DER");
      goto gt_DER_EncodeCSR_Exit;
   }

gt_DER_EncodeCSR_Exit:
   (void)k_mutex_unlock(&st_DERWorkBufferMutex);
   return t_retVal;
}

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
