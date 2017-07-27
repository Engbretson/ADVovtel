////////////////////////////////////////////////////////////////////////////////
//! 
//! \file  mil3dmap.h
//! 
//! \brief Mil3dmap CAPI header (M3dmap...)
//! 
//! AUTHOR: Matrox Imaging
//!
//! COPYRIGHT NOTICE:
//! Copyright © Matrox Electronic Systems Ltd., 1992-2015.
//! All Rights Reserved 
//  Revision:  10.10.0614
////////////////////////////////////////////////////////////////////////////////

#ifndef __MIL_3DMAP_H__
#define __MIL_3DMAP_H__

#if (!M_MIL_LITE) /* MIL FULL ONLY */

#if M_MIL_USE_RT
#ifdef M_3DMAP_EXPORTS
#define MIL_3DMAP_DLLFUNC __declspec(dllexport)
#else
#define MIL_3DMAP_DLLFUNC __declspec(dllimport)
#endif
#else
#define MIL_3DMAP_DLLFUNC
#endif

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
   {
#endif

////////////////////////////////////////////////////////////////////////////////
// M3dmapAlloc ContextTypes

#define M_LASER                                       1L
#define M_GEOMETRY                                 1306L
#define M_PAIRWISE_ALIGNMENT_CONTEXT               1939L

// ControlFlags for M_LASER ContextType
#define M_CALIBRATED_CAMERA_LINEAR_MOTION             1L
#define M_DEPTH_CORRECTION                            2L

// Combination flags for M_CALIBRATED_CAMERA_LINEAR_MOTION
#define M_LASER_OFFSET                               16                // =utilities=
#define M_LASER_LABEL_FLAG                  0x40000000L                // =utilities=
#define M_LASER_LABEL(LaserLabel)    ( ((LaserLabel) << M_LASER_OFFSET) | M_LASER_LABEL_FLAG )

#define M_CAMERA_OFFSET                               3                // =utilities=
#define M_CAMERA_LABEL_FLAG                 0x20000000L                // =utilities=
#define M_CAMERA_LABEL(CameraLabel)  ( ((CameraLabel) << M_CAMERA_OFFSET) | M_CAMERA_LABEL_FLAG )

// Indexing, used in other M3dmap functions (M3dmapInquire(), M3dmapControl(), ...)
#define M_CONTEXT                            0x08000000L // already defined in mil.h
#define M_GENERAL                            0x20000000L // already defined in milmod.h, milstr.h, ...
#define M_ALL                                0x40000000L // already defined in mil.h

#define M_POINT_CLOUD_LABEL_FLAG             0x18000000L               // =utilities=      
#define M_POINT_CLOUD_LABEL(PointCloudLabel)    ((PointCloudLabel) | M_POINT_CLOUD_LABEL_FLAG)

#define M_POINT_CLOUD_INDEX_FLAG             0x28000000L               // =utilities= 
#define M_POINT_CLOUD_INDEX(PointCloudIndex)    ((PointCloudIndex) | M_POINT_CLOUD_INDEX_FLAG)

////////////////////////////////////////////////////////////////////////////////
// M3dmapAllocResult ResultTypes

#define M_STAT_RESULT                              1307L
#define M_LASER_CALIBRATION_DATA                   1901L
#define M_DEPTH_CORRECTED_DATA                     1902L
#define M_POINT_CLOUD_CONTAINER                    1903L
#define M_ALIGNMENT_RESULT                         1921L

////////////////////////////////////////////////////////////////////////////////
// M3dmapControl/M3dmapInquire

// ControlTypes for 3d reconstruction contexts

#define M_SCAN_SPEED                                  2L


#define M_CORRECTED_DEPTH                            18L

#define M_CALIBRATION_STATUS                        159L // Already defined in milcal.h

#define M_CAMERA_IMAGE_SIZE_X                      1303L
#define M_CAMERA_IMAGE_SIZE_Y                      1304L
#define M_EXTRACTION_CHILD_OFFSET_X                1308L
#define M_EXTRACTION_CHILD_OFFSET_Y                1309L
#define M_EXTRACTION_FIXED_POINT                   1310L
#define M_LASER_CONTEXT_TYPE                       1313L
#define M_CALIBRATION_DEPTHS                       1314L
#define M_NUMBER_OF_CALIBRATION_DEPTHS             1315L
#define M_NUMBER_OF_MISSING_DATA_PER_COLUMN        1316L
#define M_NUMBER_OF_COLUMNS                        1317L
#define M_NUMBER_OF_COLUMNS_WITH_MISSING_DATA      1318L
#define M_NUMBER_OF_INVERSIONS_PER_COLUMN          1319L
#define M_NUMBER_OF_COLUMNS_WITH_INVERSIONS        1320L
#define M_FIT_RMS_ERROR                            1333L
#define M_LASER_PLANE_A                            1385L
#define M_LASER_PLANE_B                            1386L
#define M_LASER_PLANE_C                            1387L
#define M_LASER_PLANE_D                            1388L
#define M_LASER_LABEL_VALUE                        1871L
#define M_CAMERA_LABEL_VALUE                       1872L
#define M_ASSUMED_PERPENDICULAR_TO_MOTION          1878L
#define M_EXTRACTION_RANGE_Z_LIMIT1                1904L
#define M_EXTRACTION_RANGE_Z_LIMIT2                1905L
#define M_EXTRACTION_RANGE_Z                       1913L
#define M_LOCATE_PEAK_1D_CONTEXT_ID                2003L


// ControlTypes for 3d reconstruction result buffers

#define M_FILL_MODE                                   3L
#define M_FILL_SHARP_ELEVATION                        4L
#define M_FILL_SHARP_ELEVATION_DEPTH                  5L

#define M_MAX_FRAMES                                 17L

#define M_PIXEL_SIZE_X                              139L // Already defined in mildisplay.h, milcal.h
#define M_PIXEL_SIZE_Y                              140L // Already defined in mildisplay.h, milcal.h
#define M_WORLD_POS_X                               207L // Already defined in milcal.h
#define M_WORLD_POS_Y                               208L // Already defined in milcal.h
#define M_EXTRACTION_CUMULATIVE                    1311L
#define M_EXTRACTION_SCALE_MODE                    1312L
#define M_GRAY_LEVEL_SIZE_Z                        1370L // Already defined in milcal.h
#define M_WORLD_POS_Z                              1371L // Already defined in milcal.h

#define M_FILL_THRESHOLD_X                         1674L
#define M_FILL_THRESHOLD_Y                         1675L
#define M_EXTRACTION_SATURATION                    1859L
#define M_EXTRACTION_OVERLAP                       1860L
#define M_RESULTS_DISPLACEMENT_MODE                1898L
#define M_RESULTS_DISPLACEMENT_Y                   1899L
#define M_NUMBER_OF_POINT_CLOUDS                   1916L

#define M_EXTRACTION_BOX_DEFINED                   1974L
#define M_EXTRACTION_BOX_MIN_X                     1975L
#define M_EXTRACTION_BOX_MIN_Y                     1976L
#define M_EXTRACTION_BOX_MIN_Z                     1977L
#define M_EXTRACTION_BOX_MAX_X                     1978L
#define M_EXTRACTION_BOX_MAX_Y                     1979L
#define M_EXTRACTION_BOX_MAX_Z                     1980L
#define M_EXTRACTION_BOX_CENTER_X                  1981L
#define M_EXTRACTION_BOX_CENTER_Y                  1982L
#define M_EXTRACTION_BOX_CENTER_Z                  1983L
#define M_EXTRACTION_BOX_SIZE_X                    1984L
#define M_EXTRACTION_BOX_SIZE_Y                    1985L
#define M_EXTRACTION_BOX_SIZE_Z                    1986L

#define M_AUTO_SCALE_ASPECT_RATIO                  1987L
#define M_AUTO_SCALE_XY                            1988L
#define M_AUTO_SCALE_Z                             1989L

#define M_BOUNDING_BOX_ALGORITHM                   1990L
#define M_BOUNDING_BOX_OUTLIER_RATIO_X             1991L
#define M_BOUNDING_BOX_OUTLIER_RATIO_Y             1992L
#define M_BOUNDING_BOX_OUTLIER_RATIO_Z             1993L
#define M_BOUNDING_BOX_SECURITY_FACTOR_X           1994L
#define M_BOUNDING_BOX_SECURITY_FACTOR_Y           1995L
#define M_BOUNDING_BOX_SECURITY_FACTOR_Z           1996L
#define M_BOUNDING_BOX_CLAMP_TO_INLIERS            1997L

// ControlTypes for point clouds

#define M_MAX_FRAMES                                 17L
#define M_LASER_LABEL_VALUE                        1871L
#define M_CAMERA_LABEL_VALUE                       1872L
#define M_POINT_CLOUD_TYPE                         1915L
#define M_POINT_CLOUD_ORGANIZED                    1920L
#define M_POINT_CLOUD_LABEL_VALUE                  1937L
#define M_POINT_CLOUD_INDEX_VALUE                  1938L

// ControlTypes for geometry objects

#define M_GEOMETRY_TYPE                            1321L
#define M_FIT_PARAM_AX                             1322L
#define M_FIT_PARAM_AY                             1325L
#define M_FIT_PARAM_Z0                             1330L
#define M_GEOMETRY_DEFINITION_TYPE                 1332L
#define M_ALIGN_RMS_ERROR                          M_FIT_RMS_ERROR

#define M_STATUS                             0x00008002L // Already defined in milcode.h, milcolor.h, miledge.h

// ControlTypes for 3d pairwise alignment contexts

#define M_DECIMATION_STEP_MODEL                    1940L
#define M_DECIMATION_STEP_SCENE                    1941L
#define M_PREALIGNMENT_MODE                        1942L
#define M_MODEL_OVERLAP                            1947L
#define M_MAX_ITERATIONS                           1504L // Already defined in milmeas.h
#define M_ALIGN_RMS_ERROR_THRESHOLD                1951L
#define M_ALIGN_RMS_ERROR_RELATIVE_THRESHOLD       1952L

// Control Values for M_FILL_MODE

#define M_DISABLE                                 -9999L // Already defined in milblob.h, milcal.h, milmeas.h, mil.h, ...
#define M_X_THEN_Y                                    1L
#define M_Y_THEN_X                                 1773L

// Control Values for M_FILL_SHARP_ELEVATION

#define M_DISABLE                                 -9999L // Already defined in milblob.h, milcal.h, milmeas.h, mil.h, ...
#define M_MIN                                0x02000000L // Already defined in mil.h, milim.h, ...
#define M_MAX                                0x04000000L // Already defined in mil.h, milim.h, ...

// Control Values for M_FILL_SHARP_ELEVATION_DEPTH

#define M_INFINITE                                   -1L // Already defined in mil.h, milstr.h, milreg.h, milmetrol.h

// Control Values for M_EXTRACTION_SCALE_MODE

#define M_AUTO_SCALE                                  2L // Already defined in mil.h, mildisplay.h
#define M_USER_DEFINED                               21L // Already defined in mil.h, milcal.h, milcol.h, ...
#define M_USE_DESTINATION_CALIBRATION            0x0040L // Already defined in milcal.h

// Control Values for M_CALIBRATION_STATUS

#define M_CALIBRATED                          0x0000300L // Already defined in milcal.h, milmod.h
#define M_LASER_LINE_NOT_DETECTED                     2L
#define M_NOT_INITIALIZED                             3L // Already defined in milcal.h
#define M_NOT_ENOUGH_MEMORY                           4L
#define M_INTERNAL_ERROR                              5L
#define M_MATHEMATICAL_EXCEPTION                      8L // Already defined in milcal.h
#define M_GLOBAL_OPTIMIZATION_ERROR                1879L

// Control Values for M_STATUS

#define M_SUCCESS                            0x00000000L // Already defined in milreg.h, milcolor.h
#define M_NOT_INITIALIZED                             3L // Already defined in milcal.h
#define M_NOT_ENOUGH_VALID_DATA                    1336L
#define M_ALL_POINTS_COLINEAR                      1337L

// Control Values for M_GEOMETRY_DEFINITION_TYPE

#define M_FIT                                    0x0020L // Already defined in milcal.h, milmetrol.h
#define M_PARAMETRIC                             0x0021L // Already defined in milmetrol.h

// Control Values for M_EXTRACTION_OVERLAP

#define M_OVERWRITE                                1861L
#define M_MIN                                0x02000000L // Already defined in mil.h, milim.h, ...
#define M_MAX                                0x04000000L // Already defined in mil.h, milim.h, ...

// Control Values for M_RESULTS_DISPLACEMENT_MODE

#define M_FIXED                                    0x50L // Already defined in milim.h
#define M_CURRENT                            0x00000002L // Already defined in mil.h

// Control Values for M_AUTO_SCALE_ASPECT_RATIO

#define M_UNCONSTRAINED                              -2L

// Control Values for M_AUTO_SCALE_XY

#define M_CLIP                                   0x0010L // Already defined in mil.h, milcal.h
#define M_FIT                                    0x0020L // Already defined in milcal.h, milmetrol.h

// Control Values for M_AUTO_SCALE_Z

#define M_POSITIVE                                    2L // Already defined in milmeas.h
#define M_NEGATIVE                                   -2L // Already defined in milmeas.h

// Control Values for M_BOUNDING_BOX_ALGORITHM

#define M_ALL_POINTS                               1998L
#define M_ROBUST                                   1999L

// Inquire values for M_POINT_CLOUD_TYPE

#define M_LASER_SCAN                               1917L
#define M_UNORGANIZED                              1919L

// Control Values for M_PREALIGNMENT_MODE

#define M_USER_DEFINED                               21L // Already defined in mil.h, milcal.h, milcol.h, ...
#define M_CENTROID                                 1956L


////////////////////////////////////////////////////////////////////////////////
// M3dmapAddScan ControlFlags

#define M_EXTRACT_LINE                             1338L
#define M_LINE_ALREADY_EXTRACTED                   1339L

////////////////////////////////////////////////////////////////////////////////
// M3dmapClear Operations

#define M_CLEAR                              0x00000001L // Already defined in mil.h, mildisplay.h, ...
#define M_DELETE                                      3L // Already defined in mil.h, milblob.h, ...
#define M_REMOVE_LAST_SCAN                         1493L

////////////////////////////////////////////////////////////////////////////////
// M3dmapCalibrateMultiple ControlFlags

#define M_ALLOW_DUPLICATES                   0x08000000L

////////////////////////////////////////////////////////////////////////////////
// M3dmapExtract Operations

#define M_CORRECTED_DEPTH_MAP                         1L
#define M_UNCORRECTED_DEPTH_MAP                    1341L
#define M_FILL_MISSING_DATA_ONLY                   1342L

////////////////////////////////////////////////////////////////////////////////
// M3dmapGetResult ResultTypes

#define M_SCAN_LANE_DIRECTION                         1  // Already defined in milim.h
#define M_NUMBER_OF_3D_POINTS                         5L
#define M_CORRECTED_DEPTH_MAP_SIZE_X                  6L
#define M_CORRECTED_DEPTH_MAP_SIZE_Y                  7L
#define M_CORRECTED_DEPTH_MAP_BUFFER_TYPE             8L
#define M_INTENSITY_MAP_BUFFER_TYPE                   9L
#define M_CAMERA_IMAGE_SIZE_X                      1303L
#define M_CAMERA_IMAGE_SIZE_Y                      1304L
#define M_UNCORRECTED_DEPTH_MAP_FIXED_POINT        1343L
#define M_UNCORRECTED_DEPTH_MAP_SIZE_X             1344L
#define M_UNCORRECTED_DEPTH_MAP_SIZE_Y             1345L
#define M_UNCORRECTED_DEPTH_MAP_BUFFER_TYPE        1346L
#define M_NUMBER_OF_MISSING_DATA_LAST_SCAN         1348L
#define M_TOTAL_DISPLACEMENT_Y                     1896L
#define M_HAS_FEATURE                        0x08000000L

// Combination flags for M_NUMBER_OF_3D_POINTS

#define M_NO_INVALID_POINT                   0x04000000L
#define M_LAST_SCAN                          0x20000000L

// Combination flags for M_HAS_FEATURE

#define M_POSITION                           0x00000402L // Already defined in milmeas.h, miledge.h, milmetrol.h
#define M_INTENSITY                                  52L // Already defined in milbead.h
#define M_XYZ                                      1935L
#define M_XYZI                                     1936L

// Pairwise alignment ResultTypes

#define M_STATUS                             0x00008002L // Already defined in milcode.h, milcolor.h, miledge.h
#define M_NB_ITERATIONS                            1893L // Already defined in milim.h
#define M_ALIGN_RMS_ERROR                M_FIT_RMS_ERROR // Already defined in mil3dmap.h
#define M_ALIGN_RMS_ERROR_RELATIVE                 1973L
#define M_ALIGNMENT_MATRIX                         1950L
#define M_SCORE                              0x00001400L // Already defined in milbead.h, milclas.h, milcode.h, ...

// Combination flag for M_ALIGN_RMS_ERROR, M_ALIGNMENT_MATRIX, M_SCORE

#define M_ALL_ITERATIONS                     0x01000000L

// Result values for M_STATUS

#define M_NOT_INITIALIZED                               3L // Already defined in milcal.h
#define M_MAX_ITERATIONS_REACHED                     1965L
#define M_ALIGN_RMS_ERROR_THRESHOLD_REACHED          1970L
#define M_ALIGN_RMS_ERROR_RELATIVE_THRESHOLD_REACHED 1971L
#define M_NOT_ENOUGH_POINT_PAIRS                     1972L

////////////////////////////////////////////////////////////////////////////////
// M3dmapGet/M3dmapPut

#define M_INVALID_POINT_FLOAT           3.402823466e+38F

// Features

#define M_POSITION                           0x00000402L // Already defined in milmeas.h, miledge.h, milmetrol.h
#define M_INTENSITY                                  52L // Already defined in milbead.h
#define M_XYZ                                      1935L
#define M_XYZI                                     1936L

// Options

#define M_NO_INVALID_POINT                   0x04000000L
#define M_LAST_SCAN                          0x20000000L

// Type

#define M_UNSIGNED                           0x00000000L             // Already defined in mil.h
#define M_SIGNED                             0x08000000L             // Already defined in mil.h
#define M_FLOAT                             (0x40000000L | M_SIGNED) // Already defined in mil.h

////////////////////////////////////////////////////////////////////////////////
// M3dmapTriangulate ControlFlags

#define M_NO_INVALID_POINT                   0x04000000L

////////////////////////////////////////////////////////////////////////////////
// M3dmapSetGeometry

// GeometryTypes
#define M_HORIZONTAL_PLANE                         1352L
#define M_PLANE                                    1353L

// OperationTypes
#define M_FIT                                    0x0020L // Already defined in milcal.h, milmetrol.h
#define M_PARAMETRIC                             0x0021L // Already defined in milmetrol.h

////////////////////////////////////////////////////////////////////////////////
// M3dmapDraw Operations

#define M_DRAW_PEAKS_LAST                          1305L
#define M_DRAW_GEOMETRY                            1357L
#define M_DRAW_REGION_VALID                        1380L
#define M_DRAW_REGION_INTERPOLATED                 1381L
#define M_DRAW_REGION_UNCALIBRATED                 1382L
#define M_DRAW_REGION_MISSING_DATA                 1383L
#define M_DRAW_REGION_INVERTED                     1384L
#define M_DRAW_CALIBRATION_LINES                   1391L
#define M_DRAW_CALIBRATION_PEAKS                   1678L

////////////////////////////////////////////////////////////////////////////////
// M3dmapStat/M3dmapGetResult

// StatTypes
#define M_DEVIATION_MEAN                           1358L
#define M_DEVIATION_MAX                            1359L
#define M_VOLUME                                   1360L
#define M_NUMBER_OF_PIXELS_VALID                   1362L
#define M_NUMBER_OF_PIXELS_OUTLIER                 1363L
#define M_NUMBER_OF_PIXELS_MISSING_DATA            1364L
#define M_NUMBER_OF_PIXELS_TOTAL                   1365L

// StatType combination flags
#define M_STAT_POSITIVE                          0x1000L
#define M_STAT_NEGATIVE                          0x2000L
#define M_STAT_ABS                               0x4000L
#define M_STAT_ALL                               0x8000L

////////////////////////////////////////////////////////////////////////////////
// M3dmapArith

// Operations
#define M_ADD                                    0x0000L // Already defined in milim.h
#define M_SUB                                    0x0001L // Already defined in milim.h
#define M_SUB_ABS                                0x0011L // Already defined in milim.h
#define M_MIN                                0x02000000L // Already defined in milim.h
#define M_MAX                                0x04000000L // Already defined in milim.h

// ControlFlags
#define M_USE_DESTINATION_SCALES                   1335L
#define M_FIT_SCALES                               1366L
#define M_SET_WORLD_OFFSET_Z                       1367L

////////////////////////////////////////////////////////////////////////////////
// M3dmapImport

// FileFormats
#define M_PLY                                      1964L

////////////////////////////////////////////////////////////////////////////////
// M3dmapSetBox

// BoxType
#define M_EXTRACTION_BOX                           1L

// BoxDefinitionType
#define M_CORNER_AND_DIMENSION               0x00000001L // Already defined in mil.h
#define M_CENTER_AND_DIMENSION               0x00000002L // Already defined in mil.h
#define M_BOUNDING_BOX                       0x00000003L 
#define M_BOTH_CORNERS                       0x00000004L // Already defined in mil.h
#define M_DEPTH_MAP                          0x00800000L // Already defined in milcal.h

////////////////////////////////////////////////////////////////////////////////
// Other defines

// Possible value for OutlierDistanceWorld, MaxRadius
#define M_INFINITE                                   -1L // Already defined in mil.h

////////////////////////////////////////////////////////////////////////////////
// Deprecated

////////////////////////////////////////////////////////////////////////////////
// Deprecated names, kept for code backward compatibility

#if OldDefinesSupport
   // M3dmapControl/M3dmapInquire
   #define M_FILL_GAP_MODE                    M_FILL_SHARP_ELEVATION
   #define M_FILL_GAP_DEPTH                   M_FILL_SHARP_ELEVATION_DEPTH

   MIL_DEPRECATED(M_FILL_GAP_MODE , 1010)
   MIL_DEPRECATED(M_FILL_GAP_DEPTH, 1010)
#endif

////////////////////////////////////////////////////////////////////////////////
// Deprecated values, kept for binary backward compatibility

#if OldDefinesSupport
   // M3dmapAllocResult
   #define M_LASER_DATA                                  1L // Deprecated, use other result types

   // M3dmapControl/M3dmapInquire
   #define M_MIN_INTENSITY                              12L // Deprecated, use MimControl(M_MINIMUM_CONTRAST)
   #define M_DEPRECATED_GRAY_LEVEL_SIZE_Z              141L // Deprecated, use M_GRAY_LEVEL_SIZE_Z
   #define M_WORLD_OFFSET_X                            142L // Deprecated, use M3dmapSetBox
   #define M_WORLD_OFFSET_Y                            143L // Deprecated, use M3dmapSetBox
   #define M_WORLD_OFFSET_Z                            144L // Deprecated, use M3dmapSetBox

   #define M_TOP_WHITE                          0x00040000L // Deprecated, use M_AUTO_SCALE_Z with M_NEGATIVE
   #define M_TOP_BLACK                          0x00080000L // Deprecated, use M_AUTO_SCALE_Z with M_POSITIVE

   // M3dmapAddScan
   #define M_CLEAR_DATA                               1340L // Deprecated, use M3dmapClear()

   // M3dmapGetResult ResultTypes
   #define M_3D_POINTS_X                                 1L // Deprecated, use M3dmapGet()
   #define M_3D_POINTS_Y                                 2L // Deprecated, use M3dmapGet()
   #define M_3D_POINTS_Z                                 3L // Deprecated, use M3dmapGet()
   #define M_3D_POINTS_I                                 4L // Deprecated, use M3dmapGet()
   #define M_DEPTH_CORRECTION_STATE                   1347L // Deprecated, use MappInquireObject(M_OBJECT_TYPE)
   #define M_UNCORRECTED                              1349L // Deprecated, use MappInquireObject(M_OBJECT_TYPE)
   #define M_PARTIALLY_CORRECTED                      1350L // Deprecated, use MappInquireObject(M_OBJECT_TYPE)
   #define M_FULLY_CORRECTED                          1351L // Deprecated, use MappInquireObject(M_OBJECT_TYPE)

   MIL_DEPRECATED(M_LASER_DATA                  , 1010)
   MIL_DEPRECATED(M_MIN_INTENSITY               , 1010)
   MIL_DEPRECATED(M_DEPRECATED_GRAY_LEVEL_SIZE_Z, 1010)
   MIL_DEPRECATED(M_WORLD_OFFSET_X              , 1010)
   MIL_DEPRECATED(M_WORLD_OFFSET_Y              , 1010)
   MIL_DEPRECATED(M_WORLD_OFFSET_Z              , 1010)
   MIL_DEPRECATED(M_TOP_WHITE                   , 1010)
   MIL_DEPRECATED(M_TOP_BLACK                   , 1010)
   MIL_DEPRECATED(M_CLEAR_DATA                  , 1010)
   MIL_DEPRECATED(M_3D_POINTS_X                 , 1010)
   MIL_DEPRECATED(M_3D_POINTS_Y                 , 1010)
   MIL_DEPRECATED(M_3D_POINTS_Z                 , 1010)
   MIL_DEPRECATED(M_3D_POINTS_I                 , 1010)
   MIL_DEPRECATED(M_DEPTH_CORRECTION_STATE      , 1010)
   MIL_DEPRECATED(M_UNCORRECTED                 , 1010)
   MIL_DEPRECATED(M_PARTIALLY_CORRECTED         , 1010)
   MIL_DEPRECATED(M_FULLY_CORRECTED             , 1010)
#endif

////////////////////////////////////////////////////////////////////////////////
// CAPI function prototypes

MIL_3DMAP_DLLFUNC MIL_ID MFTYPE M3dmapAlloc(MIL_ID     SysId,
                                            MIL_INT64  ContextType,
                                            MIL_INT64  ControlFlag,
                                            MIL_ID*    ContextOrGeometry3dmapIdPtr);

MIL_3DMAP_DLLFUNC MIL_ID MFTYPE M3dmapAllocResult(MIL_ID     SysId,
                                                  MIL_INT64  ResultType,
                                                  MIL_INT64  ControlFlag,
                                                  MIL_ID*    Result3dmapIdPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapFree(MIL_ID M3dmapId);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapClear(MIL_ID    Result3dmapId,
                                          MIL_INT   LabelOrIndex,
                                          MIL_INT64 Operation,
                                          MIL_INT64 ControlFlag);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs
MIL_3DMAP_DLLFUNC void MFTYPE M3dmapControlInt64(MIL_ID     ContextOrResult3dmapId,
                                                 MIL_INT    LabelOrIndex,
                                                 MIL_INT64  ControlType,
                                                 MIL_INT64  ControlValue);
MIL_3DMAP_DLLFUNC void MFTYPE M3dmapControlDouble(MIL_ID     ContextOrResult3dmapId,
                                                  MIL_INT    LabelOrIndex,
                                                  MIL_INT64  ControlType,
                                                  MIL_DOUBLE ControlValue);
#else
// Prototypes for 32 bits OSs
#define M3dmapControlInt64  M3dmapControl
#define M3dmapControlDouble M3dmapControl
MIL_3DMAP_DLLFUNC void MFTYPE M3dmapControl(MIL_ID     ContextOrResult3dmapId,
                                            MIL_INT    LabelOrIndex,
                                            MIL_INT64  ControlType,
                                            MIL_DOUBLE ControlValue);
#endif

MIL_3DMAP_DLLFUNC MIL_INT MFTYPE M3dmapInquire(MIL_ID     M3dmapId,
                                               MIL_INT    LabelOrIndex,
                                               MIL_INT64  InquireType,
                                               void*      UserVarPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapAddScan(MIL_ID     Context3dmapId,
                                            MIL_ID     Result3dmapId,
                                            MIL_ID     LaserOrDepthMapImageBufId, 
                                            MIL_ID     IntensityImageBufId,
                                            MIL_ID     ExtraInfoArrayId,
                                            MIL_INT    PointCloudLabel,
                                            MIL_INT64  ControlFlag);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapCalibrate(MIL_ID     Context3dmapId,
                                              MIL_ID     Result3dmapId,
                                              MIL_ID     ContextCalId,
                                              MIL_INT64  ControlFlag);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapCalibrateMultiple(const MIL_ID* Context3dmapIdArrayPtr,
                                                      const MIL_ID* Result3dmapIdArrayPtr ,
                                                      const MIL_ID* ContextCalIdArrayPtr  ,
                                                      MIL_INT       ArraySize             ,
                                                      MIL_INT64     ControlFlag           );

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapExtract(MIL_ID     Result3dmapId,
                                            MIL_ID     DepthMapImageBufId,
                                            MIL_ID     IntensityMapImageBufId,
                                            MIL_INT64  Operation,
                                            MIL_INT    LabelOrIndex,
                                            MIL_INT64  ControlFlag);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapGetResult(MIL_ID     Result3dmapId,
                                              MIL_INT    LabelOrIndex,
                                              MIL_INT64  ResultType,
                                              void*      ResultArrayPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapPut(MIL_ID      Result3dmapId         ,
                                        MIL_INT     LabelOrIndex          ,
                                        MIL_INT64   Feature               ,
                                        MIL_INT64   Type                  ,
                                        MIL_INT     ArraySize             ,
                                        const void* Coord1OrPackedArrayPtr,
                                        const void* Coord2ArrayPtr        ,
                                        const void* Coord3ArrayPtr        ,
                                        MIL_ID      CalibratedMilObjectId ,
                                        MIL_INT64   ControlFlag           );

MIL_3DMAP_DLLFUNC MIL_INT MFTYPE M3dmapGet(MIL_ID      Result3dmapId         ,
                                           MIL_INT     LabelOrIndex          ,
                                           MIL_INT64   Feature               ,
                                           MIL_INT64   Options               ,
                                           MIL_INT64   Type                  ,
                                           MIL_INT     ArraySize             ,
                                           void*       Coord1OrPackedArrayPtr,
                                           void*       Coord2ArrayPtr        ,
                                           void*       Coord3ArrayPtr        ,
                                           MIL_INT*    NeededSizePtr         );

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapTriangulate(const MIL_ID*     ContextCalOrImageBufIdArrayPtr,
                                                const MIL_DOUBLE* PixelCoordXArrayPtr,
                                                const MIL_DOUBLE* PixelCoordYArrayPtr,
                                                MIL_DOUBLE*       WorldCoordXArrayPtr,
                                                MIL_DOUBLE*       WorldCoordYArrayPtr,
                                                MIL_DOUBLE*       WorldCoordZArrayPtr,
                                                MIL_DOUBLE*       RMSErrorArrayPtr,
                                                MIL_INT           NumCalibrations,
                                                MIL_INT           NumPoints,
                                                MIL_INT64         CoordinateSystem,
                                                MIL_INT64         ControlFlag);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapSetGeometry(MIL_ID     Geometry3dmapId,
                                                MIL_INT64  GeometryType,
                                                MIL_INT64  OperationType,
                                                MIL_DOUBLE Param1,
                                                MIL_DOUBLE Param2,
                                                MIL_DOUBLE Param3,
                                                MIL_DOUBLE Param4,
                                                MIL_DOUBLE Param5);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapDraw(MIL_ID     ContextGraId,
                                         MIL_ID     M3dmapId,
                                         MIL_ID     DstImageBufOrListGraId,
                                         MIL_INT64  Operation,
                                         MIL_INT    LabelOrIndex,
                                         MIL_INT64  ControlFlag);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapStat(MIL_ID      ImageBufId,
                                         MIL_ID      ImageBufOrGeometry3dmapId,
                                         MIL_ID      MaskBufId,
                                         MIL_ID      Result3dmapId,
                                         MIL_INT64   StatType,
                                         MIL_DOUBLE  OutlierDistanceWorld,
                                         MIL_INT64   ControlFlag,
                                         MIL_DOUBLE* StatValuePtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapArith(MIL_ID     Src1ImageBufOrGeometry3dmapId,
                                          MIL_ID     Src2ImageBufOrGeometry3dmapId,
                                          MIL_ID     DstImageBufId,
                                          MIL_ID     MaskBufId,
                                          MIL_INT64  Operation,
                                          MIL_INT64  ControlFlag);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapAlign(MIL_ID      Context3dmapId,
                                          MIL_ID      ModelResult3dmapId,
                                          MIL_INT     ModelLabelOrIndex,
                                          MIL_ID      SceneResult3dmapId,
                                          MIL_INT     SceneLabelOrIndex,
                                          MIL_ID      PreAlignmentResult3dmapOrArrayBufId,
                                          MIL_ID      AlignmentResult3dmapOrArrayBufId,
                                          MIL_INT64   ControlFlag,
                                          MIL_INT64*  StatusPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapSetBox(MIL_ID     Result3dmapId    ,
                                           MIL_INT64  BoxType          ,
                                           MIL_INT64  BoxDefinitionType,
                                           MIL_DOUBLE XPos1OrSource    ,
                                           MIL_DOUBLE YPos1            ,
                                           MIL_DOUBLE ZPos1            ,
                                           MIL_DOUBLE XPos2OrLength    ,
                                           MIL_DOUBLE YPos2OrLength    ,
                                           MIL_DOUBLE ZPos2OrLength    );

#if M_MIL_USE_UNICODE
MIL_3DMAP_DLLFUNC void MFTYPE M3dmapSaveA(const char* FileName,
                                          MIL_ID      ContextOrGeometry3dmapId,
                                          MIL_INT64   ControlFlag);

MIL_3DMAP_DLLFUNC MIL_ID MFTYPE M3dmapRestoreA(const char* FileName,
                                               MIL_ID      SysId,
                                               MIL_INT64   ControlFlag,
                                               MIL_ID*     ContextOrGeometry3dmapIdPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapStreamA(char*      MemPtrOrFileName,
                                            MIL_ID     SysId,
                                            MIL_INT64  Operation,
                                            MIL_INT64  StreamType,
                                            MIL_DOUBLE Version,
                                            MIL_INT64  ControlFlag,
                                            MIL_ID*    ContextOrGeometry3dmapIdPtr,
                                            MIL_INT*   SizeByteVarPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapImportA(const char* FileName             ,
                                            MIL_INT64   FileFormat           ,
                                            MIL_ID      Result3dmapId        ,
                                            MIL_INT     PointCloudLabel      ,
                                            MIL_ID      CalibratedMilObjectId,
                                            MIL_INT64   ControlFlag          );

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapSaveW(MIL_CONST_TEXT_PTR FileName,
                                          MIL_ID             ContextOrGeometry3dmapId,
                                          MIL_INT64          ControlFlag);

MIL_3DMAP_DLLFUNC MIL_ID MFTYPE M3dmapRestoreW(MIL_CONST_TEXT_PTR FileName,
                                               MIL_ID             SysId,
                                               MIL_INT64          ControlFlag,
                                               MIL_ID*            ContextOrGeometry3dmapIdPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapStreamW(MIL_TEXT_PTR MemPtrOrFileName,
                                            MIL_ID       SysId,
                                            MIL_INT64    Operation,
                                            MIL_INT64    StreamType,
                                            MIL_DOUBLE   Version,
                                            MIL_INT64    ControlFlag,
                                            MIL_ID*      ContextOrGeometry3dmapIdPtr,
                                            MIL_INT*     SizeByteVarPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapImportW(MIL_CONST_TEXT_PTR FileName             ,
                                            MIL_INT64          FileFormat           ,
                                            MIL_ID             Result3dmapId        ,
                                            MIL_INT            PointCloudLabel      ,
                                            MIL_ID             CalibratedMilObjectId,
                                            MIL_INT64          ControlFlag          );

#if M_MIL_UNICODE_API
#define M3dmapSave           M3dmapSaveW
#define M3dmapRestore        M3dmapRestoreW
#define M3dmapStream         M3dmapStreamW
#define M3dmapImport         M3dmapImportW
#else
#define M3dmapSave           M3dmapSaveA
#define M3dmapRestore        M3dmapRestoreA
#define M3dmapStream         M3dmapStreamA
#define M3dmapImport         M3dmapImportA
#endif

#else
MIL_3DMAP_DLLFUNC void MFTYPE M3dmapSave(MIL_CONST_TEXT_PTR FileName,
                                         MIL_ID             ContextOrGeometry3dmapId,
                                         MIL_INT64          ControlFlag);

MIL_3DMAP_DLLFUNC MIL_ID MFTYPE M3dmapRestore(MIL_CONST_TEXT_PTR FileName,
                                              MIL_ID             SysId,
                                              MIL_INT64          ControlFlag,
                                              MIL_ID*            ContextOrGeometry3dmapIdPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapStream(MIL_TEXT_PTR MemPtrOrFileName,
                                           MIL_ID       SystemId,
                                           MIL_INT64    Operation,
                                           MIL_INT64    StreamType,
                                           MIL_DOUBLE   Version,
                                           MIL_INT64    ControlFlag,
                                           MIL_ID*      ObjectIdPtr,
                                           MIL_INT*     SizeByteVarPtr);

MIL_3DMAP_DLLFUNC void MFTYPE M3dmapImport(MIL_CONST_TEXT_PTR FileName             ,
                                           MIL_INT64          FileFormat           ,
                                           MIL_ID             Result3dmapId        ,
                                           MIL_INT            PointCloudLabel      ,
                                           MIL_ID             CalibratedMilObjectId,
                                           MIL_INT64          ControlFlag          );
#endif

// Internal functions: do not use in an application.
MIL_3DMAP_DLLFUNC void MFTYPE M3dmapInternalGetCoordinateSystem(MIL_ID ContextOrResultId,       MIL_DOUBLE* CoordinateSystem4x4ArrayPtr);
MIL_3DMAP_DLLFUNC void MFTYPE M3dmapInternalSetCoordinateSystem(MIL_ID          ResultId, const MIL_DOUBLE* CoordinateSystem4x4ArrayPtr);

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif
////////////////////////////////////////////////////////////////////////////////

#if M_MIL_USE_64BIT
#ifdef __cplusplus
//////////////////////////////////////////////////////////////
// M3dmapControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void M3dmapControl(MIL_ID ContextOrResult3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ControlType, int ControlValue)
   {
   M3dmapControlInt64(ContextOrResult3dmapId, LabelOrIndex, ControlType, ControlValue);
   };
#endif
inline void M3dmapControl(MIL_ID ContextOrResult3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ControlType, MIL_INT32 ControlValue)
   {
   M3dmapControlInt64(ContextOrResult3dmapId, LabelOrIndex, ControlType, ControlValue);
   };

inline void M3dmapControl(MIL_ID ContextOrResult3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ControlType, MIL_INT64 ControlValue)
   {
   M3dmapControlInt64(ContextOrResult3dmapId, LabelOrIndex, ControlType, ControlValue);
   };

inline void M3dmapControl(MIL_ID ContextOrResult3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ControlType, MIL_DOUBLE ControlValue)
   {
   M3dmapControlDouble(ContextOrResult3dmapId, LabelOrIndex, ControlType, ControlValue);
   };
#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Double one
//////////////////////////////////////////////////////////////
#define M3dmapControl  M3dmapControlDouble

#endif // __cplusplus
#endif // M_MIL_USE_64BIT

#if M_MIL_USE_SAFE_TYPE

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------
//  M3dmapGetResult

inline void MFTYPE M3dmapGetResultUnsafe  (MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, void*       ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, int         ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT8*   ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT16*  ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT32*  ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT64*  ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, float*      ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_DOUBLE* ResultArrayPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                      
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT8*  ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT16* ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT32* ResultArrayPtr);
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT64* ResultArrayPtr);
#endif

// ----------------------------------------------------------
// M3dmapInquire

inline MIL_INT MFTYPE M3dmapInquireUnsafe  (MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, void*       UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, int         UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT8*   UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT16*  UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT32*  UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT64*  UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, float*      UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_DOUBLE* UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT8*  UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT16* UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT32* UserVarPtr);
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT64* UserVarPtr);
#endif                                                                               
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                                                      
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, wchar_t*    UserVarPtr);
#endif

// -------------------------------------------------------------------------
// M3dmapGetResult

inline void MFTYPE M3dmapGetResultSafeType (MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, int ResultPtr)
   {
   if (ResultPtr != 0)
      SafeTypeError(MIL_TEXT("M3dmapGetResult"));

   M3dmapGetResult(Result3dmapId, LabelOrIndex, ResultType, NULL);
   }

inline void M3dmapGetResultSafeTypeExecute (MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, void* ResultArrayPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (ResultType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID) && (RequiredType != M_TYPE_FLOAT) && (RequiredType != M_TYPE_CHAR) && (RequiredType != M_TYPE_SHORT))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("M3dmapGetResult"));

   M3dmapGetResult(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr);
   }


inline void MFTYPE M3dmapGetResultUnsafe  (MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, void*       ResultArrayPtr){M3dmapGetResult               (Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr                  );}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT8*   ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_CHAR     );}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT16*  ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT    );}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT32*  ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_INT64*  ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64);}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, float*      ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_FLOAT    );}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_DOUBLE* ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                      
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT8*  ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_CHAR     );}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT16* ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT    );}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT32* ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE M3dmapGetResultSafeType(MIL_ID Result3dmapId, MIL_INT LabelOrIndex, MIL_INT64  ResultType, MIL_UINT64* ResultArrayPtr){M3dmapGetResultSafeTypeExecute(Result3dmapId, LabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// M3dmapInquire

inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, int UserVarPtr)
   {
   if (UserVarPtr != 0)
      SafeTypeError(MIL_TEXT("M3dmapInquire"));

   return M3dmapInquire(M3dmapId, LabelOrIndex, InquireType, NULL);
   }

inline MIL_INT MFTYPE M3dmapInquireSafeTypeExecute(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, void* UserVarPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (InquireType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID) && (RequiredType != M_TYPE_FLOAT) && (RequiredType != M_TYPE_CHAR) && (RequiredType != M_TYPE_SHORT))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("M3dmapInquire"));

   return M3dmapInquire(M3dmapId, LabelOrIndex, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE M3dmapInquireUnsafe  (MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, void*       UserVarPtr) {return M3dmapInquire               (M3dmapId, LabelOrIndex, InquireType, UserVarPtr                  );}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT8*   UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_CHAR     );}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT16*  UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_SHORT    );}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT32*  UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_INT64*  UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, float*      UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_FLOAT    );}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_DOUBLE* UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT8*  UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_CHAR     );}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT16* UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_SHORT    );}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT32* UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, MIL_UINT64* UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif                                                                               
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                                                      
inline MIL_INT MFTYPE M3dmapInquireSafeType(MIL_ID M3dmapId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, wchar_t*    UserVarPtr) {return M3dmapInquireSafeTypeExecute(M3dmapId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_SHORT    );}
#endif

