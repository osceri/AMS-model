clear, clc

%% LUTs
soc_LUT = [0, 0.01, 0.0909090909090909,0.181818181818182,0.272727272727273,0.363636363636364,0.454545454545455,0.545454545454545,0.636363636363636,0.727272727272727,0.818181818181818,0.909090909090909,1];
Rs_LUT = [0.0044622496006,0.00446224960061823,0.00395928973129493,0.00365723545490869,0.00346135878439388,0.00332839611795259,0.00323577769308545,0.00317057626115591,0.00312485453442757,0.00309346940400882,0.00307294184679812,0.00306083426030356,0.00305538791678206];
Rp_LUT = [0.0013284973182,0.00132849731829051,0.00133071540686515,0.00133106364620441,0.00133282418704394,0.00133927918011939,0.00135371077616641,0.00137940112592065,0.00141963238011775,0.00147768668949337,0.00155684620478314,0.00166039307672272,0.00179160945604776];
tau_LUT = 1000*[0.95087194683,0.950871946837005,0.952459545918238,0.952715608141667,0.956801088701637,1.11698000087499,2.16329230815358,2.20434667293784,1.18399583949683,1.06079424954235,1.11432062847071,1.18842633649718,1.28234445639369];
ocv_LUT = [0, 2.99808472821531,3.29015678205606,3.51449858492796,3.66802196422992,3.76050972589663,3.81021773542304,3.83947699888896,3.87029574398353,3.91996150102984,3.99664318400941,4.09499317158672,4.19174938813381];

%% Simulation stats

z0 = 0.5;
Capacity_deterioration = -5;
Parameter_noise = 80; %db
SOC_upper_bound = 0.7;
SOC_lower_bound = 0.3;

%% Battery Parameters
C_r  = 6.6;           % C-rating for a cell                  [A]
Vnom = 4.072;         % Nominal voltage                      [V]
Q    = C_r*Vnom*3600; % Battery capacity                     [W*hr]
Ri   = 0.003355;      % Internal resistance                  [Ohm]
AH   = Q/Vnom;        % Ampere-hour rating                   [hr*A]
V1   = 3.8;           % Voltage V1 < Vnom when charge is AH1 [V]
AH1  = AH/2;          % Charge AH1 when no-load volts are V1 [hr*A]
AH0  = z0*AH;         % Initial charge                       [hr*A]
SOC0 = z0;            % Initial State of Charge              [%]

%% Other Parameters
Ts = 0.2;

%% Filter parameters
x0  = [0; AH0; AH];            % Initial State
Px0 = 1e-6*diag(x0);        % Initial covariance
Qx0 = 1e-5*diag(x0);        % Process noise covariance
Rx0 = 1e-3;                 % Measurement noise covariance

l_x             = length(x0);
LUT_length      = length(soc_LUT);

Up_index    = 1;
Q_index     = 2;
C_index     = 3;

soc  = soc_LUT;
Rs   = Rs_LUT;
Rp   = Rp_LUT;
tau  = tau_LUT;
ocv  = ocv_LUT;

mRs   = mean(Rs);
mRp   = mean(Rp);
mtau  = mean(tau);
mocv  = mean(ocv);

%% Cell balancing parameters
cell_count = 126;

cCap = C_r * 3600 * ones(cell_count, 1);
cQur = cCap / 2;

cCap = awgn(cCap, -60);

cTmp = 20*ones(60, 1);

Tmp = 40;


R_short = 33;

Cap_det = -1e-7;

U_sought = 4.15;
U_CC = 0.06;
I_CV = 1;
U_tol = 0.0000005;





%% Export
save("parameters.mat");