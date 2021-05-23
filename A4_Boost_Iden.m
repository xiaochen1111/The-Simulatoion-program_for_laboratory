%% �򿪷����ļ�
mdl = 'A4_BOOST_SWEEP_12b';
open_system(mdl);
%% ָ�����������
ios = [...
    linio([mdl,'/Constant'],1,'input'); ...
    linio([mdl,'/Voltage Measurement'],1,'output')];
f = logspace(log10(200),log10(80000),30);
in = frest.Sinestream('Frequency',f,'Amplitude',0.05,...
    'FreqUnits','Hz');
getSimulationTime(in)/0.02
%% ��ͼ+���
[sysData,simlog] = frestimate(mdl,ios,in);
bopt               = bodeoptions;
bopt.Grid          = 'on';
bopt.PhaseMatching = 'on';
figure, bode(sysData,'*r',bopt)
hold on
s = tf('s');
GIden= (-0.005 * s + 400)/...
  (1.25e-08 * s^2 + 2.5e-05 * s + 1);

bode(GIden,{200,1e6*6.28});
sysA = tfest(sysData,2);
figure, bode(sysData,'r*',sysA,bopt)
% ��Ƶ��ַ��https://www.bilibili.com/video/BV1bV411t7ye/