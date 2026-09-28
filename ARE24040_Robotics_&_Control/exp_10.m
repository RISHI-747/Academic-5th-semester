clc;
clear;
close all;

l1 = 0.5;
l2 = 0.3;

th1 = 30:2.5:75;
th2 = 45:2.5:90;

figure;
hold on;
grid on;
axis equal;
axis([-1 1 -1 1]);

xlabel('X (m)');
ylabel('Y (m)');
title('2R Robotic Arm - End Effector Trace');

plot([-1 1],[0 0],'r');
plot([0 0],[-1 1],'g');

X = [];
Y = [];

for i = 1:length(th1)

    theta1 = th1(i);
    theta2 = th2(i);

    x1 = l1*cosd(theta1);
    y1 = l1*sind(theta1);

    x2 = l1*cosd(theta1) + l2*cosd(theta1 + theta2);
    y2 = l1*sind(theta1) + l2*sind(theta1 + theta2);

    X = [X x2];
    Y = [Y y2];

    plot([0 x1],[0 y1],'b','LineWidth',2);

    plot([x1 x2],[y1 y2],'m','LineWidth',2);

    plot(x2,y2,'ro','MarkerSize',5);

    pause(0.1);
end

plot(X,Y,'r--','LineWidth',2);

hold off;
