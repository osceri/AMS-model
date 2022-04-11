/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_assert.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_assert(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
  int32_T M_idx_5;
  int32_T M_idx_6;
  int32_T M_idx_7;
  M_idx_5 = t1->mM.mX[5];
  M_idx_6 = t1->mM.mX[6];
  M_idx_7 = t1->mM.mX[7];
  out = t2->mASSERT;
  out.mX[0] = 1;
  out.mX[1] = 1;
  out.mX[2] = 1;
  out.mX[3] = (int32_T)(M_idx_5 != 0);
  out.mX[4] = (int32_T)(M_idx_6 != 0);
  out.mX[5] = (int32_T)(M_idx_7 != 0);
  out.mX[6] = 1;
  out.mX[7] = 1;
  out.mX[8] = 1;
  out.mX[9] = 1;
  out.mX[10] = 1;
  out.mX[11] = 1;
  out.mX[12] = 1;
  out.mX[13] = 1;
  out.mX[14] = 1;
  out.mX[15] = 1;
  out.mX[16] = 1;
  out.mX[17] = 1;
  out.mX[18] = 1;
  out.mX[19] = 1;
  out.mX[20] = 1;
  out.mX[21] = 1;
  out.mX[22] = 1;
  out.mX[23] = 1;
  out.mX[24] = 1;
  out.mX[25] = 1;
  out.mX[26] = 1;
  out.mX[27] = 1;
  out.mX[28] = 1;
  out.mX[29] = 1;
  out.mX[30] = 1;
  out.mX[31] = 1;
  out.mX[32] = 1;
  out.mX[33] = 1;
  out.mX[34] = 1;
  out.mX[35] = 1;
  out.mX[36] = 1;
  out.mX[37] = 1;
  out.mX[38] = 1;
  out.mX[39] = 1;
  out.mX[40] = 1;
  out.mX[41] = 1;
  out.mX[42] = 1;
  out.mX[43] = 1;
  out.mX[44] = 1;
  out.mX[45] = 1;
  out.mX[46] = 1;
  out.mX[47] = 1;
  out.mX[48] = 1;
  out.mX[49] = 1;
  out.mX[50] = 1;
  out.mX[51] = 1;
  out.mX[52] = 1;
  out.mX[53] = 1;
  out.mX[54] = 1;
  (void)sys;
  (void)t2;
  return 0;
}
