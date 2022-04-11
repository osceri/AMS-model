var dataJson = {"arch":{"ispc":true,"isunix":false,"ismac":false},"build":"model/Charger","ref":false,"files":[{"name":"ert_main.c","type":"source","group":"main","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Charger_ert_rtw","tag":"","groupDisplay":"Main file","code":"#include <stddef.h>\r\n#include <stdio.h>\r\n#include \"Charger.h\"\r\n\r\nvoid rt_OneStep(void);\r\nvoid rt_OneStep(void)\r\n{\r\n  static boolean_T OverrunFlag = false;\r\n  if (OverrunFlag) {\r\n    rtmSetErrorStatus(Charger_M, \"Overrun\");\r\n    return;\r\n  }\r\n\r\n  OverrunFlag = true;\r\n  Charger_step();\r\n  OverrunFlag = false;\r\n}\r\n\r\nint_T main(int_T argc, const char *argv[])\r\n{\r\n  (void)(argc);\r\n  (void)(argv);\r\n  Charger_initialize();\r\n  printf(\"Warning: The simulation will run forever. \"\r\n         \"Generated ERT main won't simulate model step behavior. \"\r\n         \"To change this behavior select the 'MAT-file logging' option.\\n\");\r\n  fflush((NULL));\r\n  while (rtmGetErrorStatus(Charger_M) == (NULL)) {\r\n  }\r\n\r\n  Charger_terminate();\r\n  return 0;\r\n}\r\n"},{"name":"Charger.c","type":"source","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Charger_ert_rtw","tag":"","groupDisplay":"Model files","code":"#include \"Charger.h\"\r\n\r\nExtU_Charger_T Charger_U;\r\nExtY_Charger_T Charger_Y;\r\nstatic RT_MODEL_Charger_T Charger_M_;\r\nRT_MODEL_Charger_T *const Charger_M = &Charger_M_;\r\nvoid Charger_step(void)\r\n{\r\n  Charger_Y.Current = Charger_P.cell_count * 0.0034726631697176778 *\r\n    Charger_U.CV_true * (Charger_U.CV_level - Charger_U.y) + Charger_U.CC_true *\r\n    Charger_U.CC_level;\r\n}\r\n\r\nvoid Charger_initialize(void)\r\n{\r\n}\r\n\r\nvoid Charger_terminate(void)\r\n{\r\n}\r\n"},{"name":"Charger.h","type":"header","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Charger_ert_rtw","tag":"","groupDisplay":"Model files","code":"#ifndef RTW_HEADER_Charger_h_\r\n#define RTW_HEADER_Charger_h_\r\n#ifndef Charger_COMMON_INCLUDES_\r\n#define Charger_COMMON_INCLUDES_\r\n#include \"rtwtypes.h\"\r\n#endif\r\n\r\n#include \"Charger_types.h\"\r\n\r\n#ifndef rtmGetErrorStatus\r\n#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)\r\n#endif\r\n\r\n#ifndef rtmSetErrorStatus\r\n#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))\r\n#endif\r\n\r\ntypedef struct {\r\n  real_T CC_true;\r\n  real_T CC_level;\r\n  real_T CV_true;\r\n  real_T CV_level;\r\n  real_T y;\r\n} ExtU_Charger_T;\r\n\r\ntypedef struct {\r\n  real_T Current;\r\n} ExtY_Charger_T;\r\n\r\nstruct P_Charger_T_ {\r\n  real_T cell_count;\r\n};\r\n\r\nstruct tag_RTM_Charger_T {\r\n  const char_T * volatile errorStatus;\r\n};\r\n\r\nextern P_Charger_T Charger_P;\r\nextern ExtU_Charger_T Charger_U;\r\nextern ExtY_Charger_T Charger_Y;\r\nextern void Charger_initialize(void);\r\nextern void Charger_step(void);\r\nextern void Charger_terminate(void);\r\nextern RT_MODEL_Charger_T *const Charger_M;\r\n\r\n#endif\r\n\r\n"},{"name":"Charger_private.h","type":"header","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Charger_ert_rtw","tag":"","groupDisplay":"Model files","code":"#ifndef RTW_HEADER_Charger_private_h_\r\n#define RTW_HEADER_Charger_private_h_\r\n#include \"rtwtypes.h\"\r\n#endif\r\n\r\n"},{"name":"Charger_types.h","type":"header","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Charger_ert_rtw","tag":"","groupDisplay":"Model files","code":"#ifndef RTW_HEADER_Charger_types_h_\r\n#define RTW_HEADER_Charger_types_h_\r\n\r\ntypedef struct P_Charger_T_ P_Charger_T;\r\ntypedef struct tag_RTM_Charger_T RT_MODEL_Charger_T;\r\n\r\n#endif\r\n\r\n"},{"name":"Charger_data.c","type":"source","group":"data","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Charger_ert_rtw","tag":"","groupDisplay":"Data files","code":"#include \"Charger.h\"\r\n\r\nP_Charger_T Charger_P = {\r\n\r\n  126.0\r\n};\r\n"},{"name":"rtwtypes.h","type":"header","group":"sharedutility","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\slprj\\ert\\_sharedutils","tag":"","groupDisplay":"Shared files","code":"#ifndef RTWTYPES_H\r\n#define RTWTYPES_H\r\n\r\n#if (!defined(__cplusplus))\r\n#ifndef false\r\n#define false                          (0U)\r\n#endif\r\n\r\n#ifndef true\r\n#define true                           (1U)\r\n#endif\r\n#endif\r\n\r\ntypedef signed char int8_T;\r\ntypedef unsigned char uint8_T;\r\ntypedef short int16_T;\r\ntypedef unsigned short uint16_T;\r\ntypedef int int32_T;\r\ntypedef unsigned int uint32_T;\r\ntypedef float real32_T;\r\ntypedef double real64_T;\r\ntypedef double real_T;\r\ntypedef double time_T;\r\ntypedef unsigned char boolean_T;\r\ntypedef int int_T;\r\ntypedef unsigned int uint_T;\r\ntypedef unsigned long ulong_T;\r\ntypedef char char_T;\r\ntypedef unsigned char uchar_T;\r\ntypedef char_T byte_T;\r\n\r\n#define MAX_int8_T                     ((int8_T)(127))\r\n#define MIN_int8_T                     ((int8_T)(-128))\r\n#define MAX_uint8_T                    ((uint8_T)(255U))\r\n#define MAX_int16_T                    ((int16_T)(32767))\r\n#define MIN_int16_T                    ((int16_T)(-32768))\r\n#define MAX_uint16_T                   ((uint16_T)(65535U))\r\n#define MAX_int32_T                    ((int32_T)(2147483647))\r\n#define MIN_int32_T                    ((int32_T)(-2147483647-1))\r\n#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))\r\n\r\ntypedef void * pointer_T;\r\n\r\n#endif\r\n\r\n"}]};