////////////////////////////////////////////////////////////////////////////////
//! 
//! \brief Mildmr CAPI header (Mdmr...)
//! 
//! AUTHOR: Matrox Imaging
//!
//! COPYRIGHT NOTICE:
//! Copyright © Matrox Electronic Systems Ltd., 1992-2016.
//! All Rights Reserved 
//  Revision:  10.20.0517
////////////////////////////////////////////////////////////////////////////////

#ifndef __MIL_DMR_H__
#define __MIL_DMR_H__

#if (!M_MIL_LITE) /* MIL FULL ONLY */

#if M_MIL_USE_RT
#ifdef M_DMR_EXPORTS
#define MIL_DMR_DLLFUNC __declspec(dllexport)
#else
#define MIL_DMR_DLLFUNC __declspec(dllimport)
#endif
#else
#define MIL_DMR_DLLFUNC
#endif

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
   {
#endif

////////////////////////////////////////////////////////////////////////////////
// MdmrAlloc ContextTypes

#define M_DOT_MATRIX                                  2194L

////////////////////////////////////////////////////////////////////////////////   
// Indexing, used in other Mdmr functions (MdmrInquire(), MdmrControl(), ...)
#define M_DEFAULT                               0x10000000L // also in mil.h
#define M_CONTEXT                               0x08000000L // also in mil.h
#define M_GENERAL                               0x20000000L // also in milmod.h, milstr.h, ...
#define M_ALL                                   0x40000000L // also in mil.h

#define M_ANY                                   0x11000000L // also in mil.h, ...

#define M_FONT_MASK                             0x00800000L // also in milstr.h
#define M_STRING_MASK                           0x00400000L // also in milstr.h
#define M_CONSTRAINED_POS_MASK                  0x00600000L
#define M_REAL_INDEX_MASK                       0x000000FFL // also in milstr.h


#define M_FONT_INDEX_FLAG                       M_FONT_MASK
#define M_STRING_INDEX_FLAG                     M_STRING_MASK
#define M_FONT_LABEL_FLAG                       0x00000000L
#define M_STRING_LABEL_FLAG                     0x00C00000L
#define M_POSITION_CONSTRAINED_ORDER_FLAG       0x00200000L
#define M_POSITION_IN_STRING_FLAG               0x00600000L
#define M_INDEX_IN_STRING_FLAG                  0x00A00000L
#define M_INDEX_IN_FORMATTED_STRING_FLAG        0x00E00000L

#define M_FONT_INDEX(IndexValue)                                          (M_FONT_MASK | (IndexValue)) // also in milstr.h
#define M_STRING_INDEX(IndexValue)                                      (M_STRING_MASK | (IndexValue)) // also in milstr.h
                                                     
#define M_FONT_LABEL(LabelValue)                                    (M_FONT_LABEL_FLAG | (LabelValue)) // also in milstr.h
#define M_STRING_LABEL(LabelValue)                                (M_STRING_LABEL_FLAG | (LabelValue)) // also in milstr.h
                                                     
#define M_INDEX_IN_STRING(IndexValue)                          (M_INDEX_IN_STRING_FLAG | (IndexValue))
#define M_INDEX_IN_FORMATTED_STRING(IndexValue)      (M_INDEX_IN_FORMATTED_STRING_FLAG | (IndexValue))

#define M_POSITION_IN_STRING(PositionValue)              (M_POSITION_IN_STRING_FLAG | (PositionValue))
#define M_POSITION_CONSTRAINED_ORDER(OrderValue)    (M_POSITION_CONSTRAINED_ORDER_FLAG | (OrderValue))
#define M_ALL_CONSTRAINED_POSITIONS                                M_POSITION_CONSTRAINED_ORDER(M_ALL)

#define M_NEW_LABEL                             0x04000000L

#define M_OWNER_SYSTEM                                1101L // also in mil.h, ...
#define M_MODIFICATION_COUNT                          5010L // also in mil.h, ...

////////////////////////////////////////////////////////////////////////////////
// MdmrControl
#define M_STRING_ADD                                   700L // also in milstr.h
#define M_STRING_DELETE                                701L // also in milstr.h
#define M_FONT_ADD                                     702L // also in milstr.h
#define M_FONT_DELETE                                  703L // also in milstr.h
                                                 
#define M_DOT_DIAMETER_MODE                           2228L
#define M_DOT_DIAMETER                                2229L
                                                 
#define M_STRING_BOX_CENTER_MODE                      2230L
#define M_STRING_BOX_CENTER_X                         2231L
#define M_STRING_BOX_CENTER_Y                         2233L
                                                      
#define M_STRING_BOX_SIZE_MODE                        2236L
#define M_STRING_BOX_WIDTH                            2235L
#define M_STRING_BOX_HEIGHT                           2237L


                                              
                                               
#define M_DOT_LONGITUDINAL_DISTANCE_MODE              2241L
#define M_DOT_LONGITUDINAL_DISTANCE                   2242L
                                                 
#define M_DOT_TRANSVERSE_DISTANCE_MODE                2243L
#define M_DOT_TRANSVERSE_DISTANCE                     2246L

#define M_MIN_CONTRAST_MODE                           2247L
#define M_MIN_CONTRAST                                 600L // also in milim.h, milstr.h, milcode.h, ...



#define M_MIN_INTENSITY_MODE                          2248L
#define M_MIN_INTENSITY                                 12L // also in mil3dmap.h
                                                 
#define M_MAX_INTENSITY_MODE                          2250L
#define M_MAX_INTENSITY                               2251L
                                            




//#define M_EXTRACTION_GRID_OFFSET                      2252L
//#define M_EXTRACTION_GRID_MATCHING                    2253L
//#define M_EXTRACTION_GRID_FIT_MODE                    2254L
//#define M_EXTRACTION_GRID_MAX_NB_ITERATIONS           2255L
//                                                 
//#define M_MATCHER_GRID_SCORE_MODE                     2256L
//#define M_MATCHER_GRID_DISTANCE                       2257L
//#define M_MATCHER_GRID_MODE                           2258L
//#define M_MATCHER_TEMPLATE_MODE                       2259L
                                                 
#define M_FIXED_SPACING                               2260L
                                                 
#define M_USE_GRAMMAR                                 2261L
#define M_USE_BASELINE                                2262L
#define M_BASELINE_THRESHOLD                          2263L
                                                 
#define M_USE_CERTAINTY                               2264L
#define M_CERTAINTY                                    202L // also in milmod.h, milpat.h, milocr.h, ...

#define M_TIMEOUT                                     2077L // also in milblob.h, milcode.h, miledge.h, ...




                                                            
////////////////////////////////////////////////////////////////////////////////
// MdmrControl / MdmrInquire
// Context 
#define M_FOREGROUND_VALUE                              4L // also in milstr.h, milocr.h, ...

#define M_FOREGROUND_WHITE                           0x80L // also in milstr.h, milblob.h, ...
#define M_FOREGROUND_BLACK                          0x100L // also in milstr.h, milblob.h, ...

#define M_SPACE_SIZE_MIN                             2358L
#define M_SPACE_SIZE_MAX                             2359L

#define M_SPACE_SIZE_MIN_MODE                        2459L
#define M_SPACE_SIZE_MAX_MODE                        2369L

#define M_CHAR_WIDTH_FACTOR                          2387L

#define M_INTERNAL_MIN_HEIGHT_OVERLAP                2539L

#define M_ENABLE                                     -9997L // also in mil.h, milstr.h, ...
#define M_DISABLE                                    -9999L // also in mil.h, milstr.h, ...

#define M_AUTO                                         444L // also in mil.h, ...
#define M_USER_DEFINED                                  21L // also in mil.h, ...

// Result                                                   
#define M_RESET                                         9L  // also in mil.h, mildisplay.h
#define M_STOP_READ                                   610L  // also in milstr.h, milcode.h
#define M_RESULT_OUTPUT_UNITS                        1300L  // also in milim.h
                                                            
// Fonts                                                    
#define M_FONT_SIZE_COLUMNS                          2207L  
#define M_FONT_SIZE_ROWS                             2208L  
#define M_FONT_SIZE_TEMPLATE                         2222L  
#define M_FONT_LABEL_VALUE                           2216L  // also in mil.h, mistr.h, ...
#define M_NUMBER_OF_CHARS                             814L  // also in milstr.h
                                                            
#define M_CHAR_ADD                                      1L  // also in milstr.h
#define M_CHAR_DELETE                                   2L  // also in milstr.h
#define M_CHAR_TEMPLATE                              2223L

// Chars
#if (M_MIL_USE_UNICODE && !M_MIL_UNICODE_API && !M_COMPILING_MILDLL)
#define M_CHAR_NAME                                 (2212L | M_CLIENT_ASCII_MODE)
#else
#define M_CHAR_NAME                                  2212L
#endif
#define M_CHAR_INDEX_VALUE                           2224L

// String models
#define M_STRING_LABEL_VALUE                         2288L
#define M_STRING_INDEX_VALUE                         2313L

#define M_STRING_SIZE_MIN                             500L
#define M_STRING_SIZE_MAX                              62L // also in milstr.h, milocr.h
#define M_STRING_SIZE_MIN_MAX                        2388L

#define M_STRING_RANK                                2334L

#define M_STRING_ACCEPTANCE                            24L // also in milstr.h, milocr.h
#define M_STRING_CERTAINTY                            526L // also in milstr.h

// Constrained positions
#define M_CONSTRAINED_ORDER                          2335L
#define M_CONSTRAINED_POS_INDEX_VALUE                M_CONSTRAINED_ORDER

#define M_ADD_PERMITTED_CHARS_ENTRY                  2282L
#define M_NUMBER_OF_PERMITTED_CHARS_ENTRIES          2283L
#define M_RESET_PERMITTED_CHARS                      2284L
#define M_RESET_POSITION_TO_IMPLICIT_CONSTRAINTS     2337L
#define M_RESET_IMPLICIT_CONSTRAINTS                 2466L

#define M_CLONE_CONSTRAINTS_FROM                     2285L
#define M_CLONE_PERMITTED_CHARS_FROM                 2296L

#define M_CHAR_MAX_BASELINE_DEVIATION                 513L // also in milstr.h
#define M_POSITION                             0x00000402L // also in milmeas.h, miledge.h, milmetrol.h, mil3dmap.h
#define M_NUMBER_OF_CONSTRAINED_POSITIONS            2465L

// Character types
#define M_ANY                                   0x11000000L // also in mil.h, milstr.h, ...
#define M_LETTER                                0x00020000L // also in milstr.h, milocr.h
#define M_DIGIT                                 0x00040000L // also in milstr.h, milocr.h
#define M_LETTERS_LOWERCASE                     0X0000090EL
#define M_LETTERS_UPPERCASE                     0X0000090FL
#define M_SPACE                                       2390L
#define M_PUNCTUATION                                    1L // also in milstr.h

#if (M_MIL_USE_UNICODE && !M_MIL_UNICODE_API && !M_COMPILING_MILDLL)
#define M_CHAR_LIST                             (0X000008E9L | M_CLIENT_ASCII_MODE)
#else
#define M_CHAR_LIST                             0X000008E9L
#endif

#define M_LETTERS                                 M_LETTER
#define M_DIGITS                                   M_DIGIT
#define M_PUNCTUATIONS                       M_PUNCTUATION

#define M_TYPE                                        1008L // also in mil.h

////////////////////////////////////////////////////////////////////////////////
// MdmrInquire 
// Context
#define M_PREPROCESSED                                 14L // also in milmod.h, milstr.h, ...
#define M_NUMBER_OF_STRING_MODELS                     900L // also in milstr.h
#define M_NUMBER_OF_FONTS                             901L // also in milstr.h


#define M_FONT_INDEX_VALUE                           2226L

#define M_INVALID                                       -1 // also in mil.h

////////////////////////////////////////////////////////////////////////////////
// MdmrName operations

#define M_SET_NAME                                      1L  // also in milmetrol.h
#define M_GET_NAME                                      2L  // also in milmetrol.h
#define M_GET_FONT_LABEL                             2201L
#define M_GET_STRING_LABEL                           2202L
#define M_GET_FONT_INDEX                             2203L
#define M_GET_STRING_INDEX                           2204L

////////////////////////////////////////////////////////////////////////////////
// MdmrAllocResult ResultTypes

#if (M_MIL_USE_UNICODE && !M_MIL_UNICODE_API && !M_COMPILING_MILDLL)
#define M_STRING                                       (3L | M_CLIENT_ASCII_MODE)   // also defined in milstr.h, milocr.h
#else
#define M_STRING                                        3L // also in milstr.h, milocr.h
#endif
#define M_STRING_CHAR_NUMBER                         2277L
#define M_FORMATTED_STRING                            793L // also in milstr.h
#define M_FORMATTED_STRING_CHAR_NUMBER               2487L 

////////////////////////////////////////////////////////////////////////////////
// ControlTypes for dot matrix result buffers

////////////////////////////////////////////////////////////////////////////////
// MdmrImportFont
#define M_INTERACTIVE                               M_NULL // also in mil.h, milstr.h, ...
#define M_DMR_FONT_FILE                              2199L
#define M_IMPORT_ALL_CHARS                          M_NULL

#define M_OVERWRITE                                  1861L // also in mil.h, mil3dmap.h
#define M_NO_OVERWRITE                              0x200L // also in mistr.h

////////////////////////////////////////////////////////////////////////////////
// MdmrExportFont
#define M_HEX_UTF16_FOR_ALL                    0x00100000L
#define M_HEX_UTF16_FOR_NON_BASIC_LATIN        0x00080000L

////////////////////////////////////////////////////////////////////////////////
// MdmrGetResult ResultTypes

// General
#define M_STATUS                                0x00008002L // also in milcode.h, milcolor.h, miledge.h, ...

#define M_READ_NOT_PERFORMED                          2552L
#define M_CURRENTLY_READING                           2553L
#define M_TIMEOUT_REACHED                             2554L
#define M_STOPPED_BY_REQUEST                          2555L
#define M_NOT_ENOUGH_MEMORY                              4L // also in mil.h, mil3dmap.h
#define M_COMPLETE                              0x00000000L // also in mil.h, milmod.h
#define M_INTERNAL_ERROR                                 5L // also in milcal.h

// String
#define M_STRING_BOX_UL_X                              914L // also in mistr.h
#define M_STRING_BOX_UL_Y                              915L // also in mistr.h
#define M_STRING_BOX_UR_X                              916L // also in mistr.h
#define M_STRING_BOX_UR_Y                              917L // also in mistr.h
#define M_STRING_BOX_BR_X                              918L // also in mistr.h
#define M_STRING_BOX_BR_Y                              919L // also in mistr.h
#define M_STRING_BOX_BL_X                              920L // also in mistr.h
#define M_STRING_BOX_BL_Y                              921L // also in mistr.h
#define M_STRING_MODEL_INDEX                           585L // also in mistr.h
#define M_STRING_MODEL_LABEL                          2278L
#define M_STRING_POSITION_X                            586L // also in mistr.h
#define M_STRING_POSITION_Y                            587L // also in mistr.h
#define M_STRING_SCORE                          0x00001400L // also in milocr.h, mistr.h
#define M_STRING_WIDTH                                2297L
#define M_STRING_HEIGHT                               2298L

// Chars
#define M_CHAR_SCORE                                   5L // also in milocr.h, mistr.h
#define M_CHAR_POSITION_X                              6L // also in milocr.h, mistr.h
#define M_CHAR_POSITION_Y                              7L // also in milocr.h, mistr.h
#define M_CHAR_BOX_UL_X                              922L // also in milstr.h
#define M_CHAR_BOX_UL_Y                              923L // also in milstr.h
#define M_CHAR_BOX_UR_X                              924L // also in milstr.h
#define M_CHAR_BOX_UR_Y                              925L // also in milstr.h
#define M_CHAR_BOX_BR_X                              926L // also in milstr.h
#define M_CHAR_BOX_BR_Y                              927L // also in milstr.h
#define M_CHAR_BOX_BL_X                              928L // also in milstr.h
#define M_CHAR_BOX_BL_Y                              929L // also in milstr.h
#define M_CHAR_FONT_INDEX                           2279L
#define M_CHAR_FONT_LABEL                           2280L
#define M_CHAR_WIDTH                                2311L
#define M_CHAR_HEIGHT                               2312L

////////////////////////////////////////////////////////////////////////////////
// MdmrDraw ControlTypes

#define M_DRAW_MIL_FONT_STRING                  0x00000020L // also in milstr.h
#define M_DRAW_STRING_BOX                       0x00000004L // also in milstr.h
#define M_DRAW_STRING_CHAR_BOX                  0x00000008L // also in milstr.h
#define M_DRAW_STRING_CHAR_BOX_TIGHT            0x00000040L 
#define M_DRAW_STRING_CHAR_POSITION             0x00000010L // also in milstr.h

////////////////////////////////////////////////////////////////////////////////
// Other defines

////////////////////////////////////////////////////////////////////////////////
// CAPI function prototypes
MIL_DMR_DLLFUNC MIL_ID MFTYPE MdmrAlloc(MIL_ID    SysId,
                                        MIL_INT64 ContextType,
                                        MIL_INT64 ControlFlag,
                                        MIL_ID*   ContextDmrIdPtr);

MIL_DMR_DLLFUNC MIL_ID MFTYPE MdmrAllocResult(MIL_ID    SysId,
                                              MIL_INT64 ResultType,
                                              MIL_INT64 ControlFlag,
                                              MIL_ID*   ResultDmrIdPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrFree(MIL_ID ContextOrResultDmrId);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs
MIL_DMR_DLLFUNC void MFTYPE MdmrControlInt64(MIL_ID     ContextOrResultDmrId,
                                             MIL_INT64  ControlType,
                                             MIL_INT64  ControlValue);
MIL_DMR_DLLFUNC void MFTYPE MdmrControlDouble(MIL_ID     ContextOrResultDmrId,
                                              MIL_INT64  ControlType,
                                              MIL_DOUBLE ControlValue);

MIL_DMR_DLLFUNC void MFTYPE MdmrControlStringModelDouble(MIL_ID      ContextDmrId           ,
                                                         MIL_INT64   StringModelLabelOrIndex,
                                                         MIL_INT64   Position               ,
                                                         MIL_INT64   ControlType            ,
                                                         MIL_DOUBLE  ControlValue1          ,
                                                         MIL_DOUBLE  ControlValue2          ,
                                                         const void* ControlValuePtr        );
MIL_DMR_DLLFUNC void MFTYPE MdmrControlStringModelInt64(MIL_ID      ContextDmrId           ,
                                                        MIL_INT64   StringModelLabelOrIndex,
                                                        MIL_INT64   Position               ,
                                                        MIL_INT64   ControlType            ,
                                                        MIL_INT64   ControlValue1          ,
                                                        MIL_INT64   ControlValue2          ,
                                                        const void* ControlValuePtr        );
#else
// Prototypes for 32 bits OSs
#define MdmrControlInt64  MdmrControl
#define MdmrControlDouble MdmrControl
#define MdmrControlStringModelInt64  MdmrControlStringModel
#define MdmrControlStringModelDouble MdmrControlStringModel

MIL_DMR_DLLFUNC void MFTYPE MdmrControl(MIL_ID     ContextOrResultDmrId,
                                        MIL_INT64  ControlType,
                                        MIL_DOUBLE ControlValue);

MIL_DMR_DLLFUNC void MFTYPE MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                                   MIL_INT64   StringModelLabelOrIndex,
                                                   MIL_INT64   Position               ,
                                                   MIL_INT64   ControlType            ,
                                                   MIL_DOUBLE  ControlValue1          ,
                                                   MIL_DOUBLE  ControlValue2          ,
                                                   const void* ControlValuePtr        );
#endif

MIL_DMR_DLLFUNC MIL_INT MFTYPE MdmrInquire(MIL_ID   ContextOrResultDmrId,
                                           MIL_INT64 InquireType,
                                           void*     UserVarPtr);

MIL_DMR_DLLFUNC MIL_INT MFTYPE MdmrInquireStringModel(MIL_ID    ContextDmrId           ,
                                                      MIL_INT64 StringModelLabelOrIndex,
                                                      MIL_INT64 Position               ,
                                                      MIL_INT64 PermittedCharEntry     ,
                                                      MIL_INT64 InquireType            ,
                                                      void*     UserVarPtr             );

MIL_DMR_DLLFUNC void MFTYPE MdmrPreprocess(MIL_ID    ContextDmrId,
                                           MIL_INT64 ControlFlag);

MIL_DMR_DLLFUNC void MFTYPE MdmrRead(MIL_ID    ContextDmrId,
                                     MIL_ID    TargetImageBufId,
                                     MIL_ID    ResultDmrId,
                                     MIL_INT64 ControlFlag);

MIL_DMR_DLLFUNC void MFTYPE MdmrGetResult(MIL_ID    ResultDmrId,
                                          MIL_INT64 StringIndex,
                                          MIL_INT64 CharPositionIndex,
                                          MIL_INT64 ResultType,
                                          void*     ResultArrayPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrDraw(MIL_ID    ContextGraId,
                                     MIL_ID    ResultDmrId,
                                     MIL_ID    DstImageBufOrListGraId,
                                     MIL_INT64 Operation,
                                     MIL_INT64 Index,
                                     MIL_INT64 CharIndex,
                                     MIL_INT64 ControlFlag);


#if M_MIL_USE_UNICODE
MIL_DMR_DLLFUNC void MFTYPE MdmrSaveA(const char* FileName,
                                      MIL_ID      ContextDmrId,
                                      MIL_INT64   ControlFlag);

MIL_DMR_DLLFUNC MIL_ID MFTYPE MdmrRestoreA(const char* FileName,
                                           MIL_ID      SysId,
                                           MIL_INT64   ControlFlag,
                                           MIL_ID*     ContextDmrIdPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrStreamA(char*      MemPtrOrFileName,
                                        MIL_ID     SysId,
                                        MIL_INT64  Operation,
                                        MIL_INT64  StreamType,
                                        MIL_DOUBLE Version,
                                        MIL_INT64  ControlFlag,
                                        MIL_ID*    ContextDmrIdPtr,
                                        MIL_INT*   SizeByteVarPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrSaveW(MIL_CONST_TEXT_PTR FileName,
                                      MIL_ID             ContextDmrId,
                                      MIL_INT64          ControlFlag);

MIL_DMR_DLLFUNC MIL_ID MFTYPE MdmrRestoreW(MIL_CONST_TEXT_PTR FileName,
                                           MIL_ID             SysId,
                                           MIL_INT64          ControlFlag,
                                           MIL_ID*            ContextDmrIdPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrStreamW(MIL_TEXT_PTR MemPtrOrFileName,
                                        MIL_ID       SysId,
                                        MIL_INT64    Operation,
                                        MIL_INT64    StreamType,
                                        MIL_DOUBLE   Version,
                                        MIL_INT64    ControlFlag,
                                        MIL_ID*      ContextDmrIdPtr,
                                        MIL_INT*     SizeByteVarPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrImportFontW(MIL_CONST_TEXT_PTR FileName            ,
                                            MIL_INT64          FileFormat          ,
                                            MIL_ID             ContextDmrId        ,
                                            MIL_INT64          FontLabelOrIndex    ,
                                            MIL_CONST_TEXT_PTR CharList            ,
                                            MIL_INT64          ControlFlag         );

MIL_DMR_DLLFUNC void MFTYPE MdmrImportFontA(const char*        FileName            ,
                                            MIL_INT64          FileFormat          ,
                                            MIL_ID             ContextDmrId        ,
                                            MIL_INT64          FontLabelOrIndex    ,
                                            const char*        CharList            ,
                                            MIL_INT64          ControlFlag         );

MIL_DMR_DLLFUNC void MFTYPE MdmrExportFontW(MIL_CONST_TEXT_PTR FileName            ,
                                            MIL_INT64          FileFormat          ,
                                            MIL_ID             ContextDmrId        ,
                                            MIL_INT64          FontLabelOrIndex    ,
                                            MIL_INT64          ControlFlag         );

MIL_DMR_DLLFUNC void MFTYPE MdmrExportFontA(const char*        FileName            ,
                                            MIL_INT64          FileFormat          ,
                                            MIL_ID             ContextDmrId        ,
                                            MIL_INT64          FontLabelOrIndex    ,
                                            MIL_INT64          ControlFlag         );

#if M_MIL_USE_64BIT
MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontDoubleW(MIL_ID             ContextDmrId     ,
                                                   MIL_INT64          FontLabelOrIndex ,
                                                   MIL_INT64          CharIndex        ,
                                                   MIL_CONST_TEXT_PTR CharNamePtr      ,
                                                   MIL_INT64          ControlType      ,
                                                   MIL_DOUBLE         ControlValue     ,
                                                   const void*        ControlValuePtr  );

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontInt64W(MIL_ID             ContextDmrId     ,
                                                  MIL_INT64          FontLabelOrIndex ,
                                                  MIL_INT64          CharIndex        ,
                                                  MIL_CONST_TEXT_PTR CharNamePtr      ,
                                                  MIL_INT64          ControlType      ,
                                                  MIL_INT64          ControlValue     ,
                                                  const void*        ControlValuePtr  );

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontDoubleA(MIL_ID            ContextDmrId     ,
                                                   MIL_INT64         FontLabelOrIndex ,
                                                   MIL_INT64         CharIndex        ,
                                                   const char*       CharNamePtr      ,
                                                   MIL_INT64         ControlType      ,
                                                   MIL_DOUBLE        ControlValue     ,
                                                   const void*       ControlValuePtr  );

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontInt64A(MIL_ID             ContextDmrId     ,
                                                  MIL_INT64          FontLabelOrIndex ,
                                                  MIL_INT64          CharIndex        ,
                                                  const char*        CharNamePtr      ,
                                                  MIL_INT64          ControlType      ,
                                                  MIL_INT64          ControlValue     ,
                                                  const void*        ControlValuePtr  );
#else

// Prototypes for 32 bits OSs
#define MdmrControlFontDoubleW         MdmrControlFontW
#define MdmrControlFontDoubleA         MdmrControlFontA
#define MdmrControlFontInt64W          MdmrControlFontW
#define MdmrControlFontInt64A          MdmrControlFontA

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontW(MIL_ID             ContextDmrId     ,
                                             MIL_INT64          FontLabelOrIndex ,
                                             MIL_INT64          CharIndex        ,
                                             MIL_CONST_TEXT_PTR CharNamePtr      ,
                                             MIL_INT64          ControlType      ,
                                             MIL_DOUBLE         ControlValue     ,
                                             const void*        ControlValuePtr  );

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontA(MIL_ID             ContextDmrId     ,
                                             MIL_INT64          FontLabelOrIndex ,
                                             MIL_INT64          CharIndex        ,
                                             const char*        CharNamePtr      ,
                                             MIL_INT64          ControlType      ,
                                             MIL_DOUBLE         ControlValue     ,
                                             const void*        ControlValuePtr  );
#endif

MIL_DMR_DLLFUNC MIL_INT MFTYPE MdmrInquireFontW(MIL_ID             ContextDmrId    ,
                                                MIL_INT64          FontLabelOrIndex,
                                                MIL_INT64          CharIndex       ,
                                                MIL_CONST_TEXT_PTR CharNamePtr     ,
                                                MIL_INT64          InquireType     ,
                                                void*              UserVarPtr      );

MIL_DMR_DLLFUNC MIL_INT MFTYPE MdmrInquireFontA(MIL_ID             ContextDmrId    ,
                                                MIL_INT64          FontLabelOrIndex,
                                                MIL_INT64          CharIndex       ,
                                                const char*        CharNamePtr     ,
                                                MIL_INT64          InquireType     ,
                                                void*              UserVarPtr      );

MIL_DMR_DLLFUNC void MFTYPE MdmrNameW(MIL_ID       ContextDmrId   ,
                                      MIL_INT64    Operation      ,
                                      MIL_INT64    LabelOrIndex   ,
                                      MIL_TEXT_PTR Name           ,
                                      MIL_INT*     ValuePtr       , 
                                      MIL_INT64    ControlFlag    );

MIL_DMR_DLLFUNC void MFTYPE MdmrNameA(MIL_ID       ContextDmrId   ,
                                      MIL_INT64    Operation      ,
                                      MIL_INT64    LabelOrIndex   ,
                                      char*        Name           ,
                                      MIL_INT*     ValuePtr       , 
                                      MIL_INT64    ControlFlag    );

#if M_MIL_UNICODE_API
#define MdmrSave               MdmrSaveW
#define MdmrRestore            MdmrRestoreW
#define MdmrStream             MdmrStreamW
#define MdmrImportFont         MdmrImportFontW
#define MdmrExportFont         MdmrExportFontW
#define MdmrInquireFont        MdmrInquireFontW
#define MdmrName               MdmrNameW

#else

#define MdmrSave               MdmrSaveA
#define MdmrRestore            MdmrRestoreA
#define MdmrStream             MdmrStreamA
#define MdmrImportFont         MdmrImportFontA
#define MdmrExportFont         MdmrExportFontA
#define MdmrInquireFont        MdmrInquireFontA
#define MdmrName               MdmrNameA
#endif

#else

MIL_DMR_DLLFUNC void MFTYPE MdmrSave(MIL_CONST_TEXT_PTR FileName,
                                     MIL_ID             ContextDmrId,
                                     MIL_INT64          ControlFlag);

MIL_DMR_DLLFUNC MIL_ID MFTYPE MdmrRestore(MIL_CONST_TEXT_PTR FileName,
                                          MIL_ID             SysId,
                                          MIL_INT64          ControlFlag,
                                          MIL_ID*            ContextDmrIdPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrStream(MIL_TEXT_PTR MemPtrOrFileName,
                                       MIL_ID       SysId,
                                       MIL_INT64    Operation,
                                       MIL_INT64    StreamType,
                                       MIL_DOUBLE   Version,
                                       MIL_INT64    ControlFlag,
                                       MIL_ID*      ContextDmrIdPtr,
                                       MIL_INT*     SizeByteVarPtr);

MIL_DMR_DLLFUNC void MFTYPE MdmrImportFont(MIL_CONST_TEXT_PTR  FileName            ,
                                           MIL_INT64           FileFormat          ,
                                           MIL_ID              ContextDmrId        ,
                                           MIL_INT64           FontLabelOrIndex    ,
                                           MIL_CONST_TEXT_PTR  CharList            ,
                                           MIL_INT64           ControlFlag         );

MIL_DMR_DLLFUNC void MFTYPE MdmrExportFont(MIL_CONST_TEXT_PTR  FileName            ,
                                           MIL_INT64           FileFormat          ,
                                           MIL_ID              ContextDmrId        ,
                                           MIL_INT64           FontLabelOrIndex    ,
                                           MIL_INT64           ControlFlag         );
#if M_MIL_USE_64BIT

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontInt64(MIL_ID             ContextDmrId     ,
                                                 MIL_INT64          FontLabelOrIndex ,
                                                 MIL_INT64          CharIndex        ,
                                                 MIL_CONST_TEXT_PTR CharNamePtr      ,
                                                 MIL_INT64          ControlType      ,
                                                 MIL_INT64          ControlValue     ,
                                                 const void*        ControlValuePtr  );

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFontDouble(MIL_ID             ContextDmrId     ,
                                                  MIL_INT64          FontLabelOrIndex ,
                                                  MIL_INT64          CharIndex        ,
                                                  MIL_CONST_TEXT_PTR CharNamePtr      ,
                                                  MIL_INT64          ControlType      ,
                                                  MIL_DOUBLE         ControlValue     ,
                                                  const void*        ControlValuePtr  );
#else

// Prototypes for 32 bits OSs
#define MdmrControlFontDouble MdmrControlFont
#define MdmrControlFontInt64  MdmrControlFont

MIL_DMR_DLLFUNC void MFTYPE MdmrControlFont(MIL_ID             ContextDmrId     ,
                                            MIL_INT64          FontLabelOrIndex ,
                                            MIL_INT64          CharIndex        ,
                                            MIL_CONST_TEXT_PTR CharNamePtr      ,
                                            MIL_INT64          ControlType      ,
                                            MIL_DOUBLE         ControlValue     ,
                                            const void*        ControlValuePtr  );

#endif //#if M_MIL_USE_64BIT

MIL_DMR_DLLFUNC MIL_INT MFTYPE MdmrInquireFont(MIL_ID             ContextDmrId    ,
                                               MIL_INT64          FontLabelOrIndex,
                                               MIL_INT64          CharIndex       ,
                                               MIL_CONST_TEXT_PTR CharNamePtr     ,
                                               MIL_INT64          InquireType     ,
                                               void*              UserVarPtr      );

MIL_DMR_DLLFUNC void MFTYPE MdmrName(MIL_ID       ContextOrResultDmrId,
                                     MIL_INT64    Operation           ,
                                     MIL_INT64    LabelOrIndex        ,
                                     MIL_TEXT_PTR Name                ,
                                     MIL_INT*     ValuePtr            , 
                                     MIL_INT64    ControlFlag         );

#endif

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif
////////////////////////////////////////////////////////////////////////////////

#if M_MIL_USE_64BIT
#ifdef __cplusplus

//////////////////////////////////////////////////////////////
// MdmrControl function overloads when compiling c++ files
//////////////////////////////////////////////////////////////
template <typename T>
inline void MdmrControl(MIL_ID ContextOrResultDmrId, MIL_INT64 ControlType, T ControlValue)
   { MdmrControlInt64(ContextOrResultDmrId, ControlType, ControlValue); };

inline void MdmrControl(MIL_ID ContextOrResultDmrId, MIL_INT64 ControlType, float ControlValue)
   { MdmrControlDouble(ContextOrResultDmrId, ControlType, ControlValue); };

inline void MdmrControl(MIL_ID ContextOrResultDmrId, MIL_INT64 ControlType, MIL_DOUBLE ControlValue)
   { MdmrControlDouble(ContextOrResultDmrId, ControlType, ControlValue); };

//////////////////////////////////////////////////////////////
// MdmrControlStringModel function overloads when compiling
// c++ files
//////////////////////////////////////////////////////////////
template <typename T1, typename T2>
inline void MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                   MIL_INT64   StringModelLabelOrIndex,
                                   MIL_INT64   Position               ,
                                   MIL_INT64   ControlType            ,
                                   T1          ControlValue1          ,
                                   T2          ControlValue2          ,
                                   const void* ControlValuePtr        )
   { MdmrControlStringModelInt64(ContextDmrId, StringModelLabelOrIndex, Position, ControlType, ControlValue1, ControlValue2, ControlValuePtr); };

template <typename T1>
inline void MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                   MIL_INT64   StringModelLabelOrIndex,
                                   MIL_INT64   Position               ,
                                   MIL_INT64   ControlType            ,
                                   T1          ControlValue1          ,
                                   float       ControlValue2          ,
                                   const void* ControlValuePtr        )
   { MdmrControlStringModelDouble(ContextDmrId, StringModelLabelOrIndex, Position, ControlType, static_cast<MIL_DOUBLE>(ControlValue1), static_cast<MIL_DOUBLE>(ControlValue2), ControlValuePtr); };

template <typename T2>
inline void MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                   MIL_INT64   StringModelLabelOrIndex,
                                   MIL_INT64   Position               ,
                                   MIL_INT64   ControlType            ,
                                   float       ControlValue1          ,
                                   T2          ControlValue2          ,
                                   const void* ControlValuePtr        )
   { MdmrControlStringModelDouble(ContextDmrId, StringModelLabelOrIndex, Position, ControlType, static_cast<MIL_DOUBLE>(ControlValue1), static_cast<MIL_DOUBLE>(ControlValue2), ControlValuePtr); };

inline void MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                   MIL_INT64   StringModelLabelOrIndex,
                                   MIL_INT64   Position   ,
                                   MIL_INT64   ControlType            ,
                                   float       ControlValue1          ,
                                   float       ControlValue2          ,
                                   const void* ControlValuePtr        )
   { MdmrControlStringModelDouble(ContextDmrId, StringModelLabelOrIndex, Position, ControlType, static_cast<MIL_DOUBLE>(ControlValue1), static_cast<MIL_DOUBLE>(ControlValue2), ControlValuePtr); };

template <typename T1>
inline void MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                   MIL_INT64   StringModelLabelOrIndex,
                                   MIL_INT64   Position               ,
                                   MIL_INT64   ControlType            ,
                                   T1          ControlValue1          ,
                                   MIL_DOUBLE  ControlValue2          ,
                                   const void* ControlValuePtr        )
   { MdmrControlStringModelDouble(ContextDmrId, StringModelLabelOrIndex, Position, ControlType, static_cast<MIL_DOUBLE>(ControlValue1), static_cast<MIL_DOUBLE>(ControlValue2), ControlValuePtr); };

template <typename T2>
inline void MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                   MIL_INT64   StringModelLabelOrIndex,
                                   MIL_INT64   Position               ,
                                   MIL_INT64   ControlType            ,
                                   MIL_DOUBLE  ControlValue1          ,
                                   T2          ControlValue2          ,
                                   const void* ControlValuePtr        )
   { MdmrControlStringModelDouble(ContextDmrId, StringModelLabelOrIndex, Position, ControlType, static_cast<MIL_DOUBLE>(ControlValue1), static_cast<MIL_DOUBLE>(ControlValue2), ControlValuePtr); };

inline void MdmrControlStringModel(MIL_ID      ContextDmrId           ,
                                   MIL_INT64   StringModelLabelOrIndex,
                                   MIL_INT64   Position   ,
                                   MIL_INT64   ControlType            ,
                                   MIL_DOUBLE  ControlValue1          ,
                                   MIL_DOUBLE  ControlValue2          ,
                                   const void* ControlValuePtr        )
   { MdmrControlStringModelDouble(ContextDmrId, StringModelLabelOrIndex, Position, ControlType, static_cast<MIL_DOUBLE>(ControlValue1), static_cast<MIL_DOUBLE>(ControlValue2), ControlValuePtr); };

#if M_MIL_USE_UNICODE
#if M_MIL_UNICODE_API
   #define MdmrControlFontDouble_API MdmrControlFontDoubleW
   #define MdmrControlFontInt64_API  MdmrControlFontInt64W
#else
   #define MdmrControlFontDouble_API MdmrControlFontDoubleA
   #define MdmrControlFontInt64_API  MdmrControlFontInt64A
#endif
#else
   #define MdmrControlFontDouble_API MdmrControlFontDouble
   #define MdmrControlFontInt64_API  MdmrControlFontInt64
#endif

inline void MdmrControlFont(MIL_ID             ContextDmrId     ,
                            MIL_INT64          FontLabelOrIndex ,
                            MIL_INT64          CharIndex        ,
                            MIL_CONST_TEXT_PTR CharNamePtr      ,
                            MIL_INT64          ControlType      ,
                            MIL_DOUBLE         ControlValue     ,
                            const void*        ControlValuePtr  )
   {
   MdmrControlFontDouble_API(ContextDmrId     ,
                             FontLabelOrIndex ,
                             CharIndex        ,
                             CharNamePtr      ,
                             ControlType      ,
                             ControlValue     ,
                             ControlValuePtr  );
   };

#define MdmrControlFontW MdmrControlFont
#define MdmrControlFontA MdmrControlFont

#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Double one
//////////////////////////////////////////////////////////////
#define MdmrControl            MdmrControlDouble
#define MdmrStringModelControl MdmrControlStringModelDouble

#if M_MIL_UNICODE_API
#define MdmrControlFontInt64  MdmrControlFontInt64W
#define MdmrControlFontDouble MdmrControlFontDoubleW
#define MdmrControlFont       MdmrControlFontDoubleW
#define MdmrControlFontW      MdmrControlFontDoubleW
#define MdmrControlFontA      MdmrControlFontDoubleA
#else
#define MdmrControlFontInt64  MdmrControlFontInt64A
#define MdmrControlFontDouble MdmrControlFontDoubleA
#define MdmrControlFont       MdmrControlFontDoubleA
#define MdmrControlFontA      MdmrControlFontDoubleA
#define MdmrControlFontW      MdmrControlFontDoubleW
#endif 

#endif // __cplusplus

#else // M_MIL_USE_64BIT

// Prototypes for 32 bits OSs
#if M_MIL_USE_UNICODE
#if M_MIL_UNICODE_API
#define MdmrControlFontInt64  MdmrControlFontW
#define MdmrControlFontDouble MdmrControlFontW
#define MdmrControlFont       MdmrControlFontW
#else
#define MdmrControlFontInt64  MdmrControlFontA
#define MdmrControlFontDouble MdmrControlFontA
#define MdmrControlFont       MdmrControlFontA
#endif
#endif 

#endif // M_MIL_USE_64BIT

#if M_MIL_USE_SAFE_TYPE

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

// -------------------------------------------------------------------------
// MdmrGetResult safe type declarations

inline void MFTYPE MdmrGetResultUnsafe  (MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, void*          ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, int            ResultArrayPtr);
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, std::nullptr_t ResultArrayPtr);
#endif
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT8*      ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT16*     ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT32*     ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT64*     ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, float*         ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_DOUBLE*    ResultArrayPtr);
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_TEXT_PTR   ResultArrayPtr);
#endif
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT8*     ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT16*    ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT32*    ResultArrayPtr);
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT64*    ResultArrayPtr);
#endif


