////////////////////////////////////////////////////////////////////////////////
//! 
//! \file  milpat.h
//! 
//! \brief Milpatb CAPI header (Mpat...)
//! 
//! AUTHOR: Matrox Imaging
//!
//! COPYRIGHT NOTICE:
//! Copyright © Matrox Electronic Systems Ltd., 1992-2016.
//! All Rights Reserved 
//  Revision:  10.20.0517
////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////
// MpatAlloc()

// ContextType
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h
#define M_NORMALIZED                            0x00000002L


////////////////////////////////////////////////////////////////////////////////
// MpatDefine()

// ModelType
#define M_REGULAR_MODEL                               2209L
#define M_AUTO_MODEL                                  2210L
#define M_CIRCULAR_OVERSCAN                     0x00010000L
#define M_DELETE                                         3L   // Also defined in mil.h

// ControlFlag for M_AUTO_MODEL
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h
#define M_BEST                                  0x00100000L
#define M_FAST                                  0x00002000L
#define M_MULTIPLE                              0x00400000L
#define M_NB_MODELS_MASK                        0x00000FFFL   // Max number of models we can allocate using M_MULTIPLE.


////////////////////////////////////////////////////////////////////////////////
// MpatInquire() (no control)

// InquireType for context:
#define M_OWNER_SYSTEM                                1101L   // Also defined in mil.h
#define M_CONTEXT_TYPE                                  162
#define M_MODEL_TYPE                                    162
#define M_PREPROCESSED                                  14L
#define M_NUMBER_MODELS                                302L   // Also defined in milmod.h
#define M_ORIGINAL_X                                     6L   // Also defined in milmod.h
#define M_ORIGINAL_Y                                     7L   // Also defined in milmod.h
#define M_MODEL_MAX_LEVEL                             1419L
#define M_PROC_FIRST_LEVEL                              50L
#define M_PROC_LAST_LEVEL                               51L
#define M_ALLOC_OFFSET_X                                15L
#define M_ALLOC_OFFSET_Y                                16L
#define M_ALLOC_SIZE_X                                   2L
#define M_ALLOC_SIZE_Y                                   3L
#define M_ALLOC_SIZE_BIT                                26L

// InquireType for result:
#define M_OWNER_SYSTEM                                1101L   // Also defined in mil.h


////////////////////////////////////////////////////////////////////////////////
// MpatControl() / MpatInquire()

// Index
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h
#define M_CONTEXT                               0x08000000L   // Also defined in mil.h
#define M_GENERAL                               0x20000000L   // Also defined in milmod.h, milstr.h, ...
#define M_ALL                                   0x40000000L   // Also defined in mil.h

// ControlType for context:
#define M_SEARCH_MODE                                 2214L
#define M_ACCEPTANCE                                   200L   // Also defined in milmod.h
#define M_ACCURACY                                     106L   // Also defined in milmod.h
#define M_CERTAINTY                                    202L   // Also defined in milmod.h
#define M_NUMBER                                      1009L   // Also defined in mil.h
#define M_REFERENCE_X                                  100L   // Also defined in milmod.h
#define M_REFERENCE_Y                                  101L   // Also defined in milmod.h
#define M_ROTATED_MODEL_MINIMUM_SCORE                 1395L
#define M_SEARCH_ANGLE                          0x00000100L
#define M_SEARCH_ANGLE_ACCURACY                 0x00001000L
#define M_SEARCH_ANGLE_DELTA_NEG                0x00000200L
#define M_SEARCH_ANGLE_DELTA_POS                0x00000400L
#define M_SEARCH_ANGLE_INTERPOLATION_MODE       0x00008000L
#define M_SEARCH_ANGLE_MODE                     0x00000080L
#define M_SEARCH_ANGLE_TOLERANCE                0x00000800L
#define M_SEARCH_OFFSET_X                              102L
#define M_SEARCH_OFFSET_Y                              103L
#define M_SEARCH_SIZE_X                                104L
#define M_SEARCH_SIZE_Y                                105L
#define M_SPEED                                          8L
#define M_COARSE_SEARCH_ACCEPTANCE                      41L 
#define M_EXTRA_CANDIDATES                              46L
#define M_FAST_FIND                                     34L
#define M_FIRST_LEVEL                                   31L
#define M_LAST_LEVEL                                    32L
#define M_MAX_INITIAL_PEAKS                           1418L
#define M_MIN_SEPARATION_X                              35L
#define M_MIN_SEPARATION_Y                              36L
#define M_MODEL_STEP                                    33L
#define M_PAT_EVAL_MORE_CANDIDATES                      52L   // =utilities=

// ControlType for result:
#define M_RESULT_OUTPUT_UNITS                         1300L   // Also defined in milim.h
#define M_SAVE_SUMS                                     55L
#define M_TARGET_CACHING                                39L