// ----------------------------------------------------------
// M3dmapGet

struct MilVoidPtr
   {
   inline MilVoidPtr(int         NullPtr     ) : m_IntVal (NullPtr     ), m_PtrType( 0             ) {}
   inline MilVoidPtr(MIL_UINT8  *MilUInt8Ptr ) : m_VoidPtr(MilUInt8Ptr ), m_PtrType( 8 + M_UNSIGNED) {}
   inline MilVoidPtr(MIL_UINT16 *MilUInt16Ptr) : m_VoidPtr(MilUInt16Ptr), m_PtrType(16 + M_UNSIGNED) {}
   inline MilVoidPtr(MIL_UINT32 *MilUInt32Ptr) : m_VoidPtr(MilUInt32Ptr), m_PtrType(32 + M_UNSIGNED) {}
   inline MilVoidPtr(MIL_UINT64 *MilUInt64Ptr) : m_VoidPtr(MilUInt64Ptr), m_PtrType(64 + M_UNSIGNED) {}
   inline MilVoidPtr(MIL_INT8   *MilInt8Ptr  ) : m_VoidPtr(MilInt8Ptr  ), m_PtrType( 8 + M_SIGNED  ) {}
   inline MilVoidPtr(MIL_INT16  *MilInt16Ptr ) : m_VoidPtr(MilInt16Ptr ), m_PtrType(16 + M_SIGNED  ) {}
   inline MilVoidPtr(MIL_INT32  *MilInt32Ptr ) : m_VoidPtr(MilInt32Ptr ), m_PtrType(32 + M_SIGNED  ) {}
   inline MilVoidPtr(MIL_INT64  *MilInt64Ptr ) : m_VoidPtr(MilInt64Ptr ), m_PtrType(64 + M_SIGNED  ) {}
   inline MilVoidPtr(MIL_FLOAT  *MilFloatPtr ) : m_VoidPtr(MilFloatPtr ), m_PtrType(32 + M_FLOAT   ) {}
   inline MilVoidPtr(MIL_DOUBLE *MilDoublePtr) : m_VoidPtr(MilDoublePtr), m_PtrType(64 + M_FLOAT   ) {}

   union
      {
      void*   m_VoidPtr;
      MIL_INT m_IntVal;
      };
   MIL_INT64  m_PtrType;
   };

