Vout= out.Voutnoise{2}.Values.Data(200001:end);
Voutnoise=out.Voutnoise{1}.Values.Data(200001:end);
t=out.Voutnoise{1}.Values.Time(200001:end);
Noise=Voutnoise-Vout;
% Calculate the power of signal and noise
MVout=mean(Vout);
MVout=42.0728;
%Noise = 0.04.*randn(length(Vout),1);
%Vout=repmat(MVout,length(Vout),1);
P_signal=sum(Vout.^2)/length(Vout);
P_noise=sum(Noise.^2)/length(Noise);
% Calculate the SNR
SNR = 10 *log10(P_signal/P_noise)
[muHat,sigmaHat] = normfit(Noise);

%% 对噪声进行拟合，估算其均值与方差的大小
% [muHat,sigmaHat] = normfit(Noise);
Vo_sample = out.ILsample{1}.Values.Data(200001:end);
I_sample1 = out.ILsample{2}.Values.Data(200001:end);
I_sample2 = out.ILsample{3}.Values.Data(200001:end);
I_sample3 = out.ILsample{4}.Values.Data(200001:end);
I_original=importdata('testdataI1.mat');
Noise1 = I_sample1-I_original;
Noise_Int=[];
Is2_Int=[];
Is3_Int=[];
dx=0.01;
N = length(t);
fk = 10e3;
fs = 1./2.5e-8;
NF = fs/fk;
for i=200001:NF:N-3*NF
    NNoise = trapz(t(i:1:i+2*NF),Noise1(i:1:i+2*NF));
    Noise_Int=[Noise_Int,NNoise];
end
[muHat1,sigmaHat1] = normfit(Noise1);
[muHat2,sigmaHat2] = normfit(Noise_Int);

P_signal=sum(I_original.^2)/length(I_original);
P_noise=sum(Noise1.^2)/length(Noise1);
% Calculate the SNR
SNR = 10 *log10(P_signal/P_noise)