// ControlValue:
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h
#define M_ENABLE                                     -9997L   // Also defined in mil.h
#define M_DISABLE                                    -9999L   // Also defined in mil.h
#define M_ALL                                   0x40000000L   // Also defined in mil.h
// For M_SEARCH_MODE
#define M_FIND_ALL_MODELS                         M_DEFAULT
#define M_FIND_BEST_MODELS                               1L
// For M_PREPROCESSED 
#define M_FALSE                                          0L
#define M_TRUE                                           1L
// For M_ACCURACY
#define M_LOW                                            1L
#define M_MEDIUM                                         2L
#define M_HIGH                                           3L
// For M_SEARCH_ANGLE_INTERPOLATION_MODE
#define M_BICUBIC                               0x00000010L   // Also defined in mil.h
#define M_BILINEAR                              0x00000008L   // Also defined in mil.h
#define M_NEAREST_NEIGHBOR                      0x00000040L   // Also defined in mil.h
// For M_SEARCH_ANGLE_TOLERANCE
#define M_AUTO                                         444L   // Also defined in mil.h
// For M_SPEED
#define M_VERY_LOW                                       0L
#define M_LOW                                            1L
#define M_MEDIUM                                         2L
#define M_HIGH                                           3L
#define M_VERY_HIGH                                      4L
// For M_RESULT_OUTPUT_UNITS
#define M_PIXEL                                     0x1000L
#define M_WORLD                                     0x2000L
#define M_ACCORDING_TO_CALIBRATION                    1301L
// For M_FIRST_LEVEL
#define M_AUTO_CONTENT_BASED                          1403L
#define M_AUTO_SIZE_BASED                             1409L


////////////////////////////////////////////////////////////////////////////////
// MpatGetResult()

// Index:
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h
#define M_ALL                                   0x40000000L   // Also defined in mil.h
#define M_GENERAL                               0x20000000L   // Also defined in milmod.h, milstr.h, ...

// ResultType for M_GENERAL:
#define M_CONTEXT_ID                            0x00001010L
#define M_NUMBER                                      1009L   // Also defined in mil.h

// ResultType for occurrence:
#define M_ANGLE                                 0x00000800L   // Also defined in mil.h
#define M_INDEX                                        217L
#define M_NUMBER_OF_PIXELS                      0x00011500L
#define M_POSITION_X                            0x00003400L
#define M_POSITION_Y                            0x00004400L
#define M_SCORE                                 0x00001400L
#define M_SUM_I                                 0x00010500L
#define M_SUM_II                                0x00010700L
#define M_SUM_IM                                0x00010900L
#define M_SUM_M                                 0x00011100L
#define M_SUM_MM                                0x00011300L


////////////////////////////////////////////////////////////////////////////////
// MpatDraw()

// Operation:
#define M_DRAW_BOX                              0x00000020L   // Also defined in milmod.h
#define M_DRAW_POSITION                         0x00000040L   // Also defined in milmod.h
#define M_DRAW_DONT_CARE                        0x00000008L   // Also defined in milmod.h
#define M_DRAW_IMAGE                            0x00000002L   // Also defined in milmod.

// Index
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h
#define M_ALL                                   0x40000000L   // Also defined in mil.h

// ControlFlag:
#define M_ORIGINAL                              0x00000199L   // Also defined in milmod.h


////////////////////////////////////////////////////////////////////////////////
// MpatMask()

// MaskType:
#define M_DONT_CARE                             0x00008000L   // Also defined in mil.h, milcolor.h, milmod.h


////////////////////////////////////////////////////////////////////////////////
// MpatRestore(), MpatSave(), MpatStream()
#define M_INTERACTIVE                                M_NULL   // Already defined in mil.h, milcal.h, milcode.h, miledge.h, milmeas.h, milocr.h, milmod.h
#define M_PAT_MODEL_TO_CONTEXT                    0x1000000   // =Utilities=
#define M_PAT_CONTEXT_TO_MODEL                    0x2000000   // =Utilities=
#define M_PAT_CONTEXT_TO_MODEL_INDEX_MASK            0xFFFF   // =Utilities=


////////////////////////////////////////////////////////////////////////////////
// Defines for deprecated function

#define M_NO_CHANGE                                  -9998L
#define M_CLEAR_BACKGROUND                          0x2000L
#define M_ALLOC_TYPE                                   322L
#define M_NUMBER_OF_ENTRIES                             24L



/***************************************************************************/
/* Deprecated                                                              */
/***************************************************************************/

