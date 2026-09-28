clc;
clear;
close all;

l1 = 0.5;       
l2 = 0.3;       

x = linspace(0.1,0.6,20);
y = linspace(0.1,0.6,20);

figure(1);
clf;
hold on;
grid on;
axis equal;
axis([-0.9 0.9 -0.9 0.9]);

xlabel('X (m)');
ylabel('Y (m)');
title('Inverse Kinematics - Straight Line Motion');

for i = 1:length(x)

    r = [x(i), y(i)];

    c2 = (x(i)^2 + y(i)^2 - l1^2 - l2^2) ...
         /(2*l1*l2);

    if abs(c2) <= 1

        t2_1 = acos(c2);
        t2_2 = -acos(c2);

        t1_1 = atan2(y(i),x(i)) - ...
               atan2(l2*sin(t2_1), ...
               l1+l2*cos(t2_1));

        t1_2 = atan2(y(i),x(i)) - ...
               atan2(l2*sin(t2_2), ...
               l1+l2*cos(t2_2));

        x1 = l1*cos(t1_1);
        y1 = l1*sin(t1_1);

        x2 = l1*cos(t1_1) + l2*cos(t1_1+t2_1);
        y2 = l1*sin(t1_1) + l2*sin(t1_1+t2_1);

        plot([0 x1],[0 y1],'-b','LineWidth',1.5);

        hold on;

        plot([x1 x2],[y1 y2],'-b','LineWidth',1.5);

        plot(x2,y2,'or','LineWidth',1.5);

        x1 = l1*cos(t1_2);
        y1 = l1*sin(t1_2);

        x2 = l1*cos(t1_2) + l2*cos(t1_2+t2_2);
        y2 = l1*sin(t1_2) + l2*sin(t1_2+t2_2);

        plot([0 x1],[0 y1],'--g','LineWidth',1.5);

        plot([x1 x2],[y1 y2],'--g','LineWidth',1.5);

        plot(x2,y2,'or','LineWidth',1.5);

        pause(0.1);

    else

        plot(x(i),y(i),'or','LineWidth',2);

    end
end

plot(x,y,'k--','LineWidth',1);

legend('Configuration 1','Configuration 2','Target Path');

hold off;

x = linspace(0.6,-0.6,30);
y = 0.6*ones(size(x));

figure(2);
clf;
hold on;
grid on;
axis equal;
axis([-0.9 0.9 -0.9 0.9]);

xlabel('X (m)');
ylabel('Y (m)');
title('Inverse Kinematics - Horizontal Line Motion');

for i = 1:length(x)

    r = [x(i),y(i)];

    c2 = (x(i)^2 + y(i)^2 - l1^2 - l2^2) ...
         /(2*l1*l2);

    if abs(c2) <= 1

        t2_1 = acos(c2);
        t2_2 = -acos(c2);

        t1_1 = atan2(y(i),x(i)) - ...
               atan2(l2*sin(t2_1), ...
               l1+l2*cos(t2_1));

        t1_2 = atan2(y(i),x(i)) - ...
               atan2(l2*sin(t2_2), ...
               l1+l2*cos(t2_2));

        x1 = l1*cos(t1_1);
        y1 = l1*sin(t1_1);

        x2 = l1*cos(t1_1) + ...
             l2*cos(t1_1+t2_1);

        y2 = l1*sin(t1_1) + ...
             l2*sin(t1_1+t2_1);

        plot([0 x1],[0 y1],'-b','LineWidth',1.5);

        plot([x1 x2],[y1 y2],'-b','LineWidth',1.5);

        plot(x2,y2,'or','LineWidth',1.5);

        x1 = l1*cos(t1_2);
        y1 = l1*sin(t1_2);

        x2 = l1*cos(t1_2) + ...
             l2*cos(t1_2+t2_2);

        y2 = l1*sin(t1_2) + ...
             l2*sin(t1_2+t2_2);

        plot([0 x1],[0 y1],'--g','LineWidth',1.5);

        plot([x1 x2],[y1 y2],'--g','LineWidth',1.5);

        plot(x2,y2,'or','LineWidth',1.5);

        pause(0.1);

    else

        plot(x(i),y(i),'or','LineWidth',2);

    end
end

plot(x,y,'k--','LineWidth',1);

legend('Configuration 1','Configuration 2','Target Path');

hold off;
