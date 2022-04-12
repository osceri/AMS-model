/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_dxf_p.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_dxf_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDXF_P;
  out.mNumCol = 15ULL;
  out.mNumRow = 15ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 1;
  out.mJc[2] = 4;
  out.mJc[3] = 9;
  out.mJc[4] = 11;
  out.mJc[5] = 15;
  out.mJc[6] = 16;
  out.mJc[7] = 19;
  out.mJc[8] = 22;
  out.mJc[9] = 23;
  out.mJc[10] = 24;
  out.mJc[11] = 25;
  out.mJc[12] = 26;
  out.mJc[13] = 27;
  out.mJc[14] = 28;
  out.mJc[15] = 29;
  out.mIr[0] = 5;
  out.mIr[1] = 2;
  out.mIr[2] = 13;
  out.mIr[3] = 14;
  out.mIr[4] = 2;
  out.mIr[5] = 5;
  out.mIr[6] = 12;
  out.mIr[7] = 13;
  out.mIr[8] = 14;
  out.mIr[9] = 5;
  out.mIr[10] = 12;
  out.mIr[11] = 2;
  out.mIr[12] = 5;
  out.mIr[13] = 13;
  out.mIr[14] = 14;
  out.mIr[15] = 4;
  out.mIr[16] = 2;
  out.mIr[17] = 13;
  out.mIr[18] = 14;
  out.mIr[19] = 2;
  out.mIr[20] = 13;
  out.mIr[21] = 14;
  out.mIr[22] = 11;
  out.mIr[23] = 3;
  out.mIr[24] = 6;
  out.mIr[25] = 7;
  out.mIr[26] = 8;
  out.mIr[27] = 9;
  out.mIr[28] = 10;
  (void)sys;
  (void)t2;
  return 0;
}