#if OldDefinesSupport
   // MIL 10 PP1
   #define M_ALL_OLD                        0L
   // MIL_DEPRECATED(M_ALL_OLD, 1010)
   #define M_DRAW_DONT_CARES                M_DRAW_DONT_CARE
   // MIL_DEPRECATED(M_DRAW_DONT_CARES, 1010)
   #define M_REJECTION_THRESHOLD            M_COARSE_SEARCH_ACCEPTANCE
   MIL_DEPRECATED(M_REJECTION_THRESHOLD, 1010)
   #define M_FIND_ALL_MODEL                 2L
   MIL_DEPRECATED(M_FIND_ALL_MODEL, 1010)
   #define M_CENTRE_X                       M_CENTER_X
   #define M_CENTRE_Y                       M_CENTER_Y
   MIL_DEPRECATED(M_CENTRE_X, 1010)
   MIL_DEPRECATED(M_CENTRE_Y, 1010)
   #define M_KEEP_PYRAMID                   M_TARGET_CACHING
   MIL_DEPRECATED(M_KEEP_PYRAMID, 1010)
   #define M_NUMBER_OF_OCCURENCES           M_NUMBER_OF_OCCURRENCES
   MIL_DEPRECATED(M_NUMBER_OF_OCCURENCES, 1010)

   // MIL 10 PP2
   #define M_MIN_SPACING_X                  M_MIN_SEPARATION_X
   MIL_DEPRECATED(M_MIN_SPACING_X, 1020)
   #define M_MIN_SPACING_Y                  M_MIN_SEPARATION_Y
   MIL_DEPRECATED(M_MIN_SPACING_Y, 1020)
   #define M_NUMBER_OF_OCCURRENCES          18L          // Deprecated: use M_NUMBER
   MIL_DEPRECATED(M_NUMBER_OF_OCCURRENCES, 1020)
   #define M_POSITION_ACCURACY              13L          // Deprecated: use M_ACCURACY
   //MIL_DEPRECATED(M_POSITION_ACCURACY, 1020)           // Also defined in milcode.h
   #define M_ACCEPTANCE_THRESHOLD           17L          // Deprecated: use M_ACCEPTANCE
   MIL_DEPRECATED(M_ACCEPTANCE_THRESHOLD, 1020)
   #define M_CERTAINTY_THRESHOLD            25L          // Deprecated: use M_CERTAINTY
   MIL_DEPRECATED(M_CERTAINTY_THRESHOLD, 1020)
   #define M_CENTER_X                        4L          // Deprecated: use M_REFERENCE_X
   //MIL_DEPRECATED(M_CENTER_X, 1020)                    // Also defined in MilMod.h
   #define M_CENTER_Y                        5L          // Deprecated: use M_REFERENCE_Y
   //MIL_DEPRECATED(M_CENTER_Y, 1020)                    // Also defined in MilMod.h
   #define M_POSITION_START_X                9L          // Deprecated: use M_SEARCH_OFFSET_X
   //MIL_DEPRECATED(M_POSITION_START_X, 1020)            // Also defined in milmetrol.h
   #define M_POSITION_START_Y               10L          // Deprecated: use M_SEARCH_OFFSET_Y
   //MIL_DEPRECATED(M_POSITION_START_Y, 1020)            // Also defined in milmetrol.h
   #define M_POSITION_UNCERTAINTY_X         11L          // Deprecated: use M_SEARCH_SIZE_X
   MIL_DEPRECATED(M_POSITION_UNCERTAINTY_X, 1020)
   #define M_POSITION_UNCERTAINTY_Y         12L          // Deprecated: use M_SEARCH_SIZE_Y
   MIL_DEPRECATED(M_POSITION_UNCERTAINTY_Y, 1020)
   #define M_MODEL_INDEX                    0x00005400L  // Deprecated: use M_INDEX
   MIL_DEPRECATED(M_MODEL_INDEX, 1020)

#endif


/********************************************************************
 * Function prototypes
 ********************************************************************/

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatAlloc(                  MIL_ID             SysId,
                                                           MIL_INT64          ContextType,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ContextPatIdPtr);

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatAllocResultNew(         MIL_ID             SysId,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ResultPatIdPtr);


#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs
MIL_PAT_DLLFUNC void    MFTYPE MpatControlInt64(           MIL_ID             ContextOrResultPatId,
                                                           MIL_INT            Index,
                                                           MIL_INT64          ControlType,
                                                           MIL_INT64          ControlValue);

MIL_PAT_DLLFUNC void    MFTYPE MpatControlDouble(          MIL_ID             ContextOrResultPatId,
                                                           MIL_INT            Index,
                                                           MIL_INT64          ControlType,
                                                           MIL_DOUBLE         ControlValue);
#else
// Prototypes for 32 bits OSs
#define MpatControlInt64  MpatControl
#define MpatControlDouble MpatControl
MIL_PAT_DLLFUNC void    MFTYPE MpatControl(                MIL_ID             ContextOrResultPatId,
                                                           MIL_INT            Index,
                                                           MIL_INT64          ControlType,
                                                           MIL_DOUBLE         ControlValue);
#endif

MIL_PAT_DLLFUNC void    MFTYPE MpatDefine(                 MIL_ID             ContextPatId,
                                                           MIL_INT64          ModelType,
                                                           MIL_ID             SrcImageBufId,
                                                           MIL_DOUBLE         Param1,
                                                           MIL_DOUBLE         Param2,
                                                           MIL_DOUBLE         Param3,
                                                           MIL_DOUBLE         Param4,
                                                           MIL_INT64          ControlFlag);

MIL_PAT_DLLFUNC void    MFTYPE MpatDraw(                   MIL_ID             ContextGraId,
                                                           MIL_ID             ContextOrResultPatId,
                                                           MIL_ID             DstImageBufOrListGraId,
                                                           MIL_INT64          Operation,
                                                           MIL_INT            Index,
                                                           MIL_INT64          ControlFlag);

