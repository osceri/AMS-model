/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_duf.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_duf(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t17, NeDsMethodOutput *t18)
{
  PmRealVector out;
  real_T t6[8];
  real_T t7[5];
  real_T t0;
  real_T t12;
  real_T t14;
  real_T t3;
  real_T t4;
  real_T t5;
  size_t t9;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_8;
  M_idx_1 = t17->mM.mX[1];
  M_idx_2 = t17->mM.mX[2];
  M_idx_3 = t17->mM.mX[3];
  M_idx_4 = t17->mM.mX[4];
  M_idx_8 = t17->mM.mX[8];
  out = t18->mDUF;
  if (M_idx_1 != 0) {
    t0 = 1.0E+6;
  } else if (M_idx_8 != 0) {
    t0 = 0.01;
  } else {
    t0 = 1.0E+6;
  }

  if (M_idx_2 != 0) {
    t14 = 0.01;
  } else {
    t14 = 1.0E+8;
  }

  if (M_idx_3 != 0) {
    t12 = 4.3755555938442746E-5;
  } else {
    t12 = 437555.55938442744;
  }

  if (M_idx_4 != 0) {
    t3 = -0.44759931494036587;
  } else {
    t3 = -1.0043755599693999E+8;
  }

  if (M_idx_3 != 0) {
    t4 = 0.0001;
  } else {
    t4 = 1.0E+6;
  }

  if (M_idx_4 != 0) {
    t5 = -1.0001;
  } else {
    t5 = -1.000001E+6;
  }

  t7[0ULL] = 0.0043755555938442747;
  t7[1ULL] = t0 / 1.0E+6;
  t7[2ULL] = t14 / 1.0E+8;
  t7[3ULL] = t12 / 1.0E+8;
  t7[4ULL] = t3 / 1.0E+8;
  for (t9 = 0ULL; t9 < 5ULL; t9++) {
    t6[t9] = t7[t9];
  }

  out.mX[0] = t6[0];
  out.mX[1] = t6[1];
  out.mX[2] = t6[2];
  out.mX[3] = t6[3];
  out.mX[4] = t6[4];
  out.mX[5] = 0.01;
  out.mX[6] = t4 / 1.0E+8;
  out.mX[7] = t5 / 1.0E+8;
  (void)sys;
  (void)t18;
  return 0;
}
