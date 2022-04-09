Rs2 = out.Rs
Rp2 = out.Rp
x2 = out.x1

figure(1)
hold on
plot(Rs_LUT(4:8))
plot(Rs2(4:8))
legend("True", "Estimated")
hold off

figure(2)
hold on
plot(Rp_LUT(4:8))
plot(Rp2(4:8))
legend("True", "Estimated")
hold off

mean(Rs2(4:8) ./ Rs_LUT(4:8))
mean(Rp2(4:8) ./ Rp_LUT(4:8))
mean(x2(3) ./ x0(3))
