/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Subsystem/Subsystem/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Subsystem_8f6c35c5_1_ds_obs_all.h"
#include "Subsystem_8f6c35c5_1_ds_sys_struct.h"
#include "Subsystem_8f6c35c5_1_ds_externals.h"
#include "Subsystem_8f6c35c5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Subsystem_8f6c35c5_1_ds_obs_all(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t5, NeDsMethodOutput *t6)
{
  PmRealVector out;
  real_T Subsystem_Battery_Table_Based_v;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T t2;
  (void)LC;
  U_idx_0 = t5->mU.mX[0];
  X_idx_0 = t5->mX.mX[0];
  X_idx_1 = t5->mX.mX[1];
  X_idx_2 = t5->mX.mX[2];
  X_idx_3 = t5->mX.mX[3];
  X_idx_4 = t5->mX.mX[4];
  X_idx_5 = t5->mX.mX[5];
  X_idx_6 = t5->mX.mX[6];
  X_idx_7 = t5->mX.mX[7];
  X_idx_8 = t5->mX.mX[8];
  X_idx_9 = t5->mX.mX[9];
  out = t6->mOBS_ALL;
  Subsystem_Battery_Table_Based_v = -((X_idx_4 * U_idx_0 + X_idx_2) + X_idx_3) /
    -1.0;
  t2 = -Subsystem_Battery_Table_Based_v / -1.0;
  out.mX[0] = X_idx_0 * 0.00027777777777777778;
  out.mX[1] = U_idx_0;
  out.mX[2] = 0.0;
  out.mX[3] = X_idx_1;
  out.mX[4] = Subsystem_Battery_Table_Based_v;
  out.mX[5] = -(U_idx_0 * U_idx_0 * X_idx_4 * 0.001 + X_idx_2 * X_idx_2 *
                X_idx_5 * 0.001) / -1.0 * 1000.0;
  out.mX[6] = X_idx_8;
  out.mX[7] = Subsystem_Battery_Table_Based_v;
  out.mX[8] = X_idx_2;
  out.mX[9] = 0.0;
  out.mX[10] = 0.0;
  out.mX[11] = 0.0;
  out.mX[12] = 0.0;
  out.mX[13] = X_idx_5;
  out.mX[14] = 0.0;
  out.mX[15] = 0.0;
  out.mX[16] = 0.0;
  out.mX[17] = 0.0;
  out.mX[18] = 0.0;
  out.mX[19] = X_idx_4;
  out.mX[20] = X_idx_3;
  out.mX[21] = X_idx_9 * 0.00027777777777777778;
  out.mX[22] = X_idx_6;
  out.mX[23] = X_idx_7;
  out.mX[24] = X_idx_8;
  out.mX[25] = X_idx_8;
  out.mX[26] = Subsystem_Battery_Table_Based_v;
  out.mX[27] = U_idx_0;
  out.mX[28] = U_idx_0;
  out.mX[29] = 0.0;
  out.mX[30] = Subsystem_Battery_Table_Based_v / -1.0;
  out.mX[31] = U_idx_0;
  out.mX[32] = U_idx_0;
  out.mX[33] = Subsystem_Battery_Table_Based_v;
  out.mX[34] = Subsystem_Battery_Table_Based_v;
  out.mX[35] = U_idx_0;
  out.mX[36] = 0.0;
  out.mX[37] = U_idx_0;
  out.mX[38] = t2;
  out.mX[39] = 0.0;
  out.mX[40] = Subsystem_Battery_Table_Based_v;
  out.mX[41] = t2;
  (void)LC;
  (void)t6;
  return 0;
}
