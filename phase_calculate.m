% =========================================================================
% =                                                                       =
% =               Demo of the FFT and the calculation of phase            =
% =                             by                                        =
% =                          Chuanfeng Li                                 =
% =                       date: 04.07.2020                                =
% =                                                                       =
% =                               HIT                                     =
% =                   e-mail: licf1996@gmail.com                          =
%% FFT Test

% Generate a signal
fs=50; 
w=20;
t=0:1./fs:0.02-1./fs;
dc=51;
DC=repmat(dc,1,50);
y=DC+25*cos(2*pi*w*t+350*pi/180);                 % 单一频率的信号
% y=y2;
N=length(y);
Fy=fft(y,N);                               % Compute DFT of x            

m = abs(Fy);                               % Magnitude
Fy(m<1e-6) = 0;
p = unwrap(angle(Fy));                     % Phase

% Process
[~,pk]=max(m);
m(pk)=[];
Fy(pk)=[];
p(pk)=[];
[~,pt]=max(m);
FFY=Fy(pt)
P=p(pt)*180/pi;
if (imag(FFY)<0 && real(FFY)<0)
    P=P+360;
end
if (imag(FFY)<0 && real(FFY)>0)
    P=P+360;
end
P

pp = atan(imag(FFY)./real(FFY))*180/pi;
if (imag(FFY)<0 && real(FFY)<0)
    pp=pp+180;
end
if (imag(FFY)<0 && real(FFY)>0)
    pp=pp+360;
end
if (imag(FFY)>0 && real(FFY)<0)
    pp=pp+180;
end
pp

% Plot the  spectrogram and phase diagram

% f = (0:length(Fy)-1)*fs/length(Fy);        % Frequency vector
% figure(1)
% subplot(2,1,1)
% plot(f,m)
% title('Magnitude')
% subplot(2,1,2)
% plot(f,p*180/pi)
% title('Phase')
% [phi,amp,fre]=Phase_calculate_detection1(y)
%% DFT according to the formular (2)
clc
clear all
clear real
% Generate a signal
fs=500; 
w=50;
tt=0:1./fs:1-1./fs;
y=sin(2*pi*w*tt+60*pi/180);
N=length(y);
FF_real=[];
for n=1:1:N
    F_real=0;
    for t=1:1:N
    Real=exp(-1i*2*pi*n*(t-1)/N).*y(t);
    F_real=F_real+Real;
    end
FF_real=[FF_real,F_real];
end
F = FF_real;
m = abs(F);                                 % Magnitude
F(m<1e-6) = 0;
p = unwrap(angle(F));                     % Phase

% Plot the  spectrogram and phase diagram

figure(2)
f = (0:length(F)-1)*fs/length(F);        % Frequency vector
subplot(2,1,1)
plot(f,m)
title('Magnitude')
subplot(2,1,2)
plot(f,p*180/pi)
title('Phase')

% Calculate the phase
pp = atan(imag(max(F))./real(max(F)));
phi1 = 90+pp*180/pi;
phi2 = 90-max(p*180/pi);
phi3 = 90-max(angle(F)*180/pi);
phi4 = 90-max(phase(F)*180/pi);
%% 
clear all;
clc;
fs=81920;%采样频率
T = 1*(1/10); %时间
dt = T/fs; %采样间隔
t = 0:dt:(T-dt); 
f0=10;%设定锯齿波信号频率
x = sawtooth(2*pi*10*t);%锯齿波
plot(x)
f1=6000; %载波 频率6KHz
fs=50; 
w=20;
t=0:1./fs:1-1./fs;
y=0.2*sawtooth(2*pi*w*t+60*pi/180,0.2);%初始相位60
z=y;
zz=fft(z);%进行fft变换
N=length(zz);%matlab可以做任意点数的fft，不用基2的
mag=abs(zz)*2/N;%求幅值 乘上后面的2/N得到正确幅值
f=(0:length(zz)-1)'*fs/length(y)/T;%之前你的频率换算有问题
angle(zz(1))*180/pi%实际应该是第601个，而不是599个