// -------------------------------------------------------------------------
// MdmrGetResult safe type definitions
// 

inline void MFTYPE MdmrGetResultSafeType (MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, int ResultPtr)
   {
   if (ResultPtr != 0)
      SafeTypeError(MIL_TEXT("MdmrGetResult"));

   MdmrGetResult(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, NULL);
   }

#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline void MFTYPE MdmrGetResultSafeType (MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, std::nullptr_t ResultPtr)
   {
   if (ResultPtr != M_NULL)
      SafeTypeError(MIL_TEXT("MdmrGetResult"));

   MdmrGetResult(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, NULL);
   }
#endif


inline void MdmrGetResultSafeTypeExecute (MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex,MIL_INT64 ResultType, void* ResultArrayPtr, MIL_INT64 GivenType)
   {
   MIL_INT64 RequiredType = (ResultType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_MIL_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID)     && (RequiredType != M_TYPE_FLOAT)     && (RequiredType != M_TYPE_CHAR)      &&
      (RequiredType != M_TYPE_SHORT)      && (RequiredType != M_TYPE_MIL_UINT8) && (RequiredType != M_TYPE_STRING))
      { RequiredType = 0; }

   MIL_INT64 StrippedResultType = M_STRIP_CLIENT_ASCII_MODE_BIT(ResultType);
   bool StrResult = (StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_STRING                                            ) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_STRING           + M_HEX_UTF16_FOR_ALL            ) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_STRING           + M_HEX_UTF16_FOR_NON_BASIC_LATIN) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_FORMATTED_STRING                                  ) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_FORMATTED_STRING + M_HEX_UTF16_FOR_ALL            ) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_FORMATTED_STRING + M_HEX_UTF16_FOR_NON_BASIC_LATIN) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_NAME                                         ) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_NAME        + M_HEX_UTF16_FOR_ALL            ) ||
                     StrippedResultType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_NAME        + M_HEX_UTF16_FOR_NON_BASIC_LATIN));

   if(RequiredType == 0)
      { RequiredType = StrResult ? M_TYPE_STRING : M_TYPE_MIL_DOUBLE; }

   if(StrResult                               &&
      M_CLIENT_ASCII_MODE_BIT_SET(ResultType) &&
      (GivenType == M_TYPE_CHAR))
      {
      GivenType = M_TYPE_STRING;
      }
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MdmrGetResult"));

   MdmrGetResult(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr);
   }


