%% Picture
% legend('ESR');%,'Ic'
ylabel('AMP')%Ripple voltage(V)Amplitude
xlabel('Time(s)','LineWidth',10)
set(gca,'FontSize',10);
set(gca,'FontName','Helvetica');%%设置所有字体大小为18号，字体为Helverica
set(gca,'linewidth',1.5);%%设置图框的线宽
set(gcf,'position',[0 0 650 550]);%%设置画幅大小为横650*纵450
set(gca,'YLim',[0,500])