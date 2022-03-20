clear, clc
load soc.mat
load ocv.mat
load docv.mat
load Rs.mat
load Rp.mat
load tau.mat
load coeffs.mat
load AF_state.mat

%% Battery Parameters
C    = 6.6;         % C-rating for a cell                  [A]
Vnom = 4.072;       % Nominal voltage                      [V]
Q    = C*Vnom*3600; % Battery capacity                     [W*hr]
Ri   = 0.003355;    % Internal resistance                  [Ohm]
AH   = Q/Vnom;      % Ampere-hour rating                   [hr*A]
V1   = 3.8;         % Voltage V1 < Vnom when charge is AH1 [V]
AH1  = AH/2;        % Charge AH1 when no-load volts are V1 [hr*A]
AH0  = 0.7*AH;      % Initial charge                       [hr*A]
SOC0 = 0.7;         % Initial State of Charge              [%]

%% Other Parameters
Ts = 0.2;           % Fundamental sample time   [s]

%% Filter parameters
x0  = [0.0; 0.7];           % Initial State
Px0 = diag(10^-11 * x0);    % Initial covariance
Qx0 = diag(10^-11 * x0);    % Process noise covariance
Rx0 = 1e-3;                 % Measurement noise covariance

Lx = 100;

p0  = [ mean(Rs_LUT), mean(Rp_LUT), mean(tau_LUT), AH*1.2 ];        % Initial parameters


%% Struct creation
s0      = struct;

s0.Lx   = uint16(Lx);
s0.lx   = uint16(0);
s0.Ex   = zeros(s0.Lx, 1);
s0.Px_  = Px0;
s0.Px   = Px0;
s0.Qx   = Qx0;
s0.Rx   = Rx0;
s0.x_   = x0;
s0.x    = x0;
s0.p    = p0;


%% Export
save("parameters.mat");