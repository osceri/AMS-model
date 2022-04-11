/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_dxf_p.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_dxf_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDXF_P;
  out.mNumCol = 16ULL;
  out.mNumRow = 16ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 1;
  out.mJc[2] = 2;
  out.mJc[3] = 4;
  out.mJc[4] = 7;
  out.mJc[5] = 12;
  out.mJc[6] = 15;
  out.mJc[7] = 16;
  out.mJc[8] = 17;
  out.mJc[9] = 20;
  out.mJc[10] = 21;
  out.mJc[11] = 22;
  out.mJc[12] = 23;
  out.mJc[13] = 24;
  out.mJc[14] = 25;
  out.mJc[15] = 26;
  out.mJc[16] = 27;
  out.mIr[0] = 6;
  out.mIr[1] = 2;
  out.mIr[2] = 5;
  out.mIr[3] = 6;
  out.mIr[4] = 5;
  out.mIr[5] = 6;
  out.mIr[6] = 13;
  out.mIr[7] = 2;
  out.mIr[8] = 5;
  out.mIr[9] = 13;
  out.mIr[10] = 14;
  out.mIr[11] = 15;
  out.mIr[12] = 5;
  out.mIr[13] = 13;
  out.mIr[14] = 15;
  out.mIr[15] = 2;
  out.mIr[16] = 14;
  out.mIr[17] = 5;
  out.mIr[18] = 6;
  out.mIr[19] = 15;
  out.mIr[20] = 12;
  out.mIr[21] = 4;
  out.mIr[22] = 7;
  out.mIr[23] = 8;
  out.mIr[24] = 9;
  out.mIr[25] = 10;
  out.mIr[26] = 11;
  (void)sys;
  (void)t2;
  return 0;
}
