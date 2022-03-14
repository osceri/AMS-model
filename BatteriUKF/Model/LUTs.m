clear, clc

data = [ 
10 3.933 1.33 0.746 3.307;
30 3.433 1.33 0.773 3.7177;
50 3.233 1.367 1.85 3.803;
70 3.066 1.467 0.676 3.922;
90 3.067 1.633 0.694 4.072 ];


soc = data(:, 1)* 10^-2; % * 10^-2
Rs = data(:, 2); % * 10^-3
Rp = data(:, 3); % * 10^-3
Cp = data(:, 4) * 100; % * 10^6
ocv = data(:, 5);

Cpf = fit(soc, Cp, 'a + c*x + b*exp(-abs(n)*(x-0.5)^2)');

figure(1)
hold on
plot(soc, Cp);
socf = linspace(0.0,1.0,100);
plot(socf, Cpf(socf));
title("soc-Cp");
hold off

Rsf = fit(soc, Rs, 'rat21');

figure(2)
hold on
plot(soc, Rs);
socf = linspace(0.0,1.0,100);
plot(socf, Rsf(socf));
title("soc-Rs");
hold off

soc_ext = [ 0, soc', 1 ]';
Rp_ext = [ Rp(1)*0.99, Rp', Rp(end)*1.07 ]';
Rpf = fit(soc_ext, Rp_ext, 'poly3')

figure(3)
hold on
plot(soc, Rp);
socf = linspace(0.0,1.0,100);
plot(socf, Rpf(socf));
title("soc-Rp");
hold off

soc_ext = [ 0, soc', 1 ]';
ocv_ext = [ 3, ocv', 4.2 ]';
f = fit(soc_ext, ocv_ext, 'rat32');

p1 =       1.383;
p2 =       2.087;
p3 =     -0.6693;
p4 =      0.4484;
q1 =     -0.3742;
q2 =      0.1495;

syms ocvf docvf z
ocvf_sym = (p1*z^3 + p2*z^2 + p3*z + p4) / (z^2 + q1*z + q2);
docvf_sym = diff(ocvf_sym, z);

ocvf = matlabFunction(ocvf_sym);
docvf = matlabFunction(docvf_sym);

figure(4)
hold on
plot(soc, ocv);
socf = linspace(0.0,1.0,100);
plot(socf, ocvf(socf));
title("soc-ocv")
hold off

%figure(4)
%hold on
%socf = linspace(0.0,1.0,100);
%plot(socf, docvf(socf));
%title("Derivative of soc-ocv")
%hold off
