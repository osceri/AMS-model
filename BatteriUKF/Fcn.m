clear, clc
load ocv.mat
load soc.mat

kf = fit(ocv_LUT', soc_LUT', 'rat53')
p5soc = [ kf.p1, kf.p2, kf.p3, kf.p4, kf.p5, kf.p6 ];
q3soc = [ kf.q1, kf.q2, kf.q3 ];
cf = fit(kf(ocv_LUT), ocv_LUT', 'poly5')
p5ocv = [ cf.p1, cf.p2, cf.p3, cf.p4, cf.p5, cf.p6 ];

ocv_Fcn = @(z) p5ocv(1)*z.^5 + p5ocv(2)*z.^4 + p5ocv(3)*z.^3 + p5ocv(4)*z.^2 + p5ocv(5)*z.^1 + p5ocv(6);
docv_Fcn = @(z) 5*p5ocv(1)*z.^4 + 4*p5ocv(2)*z.^3 + 3*p5ocv(3)*z.^2 + 2*p5ocv(4)*z + p5ocv(5);

figure(1)
hold on
plot(soc_LUT, cf(soc_LUT))
plot(kf(ocv_LUT), ocv_LUT) 
hold off

save('coeffs.mat', 'p5soc', 'q3soc', 'p5ocv');