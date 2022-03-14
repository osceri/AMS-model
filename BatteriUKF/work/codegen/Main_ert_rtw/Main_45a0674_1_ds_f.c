/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Main_45a0674_1_ds_f.h"
#include "Main_45a0674_1_ds_sys_struct.h"
#include "Main_45a0674_1_ds_externals.h"
#include "Main_45a0674_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_45a0674_1_ds_f(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t35, NeDsMethodOutput *t36)
{
  ETTS0 b_efOut;
  ETTS0 efOut;
  PmRealVector out;
  real_T nonscalar5[2];
  real_T nonscalar6[2];
  real_T c_efOut[1];
  real_T d_efOut[1];
  real_T e_efOut[1];
  real_T f_efOut[1];
  real_T g_efOut[1];
  real_T t5[1];
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_2;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T X_idx_8;
  size_t _in1ivar;
  size_t b__in1ivar;
  size_t i__in1ivar;
  U_idx_0 = t35->mU.mX[0];
  X_idx_0 = t35->mX.mX[0];
  X_idx_2 = t35->mX.mX[2];
  X_idx_5 = t35->mX.mX[5];
  X_idx_6 = t35->mX.mX[6];
  X_idx_7 = t35->mX.mX[7];
  X_idx_8 = t35->mX.mX[8];
  out = t36->mF;
  nonscalar5[0] = 298.15;
  nonscalar5[1] = 358.15;
  nonscalar6[0] = 23760.0;
  nonscalar6[1] = 23760.0;
  t5[0] = 298.15;
  _in1ivar = 2ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_nearest_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)nonscalar5, (void *)t5, (void *)&_in1ivar,
    (void *)&b__in1ivar);
  t5[0ULL] = X_idx_6;
  _in1ivar = 33ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_nearest_prelookup((void *)&b_efOut.mField0, (void *)
    &b_efOut.mField1, (void *)&b_efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable0, (void *)t5, (void *)&_in1ivar, (void *)&b__in1ivar);
  _in1ivar = 2ULL;
  b__in1ivar = 1ULL;
  tlu2_1d_linear_nearest_value((void *)&c_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)nonscalar6, (void *)&_in1ivar,
    (void *)&b__in1ivar);
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_value((void *)&d_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable2, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_value((void *)&e_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable3, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_value((void *)&f_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable4, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_value((void *)&g_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable1, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  out.mX[0] = -0.0;
  out.mX[1] = -U_idx_0 * (real_T)(U_idx_0 < 0.0) / (X_idx_8 == 0.0 ? 1.0E-16 :
    X_idx_8);
  out.mX[2] = -(X_idx_2 * X_idx_5);
  out.mX[3] = -(X_idx_0 / (X_idx_8 == 0.0 ? 1.0E-16 : X_idx_8));
  out.mX[4] = -c_efOut[0];
  out.mX[5] = -d_efOut[0] / 3.0687513120127079;
  out.mX[6] = -e_efOut[0];
  out.mX[7] = -(1.0 / (X_idx_7 == 0.0 ? 1.0E-16 : X_idx_7));
  out.mX[8] = -f_efOut[0];
  out.mX[9] = -g_efOut[0] / 128.59618708398557;
  (void)LC;
  (void)t36;
  return 0;
}
