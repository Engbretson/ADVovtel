/***************************************************************************/
/*

    Filename:  MILPAT.H
    Owner   :  Matrox Imaging
    Revision:  10.10.0614
    Content :  This file contains the defines for the MIL pattern
               recognition module. (Mpat...).

    Copyright © Matrox Electronic Systems Ltd., 1992-2015.
    All Rights Reserved

*/
/***************************************************************************/

#ifndef __MILPAT_H__
#define __MILPAT_H__

#if (!M_MIL_LITE) // MIL FULL ONLY

#if M_MIL_USE_RT
#ifdef M_PAT_EXPORTS
#define MIL_PAT_DLLFUNC __declspec(dllexport)
#else
#define MIL_PAT_DLLFUNC __declspec(dllimport)
#endif
#else
#define MIL_PAT_DLLFUNC
#endif
/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
{
#endif

/* Bit encoded model types */
#define M_NORMALIZED             0x00000002L
#define M_ORIENTATION            0x00002400L
#define M_CIRCULAR_OVERSCAN      0x00010000L


/* Levels of speed and/or accuracy */
#define M_VERY_LOW                        0L
#define M_LOW                             1L
#define M_MEDIUM                          2L
#define M_HIGH                            3L
#define M_VERY_HIGH                       4L

#define M_ALL                    0x40000000L // Already defined in Mil.h
#if OldDefinesSupport
   #define M_ALL_OLD                      0L 
// MIL_DEPRECATED(M_ALL_OLD, 1010)
#endif
#define M_DISABLE                     -9999L
#define M_UNKNOWN                     -9999L
#define M_NO_CHANGE                   -9998L
#define M_ABSOLUTE                        1L
#define M_OFFSET                          2L

/* 'type' parameter of MpatAlloc() */
#define M_REGULAR                0x00020000L
#define M_FAST                   0x00002000L
#define M_BEST                   0x00100000L
#define M_MULTIPLE               0x00400000L

/* 'Flag' parameter of MpatCopy() */
#define M_CLEAR_BACKGROUND           0x2000L
#define M_DONT_CARE                  0x00008000L // Already defined in mil.h, milcolor.h, milmod.h


/* Used by MpatDraw() */
#define M_DRAW_IMAGE             0x00000002L   // Already define in MilMod.h
#define M_DRAW_DONT_CARE         0x00000008L   // Already define in MilMod.h
#if OldDefinesSupport
   #define M_DRAW_DONT_CARES    M_DRAW_DONT_CARE 
   // MIL_DEPRECATED(M_DRAW_DONT_CARES, 1010)
#endif
#define M_DRAW_BOX               0x00000020L   // Already define in MilMod.h
#define M_DRAW_POSITION          0x00000040L   // Already define in MilMod.h
#define M_ORIGINAL               0x00000199L   // Already define in MilMod.h


/* Used by MpatGetResult() */
#define M_SCORE                  0x00001400L
#define M_POSITION_X             0x00003400L
#define M_POSITION_Y             0x00004400L
#define M_MODEL_INDEX            0x00005400L               
#define M_SCALE                  0x00008010L   // Already define in MilMod.h
#define M_SUM_I                  0x00010500L
#define M_SUM_II                 0x00010700L
#define M_SUM_IM                 0x00010900L
#define M_SUM_M                  0x00011100L
#define M_SUM_MM                 0x00011300L
#define M_NUMBER_OF_PIXELS       0x00011500L


/* Used by MpatInquire() */
#define M_ALLOC_TYPE                    322L
#define M_ALLOC_SIZE_X                    2L
#define M_ALLOC_SIZE_Y                    3L
#define M_CENTER_X                        4L
#define M_CENTER_Y                        5L
#define M_ORIGINAL_X                      6L
#define M_ORIGINAL_Y                      7L
#define M_SPEED                           8L
#define M_POSITION_START_X                9L
#define M_POSITION_START_Y               10L
#define M_POSITION_UNCERTAINTY_X         11L
#define M_POSITION_UNCERTAINTY_Y         12L
#define M_POSITION_ACCURACY              13L
#define M_PREPROCESSED                   14L
#define M_ALLOC_OFFSET_X                 15L
#define M_ALLOC_OFFSET_Y                 16L
#define M_ACCEPTANCE_THRESHOLD           17L 
#define M_NUMBER_OF_OCCURRENCES          18L
#if OldDefinesSupport
   #define M_NUMBER_OF_OCCURENCES        M_NUMBER_OF_OCCURRENCES
   MIL_DEPRECATED(M_NUMBER_OF_OCCURENCES, 1010)
#endif
#define M_NUMBER_OF_ENTRIES              24L
#define M_CERTAINTY_THRESHOLD            25L
#define M_INTERNAL_SIZE_Y                28L
#define M_MODEL_MAX_LEVEL              1419L  

/* Search parameters */
#define M_FIRST_LEVEL                    31L
#define M_LAST_LEVEL                     32L
#define M_MODEL_STEP                     33L
#define M_FAST_FIND                      34L
#define M_MIN_SPACING_X                  35L
#define M_MIN_SPACING_Y                  36L
#define M_SCORE_TYPE                     37L
#define M_TARGET_CACHING                 39L
#define M_COARSE_SEARCH_ACCEPTANCE       41L 
#if OldDefinesSupport
   #define M_REJECTION_THRESHOLD         M_COARSE_SEARCH_ACCEPTANCE
   MIL_DEPRECATED(M_REJECTION_THRESHOLD, 1010)
#endif
#define M_EXTRA_CANDIDATES               46L
#define M_PROC_FIRST_LEVEL               50L
#define M_PROC_LAST_LEVEL                51L
#define M_AUTO_RESET             0x00002000L // Already defined in mil.h
#define M_SAVE_SUMS                      55L
#define M_RESULT_OUTPUT_UNITS          1300L // Also in milim.h
#define M_AUTO_CONTENT_BASED           1403L
#define M_AUTO_SIZE_BASED              1409L
#define M_MAX_INITIAL_PEAKS            1418L

#define M_PAT_EVAL_MORE_CANDIDATES       52L    //   =utilities=

/* Search parameter values */
#define M_ENABLE                      -9997L // Already defined in mil.h
#define M_DISABLE                     -9999L // Already defined in mil.h

/* MpatControl */
#define M_NUMBER                       1009L // Already defined in mil.h
#define M_MIN_SEPARATION_X             M_MIN_SPACING_X  // already defined in MilPat.h 
#define M_MIN_SEPARATION_Y             M_MIN_SPACING_Y  // already defined in MilPat.h 
#define M_REFERENCE_X                  100L // also defined in milmod.h
#define M_REFERENCE_Y                  101L // also defined in milmod.h
#if OldDefinesSupport
   #define M_SEARCH_OFFSET_X           102L // also defined in milmod.h  
   #define M_SEARCH_OFFSET_Y           103L // also defined in milmod.h 
   #define M_SEARCH_SIZE_X             104L // also defined in milmod.h 
   #define M_SEARCH_SIZE_Y             105L // also defined in milmod.h 
//    MIL_DEPRECATED(M_SEARCH_OFFSET_X, 1010)
//    MIL_DEPRECATED(M_SEARCH_OFFSET_Y, 1010)
//    MIL_DEPRECATED(M_SEARCH_SIZE_X  , 1010)
//    MIL_DEPRECATED(M_SEARCH_SIZE_Y  , 1010)
#endif
#define M_ACCURACY                     106L // also defined in milmod.h
#define M_ACCEPTANCE                   200L // Already defined milmod.h
#define M_CERTAINTY                    202L // Already defined milmod.h 
#define M_SEARCH_ANGLE_RANGE           113L // Already defined milmod.h
#define M_ANGLE                        0x00000800L // already defined in Mil.h

/* MpatFindMultiple */
#define M_FIND_ALL_MODELS                M_DEFAULT
#define M_FIND_BEST_MODELS                1L
#if OldDefinesSupport
   #define M_FIND_ALL_MODEL               2L
   MIL_DEPRECATED(M_FIND_ALL_MODEL, 1010)
#endif

/* Search parameters for search with rotation */
#define M_SEARCH_ANGLE_MODE                   0x00000080L
#define M_SEARCH_ANGLE                        0x00000100L
#define M_SEARCH_ANGLE_DELTA_NEG              0x00000200L
#define M_SEARCH_ANGLE_DELTA_POS              0x00000400L
#define M_SEARCH_ANGLE_TOLERANCE              0x00000800L
#define M_SEARCH_ANGLE_ACCURACY               0x00001000L
#define M_SEARCH_ANGLE_INTERPOLATION_MODE     0x00008000L
#define M_ROTATED_MODEL_MINIMUM_SCORE         1395L

// Value for M_SEARCH_ANGLE
#define M_ACCORDING_TO_REGION            0x40000000L  


/* Parameters for output units */
#define M_PIXEL                              0x1000L
#define M_WORLD                              0x2000L
#define M_ACCORDING_TO_CALIBRATION             1301L
#define M_ACCORDING_TO_RESULT                  1302L //internal

/* Spelling variations and synonyms*/
#if OldDefinesSupport
   #define M_CENTRE_X                    M_CENTER_X
   #define M_CENTRE_Y                    M_CENTER_Y
   MIL_DEPRECATED(M_CENTRE_X, 1010)
   MIL_DEPRECATED(M_CENTRE_Y, 1010)
#endif   
#if OldDefinesSupport
   #define M_KEEP_PYRAMID                       M_TARGET_CACHING
   MIL_DEPRECATED(M_KEEP_PYRAMID, 1010)
#endif

/* MpatRestore, MpatSave*/
#define M_INTERACTIVE                           M_NULL // Already defined in mil.h, milcal.h, milcode.h, miledge.h, milmeas.h, milocr.h, milmod.h


/********************************************************************
 * Function prototypes
 ********************************************************************/


MIL_PAT_DLLFUNC MIL_ID MFTYPE MpatAllocModel(                       MIL_ID SystemId,
                                                    MIL_ID SrcImageBufId,
                                                    MIL_INT OffX,
                                                    MIL_INT OffY,
                                                    MIL_INT SizeX,
                                                    MIL_INT SizeY,
                                                    MIL_INT64  ModelType,
                                                    MIL_ID* ModelIdPtr);

MIL_PAT_DLLFUNC MIL_ID MFTYPE MpatAllocResult(                      MIL_ID  SystemId,
                                                    MIL_INT NbEntries,
                                                    MIL_ID* PatResultIdPtr);

MIL_PAT_DLLFUNC MIL_ID MFTYPE MpatAllocResultNoCaching(             MIL_ID  SystemId,
                                                    MIL_INT NumEntries,
                                                    MIL_ID* IdPtr);
MIL_PAT_DLLFUNC void MFTYPE MpatCopy(                               MIL_ID ModelId,
                                                    MIL_ID DestImageBufId,
                                                    MIL_INT64  CopyMode);
MIL_PAT_DLLFUNC void MFTYPE MpatFindModel(                          MIL_ID ImageBufId,
                                                    MIL_ID ModelId,
                                                    MIL_ID PatResultId);
MIL_PAT_DLLFUNC void MFTYPE MpatFindMultipleModel(                  MIL_ID ImageBufId,
                                                    const MIL_ID* ModelIdArrayPtr,
                                                    const MIL_ID* PatResultIdArrayPtr,
                                                    MIL_INT NumModels,
                                                    MIL_INT64  SearchMode);
MIL_PAT_DLLFUNC void MFTYPE MpatFindOrientation(                    MIL_ID ImageId,
                                                    MIL_ID ModelId,
                                                    MIL_ID ResultId,
                                                    MIL_INT ResultRange);
MIL_PAT_DLLFUNC void MFTYPE MpatFree(                               MIL_ID PatId);
MIL_PAT_DLLFUNC MIL_INT MFTYPE MpatGetNumber(                       MIL_ID PatResultId,
                                                    MIL_INT* CountPtr);
MIL_PAT_DLLFUNC void MFTYPE MpatGetResult(                          MIL_ID PatResultId,
                                                    MIL_INT64 ResultType,
                                                    void* UserArrayPtr);
MIL_PAT_DLLFUNC void MFTYPE MpatGetResultOutputUnits(               MIL_ID ResultId,
                                                    MIL_INT64  Type,
                                                    MIL_INT64  OutputUnits,
                                                    double* ArrayPtr);
MIL_PAT_DLLFUNC MIL_INT MFTYPE MpatInquire(                         MIL_ID PatId,
                                                    MIL_INT64  InquireType,
                                                    void*  UserVarPtr);
MIL_PAT_DLLFUNC void MFTYPE MpatPreprocModel(                       MIL_ID TypicalImageBufId,
                                                    MIL_ID ModelId,
                                                    MIL_INT64  Mode);
MIL_PAT_DLLFUNC MIL_ID MFTYPE MpatAllocRotatedModel(                MIL_ID SystemId,
                                                    MIL_ID SrcModelId,
                                                    MIL_DOUBLE Angle,
                                                    MIL_INT64  InterpolationMode,
                                                    MIL_INT64  ModelType,
                                                    MIL_ID* NewModelIdPtr);
MIL_PAT_DLLFUNC void MFTYPE MpatSetAcceptance(                      MIL_ID ModelId,
                                                    MIL_DOUBLE AcceptanceThreshold);
MIL_PAT_DLLFUNC void MFTYPE MpatSetAccuracy(                        MIL_ID ModelId,
                                                    MIL_INT64  Accuracy);
MIL_PAT_DLLFUNC void MFTYPE MpatSetAngle(                           MIL_ID ModelId,
                                                    MIL_INT64 ControlType,
                                                    MIL_DOUBLE ControlValue);
MIL_PAT_DLLFUNC void MFTYPE MpatSetCenter(                          MIL_ID ModelId,
                                                    MIL_DOUBLE OffX,
                                                    MIL_DOUBLE OffY);
MIL_PAT_DLLFUNC void MFTYPE MpatSetCertainty(                       MIL_ID ModelId,
                                                    MIL_DOUBLE CertaintyThreshold);
MIL_PAT_DLLFUNC void MFTYPE MpatSetDontCare(                        MIL_ID ModelId,
                                                    MIL_ID ImageBufId,
                                                    MIL_INT OffX,
                                                    MIL_INT OffY,
                                                    MIL_INT Value);
MIL_PAT_DLLFUNC void MFTYPE MpatSetNumber(                          MIL_ID ModelId,
                                                    MIL_INT NbOccurrences);
MIL_PAT_DLLFUNC void MFTYPE MpatSetPosition(                        MIL_ID ModelId,
                                                    MIL_INT OffX,
                                                    MIL_INT OffY,
                                                    MIL_INT SizeX,
                                                    MIL_INT SizeY);
MIL_PAT_DLLFUNC void MFTYPE MpatSetSearchParameter(                 MIL_ID PatId,
                                                    MIL_INT64  Parameter,
                                                    MIL_DOUBLE Value);
MIL_PAT_DLLFUNC void MFTYPE MpatSetSpeed(                           MIL_ID ModelId,
                                                    MIL_INT64  SpeedFactor);
MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatAllocAutoModel(                  MIL_ID SystemId,
                                                    MIL_ID SrcImageBufId,
                                                    MIL_INT SizeX,
                                                    MIL_INT SizeY,
                                                    MIL_INT PosUncertaintyX,
                                                    MIL_INT PosUncertaintyY,
                                                    MIL_INT64  ModelType,
                                                    MIL_INT64  Mode,
                                                    MIL_ID *ModelIdArrayPtr);

MIL_PAT_DLLFUNC void MFTYPE MpatDraw(                               MIL_ID ContextGraId,
                                                    MIL_ID ModelOrResultPatId,
                                                    MIL_ID DstImageBufOrListGraId,
                                                    MIL_INT64  Operation,
                                                    MIL_INT Index,
                                                    MIL_INT64  ControlFlag);

#if M_MIL_USE_UNICODE
MIL_PAT_DLLFUNC void MFTYPE MpatSaveA(                              const char* FileName,
                                                    MIL_ID ModelId);
MIL_PAT_DLLFUNC MIL_ID MFTYPE MpatRestoreA(                         MIL_ID SystemId,
                                                    const char* FileName,
                                                    MIL_ID* ModelIdPtr);

MIL_PAT_DLLFUNC void MFTYPE MpatStreamA(                            char*      MemPtrOrFileName,
                                                    MIL_ID     SystemId,
                                                    MIL_INT64  Operation,
                                                    MIL_INT64  StreamType,
                                                    MIL_DOUBLE Version,
                                                    MIL_INT64  ControlFlag,
                                                    MIL_ID*    ModelIdPtr,
                                                    MIL_INT*   SizeByteVarPtr);

MIL_PAT_DLLFUNC void MFTYPE MpatSaveW(                              MIL_CONST_TEXT_PTR FileName,
                                                    MIL_ID ModelId);
MIL_PAT_DLLFUNC MIL_ID MFTYPE MpatRestoreW(                         MIL_ID SystemId,
                                                    MIL_CONST_TEXT_PTR FileName,
                                                    MIL_ID* ModelIdPtr);

MIL_PAT_DLLFUNC void MFTYPE MpatStreamW(                            MIL_TEXT_PTR  MemPtrOrFileName,
                                                    MIL_ID        SystemId,
                                                    MIL_INT64     Operation,
                                                    MIL_INT64     StreamType,
                                                    MIL_DOUBLE    Version,
                                                    MIL_INT64     ControlFlag,
                                                    MIL_ID        *ModelIdPtr,
                                                    MIL_INT       *SizeByteVarPtr);
#if M_MIL_UNICODE_API
#define MpatSave           MpatSaveW
#define MpatRestore        MpatRestoreW
#define MpatStream         MpatStreamW
#else
#define MpatSave           MpatSaveA
#define MpatRestore        MpatRestoreA
#define MpatStream         MpatStreamA
#endif

#else
MIL_PAT_DLLFUNC void MFTYPE MpatSave(                               MIL_CONST_TEXT_PTR FileName,
                                                    MIL_ID ModelId);
MIL_PAT_DLLFUNC MIL_ID MFTYPE MpatRestore(                          MIL_ID SystemId,
                                                    MIL_CONST_TEXT_PTR FileName,
                                                    MIL_ID* ModelIdPtr);
MIL_PAT_DLLFUNC void MFTYPE MpatStream(                             MIL_TEXT_PTR  MemPtrOrFileName,
                                                    MIL_ID        SystemId,
                                                    MIL_INT64     Operation, 
                                                    MIL_INT64     StreamType,
                                                    MIL_DOUBLE    Version,
                                                    MIL_INT64     ControlFlag,
                                                    MIL_ID        *ModelIdPtr,
                                                    MIL_INT       *SizeByteVarPtr);
#endif


/* C++ directive if needed */
#ifdef __cplusplus
}
#endif

