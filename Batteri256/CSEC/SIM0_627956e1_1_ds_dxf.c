/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_dxf.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_dxf(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t39, NeDsMethodOutput *t40)
{
  PmRealVector out;
  real_T t14[29];
  real_T t16[5];
  real_T t18[4];
  real_T t0;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t2;
  real_T t29;
  real_T t3;
  real_T t36;
  real_T t37;
  real_T t38;
  real_T t4;
  real_T t7;
  real_T t8;
  real_T t9;
  size_t t24;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_8;
  int32_T M_idx_9;
  M_idx_0 = t39->mM.mX[0];
  M_idx_1 = t39->mM.mX[1];
  M_idx_2 = t39->mM.mX[2];
  M_idx_3 = t39->mM.mX[3];
  M_idx_4 = t39->mM.mX[4];
  M_idx_8 = t39->mM.mX[8];
  M_idx_9 = t39->mM.mX[9];
  out = t40->mDXF;
  if (M_idx_0 != 0) {
    t0 = -3.3433333333333333;
  } else {
    t0 = -0.01000001;
  }

  if (M_idx_3 != 0) {
    t29 = -0.0001;
  } else {
    t29 = -1.0E+6;
  }

  if (M_idx_4 != 0) {
    t2 = 0.0001;
  } else {
    t2 = 1.0E+6;
  }

  if (M_idx_1 != 0) {
    t3 = -1.0E+6;
  } else if (M_idx_8 != 0) {
    t3 = -1.0E+6;
  } else {
    t3 = M_idx_9 != 0 ? -0.01 : -1.0E+6;
  }

  if (M_idx_2 != 0) {
    t4 = -0.01;
  } else {
    t4 = -1.0E+8;
  }

  if (M_idx_3 != 0) {
    t38 = -4.3755555938442746E-5;
  } else {
    t38 = -437555.55938442744;
  }

  if (M_idx_4 != 0) {
    t37 = 0.44759931494036587;
  } else {
    t37 = 1.0043755599693999E+8;
  }

  if (M_idx_3 != 0) {
    t7 = -0.0001;
  } else {
    t7 = -1.0E+6;
  }

  if (M_idx_4 != 0) {
    t8 = 1.0001;
  } else {
    t8 = 1.000001E+6;
  }

  if (M_idx_0 != 0) {
    t9 = -1.0000033433333333;
  } else {
    t9 = -1.00000001000001;
  }

  if (M_idx_3 != 0) {
    t36 = -1.0E-10;
  } else {
    t36 = -1.0;
  }

  if (M_idx_4 != 0) {
    t11 = 1.0E-10;
  } else {
    t11 = 1.0;
  }

  if (M_idx_3 != 0) {
    t12 = 1.0001;
  } else {
    t12 = 1.000001E+6;
  }

  if (M_idx_4 != 0) {
    t13 = -0.0001;
  } else {
    t13 = -1.0E+6;
  }

  t16[0ULL] = -0.0043755555938442747;
  t16[1ULL] = t3 / 1.0E+6;
  t16[2ULL] = t4 / 1.0E+8;
  t16[3ULL] = t38 / 1.0E+8;
  t16[4ULL] = t37 / 1.0E+8;
  t18[0ULL] = -0.01;
  t18[1ULL] = 1.0E-6;
  t18[2ULL] = t7 / 1.0E+8;
  t18[3ULL] = t8 / 1.0E+8;
  t14[0ULL] = -1.0E-6;
  t14[1ULL] = t0;
  t14[2ULL] = t29 / 1.0E+8;
  t14[3ULL] = t2 / 1.0E+8;
  for (t24 = 0ULL; t24 < 5ULL; t24++) {
    t14[t24 + 4ULL] = t16[t24];
  }

  t14[9ULL] = -1.0E-6;
  t14[10ULL] = 1.0E-8;
  for (t24 = 0ULL; t24 < 4ULL; t24++) {
    t14[t24 + 11ULL] = t18[t24];
  }

  out.mX[0] = t14[0];
  out.mX[1] = t14[1];
  out.mX[2] = t14[2];
  out.mX[3] = t14[3];
  out.mX[4] = t14[4];
  out.mX[5] = t14[5];
  out.mX[6] = t14[6];
  out.mX[7] = t14[7];
  out.mX[8] = t14[8];
  out.mX[9] = t14[9];
  out.mX[10] = t14[10];
  out.mX[11] = t14[11];
  out.mX[12] = t14[12];
  out.mX[13] = t14[13];
  out.mX[14] = t14[14];
  out.mX[15] = 1.0E-6;
  out.mX[16] = t9;
  out.mX[17] = t36 / 1.0E+8;
  out.mX[18] = t11 / 1.0E+8;
  out.mX[19] = 0.01;
  out.mX[20] = t12 / 1.0E+8;
  out.mX[21] = t13 / 1.0E+8;
  out.mX[22] = 1.0;
  out.mX[23] = 1.0;
  out.mX[24] = 1.0;
  out.mX[25] = 1.0;
  out.mX[26] = 1.0;
  out.mX[27] = 1.0;
  out.mX[28] = 1.0;
  (void)sys;
  (void)t40;
  return 0;
}
