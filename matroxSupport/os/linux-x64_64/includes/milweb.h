/////////////////////////////////////////////////////////////////
//
// Filename          :  client.h
// Revision          : 10.20.0517
// Content           :  This file contains the defines necessary to use the milwebclient
//
// Copyright © Matrox Electronic Systems Ltd., 1992-2016.
// All Rights Reserved
//
/////////////////////////////////////////////////////////////////
#ifndef __MIL_WEB_CLIENT_H
#define __MIL_WEB_CLIENT_H

#include <stddef.h>

#define WEB_CLIENT 1
#define M_CLIENT_VERSION         0x1000000

#if defined(__linux__)
#define M_MIL_USE_LINUX         1
#define M_MIL_USE_WINDOWS       0
#ifdef __x86_64__
   #define M_MIL_USE_64BIT      1
#else
   #define M_MIL_USE_64BIT      0
#endif
#else
#define M_MIL_USE_LINUX         0
#define M_MIL_USE_WINDOWS       1
#if defined(_WIN64) || defined(WIN64)
   #define M_MIL_USE_64BIT      1
#else
   #define M_MIL_USE_64BIT      0
#endif
#endif
#if M_MIL_USE_LINUX && M_MIL_USE_64BIT
#define M_NULL                                           0L
#else
#define M_NULL                                           0
#endif

#if !defined(M_MIL_USE_UNICODE) && !M_MIL_USE_LINUX
   #define M_MIL_USE_UNICODE 1
#elif !defined (M_MIL_USE_UNICODE)
   #define M_MIL_USE_UNICODE 0
#endif

#if  M_MIL_USE_UNICODE
   #if defined(UNICODE)
      #define M_MIL_UNICODE_API 1
   #else
      #define M_MIL_UNICODE_API 0
   #endif
#endif

#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
   #define MIL_TEXT(quote)        L##quote
   typedef wchar_t                MIL_TEXT_CHAR;
#elif M_MIL_USE_WINDOWS || M_MIL_USE_LINUX
   #define MIL_TEXT(quote)        quote
   typedef char                   MIL_TEXT_CHAR;
#else
   #error Operating system not supported !
#endif
typedef MIL_TEXT_CHAR*               MIL_TEXT_PTR;
typedef const MIL_TEXT_CHAR*         MIL_CONST_TEXT_PTR;


#if M_MIL_USE_WINDOWS
   #define MFTYPE        _stdcall         // Exported Function type
#elif M_MIL_USE_LINUX
   #define MFTYPE                         // Exported Function type
#else
   #error Operating system not supported in Mil.h!
#endif

/************************************************************************/
/* MIL TYPE DEFINITIONS                                                 */
/************************************************************************/
/* GENERAL RELATED DEFINES */
/***************************/
#if M_MIL_USE_WINDOWS
   #if M_MIL_USE_CE
      typedef  long           MIL_INT;
      typedef  unsigned long  MIL_UINT;
      #define  MIL_UINT_MIN   0
      #define  MIL_UINT_MAX   4294967295UL
      #define  MIL_INT_MIN    (-2147483647L-1L)
      #define  MIL_INT_MAX    2147483647L
   #else
      #if M_MIL_USE_64BIT
#if defined(_MSC_VER) && (_MSC_VER < 1310)
         typedef  __int64              MIL_INT;
         typedef  unsigned __int64     MIL_UINT;
#else
         typedef  long long            MIL_INT;
         typedef  unsigned long long   MIL_UINT;
#endif

         #define  MIL_UINT_MIN      0ULL
         #define  MIL_UINT_MAX      18446744073709551615ULL
         #define  MIL_INT_MIN       -9223372036854775808LL
         #define  MIL_INT_MAX       9223372036854775807LL
      #else
         #if (_MSC_VER < 1400) // Visual Studio 2003
            typedef  long           MIL_INT;
            typedef  unsigned long  MIL_UINT;
         #else                 // Visual Studio 2005
            // _W64 Lets you mark variables, such that when you compile
            // with /Wp64 the compiler will report any warnings that would
            // be reported if you were compiling with a 64-bit compiler.
            typedef _W64          long MIL_INT;
            typedef _W64 unsigned long MIL_UINT;
         #endif
         #define  MIL_UINT_MIN   0UL
         #define  MIL_UINT_MAX   4294967295UL
         #define  MIL_INT_MIN    (-2147483647L-1L)
         #define  MIL_INT_MAX    2147483647L
      #endif
   #endif
   typedef                long         MIL_INT32;
   typedef const          long         MIL_CINT32;
   typedef       unsigned long         MIL_UINT32;
   typedef const unsigned long         MIL_CUINT32;
   #define  MIL_UINT32_MIN             0UL
   #define  MIL_UINT32_MAX             4294967295UL
   #define  MIL_INT32_MIN              (-2147483647L-1L)
   #define  MIL_INT32_MAX              2147483647L
   #define  MIL_UINT32_MIN_FLT         0UL               //Min precise value in 32-bit floating point.
   #define  MIL_UINT32_MAX_FLT         0xFFFFFF00UL      //Max precise value in 32-bit floating point.
   #define  MIL_INT32_MIN_FLT          (-2147483647L-1L) //Min precise value in 32-bit floating point.
   #define  MIL_INT32_MAX_FLT          0x7FFFFF80L       //Max precise value in 32-bit floating point.

