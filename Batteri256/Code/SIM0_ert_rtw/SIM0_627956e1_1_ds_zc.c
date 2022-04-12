/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_zc.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_zc(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t3, NeDsMethodOutput *t4)
{
  PmRealVector out;
  real_T D_idx_0;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T U_idx_6;
  real_T U_idx_7;
  real_T X_idx_1;
  real_T X_idx_6;
  real_T X_idx_8;
  real_T t0;
  int32_T M_idx_1;
  int32_T M_idx_10;
  int32_T M_idx_11;
  int32_T M_idx_12;
  int32_T M_idx_14;
  int32_T M_idx_8;
  int32_T M_idx_9;
  M_idx_1 = t3->mM.mX[1];
  M_idx_8 = t3->mM.mX[8];
  M_idx_9 = t3->mM.mX[9];
  M_idx_10 = t3->mM.mX[10];
  M_idx_11 = t3->mM.mX[11];
  M_idx_12 = t3->mM.mX[12];
  M_idx_14 = t3->mM.mX[14];
  U_idx_4 = t3->mU.mX[4];
  U_idx_5 = t3->mU.mX[5];
  U_idx_6 = t3->mU.mX[6];
  U_idx_7 = t3->mU.mX[7];
  X_idx_1 = t3->mX.mX[1];
  X_idx_6 = t3->mX.mX[6];
  X_idx_8 = t3->mX.mX[8];
  D_idx_0 = t3->mD.mX[0];
  out = t4->mZC;
  if ((!(D_idx_0 == 1.0)) && (!(D_idx_0 == 2.0)) && (!(D_idx_0 == 3.0))) {
    t0 = 1.5 - U_idx_6;
  } else {
    t0 = 0.0;
  }

  if ((!(D_idx_0 == 1.0)) && (!(D_idx_0 == 2.0)) && (!(D_idx_0 == 3.0)) &&
      (M_idx_14 == 0)) {
    U_idx_6 = 2.5 - U_idx_6;
  } else {
    U_idx_6 = 0.0;
  }

  out.mX[0] = (X_idx_6 * 1.0E-6 + X_idx_1) - 0.6;
  out.mX[1] = (real_T)(X_idx_8 == 1.0);
  out.mX[2] = (real_T)((M_idx_1 == 0) && (X_idx_8 == 2.0));
  out.mX[3] = (real_T)((M_idx_1 == 0) && (M_idx_8 == 0) && (X_idx_8 == 3.0));
  out.mX[4] = (real_T)((M_idx_1 == 0) && (M_idx_8 == 0) && (M_idx_9 == 0) &&
                       (X_idx_8 == 4.0));
  out.mX[5] = (real_T)((M_idx_1 == 0) && (M_idx_8 == 0) && (M_idx_9 == 0) &&
                       (M_idx_10 == 0) && (X_idx_8 == 5.0));
  out.mX[6] = (real_T)((M_idx_1 == 0) && (M_idx_8 == 0) && (M_idx_9 == 0) &&
                       (M_idx_10 == 0) && (M_idx_11 == 0) && (X_idx_8 == 6.0));
  out.mX[7] = (real_T)((M_idx_1 == 0) && (M_idx_8 == 0) && (M_idx_9 == 0) &&
                       (M_idx_10 == 0) && (M_idx_11 == 0) && (M_idx_12 == 0) &&
                       (X_idx_8 == 7.0));
  out.mX[8] = t0;
  out.mX[9] = U_idx_6;
  out.mX[10] = 1.0;
  out.mX[11] = 1.0;
  out.mX[12] = 1.0;
  out.mX[13] = U_idx_7 - 0.5;
  out.mX[14] = U_idx_4 - 0.5;
  out.mX[15] = U_idx_5 - 0.5;
  (void)sys;
  (void)t4;
  return 0;
}
