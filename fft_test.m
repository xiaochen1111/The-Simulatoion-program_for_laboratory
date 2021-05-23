%% FFT 的测试
fs=1000;
t=0:1/fs:1-1/fs;
fk=500;
y=sin(2*pi*t*fk);
N=length(y);
F=fft(y,N);
% 将横坐标转化，显示频率为f=n*(fs/N)
f=(0:N-1)*fs/N;
A=abs(F);
phy=phase(F)*180/pi;
plot(f,A);
plot(phy)
%% 
clc
I=0;
for n=1:1:N
    Y=y(n)./exp(-1i.*2.*pi.*(n-1)./N);
    I=I+Y;
end
I=I*2/N;
phi=atan(imag(I)/real(I))*180/pi;
phi1=angle(I)*180/pi;
phi2=phase(I)*180/pi;