inline void MFTYPE MdmrGetResultUnsafe  (MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, void*        ResultArrayPtr){MdmrGetResult               (ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr                     );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT8*    ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_CHAR        );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT8*   ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_UINT8   );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT16*   ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT       );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT32*   ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32   );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_INT64*   ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64   );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, float*       ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_FLOAT       );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_DOUBLE*  ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_DOUBLE  );}

#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_TEXT_PTR ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_STRING   );}
#endif

#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT16* ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT    );}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT32* ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MdmrGetResultSafeType(MIL_ID ResultDmrId, MIL_INT64 StringIndex, MIL_INT64 CharacterPosIndex, MIL_INT64 ResultType, MIL_UINT64* ResultArrayPtr){MdmrGetResultSafeTypeExecute(ResultDmrId, StringIndex, CharacterPosIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// MdmrInquire safe type declarations

inline MIL_INT MFTYPE MdmrInquireUnsafe  (MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, void*          UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, int            UserVarPtr);
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, std::nullptr_t UserVarPtr);
#endif
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_INT8*      UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_INT32*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_INT64*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, float*         UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_DOUBLE*    UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                                        
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_UINT8*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_UINT16*    UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_UINT32*    UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, MIL_UINT64*    UserVarPtr);
#endif                                                                              
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                                                     
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID ContextOrResultDmrId, MIL_INT64 InquireType, wchar_t*    UserVarPtr);
#endif