#if defined(_MSC_VER) && (_MSC_VER < 1310)
   typedef                __int64      MIL_INT64;
   typedef const          __int64      MIL_CINT64;
   typedef       unsigned __int64      MIL_UINT64;
   typedef const unsigned __int64      MIL_CUINT64;
#else
   typedef                long long    MIL_INT64;
   typedef const          long long    MIL_CINT64;
   typedef       unsigned long long    MIL_UINT64;
   typedef const unsigned long long    MIL_CUINT64;
#endif
   #define  MIL_UINT64_MIN             0ULL
   #define  MIL_UINT64_MAX             18446744073709551615ULL
   #define  MIL_INT64_MIN              -9223372036854775808LL
   #define  MIL_INT64_MAX              9223372036854775807LL
   #define  MIL_UINT64_MIN_DBL         0ULL                    //Min precise value in 64-bit floating point.
   #define  MIL_UINT64_MAX_DBL         0xFFFFFFFFFFFFF800ULL   //Max precise value in 64-bit floating point.
   #define  MIL_INT64_MIN_DBL          (-9223372036854775807LL - 1LL)  //Min precise value in 64-bit floating point.
   #define  MIL_INT64_MAX_DBL          0x7FFFFFFFFFFFFC00LL    //Max precise value in 64-bit floating point.

   typedef                double       MIL_DOUBLE;
   typedef                float        MIL_FLOAT;
   typedef                char         MIL_INT8;
   typedef const          char         MIL_CINT8;
   typedef       unsigned char         MIL_UINT8;
   typedef const unsigned char         MIL_CUINT8;
   typedef                short        MIL_INT16;
   typedef const          short        MIL_CINT16;
   typedef       unsigned short        MIL_UINT16;
   typedef const unsigned short        MIL_CUINT16;
   typedef MIL_INT32                   MIL_BOOL;
   typedef const MIL_INT32             MIL_CBOOL;

   #define  MIL_UINT8_MIN              0UL
   #define  MIL_UINT8_MAX              255UL
   #define  MIL_INT8_MIN               -128L
   #define  MIL_INT8_MAX               127L
   #define  MIL_UINT16_MIN             0UL
   #define  MIL_UINT16_MAX             65535UL
   #define  MIL_INT16_MIN              -32768L
   #define  MIL_INT16_MAX              32767L
   #define  MIL_DOUBLE_MIN             DBL_MIN
   #define  MIL_DOUBLE_MAX             DBL_MAX
   #define  MIL_FLOAT_MIN              FLT_MIN
   #define  MIL_FLOAT_MAX              FLT_MAX
   #define  MIL_BOOL_MIN               0UL
   #define  MIL_BOOL_MAX               1UL

#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
   typedef       wchar_t               MIL_WCHAR;
#else
   typedef       unsigned short        MIL_WCHAR;
#endif

