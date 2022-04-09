/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Subsystem/Subsystem/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Subsystem_8f6c35c5_1_ds_obs_il.h"
#include "Subsystem_8f6c35c5_1_ds_sys_struct.h"
#include "Subsystem_8f6c35c5_1_ds_externals.h"
#include "Subsystem_8f6c35c5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Subsystem_8f6c35c5_1_ds_obs_il(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmBoolVector out;
  (void)t1;
  (void)LC;
  out = t2->mOBS_IL;
  out.mX[0] = true;
  out.mX[1] = false;
  out.mX[2] = true;
  out.mX[3] = true;
  out.mX[4] = false;
  out.mX[5] = false;
  out.mX[6] = true;
  out.mX[7] = false;
  out.mX[8] = true;
  out.mX[9] = true;
  out.mX[10] = true;
  out.mX[11] = true;
  out.mX[12] = true;
  out.mX[13] = true;
  out.mX[14] = true;
  out.mX[15] = true;
  out.mX[16] = true;
  out.mX[17] = true;
  out.mX[18] = true;
  out.mX[19] = true;
  out.mX[20] = true;
  out.mX[21] = true;
  out.mX[22] = true;
  out.mX[23] = true;
  out.mX[24] = true;
  out.mX[25] = true;
  out.mX[26] = false;
  out.mX[27] = false;
  out.mX[28] = false;
  out.mX[29] = true;
  out.mX[30] = false;
  out.mX[31] = false;
  out.mX[32] = false;
  out.mX[33] = false;
  out.mX[34] = false;
  out.mX[35] = false;
  out.mX[36] = true;
  out.mX[37] = false;
  out.mX[38] = false;
  out.mX[39] = true;
  out.mX[40] = false;
  out.mX[41] = false;
  (void)LC;
  (void)t2;
  return 0;
}
