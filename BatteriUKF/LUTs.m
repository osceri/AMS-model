clear, clc

%% This script is used to generate the LUTs one by one

%% Given data
data = [ 
10 3.933 1.33 0.746 3.307;
30 3.433 1.33 0.773 3.7177;
50 3.233 1.367 1.85 3.803;
70 3.066 1.467 0.676 3.922;
90 3.067 1.633 0.694 4.072 ];

%% Extrapolated
data = [
0.0 4.500 1.330 0.700 3.000;
0.1 3.933 1.330 0.746 3.307;
0.3 3.433 1.330 0.773 3.7177;
0.5 3.233 1.367 1.85 3.803;
0.7 3.066 1.467 0.676 3.922;
0.9 3.067 1.633 0.694 4.072; 
1.0 3.068 1.800 0.723 4.200
];


%% SOC

soc = data(:, 1); % data

fsoc = linspace(soc(1), soc(end), 100);
soc_LUT = fsoc;
%save('soc.mat', 'soc_LUT')


%% OCV

ocv = data(:, 5); % data
ocvfc = fit(soc, ocv, 'poly5')
ocvf = @(z) ocvfc.p1*z.^5 + ocvfc.p2*z.^4 + ocvfc.p3*z.^3 + ocvfc.p4*z.^2 + ocvfc.p5*z.^1 + ocvfc.p6;
docvf = @(z) 5*ocvfc.p1*z.^4 + 4*ocvfc.p2*z.^3 + 3*ocvfc.p3*z.^2 + 2*ocvfc.p4*z.^1 + 1*ocvfc.p5;
ocv_LUT = ocvf(fsoc);
docv_LUT = docvf(fsoc);

%hold on
%plot(soc, ocv)
%plot(fsoc, ocv_LUT)
%hold off
%save('ocv.mat', 'ocv_LUT')
%save('docv.mat', 'docv_LUT')

%% Rs curve

Rs = data(:, 2) * 10^-3; % data
Rsfc = fit(soc, Rs, 'rat21')
Rs_LUT = Rsfc(fsoc);

%hold on
%plot(soc, Rs)
%plot(fsoc, Rs_LUT)
%hold off
%save('Rs.mat', 'Rs_LUT')

%% Rp curve

Rp = data(:, 3) * 10^-3; % data
Rpfc = fit(soc, Rp, 'poly3');
Rp_LUT = Rpfc(fsoc);

%figure(1)
%hold on
%plot(soc, Rp)
%plot(fsoc, Rp_LUT)
%hold off
%save('Rp.mat', 'Rp_LUT')

%% Cp curve

Cp = data(:, 4) % * 10^6;
Cpfc = fit(soc, Cp, 'a + b*exp(-abs(c)*(x-0.5)^2)');
Cp_LUT = Cpfc(fsoc);

%% tau curve

tauf = @(z) Rpfc(z) .* Cpfc(z) * 10^3;
tau_LUT = tauf(fsoc);

%figure(2)
%hold on
%plot(soc, Cp .* Rp * 10^3)
%plot(fsoc, tau_LUT)
%hold off
%save('tau.mat', 'tau_LUT')
