/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Main_private.h
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 17:16:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Main_private_h_
#define RTW_HEADER_Main_private_h_
#include "rtwtypes.h"
#include "Main.h"

extern const real_T rtCP_pooled_wjJxOD0WgI1H[33];
extern const real_T rtCP_pooled_yD3VEbGticFc[33];
extern const real_T rtCP_pooled_4HQkfx1LwCqp[33];
extern const real_T rtCP_pooled_qnzm1iMH9d5T[33];
extern const real_T rtCP_pooled_KAm7Ys5wt1Ak[33];

#define rtCP_uDLookupTable2_tableData  rtCP_pooled_wjJxOD0WgI1H  /* Expression: Rp_LUT
                                                                  * Referenced by: '<S13>/1-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable2_bp01Data   rtCP_pooled_yD3VEbGticFc  /* Expression: soc_LUT
                                                                  * Referenced by: '<S13>/1-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable1_tableData  rtCP_pooled_4HQkfx1LwCqp  /* Expression: tau_LUT
                                                                  * Referenced by: '<S13>/1-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp01Data   rtCP_pooled_yD3VEbGticFc  /* Expression: soc_LUT
                                                                  * Referenced by: '<S13>/1-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable_tableData_g rtCP_pooled_qnzm1iMH9d5T  /* Expression: ocv_LUT
                                                                  * Referenced by: '<S14>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_e  rtCP_pooled_yD3VEbGticFc  /* Expression: soc_LUT
                                                                  * Referenced by: '<S14>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_tableData_j rtCP_pooled_KAm7Ys5wt1Ak /* Expression: Rs_LUT
                                                                  * Referenced by: '<S14>/1-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp01Data_l rtCP_pooled_yD3VEbGticFc  /* Expression: soc_LUT
                                                                  * Referenced by: '<S14>/1-D Lookup Table1'
                                                                  */

extern void batteryStateFcn(const real_T rtu_x[2], real_T rty_x_next[2]);
extern void batteryMeasurementFcn(const real_T rtu_x[2], real_T *rty_y);

#endif                                 /* RTW_HEADER_Main_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