// ----------------------------------------------------------
// MdmrInquire safe type definitions

inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, int UserVarPtr)
   {
   if (UserVarPtr != 0)
      SafeTypeError(MIL_TEXT("MdmrInquire"));

   return MdmrInquire(MdmrId, InquireType, NULL);
   }

#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, std::nullptr_t)
   {
   return MdmrInquire(MdmrId, InquireType, NULL);
   }
#endif

inline MIL_INT MFTYPE MdmrInquireSafeTypeExecute(MIL_ID MdmrId, MIL_INT64 InquireType, void* UserVarPtr, MIL_INT64 GivenType)
   {
   MIL_INT64 RequiredType = (InquireType & M_HLVLDATATYPE_MASK);

   if((RequiredType != M_TYPE_MIL_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID)     && (RequiredType != M_TYPE_FLOAT)     && (RequiredType != M_TYPE_CHAR)      &&
      (RequiredType != M_TYPE_SHORT)      && (RequiredType != M_TYPE_MIL_UINT8) && (RequiredType != M_TYPE_STRING))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_MIL_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MdmrInquire"));

   return MdmrInquire(MdmrId, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE MdmrInquireUnsafe  (MIL_ID MdmrId, MIL_INT64 InquireType, void*       UserVarPtr) {return MdmrInquire               (MdmrId, InquireType, UserVarPtr                   );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_INT8*   UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_CHAR      );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_UINT8*  UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_MIL_UINT8 );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_INT32*  UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_MIL_INT32 );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_INT64*  UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_MIL_INT64 );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, float*      UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_FLOAT     );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_DOUBLE* UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_MIL_DOUBLE);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_UINT16* UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_SHORT     );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_UINT32* UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_MIL_INT32 );}
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64 InquireType, MIL_UINT64* UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_MIL_INT64 );}
#endif
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T
inline MIL_INT MFTYPE MdmrInquireSafeType(MIL_ID MdmrId, MIL_INT64  InquireType, wchar_t*    UserVarPtr) {return MdmrInquireSafeTypeExecute(MdmrId, InquireType, UserVarPtr, M_TYPE_STRING   );}
#endif

