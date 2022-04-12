/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_f.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_f(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t14, NeDsMethodOutput *t15)
{
  PmRealVector out;
  real_T D_idx_0;
  real_T SIM_Switch2_i;
  real_T U_idx_1;
  real_T U_idx_3;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_10;
  real_T X_idx_11;
  real_T X_idx_12;
  real_T X_idx_13;
  real_T X_idx_14;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T t1;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_14;
  int32_T M_idx_15;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_8;
  int32_T M_idx_9;
  M_idx_0 = t14->mM.mX[0];
  M_idx_1 = t14->mM.mX[1];
  M_idx_2 = t14->mM.mX[2];
  M_idx_3 = t14->mM.mX[3];
  M_idx_4 = t14->mM.mX[4];
  M_idx_8 = t14->mM.mX[8];
  M_idx_9 = t14->mM.mX[9];
  M_idx_14 = t14->mM.mX[14];
  M_idx_15 = t14->mM.mX[15];
  U_idx_1 = t14->mU.mX[1];
  U_idx_3 = t14->mU.mX[3];
  X_idx_0 = t14->mX.mX[0];
  X_idx_1 = t14->mX.mX[1];
  X_idx_2 = t14->mX.mX[2];
  X_idx_3 = t14->mX.mX[3];
  X_idx_4 = t14->mX.mX[4];
  X_idx_5 = t14->mX.mX[5];
  X_idx_6 = t14->mX.mX[6];
  X_idx_7 = t14->mX.mX[7];
  X_idx_8 = t14->mX.mX[8];
  X_idx_9 = t14->mX.mX[9];
  X_idx_10 = t14->mX.mX[10];
  X_idx_11 = t14->mX.mX[11];
  X_idx_12 = t14->mX.mX[12];
  X_idx_13 = t14->mX.mX[13];
  X_idx_14 = t14->mX.mX[14];
  D_idx_0 = t14->mD.mX[0];
  out = t15->mF;
  t5 = -X_idx_2 + U_idx_1;
  t1 = (((((X_idx_1 * -0.01 + X_idx_4 * -0.01) + X_idx_6 * -1.00000001) +
          X_idx_2 * -0.0043755555938442747) + X_idx_7 * 0.01) + U_idx_1 *
        0.0043755555938442747) + U_idx_3 * 0.01;
  t3 = X_idx_6 * 1.0E-6 + X_idx_1;
  t6 = (((((X_idx_1 * 0.01 + X_idx_4 * 0.01) + X_idx_6 * 1.0E-8) + X_idx_2 *
          0.0043755555938442747) + X_idx_7 * -0.01) + U_idx_1 *
        -0.0043755555938442747) + U_idx_3 * -0.01;
  t4 = (-X_idx_0 + -X_idx_3) + X_idx_4;
  SIM_Switch2_i = (((((X_idx_1 * -0.01 + X_idx_4 * -0.01) + X_idx_6 * -1.0E-8) +
                     X_idx_2 * -1.0043755555938443) + X_idx_7 * 0.01) + U_idx_1 *
                   1.0043755555938443) + U_idx_3 * 0.01;
  X_idx_1 = ((X_idx_2 * 0.43755555938442742 + U_idx_1 * -0.43755555938442742) +
             -U_idx_3) + X_idx_4;
  if (M_idx_0 != 0) {
    X_idx_6 = t1 - (t3 - 0.59999999819999994) / 0.3;
  } else {
    X_idx_6 = t1 - t3 * 1.0E-8;
  }

  if (M_idx_1 != 0) {
    t1 = X_idx_5 - -U_idx_1 / 1.0E-6;
  } else if (M_idx_8 != 0) {
    t1 = X_idx_5 - U_idx_1 * -0.01;
  } else {
    t1 = X_idx_5 - -U_idx_1 / 1.0E-6;
  }

  if (M_idx_1 != 0) {
    X_idx_0 = t4 - X_idx_2 / 1.0E-6;
  } else if (M_idx_8 != 0) {
    X_idx_0 = t4 - X_idx_2 / 1.0E-6;
  } else if (M_idx_9 != 0) {
    X_idx_0 = t4 - X_idx_2 * 0.01;
  } else {
    X_idx_0 = t4 - X_idx_2 / 1.0E-6;
  }

  if (D_idx_0 == 1.0) {
    t3 = X_idx_8 - 1.0;
  } else if (D_idx_0 == 2.0) {
    t3 = X_idx_8 - 2.0;
  } else if (D_idx_0 == 3.0) {
    t3 = X_idx_8 - 3.0;
  } else if (M_idx_14 != 0) {
    t3 = X_idx_8 - 1.0;
  } else if (M_idx_15 != 0) {
    t3 = X_idx_8 - 2.0;
  } else {
    t3 = X_idx_8 - 3.0;
  }

  if (M_idx_2 != 0) {
    t4 = X_idx_3 - t5 * -0.01;
  } else {
    t4 = X_idx_3 - -t5 / 1.0E-8;
  }

  if (M_idx_3 != 0) {
    t5 = X_idx_7 - t6 * 0.01;
  } else {
    t5 = X_idx_7 - t6 / 1.0E-8;
  }

  if (M_idx_4 != 0) {
    t6 = X_idx_1 - SIM_Switch2_i * 0.01;
  } else {
    t6 = X_idx_1 - SIM_Switch2_i / 1.0E-8;
  }

  out.mX[0] = -0.0;
  out.mX[1] = -0.0;
  out.mX[2] = X_idx_6;
  out.mX[3] = X_idx_9;
  out.mX[4] = t1 / 1.0E+6;
  out.mX[5] = X_idx_0 / 1.0E+6;
  out.mX[6] = X_idx_10;
  out.mX[7] = X_idx_11;
  out.mX[8] = X_idx_12;
  out.mX[9] = X_idx_13;
  out.mX[10] = X_idx_14;
  out.mX[11] = t3;
  out.mX[12] = t4 / 1.0E+8;
  out.mX[13] = t5 / 1.0E+8;
  out.mX[14] = t6 / 1.0E+8;
  (void)sys;
  (void)t15;
  return 0;
}
