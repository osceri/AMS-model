/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#include "ne_ds.h"
#include "SIM0_627956e1_1_ds_sys_struct.h"
#include "SIM0_627956e1_1_ds_log.h"
#include "SIM0_627956e1_1_ds.h"
#include "SIM0_627956e1_1_ds_externals.h"
#include "SIM0_627956e1_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T SIM0_627956e1_1_ds_log(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t17, NeDsMethodOutput *t18)
{
  PmRealVector out;
  real_T t0[109];
  real_T D_idx_0;
  real_T SIM_Capacitor_p_v;
  real_T SIM_Controlled_Current_Source_head_v;
  real_T SIM_Diode_i;
  real_T SIM_Diode_p_v;
  real_T SIM_Diode_v;
  real_T SIM_Resistor_n_v;
  real_T SIM_Switch2_i;
  real_T SIM_Switch2_v;
  real_T U_idx_0;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T U_idx_6;
  real_T U_idx_7;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_10;
  real_T X_idx_11;
  real_T X_idx_12;
  real_T X_idx_13;
  real_T X_idx_14;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T t13;
  real_T t2;
  real_T t4;
  real_T t5;
  real_T t6;
  int32_T b;
  U_idx_0 = t17->mU.mX[0];
  U_idx_1 = t17->mU.mX[1];
  U_idx_2 = t17->mU.mX[2];
  U_idx_3 = t17->mU.mX[3];
  U_idx_4 = t17->mU.mX[4];
  U_idx_5 = t17->mU.mX[5];
  U_idx_6 = t17->mU.mX[6];
  U_idx_7 = t17->mU.mX[7];
  X_idx_0 = t17->mX.mX[0];
  X_idx_1 = t17->mX.mX[1];
  X_idx_2 = t17->mX.mX[2];
  X_idx_3 = t17->mX.mX[3];
  X_idx_4 = t17->mX.mX[4];
  X_idx_5 = t17->mX.mX[5];
  X_idx_6 = t17->mX.mX[6];
  X_idx_7 = t17->mX.mX[7];
  X_idx_8 = t17->mX.mX[8];
  X_idx_9 = t17->mX.mX[9];
  X_idx_10 = t17->mX.mX[10];
  X_idx_11 = t17->mX.mX[11];
  X_idx_12 = t17->mX.mX[12];
  X_idx_13 = t17->mX.mX[13];
  X_idx_14 = t17->mX.mX[14];
  D_idx_0 = t17->mD.mX[0];
  out = t18->mLOG;
  SIM_Capacitor_p_v = X_idx_0 + X_idx_3;
  SIM_Controlled_Current_Source_head_v = -(X_idx_5 - X_idx_4);
  t2 = U_idx_2 - (-X_idx_3);
  t4 = -X_idx_2 + U_idx_1;
  SIM_Diode_i = (((((X_idx_1 * -0.01 + X_idx_4 * -0.01) + X_idx_6 * -1.00000001)
                   + X_idx_2 * -0.0043755555938442747) + X_idx_7 * 0.01) +
                 U_idx_1 * 0.0043755555938442747) + U_idx_3 * 0.01;
  t5 = (((-X_idx_1 + X_idx_6 * -1.0E-6) + X_idx_2 * -0.43755555938442742) +
        U_idx_1 * 0.43755555938442742) + U_idx_3;
  SIM_Diode_p_v = (X_idx_2 * -0.43755555938442742 + U_idx_1 *
                   0.43755555938442742) + U_idx_3;
  SIM_Diode_v = X_idx_6 * 1.0E-6 + X_idx_1;
  t6 = (((((X_idx_1 * 0.01 + X_idx_4 * 0.01) + X_idx_6 * 1.0E-8) + X_idx_2 *
          0.0043755555938442747) + X_idx_7 * -0.01) + U_idx_1 *
        -0.0043755555938442747) + U_idx_3 * -0.01;
  SIM_Resistor_n_v = ((((-X_idx_1 + X_idx_6 * -1.0E-6) + X_idx_2 *
                        -0.43755555938442742) + U_idx_1 * 0.43755555938442742) +
                      U_idx_3) + X_idx_7;
  t13 = (-X_idx_0 + -X_idx_3) + X_idx_4;
  SIM_Switch2_i = (((((X_idx_1 * -0.01 + X_idx_4 * -0.01) + X_idx_6 * -1.0E-8) +
                     X_idx_2 * -1.0043755555938443) + X_idx_7 * 0.01) + U_idx_1 *
                   1.0043755555938443) + U_idx_3 * 0.01;
  SIM_Switch2_v = ((X_idx_2 * 0.43755555938442742 + U_idx_1 *
                    -0.43755555938442742) + -U_idx_3) + X_idx_4;
  t0[0ULL] = U_idx_0 + X_idx_2;
  t0[1ULL] = X_idx_3;
  t0[2ULL] = SIM_Capacitor_p_v;
  t0[3ULL] = X_idx_0;
  t0[4ULL] = X_idx_0;
  t0[5ULL] = X_idx_0 * X_idx_0 * 1.0E-9;
  t0[6ULL] = SIM_Controlled_Current_Source_head_v;
  t0[7ULL] = U_idx_1;
  t0[8ULL] = U_idx_1;
  t0[9ULL] = t2;
  t0[10ULL] = t2 - SIM_Controlled_Current_Source_head_v;
  t0[11ULL] = SIM_Capacitor_p_v;
  t0[12ULL] = U_idx_0;
  t0[13ULL] = U_idx_0;
  t0[14ULL] = X_idx_3;
  t0[15ULL] = X_idx_3 - SIM_Capacitor_p_v;
  t0[16ULL] = t4;
  t0[17ULL] = U_idx_3;
  t0[18ULL] = U_idx_3;
  t0[19ULL] = U_idx_3;
  t0[20ULL] = -U_idx_1;
  t0[21ULL] = X_idx_3;
  t0[22ULL] = t2;
  t0[23ULL] = U_idx_2;
  t0[24ULL] = U_idx_2;
  t0[25ULL] = t4;
  t0[26ULL] = t4;
  t0[27ULL] = t4;
  t0[28ULL] = X_idx_6;
  t0[29ULL] = t5;
  t0[30ULL] = SIM_Diode_p_v;
  t0[31ULL] = SIM_Diode_v;
  t0[32ULL] = X_idx_1;
  t0[33ULL] = SIM_Diode_i;
  t0[34ULL] = X_idx_6;
  t0[35ULL] = SIM_Diode_i;
  t0[36ULL] = SIM_Diode_i + X_idx_6;
  t0[37ULL] = SIM_Diode_v;
  t0[38ULL] = t5;
  t0[39ULL] = t5;
  t0[40ULL] = SIM_Diode_p_v;
  t0[41ULL] = SIM_Diode_i * SIM_Diode_v * 0.001 * 1000.0;
  t0[42ULL] = SIM_Diode_v;
  t0[43ULL] = SIM_Diode_v;
  t0[44ULL] = t6;
  t0[45ULL] = SIM_Resistor_n_v;
  t0[46ULL] = X_idx_4;
  t0[47ULL] = t6 * 100.0;
  t0[48ULL] = t6 * t6 * 100.0;
  t0[49ULL] = t4;
  t0[50ULL] = U_idx_3;
  t0[51ULL] = SIM_Diode_p_v;
  t0[52ULL] = t4 * 0.43755555938442742;
  t0[53ULL] = t4 * t4 * 0.43755555938442742;
  t0[54ULL] = X_idx_8;
  t0[55ULL] = -U_idx_1;
  t0[56ULL] = X_idx_2;
  t0[57ULL] = -U_idx_1 + X_idx_2;
  t0[58ULL] = -(X_idx_9 - X_idx_4);
  t0[59ULL] = SIM_Controlled_Current_Source_head_v;
  t0[60ULL] = SIM_Capacitor_p_v;
  t0[61ULL] = -(X_idx_10 - X_idx_4);
  t0[62ULL] = -(X_idx_11 - X_idx_4);
  t0[63ULL] = -(X_idx_12 - X_idx_4);
  t0[64ULL] = -(X_idx_13 - X_idx_4);
  t0[65ULL] = -(X_idx_14 - X_idx_4);
  t0[66ULL] = X_idx_4;
  t0[67ULL] = (-(U_idx_1 * X_idx_5) + X_idx_2 * t13) * 0.001 * 1000.0;
  t0[68ULL] = D_idx_0;
  t0[69ULL] = X_idx_9;
  t0[70ULL] = X_idx_5;
  t0[71ULL] = t13;
  t0[72ULL] = X_idx_10;
  t0[73ULL] = X_idx_11;
  t0[74ULL] = X_idx_12;
  t0[75ULL] = X_idx_13;
  t0[76ULL] = X_idx_14;
  t0[77ULL] = U_idx_6;
  t0[78ULL] = U_idx_2;
  t0[79ULL] = U_idx_4;
  t0[80ULL] = U_idx_5;
  t0[81ULL] = U_idx_6;
  t0[82ULL] = U_idx_7;
  t0[83ULL] = U_idx_1;
  t0[84ULL] = U_idx_0;
  t0[85ULL] = U_idx_3;
  t0[86ULL] = -t4;
  t0[87ULL] = X_idx_3;
  t0[88ULL] = X_idx_3;
  t0[89ULL] = -(t4 * X_idx_3);
  t0[90ULL] = U_idx_7;
  t0[91ULL] = t6;
  t0[92ULL] = t5;
  t0[93ULL] = SIM_Resistor_n_v;
  t0[94ULL] = X_idx_7;
  t0[95ULL] = t6 * X_idx_7;
  t0[96ULL] = U_idx_4;
  t0[97ULL] = SIM_Switch2_i;
  t0[98ULL] = SIM_Diode_p_v;
  t0[99ULL] = X_idx_4;
  t0[100ULL] = SIM_Switch2_v;
  t0[101ULL] = SIM_Switch2_i * SIM_Switch2_v;
  t0[102ULL] = U_idx_5;
  t0[103ULL] = SIM_Diode_p_v;
  t0[104ULL] = SIM_Diode_p_v;
  t0[105ULL] = X_idx_4;
  t0[106ULL] = X_idx_4;
  t0[107ULL] = X_idx_4;
  t0[108ULL] = SIM_Diode_p_v;
  for (b = 0; b < 109; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t18;
  return 0;
}