inline MIL_INT MFTYPE M3dmapGetUnsafe(MIL_ID      Result3dmapId         ,
                                      MIL_INT     LabelOrIndex          ,
                                      MIL_INT64   Feature               ,
                                      MIL_INT64   Options               ,
                                      MIL_INT64   Type                  ,
                                      MIL_INT     ArraySize             ,
                                      void*       Coord1OrPackedArrayPtr,
                                      void*       Coord2ArrayPtr        ,
                                      void*       Coord3ArrayPtr        ,
                                      MIL_INT*    NeededSizePtr         )
   {
   return M3dmapGet(Result3dmapId         ,
                    LabelOrIndex          ,
                    Feature               ,
                    Options               ,
                    Type                  ,
                    ArraySize             ,
                    Coord1OrPackedArrayPtr,
                    Coord2ArrayPtr        ,
                    Coord3ArrayPtr        ,
                    NeededSizePtr         );
   }

inline void M3dmapGetValidatePtrType(MilVoidPtr UserPtr, MIL_INT64 UserType)
   {
   if (UserPtr.m_PtrType == 0)
      {
      if (UserPtr.m_IntVal != 0)
         SafeTypeError(MIL_TEXT("M3dmapGet"));
      }
   else
      {
      if (UserPtr.m_PtrType != UserType)
         SafeTypeError(MIL_TEXT("M3dmapGet"));
      }
   }