// ----------------------------------------------------------
// MdmrInquireFont safetypes declaration

inline MIL_INT MFTYPE MdmrInquireFontUnsafe  (MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, void*          UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, int            UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_UINT8*     UserVarPtr);
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, std::nullptr_t UserVarPtr);
#endif
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_INT8*      UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_INT32*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_INT64*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_FLOAT*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_DOUBLE*    UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                                        
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_UINT8*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_UINT32*    UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_UINT64*    UserVarPtr);
#endif
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_TEXT_PTR   UserVarPtr);
#endif

// ----------------------------------------------------------
// MdmrInquireFont safe type definitions

inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, int UserVarPtr)
   {
   if (UserVarPtr != 0)
      SafeTypeError(MIL_TEXT("MdmrInquireFont"));

   return MdmrInquireFont(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, M_NULL);
   }

#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, std::nullptr_t)
   {
   return MdmrInquireFont(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, M_NULL);
   }
#endif

inline MIL_INT MFTYPE MdmrInquireFontSafeTypeExecute(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, void* UserVarPtr, MIL_INT64 GivenType)
   {
   MIL_INT64 RequiredType = (InquireType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_MIL_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID)     && (RequiredType != M_TYPE_FLOAT)     && (RequiredType != M_TYPE_CHAR)      &&
      (RequiredType != M_TYPE_SHORT)      && (RequiredType != M_TYPE_MIL_UINT8) && (RequiredType != M_TYPE_STRING))
      { RequiredType = 0; }

   MIL_INT64 StrippedInquireType = M_STRIP_CLIENT_ASCII_MODE_BIT(InquireType);
   bool StrInquire = (StrippedInquireType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_NAME                                  ) ||
                      StrippedInquireType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_NAME + M_HEX_UTF16_FOR_ALL            ) ||
                      StrippedInquireType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_NAME + M_HEX_UTF16_FOR_NON_BASIC_LATIN));
   bool DefaultToMIL_UINT8 = (M_STRIP_HLVLDATATYPE(InquireType) == M_CHAR_TEMPLATE);

   if(RequiredType == 0)
      {
      if(StrInquire)
         { RequiredType = M_TYPE_STRING; }
      else if(DefaultToMIL_UINT8)
         { RequiredType = M_TYPE_MIL_UINT8; }
      else
         { RequiredType = M_TYPE_DOUBLE;}
      }

   if(StrInquire                               &&
      M_CLIENT_ASCII_MODE_BIT_SET(InquireType) &&
      (GivenType == M_TYPE_CHAR))
      {
      GivenType = M_TYPE_STRING;
      }
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MdmrInquireFont"));

   return MdmrInquireFont(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE MdmrInquireFontUnsafe  (MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, void*  UserVarPtr)      { return MdmrInquireFont(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr); }
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_INT8*    UserVarPtr)
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
   { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_CHAR    ); }
