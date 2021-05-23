%% Fault detection 
% Acquire the output data
clc
Io = out.Io{7}.Values.Data;
t  = out.Io{1}.Values.Time;
I1 = out.Io{2}.Values.Data;
I2 = out.Io{4}.Values.Data;
I3 = out.Io{6}.Values.Data;
Ig1 = out.Ig{1}.Values.Data;
Io1 = I1+I2+I3;
Vo = out.Io{8}.Values.Data;
figure
subplot(411)
PPP=0;
plt=plot(t(1:1:end),I1(1:1:end)); Picture_LCF;
subplot(412)
plt=plot(t(1:1:end),I2(1:1:end)); Picture_LCF;%260000
subplot(413)
plt=plot(t(1:1:end),I3(1:1:end)); Picture_LCF;
subplot(414)
plt=plot(t(1:1:end),Io(1:1:end)); Picture_LCF;
%% Test1
clc
tic
GPHI=[];
GAMP=[];
GFRE=[];
% Data Preprocess
clc
N = length(Ig1);
fk = 10e3;
fs = 1./2.5e-8;
% NF = fs/fk;
NF = 4013;
k  = round(NF/3);
% [~,T_star]=max(Ig1(170750:1:170750+4000));
for ii=NF:NF:N-2*NF
    y=Ig1(ii:1:ii+2*NF-1);
    [phi,amp,fre]=Phase_calculate_detection1(y);
    GPHI=[GPHI,phi];
    GAMP=[GAMP,amp];
    GFRE=[GFRE,fre];
end
% toc
figure(1)
% ii=174000:4000:N-20000;
% i2=174000:100:N-20000;
% T=t(ii);
% Y=Ig1(i2);
subplot(311)
plot(Ig1);
subplot(312)
plot(GAMP)
subplot(313)
plot(GPHI,'.')
%% Phase detection 
% Data Preprocess
clc
N = length(Io);
fk = 10e3;
fs = 1./2.5e-8;
% NF = fs/fk;
NF = 4027;
k  = round(NF/3);
k = 1335;
PHI=[];
AMP=[];
FRE=[];
N=length(Io);
[~,T_star]=max(Io(173013:1:173013+4000));
for ii=T_star:NF:N-2*NF
    y=Io(ii:1:ii+NF);
    [phi,amp,fre]=Phase_calculate_detection1(y);
    phi=phi-90;
    PHI=[PHI,phi];
    AMP=[AMP,amp];
    FRE=[FRE,fre];
end
figure(3)
PPP=0;
subplot(311);
plt=plot(Io);Picture_LCF;
subplot(312);
plt=plot(AMP);Picture_LCF;
subplot(313);
plt=plot(PHI);Picture_LCF;
%% Test 2
tic
VPHI=[];
VAMP=[];
VFRE=[];
N=length(Vo);
% [~,T_star]=max(Ig1(170750:1:170750+4000));
for ii=170750+T_star:4000:N-20000
    y=Vo(ii:1:ii+4000);
    [phi,amp,fre]=Phase_calculate_detection1(y);
    VPHI=[VPHI,phi];
    VAMP=[VAMP,amp];
    VFRE=[VFRE,fre];
end
toc

% figure(2)
% ii=174000:4000:N-20000;
% T=t(ii);
% Y=Io(ii);
% subplot(311)
% plot(Y);
% subplot(312)
% plot(VAMP)
% subplot(313)
% plot(VPHI,'.')

%% Calculate the amplititude and frequency
clc
% Sliding the windows
% Start 174000;
% i = 709500:1:720538;
% y = Io(i);
% y1 = I1(i);
% y2 = I2(i);
% y3 = I3(i);
% t = t(i);
% subplot(411)
% plot(t,y);
% subplot(412)
% plot(t,y1);
% subplot(413)
% plot(t,y2);
% subplot(414)
% plot(t,y3);
%% Phase detection 
% clc
% tic
PHI=[];
AMP=[];
FRE=[];
N=length(Io);
% [~,T_star]=max(Io(173013:1:173013+4000));
for ii=173014:2667:N-20000
    y=Io(ii:1:ii+2667);
    [phi,amp,fre]=Phase_calculate_detection1(y);
    PHI=[PHI,phi];
    AMP=[AMP,amp];
    FRE=[FRE,fre];
end
figure(3)
ii=174000:4000:N-20000;
T=t(ii);
Y=Io(ii);
subplot(311)
plot(Y);
subplot(312)
plot(AMP)
subplot(313)
plot(PHI,'.')
%% Plot 
figure(4)
DIFF1=PHI-GPHI;
DIFF2=VPHI-GPHI;
ii=174000:4000:N-20000;
T=t(ii);
Y=Io(ii);
subplot(311)
plot(Y,'.');
subplot(312)
plot(DIFF1,'.')
subplot(313)
plot(DIFF2,'.')