inline MIL_INT MFTYPE M3dmapGetSafeType(MIL_ID      Result3dmapId         ,
                                        MIL_INT     LabelOrIndex          ,
                                        MIL_INT64   Feature               ,
                                        MIL_INT64   Options               ,
                                        MIL_INT64   Type                  ,
                                        MIL_INT     ArraySize             ,
                                        MilVoidPtr  Coord1OrPackedArrayPtr,
                                        MilVoidPtr  Coord2ArrayPtr        ,
                                        MilVoidPtr  Coord3ArrayPtr        ,
                                        MIL_INT*    NeededSizePtr         )
   {
   M3dmapGetValidatePtrType(Coord1OrPackedArrayPtr, Type);
   M3dmapGetValidatePtrType(Coord2ArrayPtr        , Type);
   M3dmapGetValidatePtrType(Coord3ArrayPtr        , Type);

   return M3dmapGet(Result3dmapId                   ,
                    LabelOrIndex                    ,
                    Feature                         ,
                    Options                         ,
                    Type                            ,
                    ArraySize                       ,
                    Coord1OrPackedArrayPtr.m_VoidPtr,
                    Coord2ArrayPtr        .m_VoidPtr,
                    Coord3ArrayPtr        .m_VoidPtr,
                    NeededSizePtr                   );
   }