#else
   { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_STRING  ); }
#endif
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_UINT8*   UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_MIL_UINT8 ); }
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_INT32*   UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_MIL_INT32 ); }
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_INT64*   UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_MIL_INT64 ); }
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_DOUBLE*  UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_MIL_DOUBLE); }
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_FLOAT*   UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_MIL_FLOAT);  }
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_UINT32*  UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_MIL_INT32 ); }
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_UINT64*  UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_MIL_INT64 ); }
#endif
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
inline MIL_INT MFTYPE MdmrInquireFontSafeType(MIL_ID ContextDmrId, MIL_INT64 FontLabelOrIndex, MIL_INT64 CharIndex, MIL_CONST_TEXT_PTR CharNamePtr, MIL_INT64 InquireType, MIL_TEXT_PTR UserVarPtr) { return MdmrInquireFontSafeTypeExecute(ContextDmrId, FontLabelOrIndex, CharIndex, CharNamePtr, InquireType, UserVarPtr, M_TYPE_STRING    ); }
#endif


//-----------------------------------------------------------
// MdmrInquireStringModel safetypes declaration

inline MIL_INT MFTYPE MdmrInquireStringModelUnsafe  (MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, void*          UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, int            UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_UINT8*     UserVarPtr);
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, std::nullptr_t UserVarPtr);
#endif
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_INT8*      UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_INT32*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_INT64*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_FLOAT*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_DOUBLE*    UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                                        
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_UINT8*     UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_UINT32*    UserVarPtr);
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_UINT64*    UserVarPtr);
#endif
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_TEXT_PTR   UserVarPtr);
#endif

