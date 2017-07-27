////////////////////////////////////////////////////////////////////////////////
//! 
//! \file  milblob.h
//! 
//! \brief Milblob CAPI header (Mblob...)
//! 
//! AUTHOR: Matrox Imaging
//!
//! COPYRIGHT NOTICE:
//! Copyright © Matrox Electronic Systems Ltd., 1992-2016.
//! All Rights Reserved 
//  Revision:  10.20.0517
////////////////////////////////////////////////////////////////////////////////
#ifndef __MILBLOB_H__
#define __MILBLOB_H__

#if (!M_MIL_LITE) // MIL FULL ONLY

#if M_MIL_USE_RT
#ifdef M_BLOB_EXPORTS
#define MIL_BLOB_DLLFUNC __declspec(dllexport)
#else
#define MIL_BLOB_DLLFUNC __declspec(dllimport)
#endif
#else
#define MIL_BLOB_DLLFUNC
#endif

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
{
#endif

////////////////////////////////////////////////////////////////////////////////
// MblobAlloc()

// ContextType
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h


////////////////////////////////////////////////////////////////////////////////
// MblobControl() (no inquire)

// ControlType for context:
#define M_STOP_CALCULATE                               116L
#define M_ALL_FEATURES                               0x100L   // All features are set to M_ENABLE or M_DISABLE


////////////////////////////////////////////////////////////////////////////////
// MblobInquire() (no control)

// InquireType for context:
#define M_OWNER_SYSTEM                                1101L   // Also defined in mil.h
#define M_MODIFICATION_COUNT                          5010L   // Also defined in mil.h

// InquireType for result:
#define M_OWNER_SYSTEM                                1101L   // Also defined in mil.h
#define M_MAX_LABEL                                     16L


////////////////////////////////////////////////////////////////////////////////
// MblobControl() / MblobInquire()

// ControlType for context:
#define M_FERET_GENERAL_ANGLE                           62L   // Also defined in miledge.h
#define M_MOMENT_GENERAL_ORDER_X                      2469L
#define M_MOMENT_GENERAL_ORDER_Y                      2470L
#define M_MOMENT_GENERAL_MODE                         2471L
#define M_SORT1                                 0x02000000L
#define M_SORT2                                 0x04000000L
#define M_SORT3                                 0x06000000L
#define M_SORT1_DIRECTION                             2472L
#define M_SORT2_DIRECTION                             2473L
#define M_SORT3_DIRECTION                             2474L
#define M_BLOB_IDENTIFICATION                            2L
#define M_CONNECTIVITY                                2486L
#define M_FOREGROUND_VALUE                               4L   // Also defined in other MIL module
#define M_PIXEL_ASPECT_RATIO                             5L
#define M_SAVE_RUNS                                     14L
#define M_IDENTIFIER_TYPE                               15L
#define M_MAX_BLOBS                                     18L
#define M_NUMBER_OF_FERETS                              63L   // Also defined in miledge.h
#define M_RETURN_PARTIAL_RESULTS                        70L
#define M_FERET_ANGLE_SEARCH_START                      90L   // Also defined in miledge.h
#define M_FERET_ANGLE_SEARCH_END                        92L   // Also defined in miledge.h
#define M_TIMEOUT                                     2077L   // Also defined in mil.h

// To enable a set of features
#define M_FERET_CONTACT_POINTS                     0x30000L
// Binary only features:
#define M_BOX                                        0x101L   // Also defined in miledge.h
#define M_CONTACT_POINTS                             0x102L   // Also defined in miledge.h
#define M_CHAINS                                       209L   // Also defined in miledge.h
#define M_RUNS                                        2475L
#define M_CONVEX_HULL                                   80L
#define M_MIN_AREA_BOX                                 128L
#define M_MIN_PERIMETER_BOX                            143L
#define M_WORLD_BOX                                   1487L
#define M_FERETS                                      2476L
#define M_CONVEX_PERIMETER                              20L
#define M_FERET_GENERAL                              0x400L
#define M_FERET_PERPENDICULAR_TO_MIN_DIAMETER          123L
#define M_FERET_PERPENDICULAR_TO_MAX_DIAMETER          124L
#define M_FERET_MIN_DIAMETER_ELONGATION                125L
#define M_FERET_MAX_DIAMETER_ELONGATION                126L
#define M_RECTANGULARITY                               127L
#define M_PERIMETER                                      3L
#define M_BREADTH                                       49L
#define M_COMPACTNESS                                   25L
#define M_ELONGATION                                    50L
#define M_LENGTH                                0x00002000L
#define M_INTERCEPT                                   2477L
#define M_EULER_NUMBER                                  47L
#define M_NUMBER_OF_HOLES                               26L
#define M_ROUGHNESS                                     28L
// Grayscale only features:
#define M_BLOB_CONTRAST                                 48L
#define M_MAX_PIXEL                                     31L
#define M_MIN_PIXEL                                     30L
#define M_MEAN_PIXEL                                    32L
#define M_SUM_PIXEL                                     29L
#define M_SUM_PIXEL_SQUARED                             46L
#define M_SIGMA_PIXEL                                   33L
// Binary and grayscale features
#define M_FERET_AT_PRINCIPAL_AXIS_ANGLE                119L
#define M_FERET_AT_SECONDARY_AXIS_ANGLE                120L
#define M_FERET_PRINCIPAL_AXIS_ELONGATION              121L
#define M_CENTER_OF_GRAVITY                          0x103L   // Also defined in miledge.h
#define M_MOMENT_FIRST_ORDER                          2478L
#define M_MOMENT_SECOND_ORDER                         2479L
#define M_MOMENT_GENERAL                             0x800L
// Combination flags for binary and grayscale features
#define M_BINARY                                0x00001000L
#define M_GREYSCALE                                 0x0200L
#define M_GRAYSCALE                             M_GREYSCALE

// ControlType for result:
#define M_INPUT_SELECT_UNITS                            20L
#define M_RESULT_OUTPUT_UNITS                         1300L   // Also defined in milim.h

// ControlValue:
#define M_DEFAULT                               0x10000000L   // Also defined in mil.h
#define M_ENABLE                                     -9997L   // Also defined in mil.h
#define M_DISABLE                                    -9999L   // Also defined in mil.h
// For M_SORTn
#define M_NO_SORT                                        0L
// For M_SORTn_DIRECTION
#define M_SORT_UP                                        1L
#define M_SORT_DOWN                                      2L
// For M_MOMENT_GENERAL_MODE
#define M_ORDINARY                                   0x400L
#define M_CENTRAL                                    0x800L
// For M_CONNECTIVITY
#define M_4_CONNECTED                           0x00000010L
#define M_8_CONNECTED                           0x00000020L
// For M_BLOB_IDENTIFICATION
#define M_WHOLE_IMAGE                                    1L
#define M_INDIVIDUAL                                     2L
#define M_LABELLED                                       4L
#define M_LABELED                                M_LABELLED   // One "L" is american english while two "LL" is British.
#define M_LABELED_TOUCHING                               5L
// For M_FOREGROUND_VALUE
#define M_NONZERO                                     0x80L   // Same as M_FOREGROUND_WHITE
#define M_ZERO                                       0x100L   // Same as M_FOREGROUND_BLACK
#define M_NON_ZERO                                M_NONZERO
// For output units (M_RESULT_OUTPUT_UNITS and M_INPUT_SELECT_UNITS)
#define M_PIXEL                                     0x1000L
#define M_WORLD                                     0x2000L
#define M_ACCORDING_TO_CALIBRATION                    1301L
// For M_NUMBER_OF_FERETS 
#define M_MIN_FERETS                                     2L

////////////////////////////////////////////////////////////////////////////////
// MblobGetResult()

// LabelOrIndex:
#define M_INCLUDED_BLOBS                        0x08000000L
#define M_GENERAL                               0x20000000L   // Also defined in milmod.h, milstr.h, ...
#define M_BLOB_LABEL(BlobLabel)                 (BlobLabel)
#define M_BLOB_INDEX_FLAG                       0x04000000L   // =utilities= 
#define M_BLOB_INDEX(BlobIndex)                ((BlobIndex) | M_BLOB_INDEX_FLAG)

// ResultType:

// Always available
#define M_LABEL_VALUE                                    1L
#define M_AREA                                           2L
#define M_INDEX_VALUE                               M_INDEX   // Also defined in mil.h
#define M_BLOB_INCLUSION_STATE                       0x108L
#define M_NUMBER                                      1009L   // defined in milim.h, milmeas.h, ...
#define M_CALCULATION_TYPE                            2531L
// If ControlType M_BOX is M_ENABLE 
#define M_BOX_X_MIN                                      6L
#define M_BOX_Y_MIN                                      7L
#define M_BOX_X_MAX                                      8L
#define M_BOX_Y_MAX                                      9L
#define M_BLOB_TOUCHING_IMAGE_BORDERS                  118L
#define M_BOX_AREA                                      90L
#define M_BOX_ASPECT_RATIO                              91L
#define M_BOX_FILL_RATIO                                92L
#define M_FIRST_POINT_X                                 75L
#define M_FIRST_POINT_Y                                132L
#define M_FERET_X                                       72L
#define M_FERET_Y                                        5L
// If ControlType M_CONTACT_POINTS is M_ENABLE 
#define M_X_MIN_AT_Y_MIN                                21L
#define M_X_MAX_AT_Y_MAX                                22L
#define M_Y_MIN_AT_X_MAX                                23L
#define M_Y_MAX_AT_X_MIN                                24L
#define M_X_MIN_AT_Y_MAX                                58L
#define M_X_MAX_AT_Y_MIN                                59L
#define M_Y_MIN_AT_X_MIN                                60L
#define M_Y_MAX_AT_X_MAX                                61L
// If ControlType M_CHAINS is M_ENABLE
#define M_CHAIN_X                                       65L
#define M_CHAIN_Y                                      144L
#define M_CHAIN_INDEX                                   67L
#define M_NUMBER_OF_CHAINED_PIXELS                      56L
#define M_TOTAL_NUMBER_OF_CHAINED_PIXELS              2481L
// If ControlType M_RUNS is M_ENABLE
#define M_RUN_X                                       2482L
#define M_RUN_Y                                       2483L
#define M_RUN_LENGTH                                  2484L
#define M_NUMBER_OF_RUNS                                55L
#define M_TOTAL_NUMBER_OF_RUNS                         117L
// If ControlType M_CONVEX_HULL is M_ENABLE
#define M_CONVEX_HULL_AREA                              89L
#define M_CONVEX_HULL_COG_X                             96L
#define M_CONVEX_HULL_COG_Y                             97L
#define M_CONVEX_HULL_FILL_RATIO                        93L
#define M_CONVEX_HULL_PERIMETER                         99L
#define M_CONVEX_HULL_X                                 81L
#define M_CONVEX_HULL_Y                                 82L
#define M_CONVEX_HULL_XY_PACKED                         83L
#define M_NUMBER_OF_CONVEX_HULL_POINTS                  84L
#define M_TOTAL_NUMBER_OF_CONVEX_HULL_POINTS          2480L
// If ControlType M_MIN_AREA_BOX is M_ENABLE
#define M_MIN_AREA_BOX_X1                              129L
#define M_MIN_AREA_BOX_Y1                              130L
#define M_MIN_AREA_BOX_X2                              131L
#define M_MIN_AREA_BOX_Y2                              139L
#define M_MIN_AREA_BOX_X3                              133L
#define M_MIN_AREA_BOX_Y3                              134L
#define M_MIN_AREA_BOX_X4                              135L
#define M_MIN_AREA_BOX_Y4                              136L
#define M_MIN_AREA_BOX_AREA                            137L
#define M_MIN_AREA_BOX_PERIMETER                       138L
#define M_MIN_AREA_BOX_CENTER_X                        140L
#define M_MIN_AREA_BOX_CENTER_Y                        141L
#define M_MIN_AREA_BOX_ANGLE                           142L
#define M_MIN_AREA_BOX_WIDTH                           158L
#define M_MIN_AREA_BOX_HEIGHT                          159L
// If ControlType M_MIN_PERIMETER_BOX is M_ENABLE
#define M_MIN_PERIMETER_BOX_X1                         157L
#define M_MIN_PERIMETER_BOX_Y1                         145L
#define M_MIN_PERIMETER_BOX_X2                         146L
#define M_MIN_PERIMETER_BOX_Y2                         147L
#define M_MIN_PERIMETER_BOX_X3                         148L
#define M_MIN_PERIMETER_BOX_Y3                         149L
#define M_MIN_PERIMETER_BOX_X4                         150L
#define M_MIN_PERIMETER_BOX_Y4                         151L
#define M_MIN_PERIMETER_BOX_AREA                       152L
#define M_MIN_PERIMETER_BOX_PERIMETER                  153L
#define M_MIN_PERIMETER_BOX_CENTER_X                   154L
#define M_MIN_PERIMETER_BOX_CENTER_Y                   155L
#define M_MIN_PERIMETER_BOX_ANGLE                      156L
#define M_MIN_PERIMETER_BOX_WIDTH                      160L
#define M_MIN_PERIMETER_BOX_HEIGHT                     161L
// If ControlType M_WORLD_BOX is M_ENABLE
#define M_WORLD_FERET_X                               1465L
#define M_WORLD_FERET_Y                               1466L
#define M_WORLD_BOX_X_MIN                             1479L
#define M_WORLD_BOX_Y_MIN                             1480L
#define M_WORLD_BOX_X_MAX                             1481L
#define M_WORLD_BOX_Y_MAX                             1482L
#define M_WORLD_X_AT_Y_MIN                            1483L
#define M_WORLD_X_AT_Y_MAX                            1484L
#define M_WORLD_Y_AT_X_MIN                            1485L
#define M_WORLD_Y_AT_X_MAX                            1486L
// If ControlType M_FERETS is M_ENABLE
#define M_FERET_DIAMETERS                              122L
#define M_NUMBER_OF_FERETS                              63L   // Also defined in miledge.h
#define M_TOTAL_NUMBER_OF_FERETS                      2534L
#define M_FERET_ELONGATION                              27L
#define M_FERET_MAX_ANGLE                               17L
#define M_FERET_MIN_ANGLE                               15L
#define M_FERET_MAX_DIAMETER                            16L
#define M_FERET_MIN_DIAMETER                            14L
#define M_FERET_MEAN_DIAMETER                           18L
// If ControlType M_CONVEX_PERIMETER is M_ENABLE
#define M_CONVEX_PERIMETER                              20L
// If ControlType M_FERET_GENERAL is M_ENABLE
#define M_FERET_GENERAL                              0x400L
// If ControlType M_FERET_PERPENDICULAR_TO_MIN_DIAMETER is M_ENABLE
#define M_FERET_PERPENDICULAR_TO_MIN_DIAMETER          123L
// If ControlType M_FERET_PERPENDICULAR_TO_MAX_DIAMETER is M_ENABLE
#define M_FERET_PERPENDICULAR_TO_MAX_DIAMETER          124L
// If ControlType M_FERET_MIN_DIAMETER_ELONGATION is M_ENABLE
#define M_FERET_MIN_DIAMETER_ELONGATION                125L
// If ControlType M_FERET_MAX_DIAMETER_ELONGATION is M_ENABLE
#define M_FERET_MAX_DIAMETER_ELONGATION                126L
// If ControlType M_RECTANGULARITY is M_ENABLE
#define M_RECTANGULARITY                               127L
// If ControlType M_PERIMETER is M_ENABLE
#define M_PERIMETER                                      3L
// If ControlType M_BREADTH is M_ENABLE
#define M_BREADTH                                       49L
// If ControlType M_COMPACTNESS is M_ENABLE
#define M_COMPACTNESS                                   25L
// If ControlType M_ELONGATION is M_ENABLE
#define M_ELONGATION                                    50L
// If ControlType M_LENGTH is M_ENABLE
#define M_LENGTH                                0x00002000L
// If ControlType M_INTERCEPT is M_ENABLE
#define M_INTERCEPT_0                                   51L
#define M_INTERCEPT_45                                  52L
#define M_INTERCEPT_90                                  53L
#define M_INTERCEPT_135                                 54L
// If ControlType M_EULER_NUMBER is M_ENABLE
#define M_EULER_NUMBER                                  47L
// If ControlType M_NUMBER_OF_HOLES is M_ENABLE
#define M_NUMBER_OF_HOLES                               26L
// If ControlType M_ROUGHNESS is M_ENABLE
#define M_ROUGHNESS                                     28L
// Grayscale only features:
// If ControlType M_BLOB_CONTRAST is M_ENABLE
#define M_BLOB_CONTRAST                                 48L
// If ControlType M_MAX_PIXEL is M_ENABLE
#define M_MAX_PIXEL                                     31L
// If ControlType M_MIN_PIXEL is M_ENABLE
#define M_MIN_PIXEL                                     30L
// If ControlType M_MEAN_PIXEL is M_ENABLE
#define M_MEAN_PIXEL                                    32L
// If ControlType M_SUM_PIXEL is M_ENABLE
#define M_SUM_PIXEL                                     29L
// If ControlType M_SUM_PIXEL_SQUARED is M_ENABLE
#define M_SUM_PIXEL_SQUARED                             46L
// If ControlType M_SIGMA_PIXEL is M_ENABLE
#define M_SIGMA_PIXEL                                   33L
// Binary and grayscale features
// If ControlType M_FERET_AT_PRINCIPAL_AXIS_ANGLE is M_ENABLE
#define M_FERET_AT_PRINCIPAL_AXIS_ANGLE                119L
// If ControlType M_FERET_AT_SECONDARY_AXIS_ANGLE is M_ENABLE
#define M_FERET_AT_SECONDARY_AXIS_ANGLE                120L
// If ControlType M_FERET_PRINCIPAL_AXIS_ELONGATION is M_ENABLE
#define M_FERET_PRINCIPAL_AXIS_ELONGATION              121L
// If ControlType M_CENTER_OF_GRAVITY is M_ENABLE
#define M_CENTER_OF_GRAVITY_X                           34L
#define M_CENTER_OF_GRAVITY_Y                           35L
// If ControlType M_MOMENT_FIRST_ORDER is M_ENABLE
#define M_MOMENT_X0_Y1                                  36L
#define M_MOMENT_X1_Y0                                  37L
// If ControlType M_MOMENT_SECOND_ORDER is M_ENABLE
#define M_MOMENT_X1_Y1                                  38L
#define M_MOMENT_X0_Y2                                  39L
#define M_MOMENT_X2_Y0                                  40L
#define M_MOMENT_CENTRAL_X1_Y1                          41L
#define M_MOMENT_CENTRAL_X0_Y2                          42L
#define M_MOMENT_CENTRAL_X2_Y0                          43L
#define M_AXIS_PRINCIPAL_ANGLE                          44L
#define M_AXIS_SECONDARY_ANGLE                          45L
// If ControlType M_MOMENT_GENERAL is M_ENABLE
#define M_MOMENT_GENERAL                             0x800L
// If ControlType M_FERET_CONTACT_POINTS is M_ENABLE
// ResultType that can be mix with these defines are available.
#define M_FERET_CONTACT_POINTS_X1                  0x50000L
#define M_FERET_CONTACT_POINTS_Y1                  0x60000L
#define M_FERET_CONTACT_POINTS_X2                  0x70000L
#define M_FERET_CONTACT_POINTS_Y2                  0x80000L

// Special ResultTypes
#define M_TIMEOUT_END                                   10L   // Already defined in milmod.h
#define M_MAX_BLOBS_END                                 57L

// Result value:
#define M_YES                                            1L   // Already defined in mil.h
#define M_NO                                             0L   // Already defined in mil.h
#define M_INCLUDED                                   0x109L
#define M_EXCLUDED                                   0x110L

// Possible values for M_CALCULATION_TYPE
#define M_NOT_CALCULATED                                 0L
#define M_BINARY                                0x00001000L
#define M_BINARY_AND_GRAYSCALE                 (M_BINARY + M_GRAYSCALE)


////////////////////////////////////////////////////////////////////////////////
// MblobSelect()

// Operation:
#define M_INCLUDE                                        1L
#define M_EXCLUDE                                        2L
#define M_DELETE                                         3L
#define M_MERGE                                 0x00000040L
#define M_INCLUDE_ONLY                               0x101L
#define M_EXCLUDE_ONLY                               0x102L

// Condition:
#define M_ALWAYS                                         0L
#define M_IN_RANGE                                       1L
#define M_OUT_RANGE                                      2L
#define M_EQUAL                                          3L
#define M_NOT_EQUAL                                      4L
#define M_GREATER                                        5L
#define M_LESS                                           6L
#define M_GREATER_OR_EQUAL                               7L
#define M_LESS_OR_EQUAL                                  8L
#define M_ALL_BLOBS                             0x40000000L
#define M_INCLUDED_BLOBS                        0x08000000L
#define M_EXCLUDED_BLOBS                        0x20000000L


////////////////////////////////////////////////////////////////////////////////
// MblobReconstruct()

// Operation:
#define M_RECONSTRUCT_FROM_SEED                          1L
#define M_ERASE_BORDER_BLOBS                             2L
#define M_FILL_HOLES                                     3L
#define M_EXTRACT_HOLES                                  4L
#define M_SEED_PIXELS_ALL_IN_BLOBS                       1L
#define M_FOREGROUND_ZERO                                2L


////////////////////////////////////////////////////////////////////////////////
// MblobDraw()

// Operation:
#define M_DRAW_BOX_CENTER                       0x00000001L
#define M_DRAW_MIN_PERIMETER_BOX                0x00000002L
#define M_DRAW_MIN_AREA_BOX                     0x00000004L
#define M_DRAW_FERET_MAX                        0x00000008L
#define M_DRAW_FERET_BOX                        0x00000010L
#define M_DRAW_BOX                              0x00000020L   // Also used in other MxxxDraw()
#define M_DRAW_POSITION                         0x00000040L   // Also used in other MxxxDraw()
#define M_DRAW_CENTER_OF_GRAVITY                0x00000080L
#define M_DRAW_BLOBS_CONTOUR                    0x00000100L
#define M_DRAW_AXIS                             0x00000200L
#define M_DRAW_BLOBS                            0x00000400L
#define M_DRAW_FERET_MIN                        0x00001000L
#define M_DRAW_HOLES                            0x00002000L
#define M_DRAW_HOLES_CONTOUR                    0x00004000L
#define M_DRAW_CONVEX_HULL                      0x00008000L
#define M_DRAW_CONVEX_HULL_CONTOUR              0x00010000L
#define M_DRAW_WORLD_BOX                        0x00020000L
#define M_DRAW_WORLD_BOX_CENTER                 0x00040000L
#define M_DRAW_WORLD_FERET_X                    0x00080000L
#define M_DRAW_WORLD_FERET_Y                    0x00100000L

// Label:
#define M_ALL_BLOBS                             0x40000000L
#define M_INCLUDED_BLOBS                        0x08000000L
#define M_EXCLUDED_BLOBS                        0x20000000L


////////////////////////////////////////////////////////////////////////////////
// MblobMerge()

#define M_TOP_BOTTOM                            0x00001000L
#define M_MOVE                                  0x00010000L   // Also defined in mil.h
#define M_COPY                                  0x00020000L   // Also defined in mil.h


////////////////////////////////////////////////////////////////////////////////
// MblobLabel()

#define M_CLEAR                                 0x00000001L
#define M_NO_CLEAR                              0x00000002L


////////////////////////////////////////////////////////////////////////////////
// Defines for deprecated function

#define M_SORT1_UP                              0x02000000L   // Also defined in miledge.h
#define M_SORT2_UP                              0x04000000L   // Also defined in miledge.h
#define M_SORT3_UP                              0x06000000L   // Also defined in miledge.h
#define M_SORT1_DOWN                            0x0A000000L   // Also defined in miledge.h
#define M_SORT2_DOWN                            0x0C000000L   // Also defined in miledge.h
#define M_SORT3_DOWN                            0x0E000000L   // Also defined in miledge.h

#define M_NO_FEATURES                                0x104L
#define M_LATTICE                                        3L

#define M_CONTOUR                                    0x800L   // Also defined in mil.h





/***************************************************************************/
/* Deprecated                                                              */
/***************************************************************************/

#if OldDefinesSupport
   // MIL 10 PP1
   #define M_DRAW_RELATIVE_ORIGIN_X                    319L   // Deprecated : Use MgraControl(... M_DRAW_OFFSET_X...)
   #define M_DRAW_RELATIVE_ORIGIN_Y                    320L   // Deprecated : Use MgraControl(... M_DRAW_OFFSET_Y...)
   #define M_DRAW_SCALE_X                             3203L   // Deprecated : Use MgraControl(... M_DRAW_ZOOM_X ...)
   #define M_DRAW_SCALE_Y                             3204L   // Deprecated : Use MgraControl(... M_DRAW_ZOOM_Y ...)
   //MIL_DEPRECATED(M_DRAW_RELATIVE_ORIGIN_X, 1010)           // Already defined in mil.h
   //MIL_DEPRECATED(M_DRAW_RELATIVE_ORIGIN_Y, 1010)           // Already defined in mil.h
   //MIL_DEPRECATED(M_DRAW_SCALE_X, 1010)                     // Already defined in mil.h
   //MIL_DEPRECATED(M_DRAW_SCALE_Y, 1010)                     // Already defined in mil.h

   // MIL 10 PP2
   #define M_GENERAL_FERET                 M_FERET_GENERAL // Also defined in miledge.h
   #if !defined(MIL_DEPRECATED_M_GENERAL_FERET) || !MIL_DEPRECATED_M_GENERAL_FERET
      #define MIL_DEPRECATED_M_GENERAL_FERET 1
      MIL_DEPRECATED(M_GENERAL_FERET, 1020)
   #endif
   #define M_GENERAL_MOMENT                M_MOMENT_GENERAL
   MIL_DEPRECATED(M_GENERAL_MOMENT, 1020)
   #define M_ALL_FERETS                    M_FERET_DIAMETERS
   MIL_DEPRECATED(M_ALL_FERETS    , 1020)
#endif



/********************************************************************
 * CAPI function prototypes
 ********************************************************************/
MIL_BLOB_DLLFUNC MIL_ID  MFTYPE MblobAlloc(           MIL_ID             SysId,
                                                      MIL_INT64          ContextType,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ContextBlobIdPtr);

MIL_BLOB_DLLFUNC MIL_ID  MFTYPE MblobAllocResultNew(  MIL_ID             SysId,
                                                      MIL_INT64          ResultType,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ResultBlobIdPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobCalculate(       MIL_ID             ContextBlobId,      // Before MIL 10 PP2, was BlobIdentImageId
                                                      MIL_ID             BlobIdentImageBufId,// Before MIL 10 PP2, was GrayImageId
                                                      MIL_ID             GrayImageBufId,     // Before MIL 10 PP2, was FeatureListId
                                                      MIL_ID             ResultBlobId);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs
MIL_BLOB_DLLFUNC void    MFTYPE MblobControlInt64(    MIL_ID             ContextOrResultBlobId,
                                                      MIL_INT64          ControlType,
                                                      MIL_INT64          ControlValue);
MIL_BLOB_DLLFUNC void    MFTYPE MblobControlDouble(   MIL_ID             ContextOrResultBlobId,
                                                      MIL_INT64          ControlType,
                                                      MIL_DOUBLE         ControlValue);
#else
// Prototypes for 32 bits OSs
#define MblobControlInt64  MblobControl
#define MblobControlDouble MblobControl
MIL_BLOB_DLLFUNC void    MFTYPE MblobControl(         MIL_ID             ContextOrResultBlobId,
                                                      MIL_INT64          ControlType,
                                                      MIL_DOUBLE         ControlValue);
#endif

MIL_BLOB_DLLFUNC void    MFTYPE MblobFree(            MIL_ID             ContextOrResultBlobId);

MIL_BLOB_DLLFUNC MIL_INT MFTYPE MblobGetLabel(        MIL_ID             ResultBlobId,
                                                      MIL_INT            XPos,
                                                      MIL_INT            YPos,
                                                      MIL_INT*           LabelVarPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobGetResultNew(    MIL_ID             ResultBlobId,
                                                      MIL_INT            LabelOrIndex,
                                                      MIL_INT64          ResultType,
                                                      void*              ResultArrayPtr);

MIL_BLOB_DLLFUNC MIL_INT MFTYPE MblobInquire(         MIL_ID             ContextOrResultBlobId,
                                                      MIL_INT64          InquireType,
                                                      void*              UserVarPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobLabel(           MIL_ID             ResultBlobId,
                                                      MIL_ID             DstImageBufId,
                                                      MIL_INT64          ControlFlag);

MIL_BLOB_DLLFUNC void    MFTYPE MblobSelect(          MIL_ID             ResultBlobId,
                                                      MIL_INT64          Operation,
                                                      MIL_INT64          SelectionCriterion,
                                                      MIL_INT64          Condition,
                                                      MIL_DOUBLE         CondLow,
                                                      MIL_DOUBLE         CondHigh);

MIL_BLOB_DLLFUNC void    MFTYPE MblobReconstruct(     MIL_ID             SrcImageBufId,
                                                      MIL_ID             SeedImageBufId,
                                                      MIL_ID             DstImageBufId,
                                                      MIL_INT64          Operation,
                                                      MIL_INT64          ProcMode);

MIL_BLOB_DLLFUNC void    MFTYPE MblobMerge(           MIL_ID             SrcResultBlobId1,
                                                      MIL_ID             SrcResultBlobId2,
                                                      MIL_ID             DstResultBlobId,
                                                      MIL_INT64          ControlFlag);

MIL_BLOB_DLLFUNC void    MFTYPE MblobDraw(            MIL_ID             ContextGraId,
                                                      MIL_ID             ResultBlobId,
                                                      MIL_ID             DstImageBufOrListGraId,
                                                      MIL_INT64          Operation,
                                                      MIL_INT            LabelOrIndex,
                                                      MIL_INT64          ControlFlag);

#if M_MIL_USE_UNICODE
MIL_BLOB_DLLFUNC void    MFTYPE MblobSaveA(           const char*        FileName,
                                                      MIL_ID             ContextBlobId,
                                                      MIL_INT64          ControlFlag);

MIL_BLOB_DLLFUNC MIL_ID  MFTYPE MblobRestoreA(        const char*        FileName,
                                                      MIL_ID             SysId,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ContextBlobIdPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobStreamA(         char*              MemPtrOrFileName,
                                                      MIL_ID             SysId,
                                                      MIL_INT64          Operation,
                                                      MIL_INT64          StreamType,
                                                      MIL_DOUBLE         Version,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ContextBlobIdPtr,
                                                      MIL_INT*           SizeByteVarPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobSaveW(           MIL_CONST_TEXT_PTR FileName,
                                                      MIL_ID             ContextBlobId,
                                                      MIL_INT64          ControlFlag);

MIL_BLOB_DLLFUNC MIL_ID  MFTYPE MblobRestoreW(        MIL_CONST_TEXT_PTR FileName,
                                                      MIL_ID             SysId,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ContextBlobIdPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobStreamW(         MIL_TEXT_PTR       MemPtrOrFileName,
                                                      MIL_ID             SysId,
                                                      MIL_INT64          Operation,
                                                      MIL_INT64          StreamType,
                                                      MIL_DOUBLE         Version,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ContextBlobIdPtr,
                                                      MIL_INT*           SizeByteVarPtr);

#if M_MIL_UNICODE_API
#define MblobSave               MblobSaveW
#define MblobRestore            MblobRestoreW
#define MblobStream             MblobStreamW
#else
#define MblobSave               MblobSaveA
#define MblobRestore            MblobRestoreA
#define MblobStream             MblobStreamA
#endif

#else

MIL_BLOB_DLLFUNC void    MFTYPE MblobSave(            MIL_CONST_TEXT_PTR FileName,
                                                      MIL_ID             ContextBlobId,
                                                      MIL_INT64          ControlFlag);

MIL_BLOB_DLLFUNC MIL_ID  MFTYPE MblobRestore(         MIL_CONST_TEXT_PTR FileName,
                                                      MIL_ID             SysId,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ContextBlobIdPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobStream(          MIL_TEXT_PTR       MemPtrOrFileName,
                                                      MIL_ID             SysId,
                                                      MIL_INT64          Operation,
                                                      MIL_INT64          StreamType,
                                                      MIL_DOUBLE         Version,
                                                      MIL_INT64          ControlFlag,
                                                      MIL_ID*            ContextBlobIdPtr,
                                                      MIL_INT*           SizeByteVarPtr);

#endif



//////////////////////////////////////////////////////////////
// Deprecated functions.
//////////////////////////////////////////////////////////////

MIL_BLOB_DLLFUNC MIL_ID  MFTYPE MblobAllocFeatureList(MIL_ID             SystemId,
                                                      MIL_ID*            FeatureListIdPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobFill(            MIL_ID             BlobResId,
                                                      MIL_ID             DestImageBufId,
                                                      MIL_INT64          Criterion,
                                                      MIL_INT            Value);

MIL_BLOB_DLLFUNC MIL_INT MFTYPE MblobGetNumber(       MIL_ID             BlobResId,
                                                      MIL_INT*           CountVarPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobGetResultSingle( MIL_ID             BlobResId,
                                                      MIL_INT            LabelVal,
                                                      MIL_INT64          Feature,
                                                      void*              TargetVarPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobGetRuns(         MIL_ID             BlobResId,
                                                      MIL_INT            LabelVal,
                                                      MIL_INT64          ArrayType,
                                                      void*              RunXPtr,
                                                      void*              RunYPtr,
                                                      void*              RunLengthPtr);

MIL_BLOB_DLLFUNC void    MFTYPE MblobSelectFeature(   MIL_ID             FeatureListId,
                                                      MIL_INT64          Feature);

MIL_BLOB_DLLFUNC void    MFTYPE MblobSelectFeret(     MIL_ID             FeatureListId,
                                                      MIL_DOUBLE         Angle);

MIL_BLOB_DLLFUNC void    MFTYPE MblobSelectMoment(    MIL_ID             FeatureListId,
                                                      MIL_INT64          MomType,
                                                      MIL_INT            XMomOrder,
                                                      MIL_INT            YMomOrder);

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif


//////////////////////////////////////////////////////////////
// Overload or define to support Old API.
//////////////////////////////////////////////////////////////

#ifdef __cplusplus


// New API call so redirect it to the good entry point.
#define MblobAllocResult         MblobAllocResultNew

inline void MblobGetResult(MIL_ID             ResultBlobId,
                           MIL_INT            LabelOrIndex,
                           MIL_INT64          ResultType,
                           void*              ResultArrayPtr)
   {
   MblobGetResultNew(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr);
   }



// Support Old API through inline in C++
inline MIL_ID MblobAllocResult(MIL_ID             SysId,
                               MIL_ID*            ResultBlobIdPtr)
   {
   return MblobAllocResult(SysId, M_DEFAULT, M_DEFAULT, ResultBlobIdPtr);
   }

inline void MblobGetResult(MIL_ID             ResultBlobId,
                           MIL_INT64          ResultType,
                           void*              ResultArrayPtr)
   {
   MblobGetResult(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr);
   }


#else


// The default in C is the use of the old API until MIL 11.
#ifndef M_USE_OLD_MBLOB_API_IN_C
#define M_USE_OLD_MBLOB_API_IN_C 1
#endif

#if M_USE_OLD_MBLOB_API_IN_C
#define MblobAllocResult(SysId, ResultBlobIdPtr)                   MblobAllocResultNew(SysId, M_DEFAULT, M_DEFAULT, ResultBlobIdPtr)
#define MblobGetResult(ResultBlobId, ResultType, ResultArrayPtr)   MblobGetResultNew(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr)
#else
#define MblobAllocResult   MblobAllocResultNew
#define MblobGetResult     MblobGetResultNew
#endif


#endif




#if M_MIL_USE_64BIT
#ifdef __cplusplus

#if !M_MIL_USE_LINUX
//////////////////////////////////////////////////////////////
// MblobControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MblobControl(MIL_ID ContextOrResultBlobId, MIL_INT64 ControlType, int ControlValue)
   {
   MblobControlInt64(ContextOrResultBlobId, ControlType, ControlValue);
   };
#endif

inline void MblobControl(MIL_ID ContextOrResultBlobId, MIL_INT64 ControlType, MIL_INT32 ControlValue)
   {
   MblobControlInt64(ContextOrResultBlobId, ControlType, ControlValue);
   };

inline void MblobControl(MIL_ID ContextOrResultBlobId, MIL_INT64 ControlType, MIL_INT64 ControlValue)
   {
   MblobControlInt64(ContextOrResultBlobId, ControlType, ControlValue);
   };

inline void MblobControl(MIL_ID ContextOrResultBlobId, MIL_INT64 ControlType, MIL_DOUBLE ControlValue)
   {
   MblobControlDouble(ContextOrResultBlobId, ControlType, ControlValue);
   };
#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Int64 one
//////////////////////////////////////////////////////////////
#define MblobControl  MblobControlDouble

#endif // __cplusplus
#endif // M_MIL_USE_64BIT

#if M_MIL_USE_SAFE_TYPE

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

// ----------------------------------------------------------
// MblobGetResult

inline void MFTYPE MblobGetResultUnsafe  (MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, void*       ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, int         ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT8*   ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT16*  ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT32*  ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT64*  ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, float*      ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_DOUBLE* ResultArrayPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                       
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT8*  ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT16* ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT32* ResultArrayPtr);
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT64* ResultArrayPtr);
#endif

// Old API.
inline void MFTYPE MblobGetResultUnsafe  (MIL_ID ResultBlobId, MIL_INT64 ResultType, void*       ResultArrayPtr) { MblobGetResultUnsafe  (ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, int         ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_INT8*   ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_INT16*  ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_INT32*  ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_INT64*  ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, float*      ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_DOUBLE* ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                       
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_UINT8*  ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_UINT16* ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_UINT32* ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT64 ResultType, MIL_UINT64* ResultArrayPtr) { MblobGetResultSafeType(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr); }
#endif

// ----------------------------------------------------------
// MblobGetResultSingle

inline void MFTYPE MblobGetResultSingleUnsafe  (MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, void*       TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, int         TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT8*   TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT16*  TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT32*  TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT64*  TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, float*      TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_DOUBLE* TargetVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                               
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT8*  TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT16* TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT32* TargetVarPtr);
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT64* TargetVarPtr);
#endif

// ----------------------------------------------------------
// MblobGetRuns

inline void MFTYPE MblobGetRunsUnsafe  (MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, void*       RunXPtr, void*       RunYPtr, void*       RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, int         RunXPtr, int         RunYPtr, int         RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT8*   RunXPtr, MIL_INT8*   RunYPtr, MIL_INT8*   RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT16*  RunXPtr, MIL_INT16*  RunYPtr, MIL_INT16*  RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT32*  RunXPtr, MIL_INT32*  RunYPtr, MIL_INT32*  RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT64*  RunXPtr, MIL_INT64*  RunYPtr, MIL_INT64*  RunLengthPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                        
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT8*  RunXPtr, MIL_UINT8*  RunYPtr, MIL_UINT8*  RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT16* RunXPtr, MIL_UINT16* RunYPtr, MIL_UINT16* RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT32* RunXPtr, MIL_UINT32* RunYPtr, MIL_UINT32* RunLengthPtr);
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT64* RunXPtr, MIL_UINT64* RunYPtr, MIL_UINT64* RunLengthPtr);
#endif

// ----------------------------------------------------------
// MblobInquire

inline MIL_INT MFTYPE MblobInquireUnsafe  (MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, void*       UserVarPtr);
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, int         UserVarPtr);
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_INT32*  UserVarPtr);
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_INT64*  UserVarPtr);
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_DOUBLE* UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_UINT32* UserVarPtr);
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_UINT64* UserVarPtr);
#endif

// -------------------------------------------------------------------------
// MblobGetResult

inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, int ResultArrayPtr)
   {
   if(ResultArrayPtr)
      SafeTypeError(MIL_TEXT("MblobGetResult"));

   MblobGetResultNew(ResultBlobId, LabelOrIndex, ResultType, NULL);
   }

inline void MblobGetResultSafeTypeExecute(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, void* ResultArrayPtr, MIL_INT64 GivenType)
   {
   MIL_INT64  RequiredType = (ResultType & M_HLVLDATATYPE_MASK);

   if((RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_FLOAT) && 
      (RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_CHAR) && (RequiredType != M_TYPE_SHORT)) 
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MblobGetResult"));

   MblobGetResultNew(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr);
   }

inline void MFTYPE MblobGetResultUnsafe  (MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, void*       ResultArrayPtr) {MblobGetResultNew            (ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr                  );}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT8*   ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_CHAR     );}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT16*  ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT    );}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT32*  ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_INT64*  ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64);}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, float*      ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_FLOAT    );}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_DOUBLE* ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                       
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT8*  ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_CHAR     );}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT16* ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT    );}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT32* ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MblobGetResultSafeType(MIL_ID ResultBlobId, MIL_INT LabelOrIndex, MIL_INT64 ResultType, MIL_UINT64* ResultArrayPtr) {MblobGetResultSafeTypeExecute(ResultBlobId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64);}
#endif

