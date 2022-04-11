/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'EQV/EQV/Solver Configuration'.
 */

#include "ne_ds.h"
#include "EQV_627956e1_1_ds_sys_struct.h"
#include "EQV_627956e1_1_ds_obs_act.h"
#include "EQV_627956e1_1_ds.h"
#include "EQV_627956e1_1_ds_externals.h"
#include "EQV_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T EQV_627956e1_1_ds_obs_act(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t13, NeDsMethodOutput *t14)
{
  PmRealVector out;
  real_T t0[106];
  real_T D_idx_0;
  real_T EQV_Capacitor_p_v;
  real_T EQV_Controlled_Voltage_Source1_i;
  real_T EQV_Controlled_Voltage_Source1_p_v;
  real_T EQV_Controlled_Voltage_Source_i;
  real_T EQV_Diode_i;
  real_T EQV_Diode_p_v;
  real_T EQV_Diode_v;
  real_T EQV_SPMT_Switch_v3;
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
  int32_T b;
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
  out = t14->mOBS_ACT;
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
  t0[0ULL] = X_idx_2;
  t0[1ULL] = X_idx_3;
  t0[2ULL] = EQV_Capacitor_p_v;
  t0[3ULL] = X_idx_0;
  t0[4ULL] = X_idx_0;
  t0[5ULL] = EQV_Controlled_Voltage_Source_i;
  t0[6ULL] = 0.0;
  t0[7ULL] = U_idx_0;
  t0[8ULL] = U_idx_0;
  t0[9ULL] = U_idx_0;
  t0[10ULL] = EQV_Controlled_Voltage_Source1_i;
  t0[11ULL] = X_idx_3;
  t0[12ULL] = EQV_Controlled_Voltage_Source1_p_v;
  t0[13ULL] = U_idx_1;
  t0[14ULL] = U_idx_1;
  t0[15ULL] = EQV_Controlled_Voltage_Source_i;
  t0[16ULL] = EQV_Controlled_Voltage_Source_i;
  t0[17ULL] = 0.0;
  t0[18ULL] = 0.0;
  t0[19ULL] = EQV_Controlled_Voltage_Source_i;
  t0[20ULL] = X_idx_6;
  t0[21ULL] = t1;
  t0[22ULL] = EQV_Diode_p_v;
  t0[23ULL] = EQV_Diode_v;
  t0[24ULL] = X_idx_1;
  t0[25ULL] = 298.15;
  t0[26ULL] = 0.0;
  t0[27ULL] = EQV_Diode_i;
  t0[28ULL] = X_idx_6;
  t0[29ULL] = EQV_Diode_i;
  t0[30ULL] = EQV_Diode_i + X_idx_6;
  t0[31ULL] = EQV_Diode_v;
  t0[32ULL] = t1;
  t0[33ULL] = t1;
  t0[34ULL] = EQV_Diode_p_v;
  t0[35ULL] = EQV_Diode_i * EQV_Diode_v * 0.001 * 1000.0;
  t0[36ULL] = EQV_Diode_v;
  t0[37ULL] = EQV_Diode_v;
  t0[38ULL] = 0.0;
  t0[39ULL] = X_idx_4;
  t0[40ULL] = t2;
  t0[41ULL] = X_idx_8;
  t0[42ULL] = X_idx_4 * 100.0;
  t0[43ULL] = EQV_Controlled_Voltage_Source_i;
  t0[44ULL] = U_idx_0;
  t0[45ULL] = EQV_Diode_p_v;
  t0[46ULL] = EQV_Controlled_Voltage_Source_i * 0.43755555938442742;
  t0[47ULL] = X_idx_9;
  t0[48ULL] = 0.0;
  t0[49ULL] = EQV_Controlled_Voltage_Source1_i;
  t0[50ULL] = X_idx_2;
  t0[51ULL] = 0.0;
  t0[52ULL] = 0.0;
  t0[53ULL] = 0.0;
  t0[54ULL] = 0.0;
  t0[55ULL] = 0.0;
  t0[56ULL] = X_idx_2 + EQV_Controlled_Voltage_Source1_i;
  t0[57ULL] = -(X_idx_10 - X_idx_8);
  t0[58ULL] = EQV_Controlled_Voltage_Source1_p_v;
  t0[59ULL] = EQV_Capacitor_p_v;
  t0[60ULL] = -(X_idx_11 - X_idx_8);
  t0[61ULL] = -(X_idx_12 - X_idx_8);
  t0[62ULL] = -(X_idx_13 - X_idx_8);
  t0[63ULL] = -(X_idx_14 - X_idx_8);
  t0[64ULL] = -(X_idx_15 - X_idx_8);
  t0[65ULL] = X_idx_8;
  t0[66ULL] = (EQV_Controlled_Voltage_Source1_i * t9 + X_idx_2 *
               EQV_SPMT_Switch_v3) * 0.001 * 1000.0;
  t0[67ULL] = D_idx_0;
  t0[68ULL] = X_idx_10;
  t0[69ULL] = t9;
  t0[70ULL] = EQV_SPMT_Switch_v3;
  t0[71ULL] = X_idx_11;
  t0[72ULL] = X_idx_12;
  t0[73ULL] = X_idx_13;
  t0[74ULL] = X_idx_14;
  t0[75ULL] = X_idx_15;
  t0[76ULL] = U_idx_4;
  t0[77ULL] = U_idx_1;
  t0[78ULL] = U_idx_2;
  t0[79ULL] = U_idx_3;
  t0[80ULL] = U_idx_4;
  t0[81ULL] = U_idx_5;
  t0[82ULL] = U_idx_0;
  t0[83ULL] = -EQV_Controlled_Voltage_Source_i;
  t0[84ULL] = 0.0;
  t0[85ULL] = X_idx_3;
  t0[86ULL] = X_idx_3;
  t0[87ULL] = U_idx_5;
  t0[88ULL] = X_idx_4;
  t0[89ULL] = t1;
  t0[90ULL] = t2;
  t0[91ULL] = X_idx_7;
  t0[92ULL] = U_idx_2;
  t0[93ULL] = X_idx_5;
  t0[94ULL] = EQV_Diode_p_v;
  t0[95ULL] = X_idx_8;
  t0[96ULL] = ((X_idx_4 * -0.43755555938442742 + X_idx_5 * -0.43755555938442742)
               + -U_idx_0) + X_idx_8;
  t0[97ULL] = U_idx_3;
  t0[98ULL] = EQV_Diode_p_v;
  t0[99ULL] = 0.0;
  t0[100ULL] = EQV_Diode_p_v;
  t0[101ULL] = X_idx_8;
  t0[102ULL] = 0.0;
  t0[103ULL] = X_idx_8;
  t0[104ULL] = X_idx_8;
  t0[105ULL] = EQV_Diode_p_v;
  for (b = 0; b < 106; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t14;
  return 0;
}
