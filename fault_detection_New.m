%% Fault ditecion New
% Data Acquisition
clc
Iin = out.Io{1}.Values.Data;
t  = out.Io{1}.Values.Time;
I1 = out.Io{2}.Values.Data;
I2 = out.Io{4}.Values.Data;
I3 = out.Io{6}.Values.Data;
Ig1 = out.Ig{1}.Values.Data;
I_sample1 = out.ILsample{2}.Values.Data;
I_sample2 = out.ILsample{3}.Values.Data;
I_sample3 = out.ILsample{4}.Values.Data;
% Data Preprocess
clc
N = length(Iin);
fk = 10e3;
fs = 1./2.5e-8;
NF = fs/fk;
k  = round(NF/3);
Is1_Int=[];
Is2_Int=[];
Is3_Int=[];
for i=NF:NF:N-2*NF
    is1_Int = trapz(t(i:1:i+2*NF),I_sample1(i:1:i+2*NF));
    is2_Int = trapz(t(i:1:i+2*NF),I_sample2(i:1:i+2*NF));
    is3_Int = trapz(t(i:1:i+2*NF),I_sample3(i:1:i+2*NF));
    Is1_Int=[Is1_Int,is1_Int];
    Is2_Int=[Is2_Int,is2_Int];
    Is3_Int=[Is3_Int,is3_Int];
end
plot(Is1_Int);
hold on
plot(Is2_Int);
hold on
plot(Is3_Int);
%% Fault Diagnosis
II1=[];
II2=[];
II3=[];
NN = length(Is1_Int);
for ii=1:1:NN
if max([abs((Is1_Int(ii)-Is2_Int(ii))),abs((Is2_Int(ii)-Is3_Int(ii))),...
        abs((Is1_Int(ii)-Is3_Int(ii)))])<3.0e-05   
    IIs2_Int=0;
    IIs3_Int=0;
    IIs1_Int=0;
elseif round((Is1_Int(ii)-Is2_Int(ii)).* (Is2_Int(ii)-Is3_Int(ii)),10)>0;
    IIs2_Int=1;
    IIs3_Int=0;
    IIs1_Int=0;
elseif round((Is2_Int(ii)-Is3_Int(ii)).* (Is3_Int(ii)-Is1_Int(ii)),10)>0;
    IIs2_Int=0;
    IIs3_Int=1;
    IIs1_Int=0;
elseif round((Is3_Int(ii)-Is1_Int(ii)).* (Is1_Int(ii)-Is2_Int(ii)),10)>0
    IIs2_Int=0;
    IIs3_Int=0;
    IIs1_Int=1;
else
    IIs2_Int=0;
    IIs3_Int=0;
    IIs1_Int=0;
end
II1=[II1,IIs1_Int];
II2=[II2,IIs2_Int];
II3=[II3,IIs3_Int];
end

%% Picture
subplot(211)
PPP = 0;
plt=plot(t,I1);
Picture_LCF;
hold on
plt=plot(t,I2);
Picture_LCF;
hold on
plt=plot(t,I3);
Picture_LCF;
subplot(212)
PPP = 0;
plt=plot(II1);
Picture_LCF;
hold on
plt=plot(II2);
Picture_LCF;
hold on
plt=plot(II3);
Picture_LCF;