MIL_PAT_DLLFUNC void    MFTYPE MpatFind(                   MIL_ID             ContextPatId,
                                                           MIL_ID             TargetImageBufId,
                                                           MIL_ID             ResultPatId);

MIL_PAT_DLLFUNC void    MFTYPE MpatFree(                   MIL_ID             ContextOrResultPatId);


MIL_PAT_DLLFUNC void    MFTYPE MpatGetResultNew(           MIL_ID             ResultPatId,
                                                           MIL_INT            Index,
                                                           MIL_INT64          ResultType,
                                                           void*              ResultArrayPtr);


MIL_PAT_DLLFUNC MIL_INT MFTYPE MpatInquireNew(             MIL_ID             ContextOrResultPatId,
                                                           MIL_INT            Index,
                                                           MIL_INT64          InquireType,
                                                           void*              UserVarPtr);

MIL_PAT_DLLFUNC void    MFTYPE MpatPreprocess(             MIL_ID             ContextPatId,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID             TypicalImageBufId);

MIL_PAT_DLLFUNC void    MFTYPE MpatMask(                   MIL_ID             ContextPatId,
                                                           MIL_INT            Index,
                                                           MIL_ID             MaskBufferId,
                                                           MIL_INT64          MaskType,
                                                           MIL_INT64          ControlFlag);

#if M_MIL_USE_UNICODE
MIL_PAT_DLLFUNC void    MFTYPE MpatSaveNewA(               const char*        FileName,
                                                           MIL_ID             ContextPatId,
                                                           MIL_INT64          ControlFlag);

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatRestoreNewA(            const char*        FileName,
                                                           MIL_ID             SysId,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ContextPatIdPtr);

MIL_PAT_DLLFUNC void    MFTYPE MpatStreamA(                char*              MemPtrOrFileName,
                                                           MIL_ID             SysId,
                                                           MIL_INT64          Operation,
                                                           MIL_INT64          StreamType,
                                                           MIL_DOUBLE         Version,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ContextPatIdPtr,
                                                           MIL_INT*           SizeByteVarPtr);

MIL_PAT_DLLFUNC void    MFTYPE MpatSaveNewW(               MIL_CONST_TEXT_PTR FileName,
                                                           MIL_ID             ContextPatId,
                                                           MIL_INT64          ControlFlag);

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatRestoreNewW(            MIL_CONST_TEXT_PTR FileName,
                                                           MIL_ID             SysId,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ContextPatIdPtr);

MIL_PAT_DLLFUNC void    MFTYPE MpatStreamW(                MIL_TEXT_PTR       MemPtrOrFileName,
                                                           MIL_ID             SysId,
                                                           MIL_INT64          Operation,
                                                           MIL_INT64          StreamType,
                                                           MIL_DOUBLE         Version,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ContextPatIdPtr,
                                                           MIL_INT*           SizeByteVarPtr);
#if M_MIL_UNICODE_API

#define MpatSaveNew        MpatSaveNewW
#define MpatRestoreNew     MpatRestoreNewW
#define MpatStream         MpatStreamW
#else
#define MpatSaveNew        MpatSaveNewA
#define MpatRestoreNew     MpatRestoreNewA
#define MpatStream         MpatStreamA
#endif

#else
MIL_PAT_DLLFUNC void    MFTYPE MpatSaveNew(                MIL_CONST_TEXT_PTR FileName,
                                                           MIL_ID             ContextPatId,
                                                           MIL_INT64          ControlFlag);

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatRestoreNew(             MIL_CONST_TEXT_PTR FileName,
                                                           MIL_ID             SysId,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ContextPatIdPtr);

MIL_PAT_DLLFUNC void    MFTYPE MpatStream(                 MIL_TEXT_PTR       MemPtrOrFileName,
                                                           MIL_ID             SysId,
                                                           MIL_INT64          Operation, 
                                                           MIL_INT64          StreamType,
                                                           MIL_DOUBLE         Version,
                                                           MIL_INT64          ControlFlag,
                                                           MIL_ID*            ContextPatIdPtr,
                                                           MIL_INT*           SizeByteVarPtr);
#endif





//////////////////////////////////////////////////////////////
// Deprecated functions.
//////////////////////////////////////////////////////////////

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatAllocAutoModel(         MIL_ID             SystemId,
                                                           MIL_ID             SrcImageBufId,
                                                           MIL_INT            SizeX,
                                                           MIL_INT            SizeY,
                                                           MIL_INT            PosUncertaintyX,
                                                           MIL_INT            PosUncertaintyY,
                                                           MIL_INT64          ModelType,
                                                           MIL_INT64          Mode,
                                                           MIL_ID*            ModelIdArrayPtr);

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatAllocModel(             MIL_ID             SystemId,
                                                           MIL_ID             SrcImageBufId,
                                                           MIL_INT            OffX,
                                                           MIL_INT            OffY,
                                                           MIL_INT            SizeX,
                                                           MIL_INT            SizeY,
                                                           MIL_INT64          ModelType,
                                                           MIL_ID*            ModelIdPtr);