#elif M_MIL_USE_LINUX
   typedef               long          MIL_INT;
   typedef      unsigned long          MIL_UINT;

   #if M_MIL_USE_64BIT
   typedef                int          MIL_INT32;
   typedef const          int          MIL_CINT32;
   typedef       unsigned int          MIL_UINT32;
   typedef const unsigned int          MIL_CUINT32;

   #define  MIL_UINT_MIN               MIL_UINT64_MIN
   #define  MIL_UINT_MAX               MIL_UINT64_MAX
   #define  MIL_INT_MIN                MIL_INT64_MIN
   #define  MIL_INT_MAX                MIL_INT64_MAX
   #else // M_MIL_USE_64BIT
   typedef                long         MIL_INT32;
   typedef const          long         MIL_CINT32;
   typedef       unsigned long         MIL_UINT32;
   typedef const unsigned long         MIL_CUINT32;

   #define  MIL_UINT_MIN               MIL_UINT32_MIN
   #define  MIL_UINT_MAX               MIL_UINT32_MAX
   #define  MIL_INT_MIN                MIL_INT32_MIN
   #define  MIL_INT_MAX                MIL_INT32_MAX
   #endif

   #define  MIL_UINT32_MIN             0
   #define  MIL_UINT32_MAX             4294967295U
   #define  MIL_INT32_MIN              (-MIL_INT32_MAX - 1) // -2147483648L does not yield the right value
   #define  MIL_INT32_MAX              2147483647
   #define  MIL_UINT32_MIN_FLT         0U                //Min precise value in 32-bit floating point.
   #define  MIL_UINT32_MAX_FLT         0xFFFFFF00U       //Max precise value in 32-bit floating point.
   #define  MIL_INT32_MIN_FLT          (-2147483647-1)   //Min precise value in 32-bit floating point.
   #define  MIL_INT32_MAX_FLT          0x7FFFFF80       //Max precise value in 32-bit floating point.

   #if M_MIL_USE_64BIT
      typedef                long       MIL_INT64;
      typedef const          long       MIL_CINT64;
      typedef       unsigned long       MIL_UINT64;
      typedef const unsigned long       MIL_CUINT64;
   #else
      typedef                long long MIL_INT64;
      typedef const          long long MIL_CINT64;
      typedef       unsigned long long MIL_UINT64;
      typedef const unsigned long long MIL_CUINT64;
   #endif
   #define  MIL_UINT64_MIN             0ULL
   #define  MIL_UINT64_MAX             18446744073709551615ULL
   #define  MIL_INT64_MAX              9223372036854775807LL
   #define  MIL_INT64_MIN              (-MIL_INT64_MAX - 1LL) // Using -9223372036854775808LL directly causes weird warnings.
   #define  MIL_UINT64_MIN_DBL         0ULL                    //Min precise value in 64-bit floating point.
   #define  MIL_UINT64_MAX_DBL         0xFFFFFFFFFFFFF800ULL   //Max precise value in 64-bit floating point.
   #define  MIL_INT64_MIN_DBL          (-9223372036854775807LL - 1LL)  //Min precise value in 64-bit floating point.
   #define  MIL_INT64_MAX_DBL          0x7FFFFFFFFFFFFC00LL    //Max precise value in 64-bit floating point.

   typedef                double       MIL_DOUBLE;
   typedef                float        MIL_FLOAT;
   typedef                char         MIL_INT8;
   typedef const          char         MIL_CINT8;
   typedef       unsigned char         MIL_UINT8;
   typedef const unsigned char         MIL_CUINT8;
   typedef                short        MIL_INT16;
   typedef const          short        MIL_CINT16;
   typedef       unsigned short        MIL_UINT16;
   typedef const unsigned short        MIL_CUINT16;
   typedef MIL_INT32                   MIL_BOOL;
   typedef const MIL_INT32             MIL_CBOOL;

   #define  MIL_UINT8_MIN              0UL
   #define  MIL_UINT8_MAX              255UL
   #define  MIL_INT8_MIN               -128L
   #define  MIL_INT8_MAX               127L
   #define  MIL_UINT16_MIN             0UL
   #define  MIL_UINT16_MAX             65535UL
   #define  MIL_INT16_MIN              -32768L
   #define  MIL_INT16_MAX              32767L
   #define  MIL_DOUBLE_MIN             DBL_MIN
   #define  MIL_DOUBLE_MAX             DBL_MAX
   #define  MIL_FLOAT_MIN              FLT_MIN
   #define  MIL_FLOAT_MAX              FLT_MAX
   #define  MIL_BOOL_MIN               0UL
   #define  MIL_BOOL_MAX               1UL

   typedef       unsigned short        MIL_WCHAR;

#else
   #error Operating system not supported!
#endif

typedef MIL_UINT64               MIL_DATA_PTR;

typedef MIL_DATA_PTR             MIL_PHYS_DATA_PTR;
typedef void*                    MIL_HOST_DATA_PTR;
typedef const void*              MIL_CONST_HOST_DATA_PTR;

typedef MIL_UINT                 MIL_ADDR;   // this type is used to cast a pointer to an integer type for arithmetic conversion
                                             // for example void *NewPtr = (void*)((MIL_ADDR)OldPtr + Offset);

typedef unsigned char            MIL_BYTE;

typedef MIL_UINT64               MIL_MTXDMA_HANDLE;

#if M_MIL_USE_64BIT
#define M_MIL_USE_INT64_ID 1
#endif

#if M_MIL_USE_INT64_ID
   typedef  MIL_INT64  MIL_ID;
#else
   typedef  MIL_INT32  MIL_ID;
#endif

#if M_MIL_USE_LINUX && M_MIL_USE_64BIT
   #define MAKE_INT64(I)        (I ## L)
   #define MAKE_UINT64(I)       (I ## LU)
#elif M_MIL_USE_LINUX || __GNUC__
   #define MAKE_INT64(I)        (I ## LL)
   #define MAKE_UINT64(I)       (I ## LLU)