// ----------------------------------------------------------
// MdmrInquireStringModel safe type definitions

inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, int UserVarPtr)
   {
   if (UserVarPtr != 0)
      SafeTypeError(MIL_TEXT("MdmrInquireStringModel"));

   return MdmrInquireStringModel(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, M_NULL);
   }

#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, std::nullptr_t)
   {
   return MdmrInquireStringModel(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, M_NULL);
   }
#endif

inline MIL_INT MFTYPE MdmrInquireStringModelSafeTypeExecute(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, void* UserVarPtr, MIL_INT64 GivenType)
   {
   MIL_INT64 RequiredType = (InquireType & M_HLVLDATATYPE_MASK);
   if ((RequiredType != M_TYPE_MIL_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) &&
       (RequiredType != M_TYPE_MIL_ID)     && (RequiredType != M_TYPE_FLOAT)     && (RequiredType != M_TYPE_CHAR)      &&
       (RequiredType != M_TYPE_SHORT)      && (RequiredType != M_TYPE_MIL_UINT8) && (RequiredType != M_TYPE_STRING))
      {
      RequiredType = 0;
      }

   MIL_INT64 StrippedInquireType = M_STRIP_CLIENT_ASCII_MODE_BIT(InquireType);
   bool StrInquire = (StrippedInquireType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_LIST) ||
                      StrippedInquireType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_LIST + M_HEX_UTF16_FOR_ALL) ||
                      StrippedInquireType == M_STRIP_CLIENT_ASCII_MODE_BIT(M_CHAR_LIST + M_HEX_UTF16_FOR_NON_BASIC_LATIN));
   if (RequiredType == 0)
      {
      if (StrInquire)
         { RequiredType = M_TYPE_STRING; }
      else
         { RequiredType = M_TYPE_DOUBLE; }
      }

   if (StrInquire                               &&
       M_CLIENT_ASCII_MODE_BIT_SET(InquireType) &&
      (GivenType == M_TYPE_CHAR))
      {
      GivenType = M_TYPE_STRING;
      }
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MdmrInquireStringModel"));

   return MdmrInquireStringModel(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE MdmrInquireStringModelUnsafe  (MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, void*        UserVarPtr) { return MdmrInquireStringModel(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr); }
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_INT8*    UserVarPtr)
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
   {
   return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr, M_TYPE_CHAR);
   }