// ----------------------------------------------------------
// M3dmapPut

struct MilConstVoidPtr
   {
   inline MilConstVoidPtr(int               NullPtr     ) : m_IntVal      (NullPtr     ), m_PtrType( 0             ) {}
   inline MilConstVoidPtr(const MIL_UINT8  *MilUInt8Ptr ) : m_ConstVoidPtr(MilUInt8Ptr ), m_PtrType( 8 + M_UNSIGNED) {}
   inline MilConstVoidPtr(const MIL_UINT16 *MilUInt16Ptr) : m_ConstVoidPtr(MilUInt16Ptr), m_PtrType(16 + M_UNSIGNED) {}
   inline MilConstVoidPtr(const MIL_UINT32 *MilUInt32Ptr) : m_ConstVoidPtr(MilUInt32Ptr), m_PtrType(32 + M_UNSIGNED) {}
   inline MilConstVoidPtr(const MIL_UINT64 *MilUInt64Ptr) : m_ConstVoidPtr(MilUInt64Ptr), m_PtrType(64 + M_UNSIGNED) {}
   inline MilConstVoidPtr(const MIL_INT8   *MilInt8Ptr  ) : m_ConstVoidPtr(MilInt8Ptr  ), m_PtrType( 8 + M_SIGNED  ) {}
   inline MilConstVoidPtr(const MIL_INT16  *MilInt16Ptr ) : m_ConstVoidPtr(MilInt16Ptr ), m_PtrType(16 + M_SIGNED  ) {}
   inline MilConstVoidPtr(const MIL_INT32  *MilInt32Ptr ) : m_ConstVoidPtr(MilInt32Ptr ), m_PtrType(32 + M_SIGNED  ) {}
   inline MilConstVoidPtr(const MIL_INT64  *MilInt64Ptr ) : m_ConstVoidPtr(MilInt64Ptr ), m_PtrType(64 + M_SIGNED  ) {}
   inline MilConstVoidPtr(const MIL_FLOAT  *MilFloatPtr ) : m_ConstVoidPtr(MilFloatPtr ), m_PtrType(32 + M_FLOAT   ) {}
   inline MilConstVoidPtr(const MIL_DOUBLE *MilDoublePtr) : m_ConstVoidPtr(MilDoublePtr), m_PtrType(64 + M_FLOAT   ) {}

   union
      {
      const void* m_ConstVoidPtr;
      MIL_INT     m_IntVal;
      };
   MIL_INT64      m_PtrType;
   };