#elif M_MIL_USE_WINDOWS
   #define MAKE_INT64(I)        (I##I64)
   #define MAKE_UINT64(I)       (I##Ui64)
#else
   #define MAKE_INT64(I)        (I)
   #define MAKE_UINT64(I)       (I)
#endif

#if !M_MIL_USE_64BIT
#define M_PTR_TO_DOUBLE(ptr)            ((double) MPtrToInt((void*)(ptr)))
#define M_STRING_TO_DOUBLE(ptr)         M_PTR_TO_DOUBLE((ptr))
#else
#define M_PTR_TO_DOUBLE(ptr)            (MIL_INT64)(ptr)
#define M_STRING_TO_DOUBLE(ptr)         M_PTR_TO_DOUBLE(ptr)
#endif //!M_MIL_USE_64BIT
#define M_DOUBLE_TO_PTR(val)            ((void *)((MIL_UINT)val))
#define M_PTR_TO_MIL_INT(val)           ((MIL_INT)((MIL_UINT)val))
#define M_CLIENT_ASCII_MODE                           MAKE_INT64(0x0001000000000000)
#define M_CLIENT_ASCII_MODE_BIT_SET(X)                ((((X) & M_CLIENT_ASCII_MODE) == M_CLIENT_ASCII_MODE) ? true : false)
#define M_STRIP_CLIENT_ASCII_MODE_BIT(X)              ((X) & ~M_CLIENT_ASCII_MODE)

#define M_STRING_SIZE                                 MAKE_INT64(0x0000050000000000)
#define M_OBJ_HOOK_RANGE_START                                   0x000000800L
#define M_INVALID                                                         -1
#define M_DEFAULT                                                 0x10000000L
#define M_UNHOOK                                                  0x04000000L
#define M_NULL_ERROR                                              0L
#define M_NO_ERROR                                                0L

#define M_NO_TIMEOUT                                              0x00000800
#define M_BUFFER_TOO_SMALL                                                 1
#define M_SUCCESS                                                 0x00000000L // Already defined in milreg.h, milcolor.h

#define M_CURRENT                                                 0x00000002L
#define M_CURRENT_FCT                                             0x00030000L
#define M_CURRENT_SUB_NB                                          0x00000004L
#define M_CURRENT_SUB                                             0x00050000L
#define M_CURRENT_SUB_1                                           0x00050000L
#define M_CURRENT_SUB_2                                           0x00060000L
#define M_CURRENT_SUB_3                                           0x00070000L
#define M_GLOBAL                                                  0x00000008L
#define M_GLOBAL_FCT                                              0x00090000L
#define M_GLOBAL_SUB_NB                                           0x000A0000L
#define M_GLOBAL_SUB                                              0x000B0000L
#define M_GLOBAL_SUB_1                                            0x000B0000L
#define M_GLOBAL_SUB_2                                            0x000C0000L
#define M_GLOBAL_SUB_3                                            0x000D0000L
#define M_PARAM_NB                                                0x00140000L
#define M_BUFFER_ID                                               0x00160000L
#define M_REGION_OFFSET_X                                         0x00410000L
#define M_REGION_OFFSET_Y                                         0x00420000L
#define M_REGION_SIZE_X                                           0x00430000L
#define M_REGION_SIZE_Y                                           0x00480000L
#define M_OBJECT_ID                                               0x001B0000L
#define M_PARAM_VALUE                                             0x08000000L
#define M_EXTENDED_PARAM_TYPE                                     0x10000000L
#define M_PARAM_ATTRIBUTES                                        0x04000000L
#define M_PARAM_SIZE                                              0x01000000L
#if (M_MIL_USE_UNICODE && !M_MIL_UNICODE_API && !M_COMPILING_MILDLL)
#define M_MESSAGE                                     (0x20000000L|M_CLIENT_ERROR_ASCII_MODE)
#define M_PARAM_TYPE_INFO                             (0x02000000L | M_CLIENT_ASCII_MODE)
#else
#define M_MESSAGE                                                 0x20000000L
#define M_PARAM_TYPE_INFO                                         0x02000000L
#endif

#define M_ERROR                                                   0x40000000L
#define M_ERROR_CURRENT                                   (M_ERROR|M_CURRENT)
#define M_CONNECTING                                                       1L
#define M_DISCONNECT                                                       2L
#define M_CONNECT                                                          3L
#define M_TIMEOUT                                                       2077L
#define M_UPDATE_WEB                                                    3187L
#define M_UPDATE_END                                M_OBJ_HOOK_RANGE_START+8L
#define M_OBJECT_FREE                                             0x00010000L
#define M_OBJECT_PUBLISH_WEB                                              34L
#define M_COMPONENT_ADD                                           0x00040000
#define M_COMPONENT_REMOVE                         M_OBJ_HOOK_RANGE_START+10L
#define M_GET_END                                                         32L
#define M_READ_END                                                        11L

