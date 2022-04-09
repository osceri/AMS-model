var dataJson = {"arch":{"ispc":true,"isunix":false,"ismac":false},"build":"model/Accumulator","ref":false,"files":[{"name":"ert_main.c","type":"source","group":"main","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Accumulator_ert_rtw","tag":"","groupDisplay":"Main file","code":"#include <stddef.h>\r\n#include <stdio.h>\r\n#include \"Accumulator.h\"\r\n\r\nvoid rt_OneStep(void);\r\nvoid rt_OneStep(void)\r\n{\r\n  static boolean_T OverrunFlag = false;\r\n  if (OverrunFlag) {\r\n    rtmSetErrorStatus(Accumulator_M, \"Overrun\");\r\n    return;\r\n  }\r\n\r\n  OverrunFlag = true;\r\n  Accumulator_step();\r\n  OverrunFlag = false;\r\n}\r\n\r\nint_T main(int_T argc, const char *argv[])\r\n{\r\n  (void)(argc);\r\n  (void)(argv);\r\n  Accumulator_initialize();\r\n  printf(\"Warning: The simulation will run forever. \"\r\n         \"Generated ERT main won't simulate model step behavior. \"\r\n         \"To change this behavior select the 'MAT-file logging' option.\\n\");\r\n  fflush((NULL));\r\n  while (rtmGetErrorStatus(Accumulator_M) == (NULL)) {\r\n  }\r\n\r\n  Accumulator_terminate();\r\n  return 0;\r\n}\r\n"},{"name":"Accumulator.c","type":"source","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Accumulator_ert_rtw","tag":"","groupDisplay":"Model files","code":"#include \"Accumulator.h\"\r\n#include <math.h>\r\n#include \"rtwtypes.h\"\r\n#include <string.h>\r\n#include \"look1_binlxpw.h\"\r\n\r\nDW_Accumulator_T Accumulator_DW;\r\nExtU_Accumulator_T Accumulator_U;\r\nExtY_Accumulator_T Accumulator_Y;\r\nstatic RT_MODEL_Accumulator_T Accumulator_M_;\r\nRT_MODEL_Accumulator_T *const Accumulator_M = &Accumulator_M_;\r\nvoid Accumulator_step(void)\r\n{\r\n  real_T rtb_Divide[126];\r\n  real_T rtb_Rsz[126];\r\n  real_T rtb_Switch[126];\r\n  real_T rtb_Divide_a;\r\n  real_T rtb_Product1_g;\r\n  real_T rtb_tauz;\r\n  int32_T i;\r\n  rtb_Product1_g = Accumulator_P.Ts_sim * Accumulator_U.Current;\r\n  for (i = 0; i < 126; i++) {\r\n    real_T a;\r\n    real_T rtb_Rsz_m;\r\n    rtb_Divide_a = Accumulator_DW.Memory_PreviousInput[i] /\r\n      Accumulator_DW.Memory2_PreviousInput[i];\r\n    rtb_Rsz_m = look1_binlxpw(rtb_Divide_a, Accumulator_P.soc, Accumulator_P.Rs,\r\n      12U);\r\n    rtb_tauz = look1_binlxpw(rtb_Divide_a, Accumulator_P.soc, Accumulator_P.tau,\r\n      12U);\r\n    a = rtb_Rsz_m * rtb_tauz;\r\n    rtb_Rsz_m = (rtb_Rsz_m + look1_binlxpw(rtb_Divide_a, Accumulator_P.soc,\r\n      Accumulator_P.Rp, 12U)) * Accumulator_P.Ts_sim;\r\n    rtb_Rsz_m = (((2.0 * a + rtb_Rsz_m) * Accumulator_U.Current + (rtb_Rsz_m -\r\n      2.0 * a) * Accumulator_DW.Memory3_PreviousInput) - (Accumulator_P.Ts_sim -\r\n      2.0 * rtb_tauz) * Accumulator_DW.Memory4_PreviousInput[i]) / (2.0 *\r\n      rtb_tauz + Accumulator_P.Ts_sim);\r\n    rtb_tauz = rtb_Rsz_m + look1_binlxpw(rtb_Divide_a, Accumulator_P.soc,\r\n      Accumulator_P.ocv, 12U);\r\n    Accumulator_Y.Voltages[i] = rtb_tauz;\r\n    rtb_Divide[i] = rtb_Divide_a;\r\n    rtb_Rsz[i] = rtb_Rsz_m;\r\n    rtb_Switch[i] = (rtb_Product1_g + Accumulator_DW.Memory_PreviousInput[i]) -\r\n      rtb_tauz / Accumulator_P.R_short * Accumulator_U.Balances[i];\r\n  }\r\n\r\n  rtb_Product1_g = exp(Accumulator_P.Cap_det / (Accumulator_P.C_r * 3600.0) *\r\n                       Accumulator_DW.Memory1_PreviousInput);\r\n  Accumulator_DW.Memory3_PreviousInput = Accumulator_U.Current;\r\n  for (i = 0; i < 126; i++) {\r\n    rtb_tauz = rtb_Switch[i];\r\n    rtb_Divide_a = Accumulator_DW.Memory2_PreviousInput[i] * rtb_Product1_g;\r\n    Accumulator_Y.SOCs[i] = rtb_Divide[i];\r\n    Accumulator_Y.Capacities[i] = Accumulator_DW.Memory2_PreviousInput[i];\r\n    Accumulator_DW.Memory4_PreviousInput[i] = rtb_Rsz[i];\r\n    if (rtb_tauz > rtb_Divide_a) {\r\n      Accumulator_DW.Memory_PreviousInput[i] = rtb_Divide_a;\r\n    } else if (rtb_tauz < Accumulator_P.Constant1_Value) {\r\n      Accumulator_DW.Memory_PreviousInput[i] = Accumulator_P.Constant1_Value;\r\n    } else {\r\n      Accumulator_DW.Memory_PreviousInput[i] = rtb_tauz;\r\n    }\r\n\r\n    Accumulator_DW.Memory2_PreviousInput[i] = rtb_Divide_a;\r\n  }\r\n\r\n  Accumulator_DW.Memory1_PreviousInput = fabs(Accumulator_U.Current +\r\n    Accumulator_DW.Memory1_PreviousInput);\r\n}\r\n\r\nvoid Accumulator_initialize(void)\r\n{\r\n  Accumulator_DW.Memory3_PreviousInput = Accumulator_P.Memory3_InitialCondition;\r\n  memcpy(&Accumulator_DW.Memory4_PreviousInput[0],\r\n         &Accumulator_P.Memory4_InitialCondition[0], 126U * sizeof(real_T));\r\n  memcpy(&Accumulator_DW.Memory_PreviousInput[0], &Accumulator_P.cQur[0], 126U *\r\n         sizeof(real_T));\r\n  memcpy(&Accumulator_DW.Memory2_PreviousInput[0], &Accumulator_P.cCap[0], 126U *\r\n         sizeof(real_T));\r\n  Accumulator_DW.Memory1_PreviousInput = Accumulator_P.Memory1_InitialCondition;\r\n}\r\n\r\nvoid Accumulator_terminate(void)\r\n{\r\n}\r\n"},{"name":"Accumulator.h","type":"header","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Accumulator_ert_rtw","tag":"","groupDisplay":"Model files","code":"#ifndef RTW_HEADER_Accumulator_h_\r\n#define RTW_HEADER_Accumulator_h_\r\n#ifndef Accumulator_COMMON_INCLUDES_\r\n#define Accumulator_COMMON_INCLUDES_\r\n#include \"rtwtypes.h\"\r\n#endif\r\n\r\n#include \"Accumulator_types.h\"\r\n\r\n#ifndef rtmGetErrorStatus\r\n#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)\r\n#endif\r\n\r\n#ifndef rtmSetErrorStatus\r\n#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))\r\n#endif\r\n\r\ntypedef struct {\r\n  real_T Memory4_PreviousInput[126];\r\n  real_T Memory3_PreviousInput;\r\n  real_T Memory_PreviousInput[126];\r\n  real_T Memory2_PreviousInput[126];\r\n  real_T Memory1_PreviousInput;\r\n} DW_Accumulator_T;\r\n\r\ntypedef struct {\r\n  real_T Current;\r\n  real_T Balances[126];\r\n} ExtU_Accumulator_T;\r\n\r\ntypedef struct {\r\n  real_T Voltages[126];\r\n  real_T SOCs[126];\r\n  real_T Capacities[126];\r\n} ExtY_Accumulator_T;\r\n\r\nstruct P_Accumulator_T_ {\r\n  real_T C_r;\r\n  real_T Cap_det;\r\n  real_T R_short;\r\n  real_T Rp[13];\r\n  real_T Rs[13];\r\n  real_T Ts_sim;\r\n  real_T cCap[126];\r\n  real_T cQur[126];\r\n  real_T ocv[13];\r\n  real_T soc[13];\r\n  real_T tau[13];\r\n  real_T Memory4_InitialCondition[126];\r\n  real_T Memory3_InitialCondition;\r\n  real_T Memory1_InitialCondition;\r\n  real_T Constant1_Value;\r\n};\r\n\r\nstruct tag_RTM_Accumulator_T {\r\n  const char_T * volatile errorStatus;\r\n};\r\n\r\nextern P_Accumulator_T Accumulator_P;\r\nextern DW_Accumulator_T Accumulator_DW;\r\nextern ExtU_Accumulator_T Accumulator_U;\r\nextern ExtY_Accumulator_T Accumulator_Y;\r\nextern void Accumulator_initialize(void);\r\nextern void Accumulator_step(void);\r\nextern void Accumulator_terminate(void);\r\nextern RT_MODEL_Accumulator_T *const Accumulator_M;\r\n\r\n#endif\r\n\r\n"},{"name":"Accumulator_private.h","type":"header","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Accumulator_ert_rtw","tag":"","groupDisplay":"Model files","code":"#ifndef RTW_HEADER_Accumulator_private_h_\r\n#define RTW_HEADER_Accumulator_private_h_\r\n#include \"rtwtypes.h\"\r\n#endif\r\n\r\n"},{"name":"Accumulator_types.h","type":"header","group":"model","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Accumulator_ert_rtw","tag":"","groupDisplay":"Model files","code":"#ifndef RTW_HEADER_Accumulator_types_h_\r\n#define RTW_HEADER_Accumulator_types_h_\r\n\r\ntypedef struct P_Accumulator_T_ P_Accumulator_T;\r\ntypedef struct tag_RTM_Accumulator_T RT_MODEL_Accumulator_T;\r\n\r\n#endif\r\n\r\n"},{"name":"Accumulator_data.c","type":"source","group":"data","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\Accumulator_ert_rtw","tag":"","groupDisplay":"Data files","code":"#include \"Accumulator.h\"\r\n\r\nP_Accumulator_T Accumulator_P = {\r\n\r\n  6.6,\r\n\r\n  -1.0E-6,\r\n\r\n  33.0,\r\n\r\n\r\n  { 0.0013284973182, 0.00132849731829051, 0.00133071540686515,\r\n    0.00133106364620441, 0.00133282418704394, 0.00133927918011939,\r\n    0.00135371077616641, 0.00137940112592065, 0.00141963238011775,\r\n    0.00147768668949337, 0.00155684620478314, 0.00166039307672272,\r\n    0.00179160945604776 },\r\n\r\n\r\n  { 0.0044622496006, 0.00446224960061823, 0.00395928973129493,\r\n    0.00365723545490869, 0.00346135878439388, 0.00332839611795259,\r\n    0.00323577769308545, 0.00317057626115591, 0.00312485453442757,\r\n    0.00309346940400882, 0.00307294184679812, 0.00306083426030356,\r\n    0.00305538791678206 },\r\n\r\n  0.2,\r\n\r\n\r\n  { 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,\r\n    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0 },\r\n\r\n\r\n  { 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,\r\n    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0 },\r\n\r\n\r\n  { 0.0, 2.99808472821531, 3.29015678205606, 3.51449858492796, 3.66802196422992,\r\n    3.76050972589663, 3.81021773542304, 3.83947699888896, 3.87029574398353,\r\n    3.91996150102984, 3.99664318400941, 4.09499317158672, 4.19174938813381 },\r\n\r\n\r\n  { 0.0, 0.01, 0.0909090909090909, 0.181818181818182, 0.272727272727273,\r\n    0.363636363636364, 0.454545454545455, 0.545454545454545, 0.636363636363636,\r\n    0.727272727272727, 0.818181818181818, 0.909090909090909, 1.0 },\r\n\r\n\r\n  { 950.87194683, 950.871946837005, 952.459545918238, 952.715608141667,\r\n    956.801088701637, 1116.9800008749899, 2163.29230815358, 2204.3466729378397,\r\n    1183.99583949683, 1060.79424954235, 1114.3206284707098, 1188.42633649718,\r\n    1282.34445639369 },\r\n\r\n\r\n  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,\r\n    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },\r\n\r\n  0.0,\r\n\r\n  0.0,\r\n\r\n  0.0\r\n};\r\n"},{"name":"look1_binlxpw.c","type":"source","group":"sharedutility","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\slprj\\ert\\_sharedutils","tag":"","groupDisplay":"Shared files","code":"#include \"look1_binlxpw.h\"\r\n#include \"rtwtypes.h\"\r\n\r\nreal_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],\r\n                     uint32_T maxIndex)\r\n{\r\n  real_T frac;\r\n  real_T yL_0d0;\r\n  uint32_T iLeft;\r\n  if (u0 <= bp0[0U]) {\r\n    iLeft = 0U;\r\n    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);\r\n  } else if (u0 < bp0[maxIndex]) {\r\n    uint32_T bpIdx;\r\n    uint32_T iRght;\r\n    bpIdx = maxIndex >> 1U;\r\n    iLeft = 0U;\r\n    iRght = maxIndex;\r\n    while (iRght - iLeft > 1U) {\r\n      if (u0 < bp0[bpIdx]) {\r\n        iRght = bpIdx;\r\n      } else {\r\n        iLeft = bpIdx;\r\n      }\r\n\r\n      bpIdx = (iRght + iLeft) >> 1U;\r\n    }\r\n\r\n    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);\r\n  } else {\r\n    iLeft = maxIndex - 1U;\r\n    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);\r\n  }\r\n\r\n  yL_0d0 = table[iLeft];\r\n  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;\r\n}\r\n"},{"name":"look1_binlxpw.h","type":"header","group":"sharedutility","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\slprj\\ert\\_sharedutils","tag":"","groupDisplay":"Shared files","code":"#ifndef RTW_HEADER_look1_binlxpw_h_\r\n#define RTW_HEADER_look1_binlxpw_h_\r\n#include \"rtwtypes.h\"\r\n\r\nextern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],\r\n  uint32_T maxIndex);\r\n\r\n#endif\r\n\r\n"},{"name":"rtwtypes.h","type":"header","group":"sharedutility","path":"C:\\Users\\oscar\\Documents\\GitHub\\AMS-model\\Batteri256\\Code\\slprj\\ert\\_sharedutils","tag":"","groupDisplay":"Shared files","code":"#ifndef RTWTYPES_H\r\n#define RTWTYPES_H\r\n\r\n#if (!defined(__cplusplus))\r\n#ifndef false\r\n#define false                          (0U)\r\n#endif\r\n\r\n#ifndef true\r\n#define true                           (1U)\r\n#endif\r\n#endif\r\n\r\ntypedef signed char int8_T;\r\ntypedef unsigned char uint8_T;\r\ntypedef short int16_T;\r\ntypedef unsigned short uint16_T;\r\ntypedef int int32_T;\r\ntypedef unsigned int uint32_T;\r\ntypedef float real32_T;\r\ntypedef double real64_T;\r\ntypedef double real_T;\r\ntypedef double time_T;\r\ntypedef unsigned char boolean_T;\r\ntypedef int int_T;\r\ntypedef unsigned int uint_T;\r\ntypedef unsigned long ulong_T;\r\ntypedef char char_T;\r\ntypedef unsigned char uchar_T;\r\ntypedef char_T byte_T;\r\n\r\n#define MAX_int8_T                     ((int8_T)(127))\r\n#define MIN_int8_T                     ((int8_T)(-128))\r\n#define MAX_uint8_T                    ((uint8_T)(255U))\r\n#define MAX_int16_T                    ((int16_T)(32767))\r\n#define MIN_int16_T                    ((int16_T)(-32768))\r\n#define MAX_uint16_T                   ((uint16_T)(65535U))\r\n#define MAX_int32_T                    ((int32_T)(2147483647))\r\n#define MIN_int32_T                    ((int32_T)(-2147483647-1))\r\n#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))\r\n\r\ntypedef void * pointer_T;\r\n\r\n#endif\r\n\r\n"}]};