inline void MFTYPE M3dmapPutUnsafe(MIL_ID      Result3dmapId         ,
                                   MIL_INT     LabelOrIndex          ,
                                   MIL_INT64   Feature               ,
                                   MIL_INT64   Type                  ,
                                   MIL_INT     ArraySize             ,
                                   const void* Coord1OrPackedArrayPtr,
                                   const void* Coord2ArrayPtr        ,
                                   const void* Coord3ArrayPtr        ,
                                   MIL_ID      CalibratedMilObjectId ,
                                   MIL_INT64   ControlFlag           )
   {
   M3dmapPut(Result3dmapId         ,
             LabelOrIndex          ,
             Feature               ,
             Type                  ,
             ArraySize             ,
             Coord1OrPackedArrayPtr,
             Coord2ArrayPtr        ,
             Coord3ArrayPtr        ,
             CalibratedMilObjectId ,
             ControlFlag           );
   }

inline void M3dmapPutValidatePtrType(MilConstVoidPtr UserPtr, MIL_INT64 UserType)
   {
   if (UserPtr.m_PtrType == 0)
      {
      if (UserPtr.m_IntVal != 0)
         SafeTypeError(MIL_TEXT("M3dmapPut"));
      }
   else
      {
      if (UserPtr.m_PtrType != UserType)
         SafeTypeError(MIL_TEXT("M3dmapPut"));
      }
   }