#define M_INTERNAL_FORMAT                                          0x00003F00L
#define M_INTERNAL_FORMAT_SHIFT                                    8L
#define M_INTERNAL_COMPLETE_FORMAT                                 0x7FFFFF80L
#define M_ANY_INTERNAL_FORMAT                                      (0   << M_INTERNAL_FORMAT_SHIFT)
#define M_BGRX32                                                       (17  << M_INTERNAL_FORMAT_SHIFT)   // Force 32 bits pixels in color BGRX  8.8.8.8  format
#define M_BGR32                                                        M_BGRX32

#define M_APP_INQUIRE_SYS_START                                        15000L
#define M_CLOSE_CONNECTION                     (M_APP_INQUIRE_SYS_START+504L)
#define M_WEB_PUBLISHED_FORMAT                                          3206L

// Inquires
#define M_WEB_PUBLISH                                  14L
#define M_WEB_PUBLISHED_LIST                             4
#define M_WEB_PUBLISHED_LIST_SIZE                        5
#if (M_MIL_USE_UNICODE && !M_MIL_UNICODE_API)
#define M_WEB_PUBLISHED_NAME                    (6 | M_CLIENT_ASCII_MODE)
#else
#define M_WEB_PUBLISHED_NAME                    6
#endif
#define M_TYPE                                        1008L
#define M_SIZE_X                                      1536L
#define M_SIZE_Y                                      1537L
#define M_SIZE_BYTE                                   5061L
#define M_MESSAGE_LENGTH                                16L
#define M_INTERACTIVE                                M_NULL

// Object Type
#define M_APPLICATION                                 0x00000200L
#define M_DISPLAY                                     0x00200000L
#define M_LUT                                         0x00040000L
#define M_KERNEL                                      0x00400000L
#define M_EVENT                                       0x00000080L
#define M_STRUCT_ELEMENT                              0x08000000L
#define M_ARRAY                                       0x00000040L
#define M_GROUP                                       MAKE_INT64(0x0000400000000000)
#define M_IMAGE                                       0x00000004L
#define M_MODIFIED_BUFFER                             0x40000000L
#define M_BUFFER_ID                                   0x00160000L
#define M_OBJECT_ID                                   0x001B0000L
#define M_GROUP_ID                                            18L
#define M_MESSAGE_MAILBOX                             MAKE_INT64(0x0000800000000000)
#define M_FUNC_INQUIRE_STRING_START                   47
#if (M_MIL_USE_UNICODE && !M_MIL_UNICODE_API && !M_COMPILING_MILDLL)
#define M_ASSOCIATED_NAME                       ((M_FUNC_INQUIRE_STRING_START+0)|M_CLIENT_ASCII_MODE) //47
#else
#define M_ASSOCIATED_NAME                       (M_FUNC_INQUIRE_STRING_START+0)
#endif
#define M_OBJECT_NAME                              M_ASSOCIATED_NAME
#define M_ASSOCIATED_NAME_SIZE                     (M_STRING_SIZE + M_ASSOCIATED_NAME)
#define M_OBJECT_NAME_SIZE                         M_ASSOCIATED_NAME_SIZE
#define M_OBJECT_TYPE                                         136
#define M_COMPONENT_COUNT                                      17L
#define M_WEB_CLIENT_INDEX                                    219L
#define M_READ_WRITE                                    0x00000010L
#define M_READ_ONLY                                     0x00000020L
#define M_NO                                                     0L
#define M_COMPONENT_ID_LIST                           0x00100000
#define M_ARRAY_ID_MASK                               0x000FFFFF
#define M_ARRAY_ID_SIZE(N)                            (N & M_ARRAY_ID_MASK)
#define M_EXTRACT_ARRAY_ID_SIZE(N)                    ((MIL_INT)(N & M_ARRAY_ID_MASK))

#define M_HOST_ADDRESS                                   0x00010000L
#define M_IMAGE_HOST_ADDRESS                             0x00010000L
// DataType
#define M_SIGN                                                 1014L
#define M_SIZE_BAND                                            1005L
#define M_UNSIGNED                                       0x00000000L
#define M_SIGNED                                         0x08000000L
#define M_FLOAT                             (0x40000000L | M_SIGNED)
#define M_USER_DATA_PTR                                   0x00000001

#define M_MESSAGE_PTR                                            101

