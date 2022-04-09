/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Subsystem/Subsystem/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Subsystem_8f6c35c5_1_ds_dxf.h"
#include "Subsystem_8f6c35c5_1_ds_sys_struct.h"
#include "Subsystem_8f6c35c5_1_ds_externals.h"
#include "Subsystem_8f6c35c5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Subsystem_8f6c35c5_1_ds_dxf(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t57, NeDsMethodOutput *t58)
{
  ETTS0 b_efOut;
  ETTS0 efOut;
  PmRealVector out;
  real_T t4[14];
  real_T t14[4];
  real_T t9[4];
  real_T g_efOut[2];
  real_T h_efOut[2];
  real_T i_efOut[2];
  real_T j_efOut[2];
  real_T t10[2];
  real_T t11[2];
  real_T c_efOut[1];
  real_T d_efOut[1];
  real_T e_efOut[1];
  real_T f_efOut[1];
  real_T t5[1];
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T t29;
  size_t _in1ivar;
  size_t b__in1ivar;
  size_t i__in1ivar;
  U_idx_0 = t57->mU.mX[0];
  X_idx_0 = t57->mX.mX[0];
  X_idx_1 = t57->mX.mX[1];
  X_idx_2 = t57->mX.mX[2];
  X_idx_5 = t57->mX.mX[5];
  X_idx_6 = t57->mX.mX[6];
  X_idx_8 = t57->mX.mX[8];
  X_idx_9 = t57->mX.mX[9];
  out = t58->mDXF;
  t10[0] = 298.15;
  t10[1] = 358.15;
  t11[0] = 23760.0;
  t11[1] = 23760.0;
  t5[0] = 298.15;
  _in1ivar = 2ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_linear_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)t10, (void *)t5, (void *)&_in1ivar, (void *)
    &b__in1ivar);
  t5[0ULL] = X_idx_8;
  _in1ivar = 12ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_linear_prelookup((void *)&b_efOut.mField0, (void *)
    &b_efOut.mField1, (void *)&b_efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable0, (void *)t5, (void *)&_in1ivar, (void *)&b__in1ivar);
  _in1ivar = 2ULL;
  b__in1ivar = 1ULL;
  tlu2_1d_linear_linear_value((void *)&c_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)t11, (void *)&_in1ivar, (void *)
    &b__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_value((void *)&d_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable2, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_value((void *)&e_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable3, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_value((void *)&f_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable4, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  t29 = pmf_sqrt(X_idx_1 + 1.0E-6) * 2.0;
  t9[0ULL] = -(1.0 / (t29 == 0.0 ? 1.0E-16 : t29) * c_efOut[0] * -0.05) *
    1.6835016835016836E-6;
  t9[1ULL] = -(d_efOut[0] * -1.25E-5) * 0.31125569774571576;
  t9[2ULL] = -(1.0 / (t29 == 0.0 ? 1.0E-16 : t29) * e_efOut[0] * 0.0125);
  t9[3ULL] = -(1.0 / (t29 == 0.0 ? 1.0E-16 : t29) * f_efOut[0] *
               0.016666666666666666);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_derivatives((void *)&g_efOut, (void *)b_efOut.mField0,
    (void *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)
    (LC))->mTable2, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_derivatives((void *)&h_efOut, (void *)b_efOut.mField0,
    (void *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)
    (LC))->mTable3, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_derivatives((void *)&i_efOut, (void *)b_efOut.mField0,
    (void *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)
    (LC))->mTable4, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_derivatives((void *)&j_efOut, (void *)b_efOut.mField0,
    (void *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)((_NeDynamicSystem*)
    (LC))->mTable1, (void *)&_in1ivar, (void *)&b__in1ivar, (void *)&i__in1ivar);
  t14[0ULL] = -(((X_idx_1 + 1.0E-6) * -1.25E-5 + 1.0) * g_efOut[0]) *
    0.31125569774571576;
  t14[1ULL] = -((pmf_sqrt(X_idx_1 + 1.0E-6) * 0.0125 + 1.0) * h_efOut[0]);
  t14[2ULL] = -((pmf_sqrt(X_idx_1 + 1.0E-6) * 0.016666666666666666 + 1.0) *
                i_efOut[0]);
  t14[3ULL] = -j_efOut[0] * 0.0572619951622085;
  X_idx_8 = X_idx_9 * X_idx_9;
  t4[0ULL] = -(1.0 / (X_idx_9 == 0.0 ? 1.0E-16 : X_idx_9));
  for (_in1ivar = 0ULL; _in1ivar < 4ULL; _in1ivar++) {
    t4[_in1ivar + 1ULL] = t9[_in1ivar];
  }

  t4[5ULL] = -X_idx_5;
  t4[6ULL] = -X_idx_2;
  t29 = X_idx_6 * X_idx_6;
  t4[7ULL] = -(-1.0 / (t29 == 0.0 ? 1.0E-16 : t29));
  for (_in1ivar = 0ULL; _in1ivar < 4ULL; _in1ivar++) {
    t4[_in1ivar + 8ULL] = t14[_in1ivar];
  }

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
  out.mX[11] = t4[11];
  out.mX[12] = -(-U_idx_0 * (real_T)(U_idx_0 < 0.0)) / (X_idx_8 == 0.0 ? 1.0E-16
    : X_idx_8);
  out.mX[13] = -(-X_idx_0 / (X_idx_8 == 0.0 ? 1.0E-16 : X_idx_8));
  (void)LC;
  (void)t58;
  return 0;
}
