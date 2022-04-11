/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_tdxf_p.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_tdxf_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDXF_P;
  out.mNumCol = 16ULL;
  out.mNumRow = 16ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 2;
  out.mJc[2] = 5;
  out.mJc[3] = 8;
  out.mJc[4] = 11;
  out.mJc[5] = 17;
  out.mJc[6] = 21;
  out.mJc[7] = 24;
  out.mJc[8] = 26;
  out.mJc[9] = 30;
  out.mJc[10] = 39;
  out.mJc[11] = 40;
  out.mJc[12] = 41;
  out.mJc[13] = 42;
  out.mJc[14] = 43;
  out.mJc[15] = 44;
  out.mJc[16] = 45;
  out.mIr[0] = 0;
  out.mIr[1] = 6;
  out.mIr[2] = 1;
  out.mIr[3] = 2;
  out.mIr[4] = 3;
  out.mIr[5] = 0;
  out.mIr[6] = 5;
  out.mIr[7] = 6;
  out.mIr[8] = 5;
  out.mIr[9] = 6;
  out.mIr[10] = 13;
  out.mIr[11] = 2;
  out.mIr[12] = 3;
  out.mIr[13] = 5;
  out.mIr[14] = 13;
  out.mIr[15] = 14;
  out.mIr[16] = 15;
  out.mIr[17] = 3;
  out.mIr[18] = 5;
  out.mIr[19] = 13;
  out.mIr[20] = 15;
  out.mIr[21] = 1;
  out.mIr[22] = 2;
  out.mIr[23] = 3;
  out.mIr[24] = 3;
  out.mIr[25] = 14;
  out.mIr[26] = 3;
  out.mIr[27] = 5;
  out.mIr[28] = 6;
  out.mIr[29] = 15;
  out.mIr[30] = 4;
  out.mIr[31] = 5;
  out.mIr[32] = 6;
  out.mIr[33] = 7;
  out.mIr[34] = 8;
  out.mIr[35] = 9;
  out.mIr[36] = 10;
  out.mIr[37] = 11;
  out.mIr[38] = 12;
  out.mIr[39] = 4;
  out.mIr[40] = 7;
  out.mIr[41] = 8;
  out.mIr[42] = 9;
  out.mIr[43] = 10;
  out.mIr[44] = 11;
  (void)sys;
  (void)t2;
  return 0;
}