#else
   { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr, M_TYPE_STRING); }
#endif
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_UINT8*   UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_MIL_UINT8); }
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_INT32*   UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_MIL_INT32); }
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_INT64*   UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_MIL_INT64); }
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_DOUBLE*  UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_MIL_DOUBLE); }
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_FLOAT*   UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_MIL_FLOAT); }
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_UINT32*  UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_MIL_INT32); }
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_UINT64*  UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_MIL_INT64); }
#endif
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
inline MIL_INT MFTYPE MdmrInquireStringModelSafeType(MIL_ID ContextDmrId, MIL_INT64 StringModelLabelOrIndex, MIL_INT64 Position, MIL_INT64 PermittedCharEntry, MIL_INT64 InquireType, MIL_TEXT_PTR UserVarPtr) { return MdmrInquireStringModelSafeTypeExecute(ContextDmrId, StringModelLabelOrIndex, Position, PermittedCharEntry, InquireType, UserVarPtr,  M_TYPE_STRING); }
#endif

//------------------------------
// Safetype functions assignment

#define MdmrGetResult            MdmrGetResultSafeType
#define MdmrInquire              MdmrInquireSafeType
#undef  MdmrInquireFont
#define MdmrInquireFont          MdmrInquireFontSafeType
#define MdmrInquireStringModel   MdmrInquireStringModelSafeType

#else // #if M_MIL_USE_SAFE_TYPE

#define MdmrGetResultUnsafe            MdmrGetResult
#define MdmrInquireUnsafe              MdmrInquire
#define MdmrInquireFontUnsafe          MdmrInquireFont
#define MdmrInquireStringModelUnsafe   MdmrInquireStringModel

#endif // #if M_MIL_USE_SAFE_TYPE

#endif /* !M_MIL_LITE */

#endif
