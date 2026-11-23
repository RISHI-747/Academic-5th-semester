clc;
clear;
close all;

l1 = 0.5;
l2 = 0.3;
l3 = 0.2;

psi = deg2rad(60);

x = 0.8 * ones(1,13);
y = 0.1:0.05:0.7;

figure;
axis([-1 1 -1 1]);
axis equal;
grid on;
hold on;

xlabel('X');
ylabel('Y');
title('Inverse Kinematics of 3R Planar Robotic Arm');

plot([-1 1],[0 0],'r','LineWidth',1);
plot([0 0],[-1 1],'g','LineWidth',1);

armPlot = [];

pathX = [];
pathY = [];

oriLen = 0.10;

for i = 1:length(x)

    xd = x(i);
    yd = y(i);

    xw = xd - l3*cos(psi);
    yw = yd - l3*sin(psi);

    D = (xw^2 + yw^2 - l1^2 - l2^2)/(2*l1*l2);

    if abs(D) <= 1

        theta2 = atan2(sqrt(1-D^2),D);

        theta1 = atan2(yw,xw) - atan2(l2*sin(theta2), l1+l2*cos(theta2));

        theta3 = psi - theta1 - theta2;
        x1 = l1*cos(theta1);
        y1 = l1*sin(theta1);

        x2 = x1 + l2*cos(theta1+theta2);
        y2 = y1 + l2*sin(theta1+theta2);

        x3 = x2 + l3*cos(theta1+theta2+theta3);
        y3 = y2 + l3*sin(theta1+theta2+theta3);

        if ~isempty(armPlot)
            delete(armPlot);
        end

        h1 = plot([0 x1],[0 y1], ...
            'b','LineWidth',1);

        h2 = plot([x1 x2],[y1 y2],'b','LineWidth',1);

        h3 = plot([x2 x3],[y2 y3], 'b','LineWidth',1);

        j1 = plot(x1,y1,'ko','MarkerFaceColor','k','MarkerSize',4);

        j2 = plot(x2,y2,'ko', 'MarkerFaceColor','k','MarkerSize',4);

        armPlot = [h1 h2 h3 j1 j2];

        drawnow;
        pause(0.4);
        pathX(end+1) = x3;
        pathY(end+1) = y3;

        plot(pathX,pathY,'r.','MarkerSize',12);

        xo1 = x3;
        yo1 = y3;

        xo2 = x3 + oriLen*cos(psi);
        yo2 = y3 + oriLen*sin(psi);

        plot([xo1 xo2],[yo1 yo2], '--g','LineWidth',1.5);

        drawnow;
        pause(0.2);

    end
end
