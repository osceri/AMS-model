clear, clc
load soc.mat
load ocv.mat
load docv.mat
load Rs.mat
load Rp.mat
load tau.mat
load coeffs.mat
load MAF_state.mat

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
Kxp = round(60/Ts);         % Update parameters every 60 seconds
Kxp = 10;

x0  = [0.0; 0.7];           % Initial State
Px0 = diag(10^-11 * x0);    % Initial covariance
Qx0 = diag(10^-11 * x0);    % Process noise covariance
Rx0 = 1e-3;                 % Measurement noise covariance

Lx = 100;

p0  = [ mean(Rs_LUT), mean(Rp_LUT), mean(tau_LUT), AH*1.2 ];        % Initial parameters
Pp0 = diag(0.4 * p0);                                               % Initial covariance
Qp0 = diag(0.4 * p0);                                               % Process noise covariance
Rp0 = 1e-3;                                                         % Measurement noise 

Lp = 100;

c0 = AH*1.2;
Pc0 = 0.1*AH;
Qc0 = 1e-1;
Rc0 = 1e-2;

Lc = 100;

%% Struct creation
s0      = struct;
s0.k    = int16(0);
s0.K    = int16(Kxp);

s0.Lx   = uint16(Lx);
s0.lx   = uint16(0);
s0.Ex   = zeros(s0.Lx, 1);
s0.Px_  = Px0;
s0.Px   = Px0;
s0.Qx   = Qx0;
s0.Rx   = Rx0;
s0.x_   = x0;
s0.x    = x0;

s0.Lp   = uint16(Lp);
s0.lp   = uint16(0);
s0.Ep   = zeros(s0.Lp, 1);
s0.Pp_  = Pp0
s0.Pp   = Pp0;
s0.Qp   = Qp0;
s0.Rp   = Rp0;
s0.p_   = p0;
s0.p    = p0;


s0.Lc   = uint16(Lc);
s0.lc   = uint16(0);
s0.Ec   = zeros(s0.Lc, 2);
s0.Pc_  = Pc0
s0.Pc   = Pc0;
s0.Qc   = Qc0;
s0.Rc   = Rc0;
s0.c_   = c0;
s0.c    = c0;

%% Export
save("parameters.mat");