MIL_PAT_DLLFUNC MIL_ID  MFTYPE MpatAllocRotatedModel(      MIL_ID             SystemId,
                                                           MIL_ID             SrcModelId,
                                                           MIL_DOUBLE         Angle,
                                                           MIL_INT64          InterpolationMode,
                                                           MIL_INT64          ModelType,
                                                           MIL_ID*            NewModelIdPtr);

MIL_PAT_DLLFUNC void    MFTYPE MpatCopy(                   MIL_ID             ModelId,
                                                           MIL_ID             DestImageBufId,
                                                           MIL_INT64          CopyMode);

MIL_PAT_DLLFUNC void    MFTYPE MpatFindModel(              MIL_ID             ImageBufId,
                                                           MIL_ID             ModelId,
                                                           MIL_ID             PatResultId);

MIL_PAT_DLLFUNC void    MFTYPE MpatFindMultipleModel(      MIL_ID             ImageBufId,
                                                           const MIL_ID*      ModelIdArrayPtr,
                                                           const MIL_ID*      PatResultIdArrayPtr,
                                                           MIL_INT            NumModels,
                                                           MIL_INT64          SearchMode);

MIL_PAT_DLLFUNC void    MFTYPE MpatFindOrientation(        MIL_ID             ImageId,
                                                           MIL_ID             ModelId,
                                                           MIL_ID             ResultId,
                                                           MIL_INT            ResultRange);

MIL_PAT_DLLFUNC void    MFTYPE MpatPreprocModel(           MIL_ID             TypicalImageBufId,
                                                           MIL_ID             ModelId,
                                                           MIL_INT64          Mode);

MIL_PAT_DLLFUNC MIL_INT MFTYPE MpatGetNumber(              MIL_ID             PatResultId,
                                                           MIL_INT*           CountPtr);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetAcceptance(          MIL_ID             ModelId,
                                                           MIL_DOUBLE         AcceptanceThreshold);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetAccuracy(            MIL_ID             ModelId,
                                                           MIL_INT64          Accuracy);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetAngle(               MIL_ID             ModelId,
                                                           MIL_INT64          ControlType,
                                                           MIL_DOUBLE         ControlValue);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetCenter(              MIL_ID             ModelId,
                                                           MIL_DOUBLE         OffX,
                                                           MIL_DOUBLE         OffY);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetCertainty(           MIL_ID             ModelId,
                                                           MIL_DOUBLE         CertaintyThreshold);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetDontCare(            MIL_ID             ModelId,
                                                           MIL_ID             ImageBufId,
                                                           MIL_INT            OffX,
                                                           MIL_INT            OffY,
                                                           MIL_INT            Value);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetNumber(              MIL_ID             ModelId,
                                                           MIL_INT            NbOccurrences);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetPosition(            MIL_ID             ModelId,
                                                           MIL_INT            OffX,
                                                           MIL_INT            OffY,
                                                           MIL_INT            SizeX,
                                                           MIL_INT            SizeY);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetSearchParameter(     MIL_ID             PatId,
                                                           MIL_INT64          Parameter,
                                                           MIL_DOUBLE         Value);

MIL_PAT_DLLFUNC void    MFTYPE MpatSetSpeed(               MIL_ID             ModelId,
                                                           MIL_INT64          SpeedFactor);



/* C++ directive if needed */
#ifdef __cplusplus
}
#endif


//////////////////////////////////////////////////////////////
// Overload or define to support Old API.
//////////////////////////////////////////////////////////////

// New API call so redirect it to the good entry point
#define MpatAllocResult          MpatAllocResultNew


#ifdef __cplusplus


// New API call so redirect it to the good entry point.
#if M_MIL_USE_UNICODE
#define MpatSaveA                MpatSaveNewA
#define MpatRestoreA             MpatRestoreNewA
#define MpatSaveW                MpatSaveNewW
#define MpatRestoreW             MpatRestoreNewW
#endif
#define MpatSave                 MpatSaveNew
#define MpatRestore              MpatRestoreNew

inline void MpatGetResult( MIL_ID             ResultPatId,
                           MIL_INT            Index,
                           MIL_INT64          ResultType,
                           void*              ResultArrayPtr)
   {
   MpatGetResultNew(ResultPatId, Index, ResultType, ResultArrayPtr);
   }
inline MIL_INT MpatInquire(MIL_ID             ContextOrResultPatId,
                           MIL_INT            Index,
                           MIL_INT64          InquireType,
                           void*              UserVarPtr)
   {
   return MpatInquireNew(ContextOrResultPatId, Index, InquireType, UserVarPtr);
   }


// Support Old API through inline in C++
inline void MpatGetResult(MIL_ID             ResultPatId,
                          MIL_INT64          ResultType,
                          void*              ResultArrayPtr)
   {
   MpatGetResult(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr);
   }


inline MIL_INT MpatInquire(MIL_ID             ContextOrResultPatId,
                           MIL_INT64          InquireType,
                           void*              UserVarPtr)
   {
   return MpatInquire(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr);
   }

#if M_MIL_USE_UNICODE
inline void MpatSaveA(const char*        FileName,
                      MIL_ID             ContextPatId)
   {
   MpatSaveA(FileName, ContextPatId, M_DEFAULT);
   }