inline void MFTYPE M3dmapPutSafeType(MIL_ID          Result3dmapId         ,
                                     MIL_INT         LabelOrIndex          ,
                                     MIL_INT64       Feature               ,
                                     MIL_INT64       Type                  ,
                                     MIL_INT         ArraySize             ,
                                     MilConstVoidPtr Coord1OrPackedArrayPtr,
                                     MilConstVoidPtr Coord2ArrayPtr        ,
                                     MilConstVoidPtr Coord3ArrayPtr        ,
                                     MIL_ID          CalibratedMilObjectId ,
                                     MIL_INT64       ControlFlag           )
   {
   M3dmapPutValidatePtrType(Coord1OrPackedArrayPtr, Type);
   M3dmapPutValidatePtrType(Coord2ArrayPtr        , Type);
   M3dmapPutValidatePtrType(Coord3ArrayPtr        , Type);

   M3dmapPut(Result3dmapId                        ,
             LabelOrIndex                         ,
             Feature                              ,
             Type                                 ,
             ArraySize                            ,
             Coord1OrPackedArrayPtr.m_ConstVoidPtr,
             Coord2ArrayPtr        .m_ConstVoidPtr,
             Coord3ArrayPtr        .m_ConstVoidPtr,
             CalibratedMilObjectId                ,
             ControlFlag                          );
   }

#define M3dmapGetResult        M3dmapGetResultSafeType
#define M3dmapInquire          M3dmapInquireSafeType
#define M3dmapGet              M3dmapGetSafeType
#define M3dmapPut              M3dmapPutSafeType

#else // #if M_MIL_USE_SAFE_TYPE

#define M3dmapGetResultUnsafe  M3dmapGetResult
#define M3dmapInquireUnsafe    M3dmapInquire
#define M3dmapGetUnsafe        M3dmapGet
#define M3dmapPutUnsafe        M3dmapPut

#endif // #if M_MIL_USE_SAFE_TYPE

#endif /* !M_MIL_LITE */

#endif
