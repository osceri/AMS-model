/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Main_45a0674_1_ds_log.h"
#include "Main_45a0674_1_ds_sys_struct.h"
#include "Main_45a0674_1_ds_externals.h"
#include "Main_45a0674_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_45a0674_1_ds_log(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t4, NeDsMethodOutput *t5)
{
  PmRealVector out;
  real_T Battery_Table_Based_v;
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
  real_T t1;
  (void)LC;
  U_idx_0 = t4->mU.mX[0];
  X_idx_0 = t4->mX.mX[0];
  X_idx_1 = t4->mX.mX[1];
  X_idx_2 = t4->mX.mX[2];
  X_idx_3 = t4->mX.mX[3];
  X_idx_4 = t4->mX.mX[4];
  X_idx_5 = t4->mX.mX[5];
  X_idx_6 = t4->mX.mX[6];
  X_idx_7 = t4->mX.mX[7];
  X_idx_8 = t4->mX.mX[8];
  X_idx_9 = t4->mX.mX[9];
  out = t5->mLOG;
  Battery_Table_Based_v = -((X_idx_4 * U_idx_0 + X_idx_2) + X_idx_3) / -1.0;
  t1 = Battery_Table_Based_v / -1.0;
  out.mX[0] = X_idx_0 * 0.00027777777777777778;
  out.mX[1] = U_idx_0;
  out.mX[2] = 0.0;
  out.mX[3] = X_idx_1;
  out.mX[4] = Battery_Table_Based_v;
  out.mX[5] = -(U_idx_0 * U_idx_0 * X_idx_4 * 0.001 + X_idx_2 * X_idx_2 *
                X_idx_5 * 0.001) / -1.0 * 1000.0;
  out.mX[6] = X_idx_6;
  out.mX[7] = Battery_Table_Based_v;
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
  out.mX[21] = X_idx_8 * 0.00027777777777777778;
  out.mX[22] = X_idx_7;
  out.mX[23] = X_idx_9;
  out.mX[24] = Battery_Table_Based_v;
  out.mX[25] = U_idx_0;
  out.mX[26] = U_idx_0;
  out.mX[27] = 0.0;
  out.mX[28] = t1;
  out.mX[29] = 0.0;
  out.mX[30] = -U_idx_0;
  out.mX[31] = -U_idx_0;
  out.mX[32] = Battery_Table_Based_v;
  out.mX[33] = Battery_Table_Based_v;
  out.mX[34] = -U_idx_0;
  out.mX[35] = Battery_Table_Based_v;
  out.mX[36] = Battery_Table_Based_v;
  out.mX[37] = t1;
  out.mX[38] = Battery_Table_Based_v;
  out.mX[39] = 0.0;
  out.mX[40] = t1;
  out.mX[41] = 0.0;
  out.mX[42] = Battery_Table_Based_v;
  out.mX[43] = U_idx_0;
  (void)LC;
  (void)t5;
  return 0;
}