// -------------------------------------------------------------------------
// MblobGetResultSingle

inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, int TargetVarPtr)
   {
   if (TargetVarPtr)
      SafeTypeError(MIL_TEXT("MblobGetResultSingle"));

   MblobGetResultSingle(BlobResId, LabelVal, Feature, NULL);
   }

inline void MblobGetResultSingleSafeTypeExecute(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, void* TargetVarPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (Feature & M_HLVLDATATYPE_MASK);

   if((RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_FLOAT) && 
      (RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_CHAR) && (RequiredType != M_TYPE_SHORT)) 
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MblobGetResultSingle"));

   MblobGetResultSingle(BlobResId, LabelVal, Feature, TargetVarPtr);
   }

inline void MFTYPE MblobGetResultSingleUnsafe  (MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, void*       TargetVarPtr) {MblobGetResultSingle               (BlobResId, LabelVal, Feature, TargetVarPtr                  );}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT8*   TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_CHAR     );}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT16*  TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_SHORT    );}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT32*  TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_INT64*  TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_MIL_INT64);}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, float*      TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_FLOAT    );}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_DOUBLE* TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                               
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT8*  TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_CHAR     );}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT16* TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_SHORT    );}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT32* TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MblobGetResultSingleSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  Feature, MIL_UINT64* TargetVarPtr) {MblobGetResultSingleSafeTypeExecute(BlobResId, LabelVal, Feature, TargetVarPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// MblobGetRuns

inline void MFTYPE MblobGetRunsSafeTypeExecute(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, void* RunXPtr, void* RunYPtr, void* RunLengthPtr, MIL_INT64  ExpectedType)
   {
   MIL_INT64  RequiredType = (ArrayType & M_HLVLDATATYPE_MASK);

   if((RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_FLOAT) && 
      (RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_CHAR) && (RequiredType != M_TYPE_SHORT)) 
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;

   if (RequiredType != ExpectedType)
      SafeTypeError(MIL_TEXT("MblobGetRuns"));

   MblobGetRuns(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr);
   }
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, int RunXPtr, int RunYPtr, int RunLengthPtr)
   {
   if (RunXPtr || RunYPtr || RunLengthPtr)
      SafeTypeError(MIL_TEXT("MblobGetRuns"));

   MblobGetRuns(BlobResId, LabelVal, ArrayType, NULL, NULL, NULL);
   }

inline void MFTYPE MblobGetRunsUnsafe  (MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, void*       RunXPtr, void*       RunYPtr, void*       RunLengthPtr) {MblobGetRuns               (BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr                  );}
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT8*   RunXPtr, MIL_INT8*   RunYPtr, MIL_INT8*   RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_CHAR     );}
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT16*  RunXPtr, MIL_INT16*  RunYPtr, MIL_INT16*  RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_SHORT    );}
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT32*  RunXPtr, MIL_INT32*  RunYPtr, MIL_INT32*  RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_INT64*  RunXPtr, MIL_INT64*  RunYPtr, MIL_INT64*  RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_MIL_INT64);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                        
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT8*  RunXPtr, MIL_UINT8*  RunYPtr, MIL_UINT8*  RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_CHAR     );}
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT16* RunXPtr, MIL_UINT16* RunYPtr, MIL_UINT16* RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_SHORT    );}
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT32* RunXPtr, MIL_UINT32* RunYPtr, MIL_UINT32* RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MblobGetRunsSafeType(MIL_ID BlobResId, MIL_INT LabelVal, MIL_INT64  ArrayType, MIL_UINT64* RunXPtr, MIL_UINT64* RunYPtr, MIL_UINT64* RunLengthPtr) {MblobGetRunsSafeTypeExecute(BlobResId, LabelVal, ArrayType, RunXPtr, RunYPtr, RunLengthPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// MblobInquire

inline MIL_INT MFTYPE MblobInquireSafeType (MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MIL_TEXT("MblobInquire"));

   return MblobInquire(ResOrFeatListBlobId, InquireType, NULL);
   }


inline MIL_INT MFTYPE MblobInquireSafeTypeExecute (MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, void* UserVarPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (InquireType & M_HLVLDATATYPE_MASK);

   if((RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_MIL_ID) && 
      (RequiredType != M_TYPE_DOUBLE) ) 
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MblobInquire"));

   return MblobInquire(ResOrFeatListBlobId, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE MblobInquireUnsafe  (MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, void*       UserVarPtr) {return MblobInquire               (ResOrFeatListBlobId, InquireType, UserVarPtr                  );}
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_INT32*  UserVarPtr) {return MblobInquireSafeTypeExecute(ResOrFeatListBlobId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_INT64*  UserVarPtr) {return MblobInquireSafeTypeExecute(ResOrFeatListBlobId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_DOUBLE* UserVarPtr) {return MblobInquireSafeTypeExecute(ResOrFeatListBlobId, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_UINT32* UserVarPtr) {return MblobInquireSafeTypeExecute(ResOrFeatListBlobId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE MblobInquireSafeType(MIL_ID ResOrFeatListBlobId, MIL_INT64  InquireType, MIL_UINT64* UserVarPtr) {return MblobInquireSafeTypeExecute(ResOrFeatListBlobId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

#define MblobGetResult       MblobGetResultSafeType
#define MblobGetResultSingle MblobGetResultSingleSafeType
#define MblobGetRuns         MblobGetRunsSafeType
#define MblobInquire         MblobInquireSafeType

#else // #if M_MIL_USE_SAFE_TYPE

#define MblobGetResultSingleUnsafe MblobGetResultSingle
#define MblobGetRunsUnsafe         MblobGetRuns
#define MblobInquireUnsafe         MblobInquire


#if(!defined(__cplusplus) && M_USE_OLD_MBLOB_API_IN_C)
#define MblobGetResultUnsafe(ResultBlobId, ResultType, ResultArrayPtr)     MblobGetResultNew(ResultBlobId, M_DEFAULT, ResultType, ResultArrayPtr)
#else
#define MblobGetResultUnsafe       MblobGetResult
#endif



#endif // #if M_MIL_USE_SAFE_TYPE


#ifndef M_MIL_WARN_ON_DEPRECATED_MBLOB
   #define M_MIL_WARN_ON_DEPRECATED_MBLOB 1
#endif
#if defined(M_MIL_WARN_ON_DEPRECATED_MBLOB) && M_MIL_WARN_ON_DEPRECATED_MBLOB
   MIL_DEPRECATED(MblobAllocFeatureList, 1020) // Use MblobAlloc() instead.
   MIL_DEPRECATED(MblobFill            , 1020) // Use MblobDraw() instead.
   MIL_DEPRECATED(MblobGetNumber       , 1020) // Use MblobGetResult(M_NUMBER) instead.
   MIL_DEPRECATED(MblobGetResultSingle , 1020) // Use MblobGetResult() instead.
   MIL_DEPRECATED(MblobGetRuns         , 1020) // Use MblobGetResult() instead.
   MIL_DEPRECATED(MblobSelectFeature   , 1020) // Use MblobControl() instead.
   MIL_DEPRECATED(MblobSelectFeret     , 1020) // Use MblobControl() instead.
   MIL_DEPRECATED(MblobSelectMoment    , 1020) // Use MblobControl() instead.

   // For defines used in deprecated functions
   MIL_DEPRECATED(M_NO_FEATURES        , 1020) // Use MblobControl(M_ALL_FEATURES, M_DISABLE)
   MIL_DEPRECATED(M_LATTICE            , 1020) // Use MblobControl(ContextBlobId, M_CONNECTIVITY)
#endif

#endif // !M_MIL_LITE

#endif /* __MILBLOB_H__ */
