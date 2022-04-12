/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_obs_exp.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_obs_exp(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  static real_T _cg_const_1[118] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 298.15, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  PmRealVector out;
  real_T t0[118];
  int32_T b;
  (void)t1;
  out = t2->mOBS_EXP;
  for (b = 0; b < 118; b++) {
    t0[b] = _cg_const_1[b];
  }

  for (b = 0; b < 118; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}
