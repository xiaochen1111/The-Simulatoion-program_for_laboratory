% Picture for the open-circuit fault for IBC
% laod the data
% The inductor current and the input current
N=320002:1:800000;
t=out.per_phase_current{1}.Values.Time(N);
iL1=out.per_phase_current{1}.Values.Data(N);
iL2=out.per_phase_current{2}.Values.Data(N);
iL3=out.per_phase_current{3}.Values.Data(N);
Iin=out.per_phase_current{4}.Values.Data(N);
%% The sampling value of input current at three specific moments
Vo_sample = out.ILsample{1}.Values.Data(N);
I_sample1 = out.ILsample{2}.Values.Data(N);
I_sample2 = out.ILsample{3}.Values.Data(N);
I_sample3 = out.ILsample{4}.Values.Data(N);
%% Plot 
T=linspace(0.008,0.020,117);
NN=1:1:117;
I1_In=Is1_Int(NN);
I2_In=Is2_Int(NN);
I3_In=Is3_Int(NN);
NNN= 145:1:160;

%%
figure(1)
% ha = tight_subplot(2,1,[.15 .03],[.15 .1],[.088 .04]); %调整图窗大小(gap down
% up left right) %650 400
% ha = tight_subplot(2,1,[.13 .03],[.13 ,0.08],[.11 .03]); 
ha = tight_subplot(4,1,[.115 .03],[.115 ,0.05],[.11 .03]); 
%%
PPP = 0;
%%
plt = plot(t,iL1);
Picture_LCF;
ylabel('I_{L1}')
%%
plt = plot(t,iL2);
Picture_LCF;
ylabel('I_{L2}')
%%
plt = plot(t,iL3);
Picture_LCF; 
ylabel('I_{L3}')
%%
plt = plot(t,Iin);
Picture_LCF;  
ylabel('I_{in}')
%%
legend('I_{L1}','I_{L2}','I_{L3}','I_{in}')
ylabel('I_{Sample}(A)','FontSize',15,'LineWidth',12)  
Picture_LCF;
%%
PPP = 1;
plt = plot(T,Is1_Int);
Picture_LCF;
hold on
plt = plot(T,Is2_Int);
Picture_LCF;
hold on
plt = plot(T,Is3_Int);
legend("I_{in}(T_1)'","{I_{in}}(T_2)'","{I_{in}}(T_3)'")
ylabel('I_{Integration}','FontSize',15,'LineWidth',12) 
Picture_LCF;
%% subpicture
axes('position', [0.18 0.18, 0.35, 0.22])

%%
h=figure(1);
%codes to generate figure;
% set(h,'PaperPositionMode','manual');
% set(h,'PaperUnits','points');
%set(h,'PaperPosition',[0,0,650,400]);%恰当选择尺寸
%print(h,'C:\Users\Dell\Desktop\Fig10.tiff','-painters','-r600','-dtiffn');%-r600可改为300dpi分辨率
saveas(h,'C:\Users\Dell\Desktop\Fig12.mfig')
%exportgraphics(gcf,'C:\Users\Dell\Desktop\test.tiff','Resolution',600);
%exportgraphics(gcf,'C:\Users\Dell\Desktop\test.tiff','Resolution',600);