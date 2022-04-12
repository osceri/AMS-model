/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_mode.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_mode(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T U_idx_6;
  real_T U_idx_7;
  real_T X_idx_1;
  real_T X_idx_6;
  real_T X_idx_8;
  U_idx_4 = t1->mU.mX[4];
  U_idx_5 = t1->mU.mX[5];
  U_idx_6 = t1->mU.mX[6];
  U_idx_7 = t1->mU.mX[7];
  X_idx_1 = t1->mX.mX[1];
  X_idx_6 = t1->mX.mX[6];
  X_idx_8 = t1->mX.mX[8];
  out = t2->mMODE;
  out.mX[0] = (int32_T)(X_idx_6 * 1.0E-6 + X_idx_1 > 0.6);
  out.mX[1] = (int32_T)(X_idx_8 == 1.0);
  out.mX[2] = (int32_T)(U_idx_7 > 0.5);
  out.mX[3] = (int32_T)(U_idx_4 > 0.5);
  out.mX[4] = (int32_T)(U_idx_5 > 0.5);
  out.mX[5] = 1;
  out.mX[6] = 1;
  out.mX[7] = 1;
  out.mX[8] = (int32_T)(X_idx_8 == 2.0);
  out.mX[9] = (int32_T)(X_idx_8 == 3.0);
  out.mX[10] = (int32_T)(X_idx_8 == 4.0);
  out.mX[11] = (int32_T)(X_idx_8 == 5.0);
  out.mX[12] = (int32_T)(X_idx_8 == 6.0);
  out.mX[13] = (int32_T)(X_idx_8 == 7.0);
  out.mX[14] = (int32_T)(U_idx_6 < 1.5);
  out.mX[15] = (int32_T)(U_idx_6 < 2.5);
  (void)sys;
  (void)t2;
  return 0;
}