#define M_MOUSE_LEFT_BUTTON_DOWN                                 56L
#define M_MOUSE_RIGHT_BUTTON_DOWN                                57L
#define M_MOUSE_LEFT_BUTTON_UP                                   58L
#define M_MOUSE_RIGHT_BUTTON_UP                                  59L
#define M_MOUSE_MOVE                                             64L
#define M_MOUSE_WHEEL                                            65L
#define M_MOUSE_MIDDLE_BUTTON_DOWN                               66L
#define M_MOUSE_MIDDLE_BUTTON_UP                                 67L
#define M_KEY_DOWN                                               68L
#define M_KEY_UP                                                 69L

#define M_MOUSE_LEFT_BUTTON                               0x00080000
#define M_MOUSE_MIDDLE_BUTTON                             0x00100000
#define M_MOUSE_RIGHT_BUTTON                              0x00200000

#define M_MOUSE_POSITION_X                                         1L
#define M_MOUSE_POSITION_Y                                         2L
#define M_ANNOTATIONS_DC                                           3L
#define M_COMBINATION_KEYS                                         7L
#define M_EVENT_VALUE                                              8L

#define M_MOUSE_WHEEL_VALUE                              M_EVENT_VALUE
#define M_KEY_VALUE                                      M_EVENT_VALUE


#define M_FRAMES_PER_SECOND_DEFAULT                               10

#define M_ENABLE                                               -9997L
#define M_DISABLE                                              -9999L
#define M_NOW                                                     29L

#define M_PRINT_DISABLE                                            0L
#define M_PRINT_ENABLE                                             1L

#define M_FRAME_RATE                                            6002L

#define M_PIXEL_FORMAT                                          3032L //M_LOCAL_DISPLAY_CONTROL
#define M_DATA_FORMAT                                           1041L
#define M_PITCH                                            0x20000000L
#define M_PITCH_BYTE                                      0x08000000L
#define M_INTERNAL_FORMAT_SHIFT                                    8L
#define M_MONO8                           (2   << M_INTERNAL_FORMAT_SHIFT)   // Force  8 bits pixels in monochrome format
#define M_RGBX32                          (9   << M_INTERNAL_FORMAT_SHIFT)   // Force 32 bits pixels in color RGBX  8.8.8.8  format
#define M_RGB32                                             M_RGBX32

#define WEB_TIMEOUT                                             100
#define WEB_MAX_LOOP_WAIT                                        20

typedef MIL_INT (MFTYPE* MIL_HOOK_FUNCTION_PTR)(MIL_INT HookType,
                                                MIL_ID EventId,
                                                void* UserData);
