clear, clc
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
Ts    = 0.2;        % Fundamental sample time   [s]

%% Export
save("parameters.mat");