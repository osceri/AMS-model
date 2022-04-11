/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_obs_il.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_obs_il(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  static boolean_T _cg_const_1[106] = { true, true, true, true, true, true, true,
    false, false, false, true, true, false, false, false, true, true, true, true,
    true, true, false, false, true, true, true, true, true, true, true, true,
    true, false, false, false, false, true, true, true, true, false, true, true,
    true, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, false, true, true, true, true, true, true, true, false,
    false, true, false, true, true, true, true, true, true, false, false, false,
    false, false, false, false, true, true, true, true, false, true, false,
    false, true, false, true, false, true, false, false, false, true, false,
    true, true, true, true, false };

  PmBoolVector out;
  int32_T b;
  boolean_T t0[106];
  (void)t1;
  out = t2->mOBS_IL;
  for (b = 0; b < 106; b++) {
    t0[b] = _cg_const_1[b];
  }

  for (b = 0; b < 106; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}