#ifdef __cplusplus
extern "C"
{
#endif
#if M_MIL_USE_UNICODE
void MFTYPE MilWebMappOpenConnectionW(MIL_CONST_TEXT_PTR ConnectionDescriptor, MIL_INT64 InitFlag, MIL_INT64 ControlFlag, MIL_ID* RemoteContextAppIdPtr);
void MFTYPE MilWebMappOpenConnectionA(const char* ConnectionDescriptor, MIL_INT64 InitFlag, MIL_INT64 ControlFlag, MIL_ID* RemoteContextAppIdPtr);
#if M_MIL_UNICODE_API
#define MilWebMappOpenConnection MilWebMappOpenConnectionW
#else
#define MilWebMappOpenConnection MilWebMappOpenConnectionA
#endif
#else
void MFTYPE MilWebMappOpenConnection(MIL_CONST_TEXT_PTR ConnectionDescriptor, MIL_INT64 InitFlag, MIL_INT64 ControlFlag, MIL_ID* RemoteContextAppIdPtr);
#endif
void MFTYPE MilWebMappCloseConnection(MIL_ID AppId);
MIL_INT MFTYPE MilWebMappInquireConnection(MIL_ID ContextAppId, MIL_INT64 InquireType, MIL_INT64 ControlFlag, MIL_INT64 ExtraFlag, void* UserVarPtr);
MIL_INT MFTYPE MilWebMappInquire(MIL_ID AppId, MIL_INT64 InquireType, void* ResultPtr);
void MFTYPE MilWebMappControl(MIL_ID ContextAppId, MIL_INT64 ControlType, MIL_INT ControlFlag);
void MFTYPE MilWebMappHookFunction(MIL_ID AppId, MIL_INT HookType, MIL_HOOK_FUNCTION_PTR HookHandlerPtr, void* UserDataPtr);
MIL_INT MFTYPE MilWebMappGetHookInfo(MIL_ID AppId, MIL_ID EventId, MIL_INT64 InfoType, void* UserPtr);

MIL_INT MFTYPE MilWebMdispInquire(MIL_ID DisplayId, MIL_INT64 InquireType, void* ResultPtr);
void MFTYPE MilWebMdispControl(MIL_ID DisplayId, MIL_INT64 ControlType, MIL_DOUBLE ControlFlag);
void MFTYPE  MilWebMdispMessage(  MIL_ID  DisplayId, MIL_INT EventType, MIL_INT MousePositionX,MIL_INT MousePositionY, MIL_INT EventValue, MIL_INT CombinationKeys, MIL_INT UserValue);
void MFTYPE MilWebMdispHookFunction(MIL_ID ObjectId, MIL_INT HookType, MIL_HOOK_FUNCTION_PTR HookHandler, void *UserDataPtr);
MIL_INT MFTYPE MilWebMdispGetHookInfo(MIL_ID EventId, MIL_INT64 InfoType, void* UserVarPtr);
void MFTYPE MilWebMdispZoom(MIL_ID DisplayId, MIL_DOUBLE XFactor, MIL_DOUBLE YFactor);

MIL_INT MFTYPE MilWebMbufInquire(MIL_ID BufId, MIL_INT64 InquireType, void* ResultPtr);
void MFTYPE MilWebMbufControl(MIL_ID BufId, MIL_INT64 ControlType, MIL_DOUBLE ControlFlag);
MIL_INT MFTYPE MilWebMbufGetHookInfo(MIL_ID EventId,  MIL_INT64 InfoType, void* UserPtr);
void MFTYPE MilWebMbufGet(MIL_ID SrcBufId, void* BufferPtr);

MIL_INT MFTYPE MilWebMobjInquire(MIL_ID ObjectId, MIL_INT64 InquireType, void* ResultPtr);
void MFTYPE MilWebMobjControl(MIL_ID ObjId, MIL_INT64 ControlType, MIL_DOUBLE ControlFlag);
void MFTYPE MilWebMobjHookFunction(MIL_ID ObjectId, MIL_INT HookType, MIL_HOOK_FUNCTION_PTR HookHandler, void *UserDataPtr);
MIL_INT MFTYPE MilWebMobjGetHookInfo(MIL_ID EventId, MIL_INT64 InfoType, void* UserVarPtr);


MIL_INT64 MFTYPE MilWebMobjMessageRead(MIL_ID MessageId, void* MessagePtr, MIL_INT64 MessageInSize, MIL_INT64 *MessageOutSizePtr, MIL_INT64 *MessageTagPtr, MIL_INT64 *StatusPtr, MIL_INT64  OperationFlag);
void MFTYPE MilWebMobjMessageWrite(MIL_ID MessageId, const void* MessagePtr, MIL_INT64 MessageSize, MIL_INT64 MessageTag, MIL_INT64  OperationFlag);

MIL_UINT MFTYPE MPtrToInt(void *pPtr);
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace MilWeb
   {
#if M_MIL_USE_UNICODE
#if M_MIL_UNICODE_API
      inline void MappOpenConnection(MIL_CONST_TEXT_PTR ConnectionDescriptor, MIL_INT64 InitFlag, MIL_INT64 ControlFlag, MIL_ID* RemoteContextAppIdPtr)
         {
         MilWebMappOpenConnectionW(ConnectionDescriptor, InitFlag, ControlFlag, RemoteContextAppIdPtr);
         }
#else
      inline void MappOpenConnection(const char* ConnectionDescriptor, MIL_INT64 InitFlag, MIL_INT64 ControlFlag, MIL_ID* RemoteContextAppIdPtr)
         {
         MilWebMappOpenConnectionA(ConnectionDescriptor, InitFlag, ControlFlag, RemoteContextAppIdPtr);
         }
#endif
#else
      inline void MappOpenConnection(MIL_CONST_TEXT_PTR ConnectionDescriptor, MIL_INT64 InitFlag, MIL_INT64 ControlFlag, MIL_ID* RemoteContextAppIdPtr)
         {
         MilWebMappOpenConnection(ConnectionDescriptor, InitFlag, ControlFlag, RemoteContextAppIdPtr);
         }
#endif
      inline void  MappCloseConnection(MIL_ID AppId)
         {
         MilWebMappCloseConnection(AppId);
         }

      inline MIL_INT MappInquireConnection(MIL_ID ContextAppId, MIL_INT64 InquireType, MIL_INT64 ControlFlag, MIL_INT64 ExtraFlag, void* UserVarPtr)
         {
         return MilWebMappInquireConnection(ContextAppId, InquireType, ControlFlag, ExtraFlag, UserVarPtr);
         }

      inline MIL_INT MappInquire(MIL_ID AppId, MIL_INT64 InquireType, void* ResultPtr)
         {
         return MilWebMappInquire(AppId, InquireType, ResultPtr);
         }

      inline void MappControl(MIL_ID ContextAppId, MIL_INT64 ControlType, MIL_INT ControlFlag)
         {
         MilWebMappControl(ContextAppId, ControlType, ControlFlag);
         }

      inline void MappHookFunction(MIL_ID AppId, MIL_INT HookType, MIL_HOOK_FUNCTION_PTR HookHandlerPtr, void* UserDataPtr)
         {
         MilWebMappHookFunction(AppId, HookType, HookHandlerPtr, UserDataPtr);
         }

      inline MIL_INT MappGetHookInfo(MIL_ID AppId, MIL_ID EventId, MIL_INT64 InfoType, void* UserVarPtr)
         {
         return MilWebMappGetHookInfo(AppId,EventId, InfoType, UserVarPtr);
         }

      inline MIL_INT MdispInquire(MIL_ID DisplayId, MIL_INT64 InquireType, void* ResultPtr)
         {
         return MilWebMdispInquire(DisplayId, InquireType, ResultPtr);
         }

      inline void MdispControl(MIL_ID DisplayId, MIL_INT64 ControlType, MIL_DOUBLE ControlFlag)
         {
         MilWebMdispControl(DisplayId, ControlType, ControlFlag);
         }

      inline void MdispMessage(  MIL_ID  DisplayId, MIL_INT EventType, MIL_INT MousePositionX,MIL_INT MousePositionY, MIL_INT EventValue, MIL_INT CombinationKeys, MIL_INT UserValue)
         {
         MilWebMdispMessage(DisplayId, EventType, MousePositionX, MousePositionY, EventValue, CombinationKeys, UserValue);
         }

      inline void MdispHookFunction(MIL_ID ObjectId, MIL_INT HookType, MIL_HOOK_FUNCTION_PTR HookHandler, void *UserDataPtr)
         {
         MilWebMdispHookFunction(ObjectId, HookType, HookHandler, UserDataPtr);
         }

      inline MIL_INT MdispGetHookInfo(MIL_ID EventId, MIL_INT64 InfoType, void* UserVarPtr)
         {
         return MilWebMdispGetHookInfo(EventId, InfoType, UserVarPtr);
         }

      inline void MdispZoom(MIL_ID DisplayId, MIL_DOUBLE XFactor, MIL_DOUBLE YFactor)
         {
         MilWebMdispZoom(DisplayId, XFactor, YFactor);
         }

      inline MIL_INT MbufInquire(MIL_ID BufId, MIL_INT64 InquireType, void* ResultPtr)
         {
         return  MilWebMbufInquire(BufId, InquireType, ResultPtr);
         }

      inline MIL_INT MbufGetHookInfo(MIL_ID EventId,  MIL_INT64 InfoType, void* UserPtr)
         {
         return MilWebMbufGetHookInfo(EventId,  InfoType, UserPtr);
         }

      inline void MbufGetWeb(MIL_ID SrcBufId, void* BufferPtr)
         {
         MilWebMbufGet(SrcBufId, BufferPtr);
         }

      inline void MbufControl(MIL_ID BufId, MIL_INT64 ControlType, MIL_DOUBLE ControlFlag)
         {
         MilWebMbufControl(BufId, ControlType, ControlFlag);
         }

      inline MIL_INT MobjInquire(MIL_ID ObjId, MIL_INT64 InquireType, void* ResultPtr)
         {
         return MilWebMobjInquire(ObjId, InquireType, ResultPtr);
         }

      inline void MobjControl(MIL_ID ObjectId, MIL_INT64 ControlType, MIL_DOUBLE ControlFlag)
         {
         MilWebMobjControl(ObjectId, ControlType, ControlFlag);
         }

      inline void MobjHookFunction(MIL_ID ObjectId, MIL_INT HookType, MIL_HOOK_FUNCTION_PTR HookHandler, void *UserDataPtr)
         {
         MilWebMobjHookFunction(ObjectId, HookType, HookHandler, UserDataPtr);
         }

      inline MIL_INT MobjGetHookInfo(MIL_ID EventId, MIL_INT64 InfoType, void* UserVarPtr)
         {
         return MilWebMobjGetHookInfo(EventId, InfoType, UserVarPtr);
         }


      inline MIL_INT64 MobjMessageRead(MIL_ID MessageId, void* MessagePtr, MIL_INT64 MessageInSize, MIL_INT64 *MessageOutSizePtr, MIL_INT64 *MessageTagPtr, MIL_INT64 *StatusPtr, MIL_INT64  OperationFlag)
         {
         return MilWebMobjMessageRead(MessageId, MessagePtr, MessageInSize, MessageOutSizePtr, MessageTagPtr, StatusPtr, OperationFlag);
         }

      inline void MobjMessageWrite(MIL_ID MessageId, const void* MessagePtr, MIL_INT64 MessageSize, MIL_INT64 MessageTag, MIL_INT64  OperationFlag)
         {
         MilWebMobjMessageWrite(MessageId, MessagePtr, MessageSize, MessageTag, OperationFlag);
         }
   }
#endif // __cplusplus
#endif //__MIL_WEB_CLIENT_H
