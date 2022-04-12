/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_tdxf_p.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_tdxf_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDXF_P;
  out.mNumCol = 15ULL;
  out.mNumRow = 15ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 2;
  out.mJc[2] = 6;
  out.mJc[3] = 12;
  out.mJc[4] = 14;
  out.mJc[5] = 18;
  out.mJc[6] = 19;
  out.mJc[7] = 23;
  out.mJc[8] = 26;
  out.mJc[9] = 35;
  out.mJc[10] = 36;
  out.mJc[11] = 37;
  out.mJc[12] = 38;
  out.mJc[13] = 39;
  out.mJc[14] = 40;
  out.mJc[15] = 41;
  out.mIr[0] = 0;
  out.mIr[1] = 5;
  out.mIr[2] = 1;
  out.mIr[3] = 2;
  out.mIr[4] = 13;
  out.mIr[5] = 14;
  out.mIr[6] = 0;
  out.mIr[7] = 2;
  out.mIr[8] = 5;
  out.mIr[9] = 12;
  out.mIr[10] = 13;
  out.mIr[11] = 14;
  out.mIr[12] = 5;
  out.mIr[13] = 12;
  out.mIr[14] = 2;
  out.mIr[15] = 5;
  out.mIr[16] = 13;
  out.mIr[17] = 14;
  out.mIr[18] = 4;
  out.mIr[19] = 1;
  out.mIr[20] = 2;
  out.mIr[21] = 13;
  out.mIr[22] = 14;
  out.mIr[23] = 2;
  out.mIr[24] = 13;
  out.mIr[25] = 14;
  out.mIr[26] = 3;
  out.mIr[27] = 4;
  out.mIr[28] = 5;
  out.mIr[29] = 6;
  out.mIr[30] = 7;
  out.mIr[31] = 8;
  out.mIr[32] = 9;
  out.mIr[33] = 10;
  out.mIr[34] = 11;
  out.mIr[35] = 3;
  out.mIr[36] = 6;
  out.mIr[37] = 7;
  out.mIr[38] = 8;
  out.mIr[39] = 9;
  out.mIr[40] = 10;
  (void)sys;
  (void)t2;
  return 0;
}
