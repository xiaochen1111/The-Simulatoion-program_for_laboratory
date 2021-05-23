% Test 
% 检测相位差，给定一个基准信号去计算相位差。
% Generate a signal
clear all
clc
fs=1./(2.5e-8); 
w=10000;
t=0:1./fs:0.02-1./fs;
N=length(t);
dc=51;
DC=repmat(dc,1,N);
Y_test=DC+50*sawtooth(2*pi*2*w*t+320*pi/180/2,0.5);            % 生成测试信号
Y_base=DC+50*sawtooth(2*pi*w*t+20*pi/180,0.5);             % 生成基准信号
[phase1] = phase_detection (Y_base,Y_base);
[phase2] = phase_detection (Y_base,Y_test);
phase=phase2-phase1;
if phase <0
    phase=phase+360;
end
plot(phase)

% The phase calculation based FFT,the time is more than a cycle.
% Subfunction
function [phase] = phase_detection (Y_base,Y)
% Phase detection I
% clc
% tic
PHI=[];
AMP=[];
FRE=[];
N=length(Y);
[~,T_star]=max(Y_base(173013:1:173013+4000));
for ii=173013+T_star:4000:N-20000
    y=Y(ii:1:ii+4001);
    [phi,amp,fre]=Phase_calculate_detection1(y);
    PHI=[PHI,phi];
    AMP=[AMP,amp];
    FRE=[FRE,fre];
end
phase=PHI;
end