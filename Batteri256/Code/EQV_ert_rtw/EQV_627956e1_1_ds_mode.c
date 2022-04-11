/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_mode.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_mode(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T X_idx_1;
  real_T X_idx_6;
  real_T X_idx_9;
  U_idx_2 = t1->mU.mX[2];
  U_idx_3 = t1->mU.mX[3];
  U_idx_4 = t1->mU.mX[4];
  U_idx_5 = t1->mU.mX[5];
  X_idx_1 = t1->mX.mX[1];
  X_idx_6 = t1->mX.mX[6];
  X_idx_9 = t1->mX.mX[9];
  out = t2->mMODE;
  out.mX[0] = (int32_T)(X_idx_6 * 1.0E-6 + X_idx_1 > 0.6);
  out.mX[1] = (int32_T)(X_idx_9 == 1.0);
  out.mX[2] = (int32_T)(U_idx_5 > 0.5);
  out.mX[3] = (int32_T)(U_idx_2 > 0.5);
  out.mX[4] = (int32_T)(U_idx_3 > 0.5);
  out.mX[5] = 1;
  out.mX[6] = 1;
  out.mX[7] = 1;
  out.mX[8] = (int32_T)(X_idx_9 == 2.0);
  out.mX[9] = (int32_T)(X_idx_9 == 3.0);
  out.mX[10] = (int32_T)(X_idx_9 == 4.0);
  out.mX[11] = (int32_T)(X_idx_9 == 5.0);
  out.mX[12] = (int32_T)(X_idx_9 == 6.0);
  out.mX[13] = (int32_T)(X_idx_9 == 7.0);
  out.mX[14] = (int32_T)(U_idx_4 < 1.5);
  out.mX[15] = (int32_T)(U_idx_4 < 2.5);
  (void)sys;
  (void)t2;
  return 0;
}
