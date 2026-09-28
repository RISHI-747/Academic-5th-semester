clc;
clear;
close all;

%% Link lengths
l1 = 0.5;
l2 = 0.3;

%% =========================================================
% STUDY 1: END EFFECTOR TRACE
% =========================================================

th1 = 30:2.5:75;
th2 = 45:2.5:90;

X = [];
Y = [];

figure(1);
hold on;
grid on;
axis equal;

xlabel('X (m)');
ylabel('Y (m)');
title('End Effector Trace of 2R Robotic Arm');

for i = 1:length(th1)
    for j = 1:length(th2)

        t1 = deg2rad(th1(i));
        t2 = deg2rad(th2(j));

        % Joint 1
        x1 = l1*cos(t1);
        y1 = l1*sin(t1);

        % End effector
        x2 = l1*cos(t1) + l2*cos(t1+t2);
        y2 = l1*sin(t1) + l2*sin(t1+t2);

        % Plot configuration
        plot([0 x1],[0 y1],'b','LineWidth',0.8);
        plot([x1 x2],[y1 y2],'r','LineWidth',0.8);

        % End effector
        plot(x2,y2,'ro','MarkerSize',2);

        X(end+1) = x2;
        Y(end+1) = y2;
    end
end

plot(X,Y,'r.','MarkerSize',5);

xlim([-0.1 0.9]);
ylim([-0.1 0.9]);


%% =========================================================
% STUDY 2: WORK ENVELOPE AND CONFIGURATIONS
% =========================================================

th1 = -45:2.5:45;
th2 = -170:2.5:170;

figure(2);
hold on;
grid on;
axis equal;

xlabel('X (m)');
ylabel('Y (m)');
title('Work Envelope and Configuration of 2R Robotic Arm');

% Coordinate axes
plot([-1 1],[0 0],'r','LineWidth',0.8);
plot([0 0],[-1 1],'g','LineWidth',0.8);

for i = 1:length(th1)
    for j = 1:length(th2)

        t1 = deg2rad(th1(i));
        t2 = deg2rad(th2(j));

        % Joint 1
        x1 = l1*cos(t1);
        y1 = l1*sin(t1);

        % End effector
        x2 = l1*cos(t1) + l2*cos(t1+t2);
        y2 = l1*sin(t1) + l2*sin(t1+t2);

        % First link - Blue
        plot([0 x1],[0 y1], ...
            'b','LineWidth',0.35);

        % Second link - Magenta
        plot([x1 x2],[y1 y2], ...
            'm','LineWidth',0.35);

    end
end

xlim([-1 1]);
ylim([-1 1]);

axis square;
box on;
