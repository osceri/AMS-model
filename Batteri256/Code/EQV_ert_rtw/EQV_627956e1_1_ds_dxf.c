/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_dxf.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_dxf(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t34, NeDsMethodOutput *t35)
{
  PmRealVector out;
  real_T t9[27];
  real_T t12[5];
  real_T t0;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t24;
  real_T t26;
  real_T t27;
  real_T t31;
  real_T t32;
  real_T t6;
  real_T t8;
  size_t t17;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_8;
  int32_T M_idx_9;
  M_idx_0 = t34->mM.mX[0];
  M_idx_1 = t34->mM.mX[1];
  M_idx_2 = t34->mM.mX[2];
  M_idx_3 = t34->mM.mX[3];
  M_idx_4 = t34->mM.mX[4];
  M_idx_8 = t34->mM.mX[8];
  M_idx_9 = t34->mM.mX[9];
  out = t35->mDXF;
  if (M_idx_0 != 0) {
    t0 = -3.3333333333333335;
  } else {
    t0 = -1.0E-8;
  }

  if (M_idx_1 != 0) {
    t21 = 1.0E+6;
  } else if (M_idx_8 != 0) {
    t21 = 0.01;
  } else {
    t21 = 1.0E+6;
  }

  if (M_idx_1 != 0) {
    t22 = -1.0E+6;
  } else if (M_idx_8 != 0) {
    t22 = -1.0E+6;
  } else {
    t22 = M_idx_9 != 0 ? -0.01 : -1.0E+6;
  }

  if (M_idx_1 != 0) {
    t26 = 1.0E+6;
  } else if (M_idx_8 != 0) {
    t26 = 0.01;
  } else {
    t26 = 1.0E+6;
  }

  if (M_idx_2 != 0) {
    t27 = 0.01;
  } else {
    t27 = 1.0E+8;
  }

  if (M_idx_1 != 0) {
    t31 = 1.0E+6;
  } else if (M_idx_8 != 0) {
    t31 = 0.01;
  } else {
    t31 = 1.0E+6;
  }

  if (M_idx_2 != 0) {
    t6 = 0.01;
  } else {
    t6 = 1.0E+8;
  }

  if (M_idx_4 != 0) {
    t32 = -0.44755555938442743;
  } else {
    t32 = -1.0000000043755557E+8;
  }

  if (M_idx_0 != 0) {
    t8 = -1.0000033333333334;
  } else {
    t8 = -1.00000000000001;
  }

  t20 = t21 / 1.0E+6;
  t21 = t22 / 1.0E+6;
  t22 = -1.0E-6;
  t24 = 1.0E-8;
  t12[0ULL] = -1.0;
  t12[1ULL] = t26 / 1.0E+6;
  t12[2ULL] = t27 / 1.0E+8;
  t12[3ULL] = (M_idx_3 != 0 ? -0.01 : -1.0E+8) / 1.0E+8;
  t12[4ULL] = -4.3755555938442745E-9;
  t26 = t31 / 1.0E+6;
  t31 = 1.0E-6;
  t9[0ULL] = -1.0E-6;
  t9[1ULL] = t0;
  t9[2ULL] = t20;
  t9[3ULL] = t21;
  t9[4ULL] = t22;
  t9[5ULL] = t22;
  t9[6ULL] = t24;
  for (t17 = 0ULL; t17 < 5ULL; t17++) {
    t9[t17 + 7ULL] = t12[t17];
  }

  out.mX[0] = t9[0];
  out.mX[1] = t9[1];
  out.mX[2] = t9[2];
  out.mX[3] = t9[3];
  out.mX[4] = t9[4];
  out.mX[5] = t9[5];
  out.mX[6] = t9[6];
  out.mX[7] = t9[7];
  out.mX[8] = t9[8];
  out.mX[9] = t9[9];
  out.mX[10] = t9[10];
  out.mX[11] = t9[11];
  out.mX[12] = t26;
  out.mX[13] = t6 / 1.0E+8;
  out.mX[14] = t32 / 1.0E+8;
  out.mX[15] = t8;
  out.mX[16] = 1.0E-8;
  out.mX[17] = t31;
  out.mX[18] = t31;
  out.mX[19] = t24;
  out.mX[20] = 1.0;
  out.mX[21] = 1.0;
  out.mX[22] = 1.0;
  out.mX[23] = 1.0;
  out.mX[24] = 1.0;
  out.mX[25] = 1.0;
  out.mX[26] = 1.0;
  (void)sys;
  (void)t35;
  return 0;
}
