/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Main_45a0674_1_ds_dxf.h"
#include "Main_45a0674_1_ds_sys_struct.h"
#include "Main_45a0674_1_ds_externals.h"
#include "Main_45a0674_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_45a0674_1_ds_dxf(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t37, NeDsMethodOutput *t38)
{
  ETTS0 b_efOut;
  ETTS0 efOut;
  PmRealVector out;
  real_T t4[14];
  real_T t10[4];
  real_T t5[4];
  real_T c_efOut[2];
  real_T d_efOut[2];
  real_T e_efOut[2];
  real_T f_efOut[2];
  real_T t6[2];
  real_T t3[1];
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_2;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T X_idx_8;
  real_T t19;
  size_t _in1ivar;
  size_t b__in1ivar;
  size_t g__in1ivar;
  U_idx_0 = t37->mU.mX[0];
  X_idx_0 = t37->mX.mX[0];
  X_idx_2 = t37->mX.mX[2];
  X_idx_5 = t37->mX.mX[5];
  X_idx_6 = t37->mX.mX[6];
  X_idx_7 = t37->mX.mX[7];
  X_idx_8 = t37->mX.mX[8];
  out = t38->mDXF;
  t6[0] = 298.15;
  t6[1] = 358.15;
  t3[0ULL] = X_idx_6;
  _in1ivar = 33ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_nearest_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)((_NeDynamicSystem*)(LC))->mTable0, (void *)
    t3, (void *)&_in1ivar, (void *)&b__in1ivar);
  t3[0] = 298.15;
  _in1ivar = 2ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_nearest_prelookup((void *)&b_efOut.mField0, (void *)
    &b_efOut.mField1, (void *)&b_efOut.mField2, (void *)t6, (void *)t3, (void *)
    &_in1ivar, (void *)&b__in1ivar);
  t5[0] = 0.0;
  t5[1] = 0.0;
  t5[2] = 0.0;
  t5[3] = 0.0;
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  g__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_derivatives((void *)&c_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)b_efOut.mField0, (void
    *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable2, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&g__in1ivar);
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  g__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_derivatives((void *)&d_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)b_efOut.mField0, (void
    *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable3, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&g__in1ivar);
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  g__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_derivatives((void *)&e_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)b_efOut.mField0, (void
    *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable4, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&g__in1ivar);
  _in1ivar = 33ULL;
  b__in1ivar = 2ULL;
  g__in1ivar = 1ULL;
  tlu2_2d_linear_nearest_derivatives((void *)&f_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)b_efOut.mField0, (void
    *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable1, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&g__in1ivar);
  t10[0ULL] = -c_efOut[0] * 0.32586544112762533;
  t10[1ULL] = -d_efOut[0];
  t10[2ULL] = -e_efOut[0];
  t10[3ULL] = -f_efOut[0] * 0.0077762803289564463;
  t19 = X_idx_8 * X_idx_8;
  t4[0ULL] = -(1.0 / (X_idx_8 == 0.0 ? 1.0E-16 : X_idx_8));
  for (_in1ivar = 0ULL; _in1ivar < 4ULL; _in1ivar++) {
    t4[_in1ivar + 1ULL] = t5[_in1ivar];
  }

  t4[5ULL] = -X_idx_5;
  t4[6ULL] = -X_idx_2;
  for (_in1ivar = 0ULL; _in1ivar < 4ULL; _in1ivar++) {
    t4[_in1ivar + 7ULL] = t10[_in1ivar];
  }

  X_idx_6 = X_idx_7 * X_idx_7;
  out.mX[0] = t4[0];
  out.mX[1] = t4[1];
  out.mX[2] = t4[2];
  out.mX[3] = t4[3];
  out.mX[4] = t4[4];
  out.mX[5] = t4[5];
  out.mX[6] = t4[6];
  out.mX[7] = t4[7];
  out.mX[8] = t4[8];
  out.mX[9] = t4[9];
  out.mX[10] = t4[10];
  out.mX[11] = -(-1.0 / (X_idx_6 == 0.0 ? 1.0E-16 : X_idx_6));
  out.mX[12] = -(-U_idx_0 * (real_T)(U_idx_0 < 0.0)) / (t19 == 0.0 ? 1.0E-16 :
    t19);
  out.mX[13] = -(-X_idx_0 / (t19 == 0.0 ? 1.0E-16 : t19));
  (void)LC;
  (void)t38;
  return 0;
}