inline MIL_ID MpatRestoreA(MIL_ID             SysId,
                           const char*        FileName,
                           MIL_ID*            ContextPatIdPtr)
   {
   return MpatRestoreA(FileName, SysId, M_DEFAULT, ContextPatIdPtr);
   }

inline void MpatSaveW(MIL_CONST_TEXT_PTR FileName,
                      MIL_ID             ContextPatId)
   {
   MpatSaveW(FileName, ContextPatId, M_DEFAULT);
   }

inline MIL_ID MpatRestoreW(MIL_ID             SysId,
                           MIL_CONST_TEXT_PTR FileName,
                           MIL_ID*            ContextPatIdPtr)
   {
   return MpatRestoreW(FileName, SysId, M_DEFAULT, ContextPatIdPtr);
   }
#else
inline void MpatSave(MIL_CONST_TEXT_PTR FileName,
                     MIL_ID             ContextPatId)
   {
   MpatSave(FileName, ContextPatId, M_DEFAULT);
   }

inline MIL_ID MpatRestore(MIL_ID             SysId,
                          MIL_CONST_TEXT_PTR FileName,
                          MIL_ID*            ContextPatIdPtr)
   {
   return MpatRestore(FileName, SysId, M_DEFAULT, ContextPatIdPtr);
   }
#endif



#else


// The default in C is the use of the old API until MIL 11.
#ifndef M_USE_OLD_MPAT_API_IN_C
#define M_USE_OLD_MPAT_API_IN_C 1
#endif

#if M_USE_OLD_MPAT_API_IN_C
#define MpatInquire(ContextOrResultPatId, InquireType, UserVarPtr) MpatInquireNew(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr)
#define MpatGetResult(ResultPatId, ResultType, ResultArrayPtr)     MpatGetResultNew(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr)
#if M_MIL_USE_UNICODE
#define MpatSaveA(FileName, ContextPatId)                          MpatSaveNewA(FileName, ContextPatId, M_DEFAULT)
#define MpatRestoreA(SysId, FileName, ContextPatIdPtr)             MpatRestoreNewA(FileName, SysId, M_DEFAULT, ContextPatIdPtr)
#define MpatSaveW(FileName, ContextPatId)                          MpatSaveNewW(FileName, ContextPatId, M_DEFAULT)
#define MpatRestoreW(SysId, FileName, ContextPatIdPtr)             MpatRestoreNewW(FileName, SysId, M_DEFAULT, ContextPatIdPtr)
#endif
#define MpatSave(FileName, ContextPatId)                           MpatSaveNew(FileName, ContextPatId, M_DEFAULT)
#define MpatRestore(SysId, FileName, ContextPatIdPtr)              MpatRestoreNew(FileName, SysId, M_DEFAULT, ContextPatIdPtr)

#else
#define MpatInquire   MpatInquireNew
#define MpatGetResult MpatGetResultNew
#if M_MIL_USE_UNICODE
#define MpatSaveA     MpatSaveNewA
#define MpatRestoreA  MpatRestoreNewA
#define MpatSaveW     MpatSaveNewW
#define MpatRestoreW  MpatRestoreNewW
#endif
#define MpatSave      MpatSaveNew
#define MpatRestore   MpatRestoreNew
#endif



#endif

//////////////////////////////////////////////////////////////
// Overload for functions that take different param type.
//////////////////////////////////////////////////////////////
#if M_MIL_USE_64BIT
#ifdef __cplusplus
//////////////////////////////////////////////////////////////
// MpatControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void MpatControl(MIL_ID      ContextOrResultPatId,
                        MIL_INT     Index,
                        MIL_INT64   ControlType,
                        int         ControlValue)
   {
   MpatControlInt64(ContextOrResultPatId, Index, ControlType, ControlValue);
   };
#endif
inline void MpatControl(MIL_ID      ContextOrResultPatId,
                        MIL_INT     Index,
                        MIL_INT64   ControlType,
                        MIL_INT32   ControlValue)
   {
   MpatControlInt64(ContextOrResultPatId, Index, ControlType, ControlValue);
   }
inline void MpatControl(MIL_ID      ContextOrResultPatId,
                        MIL_INT     Index,
                        MIL_INT64   ControlType,
                        MIL_INT64   ControlValue)
   {
   MpatControlInt64(ContextOrResultPatId, Index, ControlType, ControlValue);
   }
inline void MpatControl(MIL_ID      ContextOrResultPatId,
                        MIL_INT     Index,
                        MIL_INT64   ControlType,
                        MIL_DOUBLE  ControlValue)
   {
   MpatControlDouble(ContextOrResultPatId, Index, ControlType, ControlValue);
   }

