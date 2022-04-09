/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Subsystem/Subsystem/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "Subsystem_8f6c35c5_1_ds_f.h"
#include "Subsystem_8f6c35c5_1_ds_sys_struct.h"
#include "Subsystem_8f6c35c5_1_ds_externals.h"
#include "Subsystem_8f6c35c5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Subsystem_8f6c35c5_1_ds_f(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t43, NeDsMethodOutput *t44)
{
  ETTS0 c_efOut;
  ETTS0 efOut;
  PmRealVector out;
  real_T t13[2];
  real_T t14[2];
  real_T b_efOut[1];
  real_T d_efOut[1];
  real_T e_efOut[1];
  real_T f_efOut[1];
  real_T g_efOut[1];
  real_T t4[1];
  real_T t7[1];
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T t6_idx_6;
  real_T t6_idx_8;
  size_t t15[1];
  size_t _in1ivar;
  size_t b__in1ivar;
  size_t i__in1ivar;
  U_idx_0 = t43->mU.mX[0];
  X_idx_0 = t43->mX.mX[0];
  X_idx_1 = t43->mX.mX[1];
  X_idx_2 = t43->mX.mX[2];
  X_idx_5 = t43->mX.mX[5];
  X_idx_6 = t43->mX.mX[6];
  X_idx_8 = t43->mX.mX[8];
  X_idx_9 = t43->mX.mX[9];
  out = t44->mF;
  t13[0] = 298.15;
  t13[1] = 358.15;
  t14[0] = 23760.0;
  t14[1] = 23760.0;
  t4[0] = 298.15;
  _in1ivar = 2ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_linear_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)t13, (void *)t4, (void *)&_in1ivar, (void *)
    &b__in1ivar);
  _in1ivar = 2ULL;
  b__in1ivar = 1ULL;
  tlu2_1d_linear_linear_value((void *)&b_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)t14, (void *)&_in1ivar, (void *)
    &b__in1ivar);
  t7[0ULL] = X_idx_8;
  _in1ivar = 12ULL;
  b__in1ivar = 1ULL;
  tlu2_linear_linear_prelookup((void *)&c_efOut.mField0, (void *)
    &c_efOut.mField1, (void *)&c_efOut.mField2, (void *)((_NeDynamicSystem*)(LC))
    ->mTable0, (void *)t7, (void *)&_in1ivar, (void *)&b__in1ivar);
  t13[0ULL] = efOut.mField0[0ULL];
  t13[1ULL] = efOut.mField0[1ULL];
  t14[0ULL] = efOut.mField1[0ULL];
  t14[1ULL] = efOut.mField1[1ULL];
  t15[0ULL] = efOut.mField2[0ULL];
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_value((void *)&d_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)t13, (void *)t14, (void *)
    t15, (void *)((_NeDynamicSystem*)(LC))->mTable2, (void *)&_in1ivar, (void *)
    &b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_value((void *)&e_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)t13, (void *)t14, (void *)
    t15, (void *)((_NeDynamicSystem*)(LC))->mTable3, (void *)&_in1ivar, (void *)
    &b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_value((void *)&f_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)t13, (void *)t14, (void *)
    t15, (void *)((_NeDynamicSystem*)(LC))->mTable4, (void *)&_in1ivar, (void *)
    &b__in1ivar, (void *)&i__in1ivar);
  _in1ivar = 12ULL;
  b__in1ivar = 2ULL;
  i__in1ivar = 1ULL;
  tlu2_2d_linear_linear_value((void *)&g_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)t13, (void *)t14, (void *)
    t15, (void *)((_NeDynamicSystem*)(LC))->mTable1, (void *)&_in1ivar, (void *)
    &b__in1ivar, (void *)&i__in1ivar);
  X_idx_8 = -(pmf_sqrt(X_idx_1 + 1.0E-6) * b_efOut[0] * -0.05);
  t6_idx_6 = -((pmf_sqrt(X_idx_1 + 1.0E-6) * 0.0125 + 1.0) * e_efOut[0]);
  t6_idx_8 = -((pmf_sqrt(X_idx_1 + 1.0E-6) * 0.016666666666666666 + 1.0) *
               f_efOut[0]);
  out.mX[0] = -0.0;
  out.mX[1] = -U_idx_0 * (real_T)(U_idx_0 < 0.0) / (X_idx_9 == 0.0 ? 1.0E-16 :
    X_idx_9);
  out.mX[2] = -(X_idx_2 * X_idx_5);
  out.mX[3] = -(X_idx_0 / (X_idx_9 == 0.0 ? 1.0E-16 : X_idx_9));
  out.mX[4] = -b_efOut[0] / 594000.0 + X_idx_8 / 594000.0;
  out.mX[5] = -(((X_idx_1 + 1.0E-6) * -1.25E-5 + 1.0) * d_efOut[0]) /
    3.2127925922081033;
  out.mX[6] = t6_idx_6;
  out.mX[7] = -(1.0 / (X_idx_6 == 0.0 ? 1.0E-16 : X_idx_6));
  out.mX[8] = t6_idx_8;
  out.mX[9] = -g_efOut[0] / 17.463589893563039;
  (void)LC;
  (void)t44;
  return 0;
}
