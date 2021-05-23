function [phi]=Phase_calculate_detection(y)
N=length(y);
FF_real=[];
for n=0:1:N
    F_real=0;
    for t=1:1:N
    Real=exp(-1i*2*pi*n*(t-1)/N).*y(t);
    F_real=F_real+Real;
    end
FF_real=[FF_real,F_real];
end
F = FF_real;
m = abs(F);                                 % Magnitude
F(m<1e-4) = 0;
p = unwrap(angle(F));                     % Phase
% Calculate the phase
pp = atan(imag(F)./real(F));
pk=find(isnan(pp));
pp(pk)=[];
pp=max(pp(:));

ims=imag(F);
imsk=find(ims==0);
ims(imsk)=[];
ims=max(ims(:));

rea=real(F);
reak=find(rea==0);
rea(reak)=[];
rea=max(rea(:));

phi1 = pp*180/pi;
phi2 = max(p*180/pi);
phi3 = max(angle(F)*180/pi);
phi4 = max(phase(F)*180/pi);

% Judge
if (rea<0 && ims>0)
    phi1=180+phi1;
end
if (rea<0 && ims<0)
    phi1=180+phi1;
end
if (rea>0 && ims<0)
    phi1=360+phi1;
end

phi=[phi1,phi2,phi3,phi4];
end