//////////////////////////////////////////////////////////////
// MpatDefine function definition when compiling c++ files
//////////////////////////////////////////////////////////////
template<typename T1, typename T2, typename T3, typename T4>
inline void MpatDefine(MIL_ID       ContextPatId,
                       MIL_INT64    ModelType,
                       MIL_ID       SrcImageBufId,
                       T1           Param1,
                       T2           Param2,
                       T3           Param3,
                       T4           Param4,
                       MIL_INT64    ControlFlag)
   {
   MpatDefine(ContextPatId, ModelType, SrcImageBufId, static_cast<MIL_DOUBLE>(Param1), static_cast<MIL_DOUBLE>(Param2), static_cast<MIL_DOUBLE>(Param3), static_cast<MIL_DOUBLE>(Param4), ControlFlag);
   }
#else
// For C file, call the default function, i.e. Double one
#define MpatControl  MpatControlDouble
#endif // __cplusplus
#endif // M_MIL_USE_64BIT

//////////////////////////////////////////////////////////////
// Safe type functions.
//////////////////////////////////////////////////////////////
#if M_MIL_USE_SAFE_TYPE

// See milos.h for explanation about these functions.

//-------------------------------------------------------------------------------------
// MpatGetResult

inline void MFTYPE MpatGetResultUnsafe  (MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, void           *ResultArrayPtr);
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, int             ResultArrayPtr);
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_INT32      *ResultArrayPtr);
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_INT64      *ResultArrayPtr);
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_DOUBLE     *ResultArrayPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_UINT32     *ResultArrayPtr);
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_UINT64     *ResultArrayPtr);
#endif

// Old API.
inline void MFTYPE MpatGetResultUnsafe  (MIL_ID ResultPatId, MIL_INT64 ResultType, void           *ResultArrayPtr) { MpatGetResultUnsafe  (ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT64 ResultType, int             ResultArrayPtr) { MpatGetResultSafeType(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT64 ResultType, MIL_INT32      *ResultArrayPtr) { MpatGetResultSafeType(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT64 ResultType, MIL_INT64      *ResultArrayPtr) { MpatGetResultSafeType(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT64 ResultType, MIL_DOUBLE     *ResultArrayPtr) { MpatGetResultSafeType(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr); }
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT64 ResultType, MIL_UINT32     *ResultArrayPtr) { MpatGetResultSafeType(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT64 ResultType, MIL_UINT64     *ResultArrayPtr) { MpatGetResultSafeType(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr); }
#endif

// ----------------------------------------------------------
// MpatInquire

inline MIL_INT MFTYPE MpatInquireUnsafe  (MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, void           *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, int             UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_INT32      *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_INT64      *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_DOUBLE     *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_UINT32     *UserVarPtr);
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_UINT64     *UserVarPtr);
#endif


// Old API.
inline MIL_INT MFTYPE MpatInquireUnsafe  (MIL_ID ContextOrResultPatId, MIL_INT64 InquireType, void           *UserVarPtr) { return MpatInquireUnsafe  (ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr); }
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT64 InquireType, int             UserVarPtr) { return MpatInquireSafeType(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr); }
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT64 InquireType, MIL_INT32      *UserVarPtr) { return MpatInquireSafeType(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr); }
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT64 InquireType, MIL_INT64      *UserVarPtr) { return MpatInquireSafeType(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr); }
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT64 InquireType, MIL_DOUBLE     *UserVarPtr) { return MpatInquireSafeType(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr); }
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT64 InquireType, MIL_UINT32     *UserVarPtr) { return MpatInquireSafeType(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr); }
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT64 InquireType, MIL_UINT64     *UserVarPtr) { return MpatInquireSafeType(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr); }
#endif


// ----------------------------------------------------------
// MpatGetResult

inline void MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, int ResultArrayPtr)
   {
   if(ResultArrayPtr)
      SafeTypeError(MIL_TEXT("MpatGetResult"));

   MpatGetResultNew(ResultPatId, Index, ResultType, NULL);
   }

inline void MpatGetResultSafeTypeExecute(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, void        *ResultArrayPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (ResultType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_MIL_ID) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_DOUBLE))
      RequiredType = 0;
   if(RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if(RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MpatGetResult"));

   MpatGetResultNew(ResultPatId, Index, ResultType, ResultArrayPtr);
   }

inline void   MFTYPE MpatGetResultUnsafe  (MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, void       *ResultArrayPtr) { MpatGetResultNew            (ResultPatId, Index, ResultType, ResultArrayPtr                  ); }
inline void   MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_INT32  *ResultArrayPtr) { MpatGetResultSafeTypeExecute(ResultPatId, Index, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32); }
inline void   MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_INT64  *ResultArrayPtr) { MpatGetResultSafeTypeExecute(ResultPatId, Index, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64); }
inline void   MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_DOUBLE *ResultArrayPtr) { MpatGetResultSafeTypeExecute(ResultPatId, Index, ResultType, ResultArrayPtr, M_TYPE_DOUBLE   ); }
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                      
inline void   MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_UINT32 *ResultArrayPtr) { MpatGetResultSafeTypeExecute(ResultPatId, Index, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32); }
inline void   MFTYPE MpatGetResultSafeType(MIL_ID ResultPatId, MIL_INT Index, MIL_INT64 ResultType, MIL_UINT64 *ResultArrayPtr) { MpatGetResultSafeTypeExecute(ResultPatId, Index, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64); }
#endif

//--------------------------------------------------------------------------------
// MpatInquire

inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MIL_TEXT("MpatInquire"));

   return MpatInquireNew(ContextOrResultPatId, Index, InquireType, NULL);
   }

inline MIL_INT MFTYPE MpatInquireExecute(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, void  *UserVarPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (InquireType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_MIL_ID))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MpatInquire"));

   return MpatInquireNew(ContextOrResultPatId, Index, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE MpatInquireUnsafe  (MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, void        *UserVarPtr) {return MpatInquireNew    (ContextOrResultPatId, Index, InquireType, UserVarPtr                  );}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_INT32   *UserVarPtr) {return MpatInquireExecute(ContextOrResultPatId, Index, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_INT64   *UserVarPtr) {return MpatInquireExecute(ContextOrResultPatId, Index, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_DOUBLE  *UserVarPtr) {return MpatInquireExecute(ContextOrResultPatId, Index, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_UINT32  *UserVarPtr) {return MpatInquireExecute(ContextOrResultPatId, Index, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE MpatInquireSafeType(MIL_ID ContextOrResultPatId, MIL_INT Index, MIL_INT64 InquireType, MIL_UINT64  *UserVarPtr) {return MpatInquireExecute(ContextOrResultPatId, Index, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif


#define MpatGetResult        MpatGetResultSafeType
#define MpatInquire          MpatInquireSafeType

#else // #if M_MIL_USE_SAFE_TYPE


#if(!defined(__cplusplus) && M_USE_OLD_MPAT_API_IN_C)
#define MpatGetResultUnsafe(ResultPatId, ResultType, ResultArrayPtr)     MpatGetResultNew(ResultPatId, M_DEFAULT, ResultType, ResultArrayPtr)
#define MpatInquireUnsafe(ContextOrResultPatId, InquireType, UserVarPtr) MpatInquireNew(ContextOrResultPatId, M_DEFAULT, InquireType, UserVarPtr)
#else
#define MpatGetResultUnsafe MpatGetResult
#define MpatInquireUnsafe   MpatInquire
#endif


#endif // #if M_MIL_USE_SAFE_TYPE


#ifndef M_MIL_WARN_ON_DEPRECATED_MPAT
   #define M_MIL_WARN_ON_DEPRECATED_MPAT 1
#endif
#if M_MIL_WARN_ON_DEPRECATED_MPAT
   MIL_DEPRECATED(MpatAllocAutoModel    , 1020) // Use MpatAlloc() + MpatDefine(M_AUTO_MODEL) instead.
   MIL_DEPRECATED(MpatAllocModel        , 1020) // Use MpatAlloc() + MpatDefine(M_REGULAR_MODEL) instead.
   MIL_DEPRECATED(MpatAllocRotatedModel , 1020) // Use MpatAlloc() + MpatDefine(M_REGULAR_MODEL) with M_SEARCH_ANGLE_MODE enable with a specific angle (M_SEARCH_ANGLE_DELTA_NEG/POS == 0) instead.
   MIL_DEPRECATED(MpatCopy              , 1020) // Use MpatDraw() instead.
   MIL_DEPRECATED(MpatFindModel         , 1020) // Use MpatFind() instead.
   MIL_DEPRECATED(MpatFindMultipleModel , 1020) // Use MpatFind() instead and MpatControl(M_SEARCH_MODE).
   MIL_DEPRECATED(MpatFindOrientation   , 1020) // Unsupported since MIL 8
   MIL_DEPRECATED(MpatPreprocModel      , 1020) // Use MpatPreprocess() instead.
   MIL_DEPRECATED(MpatGetNumber         , 1020) // Use MpatGetResult(M_NUMBER) instead.
   MIL_DEPRECATED(MpatSetAcceptance     , 1020) // Use MpatControl(M_ACCEPTANCE) instead.
   MIL_DEPRECATED(MpatSetAccuracy       , 1020) // Use MpatControl(M_ACCURACY) instead.
   MIL_DEPRECATED(MpatSetAngle          , 1020) // Use MpatControl() instead.
   MIL_DEPRECATED(MpatSetCenter         , 1020) // Use MpatControl(M_REFERENCE_X / M_REFERENCE_Y) instead.
   MIL_DEPRECATED(MpatSetCertainty      , 1020) // Use MpatControl(M_CERTAINTY) instead.
   MIL_DEPRECATED(MpatSetDontCare       , 1020) // Use MpatMask() instead.
   MIL_DEPRECATED(MpatSetNumber         , 1020) // Use MpatControl(M_NUMBER) instead.
   MIL_DEPRECATED(MpatSetPosition       , 1020) // Use MpatControl(M_POSITION_START_XM_SEARCH_OFFSET_X / M_SEARCH_OFFSET_Y / M_SEARCH_SIZE_X / M_SEARCH_SIZE_Y) instead.
   MIL_DEPRECATED(MpatSetSearchParameter, 1020) // Use MpatControl() instead.
   MIL_DEPRECATED(MpatSetSpeed          , 1020) // Use MpatControl(M_SPEED) instead.
#endif


#endif // !M_MIL_LITE

#endif /* __MILPAT_H__ */

