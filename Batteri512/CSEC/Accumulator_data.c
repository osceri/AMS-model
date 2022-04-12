#include "Accumulator.h"

P_Accumulator_T Accumulator_P = {

  6.6,

  -1.0E-7,

  33.0,


  { 0.0013284973182, 0.00132849731829051, 0.00133071540686515,
    0.00133106364620441, 0.00133282418704394, 0.00133927918011939,
    0.00135371077616641, 0.00137940112592065, 0.00141963238011775,
    0.00147768668949337, 0.00155684620478314, 0.00166039307672272,
    0.00179160945604776 },


  { 0.0044622496006, 0.00446224960061823, 0.00395928973129493,
    0.00365723545490869, 0.00346135878439388, 0.00332839611795259,
    0.00323577769308545, 0.00317057626115591, 0.00312485453442757,
    0.00309346940400882, 0.00307294184679812, 0.00306083426030356,
    0.00305538791678206 },

  0.2,


  { 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0,
    23760.0, 23760.0, 23760.0, 23760.0, 23760.0, 23760.0 },


  { 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0,
    11880.0, 11880.0, 11880.0, 11880.0, 11880.0, 11880.0 },


  { 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
    20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
    20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
    20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
    20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0 },


  { 0.0, 2.99808472821531, 3.29015678205606, 3.51449858492796, 3.66802196422992,
    3.76050972589663, 3.81021773542304, 3.83947699888896, 3.87029574398353,
    3.91996150102984, 3.99664318400941, 4.09499317158672, 4.19174938813381 },


  { 0.0, 0.01, 0.0909090909090909, 0.181818181818182, 0.272727272727273,
    0.363636363636364, 0.454545454545455, 0.545454545454545, 0.636363636363636,
    0.727272727272727, 0.818181818181818, 0.909090909090909, 1.0 },


  { 950.87194683, 950.871946837005, 952.459545918238, 952.715608141667,
    956.801088701637, 1116.9800008749899, 2163.29230815358, 2204.3466729378397,
    1183.99583949683, 1060.79424954235, 1114.3206284707098, 1188.42633649718,
    1282.34445639369 },


  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  0.0,

  -1.0,

  0.0,

  0.0
};