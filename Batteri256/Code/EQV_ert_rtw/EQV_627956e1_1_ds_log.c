/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_log.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_log(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t13, NeDsMethodOutput *t14)
{
  PmRealVector out;
  real_T D_idx_0;
  real_T EQV_Capacitor_p_v;
  real_T EQV_Controlled_Voltage_Source1_i;
  real_T EQV_Controlled_Voltage_Source1_p_v;
  real_T EQV_Controlled_Voltage_Source_i;
  real_T EQV_Diode_i;
  real_T EQV_Diode_p_v;
  real_T EQV_Diode_v;
  real_T EQV_SPMT_Switch_v3;
  real_T EQV_Switch2_v;
  real_T U_idx_0;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_10;
  real_T X_idx_11;
  real_T X_idx_12;
  real_T X_idx_13;
  real_T X_idx_14;
  real_T X_idx_15;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T t1;
  real_T t2;
  real_T t9;
  U_idx_0 = t13->mU.mX[0];
  U_idx_1 = t13->mU.mX[1];
  U_idx_2 = t13->mU.mX[2];
  U_idx_3 = t13->mU.mX[3];
  U_idx_4 = t13->mU.mX[4];
  U_idx_5 = t13->mU.mX[5];
  X_idx_0 = t13->mX.mX[0];
  X_idx_1 = t13->mX.mX[1];
  X_idx_2 = t13->mX.mX[2];
  X_idx_3 = t13->mX.mX[3];
  X_idx_4 = t13->mX.mX[4];
  X_idx_5 = t13->mX.mX[5];
  X_idx_6 = t13->mX.mX[6];
  X_idx_7 = t13->mX.mX[7];
  X_idx_8 = t13->mX.mX[8];
  X_idx_9 = t13->mX.mX[9];
  X_idx_10 = t13->mX.mX[10];
  X_idx_11 = t13->mX.mX[11];
  X_idx_12 = t13->mX.mX[12];
  X_idx_13 = t13->mX.mX[13];
  X_idx_14 = t13->mX.mX[14];
  X_idx_15 = t13->mX.mX[15];
  D_idx_0 = t13->mD.mX[0];
  out = t14->mLOG;
  EQV_Capacitor_p_v = X_idx_0 + X_idx_3;
  EQV_Controlled_Voltage_Source_i = X_idx_4 + X_idx_5;
  EQV_Controlled_Voltage_Source1_i = (-X_idx_2 + -X_idx_4) + -X_idx_5;
  EQV_Controlled_Voltage_Source1_p_v = U_idx_1 + X_idx_3;
  EQV_Diode_i = -X_idx_6 + -X_idx_4;
  t1 = (((-X_idx_1 + X_idx_6 * -1.0E-6) + X_idx_4 * 0.43755555938442742) +
        X_idx_5 * 0.43755555938442742) + U_idx_0;
  EQV_Diode_p_v = (X_idx_4 * 0.43755555938442742 + X_idx_5 * 0.43755555938442742)
    + U_idx_0;
  EQV_Diode_v = X_idx_6 * 1.0E-6 + X_idx_1;
  t2 = ((((-X_idx_1 + X_idx_6 * -1.0E-6) + X_idx_4 * 0.43755555938442742) +
         X_idx_5 * 0.43755555938442742) + U_idx_0) + X_idx_7;
  t9 = (-X_idx_3 + -U_idx_1) + X_idx_8;
  EQV_SPMT_Switch_v3 = (-X_idx_0 + -X_idx_3) + X_idx_8;
  EQV_Switch2_v = ((X_idx_4 * -0.43755555938442742 + X_idx_5 *
                    -0.43755555938442742) + -U_idx_0) + X_idx_8;
  out.mX[0] = X_idx_2;
  out.mX[1] = X_idx_3;
  out.mX[2] = EQV_Capacitor_p_v;
  out.mX[3] = X_idx_0;
  out.mX[4] = X_idx_0;
  out.mX[5] = X_idx_0 * X_idx_0 * 1.0E-9;
  out.mX[6] = EQV_Controlled_Voltage_Source_i;
  out.mX[7] = U_idx_0;
  out.mX[8] = U_idx_0;
  out.mX[9] = U_idx_0;
  out.mX[10] = EQV_Controlled_Voltage_Source1_i;
  out.mX[11] = X_idx_3;
  out.mX[12] = EQV_Controlled_Voltage_Source1_p_v;
  out.mX[13] = U_idx_1;
  out.mX[14] = U_idx_1;
  out.mX[15] = EQV_Controlled_Voltage_Source_i;
  out.mX[16] = EQV_Controlled_Voltage_Source_i;
  out.mX[17] = EQV_Controlled_Voltage_Source_i;
  out.mX[18] = X_idx_6;
  out.mX[19] = t1;
  out.mX[20] = EQV_Diode_p_v;
  out.mX[21] = EQV_Diode_v;
  out.mX[22] = X_idx_1;
  out.mX[23] = EQV_Diode_i;
  out.mX[24] = X_idx_6;
  out.mX[25] = EQV_Diode_i;
  out.mX[26] = EQV_Diode_i + X_idx_6;
  out.mX[27] = EQV_Diode_v;
  out.mX[28] = t1;
  out.mX[29] = t1;
  out.mX[30] = EQV_Diode_p_v;
  out.mX[31] = EQV_Diode_i * EQV_Diode_v * 0.001 * 1000.0;
  out.mX[32] = EQV_Diode_v;
  out.mX[33] = EQV_Diode_v;
  out.mX[34] = X_idx_4;
  out.mX[35] = t2;
  out.mX[36] = X_idx_8;
  out.mX[37] = X_idx_4 * 100.0;
  out.mX[38] = X_idx_4 * X_idx_4 * 100.0;
  out.mX[39] = EQV_Controlled_Voltage_Source_i;
  out.mX[40] = U_idx_0;
  out.mX[41] = EQV_Diode_p_v;
  out.mX[42] = EQV_Controlled_Voltage_Source_i * 0.43755555938442742;
  out.mX[43] = EQV_Controlled_Voltage_Source_i * EQV_Controlled_Voltage_Source_i
    * 0.43755555938442742;
  out.mX[44] = X_idx_9;
  out.mX[45] = EQV_Controlled_Voltage_Source1_i;
  out.mX[46] = X_idx_2;
  out.mX[47] = X_idx_2 + EQV_Controlled_Voltage_Source1_i;
  out.mX[48] = -(X_idx_10 - X_idx_8);
  out.mX[49] = EQV_Controlled_Voltage_Source1_p_v;
  out.mX[50] = EQV_Capacitor_p_v;
  out.mX[51] = -(X_idx_11 - X_idx_8);
  out.mX[52] = -(X_idx_12 - X_idx_8);
  out.mX[53] = -(X_idx_13 - X_idx_8);
  out.mX[54] = -(X_idx_14 - X_idx_8);
  out.mX[55] = -(X_idx_15 - X_idx_8);
  out.mX[56] = X_idx_8;
  out.mX[57] = (EQV_Controlled_Voltage_Source1_i * t9 + X_idx_2 *
                EQV_SPMT_Switch_v3) * 0.001 * 1000.0;
  out.mX[58] = D_idx_0;
  out.mX[59] = X_idx_10;
  out.mX[60] = t9;
  out.mX[61] = EQV_SPMT_Switch_v3;
  out.mX[62] = X_idx_11;
  out.mX[63] = X_idx_12;
  out.mX[64] = X_idx_13;
  out.mX[65] = X_idx_14;
  out.mX[66] = X_idx_15;
  out.mX[67] = U_idx_4;
  out.mX[68] = U_idx_1;
  out.mX[69] = U_idx_2;
  out.mX[70] = U_idx_3;
  out.mX[71] = U_idx_4;
  out.mX[72] = U_idx_5;
  out.mX[73] = U_idx_0;
  out.mX[74] = -EQV_Controlled_Voltage_Source_i;
  out.mX[75] = X_idx_3;
  out.mX[76] = X_idx_3;
  out.mX[77] = -(EQV_Controlled_Voltage_Source_i * X_idx_3);
  out.mX[78] = U_idx_5;
  out.mX[79] = X_idx_4;
  out.mX[80] = t1;
  out.mX[81] = t2;
  out.mX[82] = X_idx_7;
  out.mX[83] = X_idx_4 * X_idx_7;
  out.mX[84] = U_idx_2;
  out.mX[85] = X_idx_5;
  out.mX[86] = EQV_Diode_p_v;
  out.mX[87] = X_idx_8;
  out.mX[88] = EQV_Switch2_v;
  out.mX[89] = X_idx_5 * EQV_Switch2_v;
  out.mX[90] = U_idx_3;
  out.mX[91] = EQV_Diode_p_v;
  out.mX[92] = EQV_Diode_p_v;
  out.mX[93] = X_idx_8;
  out.mX[94] = X_idx_8;
  out.mX[95] = X_idx_8;
  out.mX[96] = EQV_Diode_p_v;
  (void)sys;
  (void)t14;
  return 0;
}