#if M_MIL_USE_SAFE_TYPE

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

// ----------------------------------------------------------
// MpatInquire

inline MIL_INT MFTYPE MpatInquireUnsafe  (MIL_ID PatId, MIL_INT64  InquireType, void           *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, int             UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_INT32      *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_INT64      *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_DOUBLE     *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                       
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_UINT32     *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_UINT64     *UserVarPtr);
#endif

//--------------------------------------------------------------------------------
// MpatInquire

inline MIL_INT MFTYPE MpatInquireSafeType (MIL_ID PatId, MIL_INT64  InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MIL_TEXT("MpatInquire"));

   return MpatInquire(PatId, InquireType, NULL);
   }

inline MIL_INT MFTYPE MpatInquireExecute (MIL_ID PatId, MIL_INT64  InquireType, void  *UserVarPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (InquireType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_MIL_ID))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MpatInquire"));

   return MpatInquire(PatId, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE MpatInquireUnsafe  (MIL_ID PatId, MIL_INT64  InquireType, void        *UserVarPtr) {return MpatInquire       (PatId, InquireType, UserVarPtr                  );}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_INT32   *UserVarPtr) {return MpatInquireExecute(PatId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_INT64   *UserVarPtr) {return MpatInquireExecute(PatId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_DOUBLE  *UserVarPtr) {return MpatInquireExecute(PatId, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_UINT32  *UserVarPtr) {return MpatInquireExecute(PatId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID PatId, MIL_INT64  InquireType, MIL_UINT64  *UserVarPtr) {return MpatInquireExecute(PatId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

#define MpatInquire          MpatInquireSafeType

#else // #if M_MIL_USE_SAFE_TYPE

#define MpatInquireUnsafe          MpatInquire

#endif // #if M_MIL_USE_SAFE_TYPE

#endif // !M_MIL_LITE

#endif /* __MILPAT_H__ */

