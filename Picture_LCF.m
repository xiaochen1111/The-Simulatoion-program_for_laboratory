% Picture Beautiful
% Picture_LCF
PPP = PPP+1;
switch PPP
    case {1}
    plt.Color = [0 0.4470 0.7410];
    case {2}
    plt.Color = [0.8500 0.3250 0.0980];
    case {3}
    plt.Color = [0.9290 0.6940 0.1250];
    otherwise
    plt.Color = [0.4940 0.1840 0.5560];
end
% plt.Color = [0.4660 0.6740 0.1880];                                      % set the color of picture
plt.LineWidth = 1.0000;                                                    % set the linewidth of picture
plt.MarkerSize = 10;                                                       % set the markersize of picture
% plt.Marker = '_';



% ylabel('Output Ripple Voltage(V)')                                       % set the label of  y axis                 
xlabel('Time(s)','LineWidth',10)                                           % set the label of  x axis 
set(gca,'FontSize',12);
set(gca,'FontName','Helvetica');                                           %设置所有字体大小为18号，字体为Helverica
set(gca,'linewidth',1.5);                                                  %设置图框的线宽
set(gcf,'position',[0 0 650 450]);                                         %设置画幅大小为横650*纵450
% set(gca,'XLim',[0,0.02])                                                  %设置y轴的范围
set(gca,'xticklabel',{'0.0','0.005','0.01','0.015','0.02'});      %设置x轴的label
% set(gca,'yticklabel',{'1.0','1.5','2.0','2.5','3.0','3.5'});             %设置y轴的label

grid on                                                                    %设置网格线                                   


