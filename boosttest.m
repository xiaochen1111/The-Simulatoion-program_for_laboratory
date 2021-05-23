% =========================================================================
% =                                                                       =
% =               Demo of the parameter estimation based on frequency     =
% =                   scan for a boost converter based on derivation      =
% =                             by                                        =
% =                          Chuanfeng Li                                 =
% =                       date: 02.03.2020                                =
% =                                                                       =
% =                               HIT                                     =
% =                   e-mail: licf1996@gmail.com                          =
%% open the simulation 
clc
Boost_mdl='boost_test1';
open_system(Boost_mdl);
%% Determine the input and the output
ios = [linio([Boost_mdl,'/Constant'],1,'input');linio([Boost_mdl,'/Voltage Measurement'],1,'output')];
f = logspace(log10(200),log10(80000),60);
in = frest.Sinestream('Frequency',f, 'Amplitude', 0.01, ...
    'FreqUnits','Hz');
getSimulationTime(in)/0.02; % 预估仿真时长；

%% Plot and Fit 
clc
[sysData,simlog] = frestimate(Boost_mdl,ios,in);
bopt             = bodeoptions;
bopt.Grid        = 'on';
bopt.PhaseMatching= 'on';
figure
bode(sysData, '*r', bopt);
hold on
s = tf ('s');
alp=1-D;
GIden = V/(alp^2)*(-L/R/alp*s+1)/...
(L/R/(alp^2)*s^2+L*C/alp^2*s+1);
bode (GIden,{200,1e6*6,28})
sysA = tfest(sysData,2); % tfest 估计传递函数
figure
bode(sysData,'r*',sysA,bopt)
