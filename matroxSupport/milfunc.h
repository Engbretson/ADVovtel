/***************************************************************************/
/*

    Filename:  MILFUNC.H
    Revision:  10.10.0614
    Content :  This file contains the prototypes for the Matrox
               Imaging Library (MIL) Mfunc user's functions.

    Copyright © Matrox Electronic Systems Ltd., 1992-2015.
    All Rights Reserved

*/
/***************************************************************************/

#ifndef __MILFUNC_H
#define __MILFUNC_H

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************/
/* TOOLKIT FOR PSEUDO MIL FUNCTIONS DEVELOPMENT                            */
/***************************************************************************/
typedef void (MFTYPE *MIL_FUNC_FUNCTION_PTR)(MIL_ID FunctionId);
typedef MIL_FUNC_FUNCTION_PTR MFUNCSLAVEFCTPTR;
typedef MIL_FUNC_FUNCTION_PTR MFUNCFCTPTR;
typedef MIL_FUNC_FUNCTION_PTR MFUNCSLAVEPAFCTPTR;

// we need the ASCII version even on non-Unicode version
// this is needed for transferring ASCII strings in DMIL 
MIL_DLLFUNC void MFTYPE MfuncParamMilTextA(MIL_ID ContextFuncId, MIL_INT ParamIndex, char* ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamConstMilTextA(MIL_ID ContextFuncId, MIL_INT ParamIndex,const char* ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamFilenameA(MIL_ID ContextFuncId, MIL_INT ParamIndex, const char* ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

#if M_MIL_USE_UNICODE
   MIL_DLLFUNC MIL_ID MFTYPE MfuncAllocW(MIL_CONST_TEXT_PTR FunctionName,
                             MIL_INT ParameterNum,
                             MIL_FUNC_FUNCTION_PTR SlaveFunctionPtr,
                             MIL_CONST_TEXT_PTR SlaveFunctionDLLName,
                             MIL_CONST_TEXT_PTR SlaveFunctionName,
                             MIL_INT SlaveFunctionOpcode,
                             MIL_INT64 InitFlag,
                             MIL_ID *CBasedContextFuncIdPtr);
   MIL_DLLFUNC MIL_ID MFTYPE MfuncAllocA(const char* FunctionName,
                             MIL_INT ParameterNum,
                             MIL_FUNC_FUNCTION_PTR SlaveFunctionPtr,
                             const char* SlaveFunctionDLLName,
                             const char* SlaveFunctionName,
                             MIL_INT SlaveFunctionOpcode,
                             MIL_INT64 InitFlag,
                             MIL_ID *CBasedContextFuncIdPtr);

   MIL_DLLFUNC MIL_ID MFTYPE MfuncAllocScriptW(MIL_CONST_TEXT_PTR FunctionName,
                             MIL_INT ParameterNum,
                             MIL_CONST_TEXT_PTR InterpreterLanguage,
                             MIL_CONST_TEXT_PTR ScriptFileName,
                             MIL_CONST_TEXT_PTR ScriptFunctionName,
                             MIL_INT ScriptFunctionOpcode,
                             MIL_INT64 InitFlag,
                             MIL_ID *ScriptBasedContextFuncIdPtr);
   MIL_DLLFUNC MIL_ID MFTYPE MfuncAllocScriptA(const char* FunctionName,
                             MIL_INT ParameterNum,
                             const char* InterpreterLanguage,
                             const char* ScriptFileName,
                             const char* ScriptFunctionName,
                             MIL_INT ScriptFunctionOpcode,
                             MIL_INT64 InitFlag,
                             MIL_ID *ScriptBasedContextFuncIdPtr);

   MIL_DLLFUNC MIL_INT MFTYPE MfuncErrorReportW(MIL_ID ContextFuncId,
                                    MIL_INT ErrorCode,
                                    MIL_CONST_TEXT_PTR ErrorMessage,
                                    MIL_CONST_TEXT_PTR ErrorSubMessage1,
                                    MIL_CONST_TEXT_PTR ErrorSubMessage2,
                                    MIL_CONST_TEXT_PTR ErrorSubMessage3);
   MIL_DLLFUNC MIL_INT MFTYPE MfuncErrorReportA(MIL_ID ContextFuncId,
                                    MIL_INT ErrorCode,
                                    const char* ErrorMessage,
                                    const char* ErrorSubMessage1,
                                    const char* ErrorSubMessage2,
                                    const char* ErrorSubMessage3);

   MIL_DLLFUNC void MFTYPE MfuncParamMilTextW(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_TEXT_PTR ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

   MIL_DLLFUNC void MFTYPE MfuncParamConstMilTextW(MIL_ID ContextFuncId, MIL_INT ParamIndex,MIL_CONST_TEXT_PTR ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

   MIL_DLLFUNC void MFTYPE MfuncParamFilenameW(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_CONST_TEXT_PTR ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

   MIL_DLLFUNC MIL_INT MFTYPE MfuncPrintMessageW(MIL_INT Mode,
                                     MIL_CONST_TEXT_PTR Str1,
                                     MIL_CONST_TEXT_PTR Str2,
                                     MIL_CONST_TEXT_PTR Str3,
                                     MIL_CONST_TEXT_PTR Str4,
                                     MIL_CONST_TEXT_PTR Str5);
   MIL_DLLFUNC MIL_INT MFTYPE MfuncPrintMessageA(MIL_INT Mode,
                                     const char* Str1,
                                     const char* Str2,
                                     const char* Str3,
                                     const char* Str4,
                                     const char* Str5);
   #if M_MIL_UNICODE_API
      #define MfuncAlloc                     MfuncAllocW
      #define MfuncAllocScript               MfuncAllocScriptW
      #define MfuncErrorReport               MfuncErrorReportW
      #define MfuncParamMilText              MfuncParamMilTextW
      #define MfuncParamConstMilText         MfuncParamConstMilTextW
      #define MfuncParamFilename             MfuncParamFilenameW
      #define MfuncPrintMessage              MfuncPrintMessageW
   #else
      #define MfuncAlloc                     MfuncAllocA
      #define MfuncAllocScript               MfuncAllocScriptA
      #define MfuncErrorReport               MfuncErrorReportA
      #define MfuncParamMilText              MfuncParamMilTextA
      #define MfuncParamConstMilText         MfuncParamConstMilTextA
      #define MfuncParamFilename             MfuncParamFilenameA
      #define MfuncPrintMessage              MfuncPrintMessageA
   #endif
   #else
      MIL_DLLFUNC MIL_ID MFTYPE MfuncAlloc(MIL_CONST_TEXT_PTR FunctionName,
                              MIL_INT ParameterNum,
                              MIL_FUNC_FUNCTION_PTR SlaveFunctionPtr,
                              MIL_CONST_TEXT_PTR SlaveFunctionDLLName,
                              MIL_CONST_TEXT_PTR SlaveFunctionName,
                              MIL_INT SlaveFunctionOpcode,
                              MIL_INT64 InitFlag,
                              MIL_ID *CBasedContextFuncIdPtr);

      MIL_DLLFUNC MIL_ID MFTYPE MfuncAllocScript(MIL_CONST_TEXT_PTR FunctionName,
                              MIL_INT ParameterNum,
                              MIL_CONST_TEXT_PTR InterpreterLanguage,
                              MIL_CONST_TEXT_PTR ScriptFileName,
                              MIL_CONST_TEXT_PTR ScriptFunctionName,
                              MIL_INT ScriptFunctionOpcode,
                              MIL_INT64 InitFlag,
                              MIL_ID *ScriptBasedContextFuncIdPtr);

      MIL_DLLFUNC MIL_INT MFTYPE MfuncErrorReport( MIL_ID ContextFuncId,
                                       MIL_INT ErrorCode,
                                       MIL_CONST_TEXT_PTR ErrorMessage,
                                       MIL_CONST_TEXT_PTR ErrorSubMessage1,
                                       MIL_CONST_TEXT_PTR ErrorSubMessage2,
                                       MIL_CONST_TEXT_PTR ErrorSubMessage3);

      MIL_DLLFUNC void MFTYPE MfuncParamMilText(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_TEXT_PTR ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

      MIL_DLLFUNC void MFTYPE MfuncParamConstMilText(MIL_ID ContextFuncId, MIL_INT ParamIndex,MIL_CONST_TEXT_PTR ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);


      MIL_DLLFUNC void MFTYPE MfuncParamFilename(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_CONST_TEXT_PTR ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);


      MIL_DLLFUNC MIL_INT MFTYPE MfuncPrintMessage(MIL_INT Mode, MIL_CONST_TEXT_PTR Str1,
                                       MIL_CONST_TEXT_PTR Str2,
                                       MIL_CONST_TEXT_PTR Str3,
                                       MIL_CONST_TEXT_PTR Str4,
                                       MIL_CONST_TEXT_PTR Str5);
#endif
// compatibility function
#if OldDefinesSupport
#define MfuncParamString   MfuncParamMilText
MIL_DEPRECATED(MfuncParamString, 1000)
#endif


MIL_DLLFUNC MIL_ID MFTYPE MfuncAllocId(MIL_ID ContextFuncId, MIL_INT64 MilObjectType, void *UserObjectPtr);
MIL_DLLFUNC MIL_INT MFTYPE MfuncParamCheck(MIL_ID ContextFuncId);
MIL_DLLFUNC void MFTYPE MfuncParam(MIL_ID ContextFuncId, MIL_INT ParamIndex, const void* ParamValuePtr, MIL_UINT ParamType, MIL_INT NumOfItems, MIL_INT64 MilObjectType, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamMilId(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_ID ParamValue, MIL_INT64 MilObjectType, MIL_INT Attribute);
#if OldDefinesSupport
#define MfuncParamId MfuncParamMilId // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamId, 1000)
#endif
MIL_DLLFUNC void MFTYPE MfuncParamLong (MIL_ID ContextFuncId, MIL_INT ParamIndex, long ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamMilInt(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamMilInt32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT32 ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamMilInt64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT64 ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamMilUint(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamMilUint32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT32 ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamMilUint64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT64 ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamMilDouble(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_DOUBLE ParamValue);
MIL_DLLFUNC void MFTYPE MfuncParamDataPointer(MIL_ID ContextFuncId, MIL_INT ParamIndex, void *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
#if OldDefinesSupport
#define MfuncParamDouble MfuncParamMilDouble // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamDouble, 1000)
#define MfuncParamPointer MfuncParamDataPointer
MIL_DEPRECATED(MfuncParamPointer, 1000)
#endif
MIL_DLLFUNC void MFTYPE MfuncParamIdPointer(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_ID *ParamValuePtr, MIL_INT64 MilObjectType, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamValue(MIL_ID ContextFuncId, MIL_INT ParamIndex, void *ParamValuePtr);
MIL_DLLFUNC MIL_INT MFTYPE MfuncGetError(MIL_ID FunctId, MIL_INT ErrorType,void* ErrorVarPtr);
MIL_DLLFUNC void MFTYPE MfuncFreeId(MIL_ID ContextFuncId, MIL_ID UserObjectFuncId);
MIL_DLLFUNC void MFTYPE MfuncFree(MIL_ID ContextFuncId);
MIL_DLLFUNC MIL_INT MFTYPE MfuncCall(MIL_ID ContextFuncId);
MIL_DLLFUNC MIL_INT MFTYPE MfuncInquire(MIL_ID MilObjectId, MIL_INT64 InquireType, void* UserVarPtr);
MIL_DLLFUNC MIL_INT MFTYPE MfuncExit();
MIL_DLLFUNC void* MFTYPE MfuncMemory(MIL_INT64 Operation, MIL_INT OperationValue, MIL_INT64 OperationFlag, void *DataPointer);
MIL_DLLFUNC MIL_ID MFTYPE MfuncGetNextId(MIL_ID CurrentId);
MIL_DLLFUNC void MFTYPE MfuncMDTrace(void** FileHandle, MIL_INT64 Action, void* DataPointer);
MIL_DLLFUNC void MFTYPE MfuncTraceTimerRead(MIL_DOUBLE* pCurrentTime);


/* The following MfuncParamValue are for getting the value by type */
MIL_DLLFUNC void MFTYPE MfuncParamValueMilInt(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueMilInt32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT32 *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueMilInt64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT64 *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueMilUint(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueMilUint32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT32 *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueMilUint64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT64 *ParamValuePtr);

MIL_DLLFUNC void MFTYPE MfuncParamValueMilDouble(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_DOUBLE *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueMilId(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_ID *ParamValuePtr);

MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilDouble(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_DOUBLE **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilDouble(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_DOUBLE **ParamValuePtr);

#if OldDefinesSupport
#define MfuncParamValueDouble MfuncParamValueMilDouble                     // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamValueDouble, 1000)
#define MfuncParamValueId MfuncParamValueMilId                             // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamValueId, 1000)
#define MfuncParamValueArrayDouble MfuncParamValueArrayMilDouble           // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamValueArrayDouble, 1000)
#define MfuncParamValueConstArrayDouble MfuncParamValueConstArrayMilDouble // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamValueConstArrayDouble, 1000)
#endif

MIL_DLLFUNC void MFTYPE MfuncParamValueMilTextA(MIL_ID ContextFuncId, MIL_INT ParamIndex, char* *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstMilTextA(MIL_ID ContextFuncId, MIL_INT ParamIndex, const char* *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueFilenameA(MIL_ID ContextFuncId, MIL_INT ParamIndex, const char* *ParamValuePtr);

#if M_MIL_USE_UNICODE
#if M_MIL_UNICODE_API
#define MfuncParamValueMilText            MfuncParamValueMilTextW
#define MfuncParamValueConstMilText       MfuncParamValueConstMilTextW
#define MfuncParamValueFilename           MfuncParamValueFilenameW
#else
#define MfuncParamValueMilText            MfuncParamValueMilTextA
#define MfuncParamValueConstMilText       MfuncParamValueConstMilTextA
#define MfuncParamValueFilename           MfuncParamValueFilenameA
#endif

MIL_DLLFUNC void MFTYPE MfuncParamValueMilTextW(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_TEXT_PTR *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstMilTextW(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_CONST_TEXT_PTR *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueFilenameW(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_CONST_TEXT_PTR *ParamValuePtr);

#else

MIL_DLLFUNC void MFTYPE MfuncParamValueMilText(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_TEXT_PTR *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstMilText(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_CONST_TEXT_PTR *ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueFilename(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_CONST_TEXT_PTR *ParamValuePtr);

#endif

MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilInt(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilUint(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT **ParamValuePtr);

MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilInt32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT32 **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilUint32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT32 **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilInt64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT64 **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilUint64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT64 **ParamValuePtr);

MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilInt32(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_INT32 **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilUint32(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_UINT32 **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilInt64(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_INT64 **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilUint64(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_UINT64 **ParamValuePtr);

MIL_DLLFUNC void MFTYPE MfuncParamValueArrayMilId(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_ID **ParamValuePtr);
#if OldDefinesSupport
#define MfuncParamValueArrayId MfuncParamValueArrayMilId                          // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamValueArrayId, 1000)
#endif

MIL_DLLFUNC void MFTYPE MfuncParamValuePointer(MIL_ID ContextFuncId, MIL_INT ParamIndex, void ** ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstDataPointer(MIL_ID ContextFuncId, MIL_INT ParamIndex, const void ** ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilId(MIL_ID ContextFuncId, MIL_INT ParamIndex,const MIL_ID **ParamValuePtr);
#if OldDefinesSupport
#define MfuncParamValueConstArrayId MfuncParamValueConstArrayMilId                // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamValueConstArrayId, 1000)
#endif
MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilInt(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_INT **ParamValuePtr);
MIL_DLLFUNC void MFTYPE MfuncParamValueConstArrayMilUint(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_UINT **ParamValuePtr);


MIL_DLLFUNC void MFTYPE MfuncParamArrayMilInt(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamArrayMilDouble(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_DOUBLE *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
#if OldDefinesSupport
#define MfuncParamArrayDouble MfuncParamArrayMilDouble   // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamArrayDouble, 1000)
#endif
MIL_DLLFUNC void MFTYPE MfuncParamArrayMilUint(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamArrayMilId(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_ID *ParamValuePtr, MIL_INT NumOfItems, MIL_INT64 MilObjectType, MIL_INT Attribute);
#if OldDefinesSupport
#define MfuncParamArrayId MfuncParamArrayMilId           // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamArrayId, 1000)
#endif
MIL_DLLFUNC void MFTYPE MfuncParamArrayMilInt32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT32 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamArrayMilInt64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_INT64 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamArrayMilUint32(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT32 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamArrayMilUint64(MIL_ID ContextFuncId, MIL_INT ParamIndex, MIL_UINT64 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilDouble(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_DOUBLE *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
#if OldDefinesSupport
#define MfuncParamConstArrayDouble MfuncParamConstArrayMilDouble // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamConstArrayDouble, 1000)
#endif
MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilInt32(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_INT32 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilInt64(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_INT64 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilUint32(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_UINT32 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilUint64(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_UINT64 *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilId(MIL_ID ContextFuncId, MIL_INT ParamIndex,const MIL_ID *ParamValuePtr, MIL_INT NumOfItems, MIL_INT64 MilObjectType, MIL_INT Attribute);
#if OldDefinesSupport
#define MfuncParamConstArrayId MfuncParamConstArrayMilId // it was documented in MIL 9, so keep it
MIL_DEPRECATED(MfuncParamConstArrayId, 1000)
#endif
MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilInt(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_INT *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);
MIL_DLLFUNC void MFTYPE MfuncParamConstArrayMilUint(MIL_ID ContextFuncId, MIL_INT ParamIndex, const MIL_UINT *ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

MIL_DLLFUNC void MFTYPE MfuncParamConstDataPointer(MIL_ID ContextFuncId, MIL_INT ParamIndex, const void * ParamValuePtr, MIL_INT NumOfItems, MIL_INT Attribute);

typedef struct 
   {
   MIL_INT32 StructSize;
   MIL_INT32 ScriptPathSize;
   MIL_INT32 ScriptPathOffset;
   MIL_INT32 ScriptFunctionNameSize;
   MIL_INT32 ScriptFunctionNameOffset;
   MIL_INT32 DebugPathSize;
   MIL_INT32 DebugPathOffset;
   MIL_INT32 ReferenceListSize;
   MIL_INT32 ReferenceListOffset;
   MIL_INT64 Compile;
   MIL_INT64 DebugInfo;
   } M_FUNCSCRIPT_CALL_DATA;

/*The following Mfunc functions are obsolete*/
MIL_DLLFUNC MIL_INT MFTYPE MfuncStart(MIL_ID ContextFuncId);          /*Replaced by MfuncCall*/
MIL_DLLFUNC void    MFTYPE MfuncFreeAndEnd(MIL_ID ContextFuncId);     /*Replaced by MfuncCall*/
MIL_DLLFUNC MIL_INT MFTYPE MfuncModified(MIL_ID ImageId);      /*Replaced by MbufControl(M_MODIFIED)*/
MIL_DLLFUNC MIL_INT MFTYPE MfuncParamRegister(MIL_ID ContextFuncId);  /*Parameters must always be registered*/
MIL_DLLFUNC MIL_INT MFTYPE MfuncIdGetObjectType(MIL_ID FunctionId, MIL_ID ObjectId);               /*Replaced by MfuncInquire*/
MIL_DLLFUNC void    MFTYPE MfuncIdSetUserPtr(MIL_ID FunctionId, MIL_ID ObjectId, void *UserPtr);   /*Replaced by MfuncControl*/
MIL_DLLFUNC void*   MFTYPE MfuncIdGetUserPtr(MIL_ID FunctionId, MIL_ID ObjectId);                  /*Replaced by MfuncInquire*/

#if M_MIL_USE_64BIT
MIL_DLLFUNC void   MFTYPE MfuncControlInt64(MIL_ID ContextFuncId, MIL_INT64 ControlType, MIL_INT64 ControlValue);
MIL_DLLFUNC void   MFTYPE MfuncControlDouble(MIL_ID ContextFuncId, MIL_INT64 ControlType, MIL_DOUBLE ControlValue);
#else
#define MfuncControlDouble MfuncControl
#define MfuncControlInt64 MfuncControl
MIL_DLLFUNC void   MFTYPE MfuncControl(MIL_ID ContextFuncId, MIL_INT64 ControlType, MIL_DOUBLE ControlValue);
#endif   //M_MIL_USE_64BIT

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif

#if M_MIL_USE_64BIT

#ifdef __cplusplus
//////////////////////////////////////////////////////////////
// MfuncControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MfuncControl(  MIL_ID ContextFuncId,
                           MIL_INT64 ControlType,
                           MIL_INT64 ControlValue)
   {
   MfuncControlInt64(ContextFuncId, ControlType, ControlValue);
   };

inline void MfuncControl(  MIL_ID ContextFuncId,
                           MIL_INT64 ControlType,
                           MIL_DOUBLE ControlValue)
   {
   MfuncControlDouble(ContextFuncId, ControlType, ControlValue);
   };

inline void MfuncControl(  MIL_ID ContextFuncId,
                           MIL_INT64 ControlType,
                           int ControlValue)
   {
   MfuncControlInt64(ContextFuncId, ControlType, ControlValue);
   };
#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Int64 one
//////////////////////////////////////////////////////////////
#define MfuncControl MfuncControlInt64
#endif // __cplusplus
#endif   //M_MIL_USE_64BIT

#endif
