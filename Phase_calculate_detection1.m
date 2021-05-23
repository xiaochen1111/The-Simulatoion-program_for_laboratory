function [phi,amp,fre]=Phase_calculate_detection1(y)
fs=1./(2.5e-8); 
% w=50;
% t=0:1./fs:1-1./fs;
% y=sin(2*pi*w*t+60*pi/180);                 % 单一频率的信号
N=length(y);
Fy = fft(y);                               % Compute DFT of x            

P2 = abs(Fy/N);                            % 双侧频谱
P1 = P2(1:N/2+1);                          %
P1(2:end-1) = 2*P1(2:end-1);
Fy(P1<1e-6) = 0;
p = unwrap(angle(Fy));                     % Phase

% Plot the  spectrogram and phase diagram

f = (0:length(Fy)-1)*fs/length(Fy);        % Frequency vector
[~,pk]=max(P1);
P1(pk)=[];
f(pk)=[];
p(pk)=[];
Fy(pk)=[];
[~,fk]=max(P1);
p=p(fk);
phi=p*180/pi;
fre=f(fk);
amp=P1(fk);
FFY=Fy(fk);
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
phi=pp;
end