/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Subsystem/Subsystem/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Subsystem_8f6c35c5_1_ds_assert.h"
#include "Subsystem_8f6c35c5_1_ds_sys_struct.h"
#include "Subsystem_8f6c35c5_1_ds_externals.h"
#include "Subsystem_8f6c35c5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Subsystem_8f6c35c5_1_ds_assert(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
  real_T X_idx_1;
  real_T X_idx_6;
  real_T X_idx_9;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_5;
  (void)LC;
  M_idx_0 = t1->mM.mX[0];
  M_idx_1 = t1->mM.mX[1];
  M_idx_2 = t1->mM.mX[2];
  M_idx_3 = t1->mM.mX[3];
  M_idx_4 = t1->mM.mX[4];
  M_idx_5 = t1->mM.mX[5];
  X_idx_1 = t1->mX.mX[1];
  X_idx_6 = t1->mX.mX[6];
  X_idx_9 = t1->mX.mX[9];
  out = t2->mASSERT;
  out.mX[0] = (int32_T)(M_idx_0 != 0);
  out.mX[1] = (int32_T)(M_idx_1 != 0);
  out.mX[2] = (int32_T)(M_idx_2 != 0);
  out.mX[3] = (int32_T)(M_idx_3 != 0);
  out.mX[4] = (int32_T)(M_idx_4 != 0);
  out.mX[5] = (int32_T)(M_idx_5 != 0);
  out.mX[6] = 1;
  out.mX[7] = 1;
  out.mX[8] = 1;
  out.mX[9] = 1;
  out.mX[10] = 1;
  out.mX[11] = 1;
  out.mX[12] = (int32_T)(X_idx_9 != 0.0);
  out.mX[13] = (int32_T)(X_idx_9 != 0.0);
  out.mX[14] = (int32_T)(X_idx_1 + 1.0E-6 >= 0.0);
  out.mX[15] = (int32_T)(X_idx_1 + 1.0E-6 >= 0.0);
  out.mX[16] = (int32_T)(X_idx_6 != 0.0);
  out.mX[17] = (int32_T)(X_idx_1 + 1.0E-6 >= 0.0);
  (void)LC;
  (void)t2;
  return 0;
}
