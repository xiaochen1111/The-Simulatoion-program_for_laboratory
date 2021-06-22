% Picture Beautiful
% Picture_LCF
PPP = PPP+1;
switch PPP
    case {1}
    plt.Color = [0.8500 0.3250 0.0980];
    case {2}
    plt.Color = [0 0.4470 0.7410];
    case {3}
    plt.Color = [0.4660 0.6740 0.1880];
    otherwise
    plt.Color = [0.3010 0.7450 0.9330];
end
% plt.Color = [0.4660 0.6740 0.1880];                                      % set the color of picture
plt.LineWidth = 1.8000;                                                    % set the linewidth of picture
plt.MarkerSize = 10;                                                       % set the markersize of picture
% plt.Marker = '_';
set(gca,'FontSize',15);


% ylabel('Inductor Current(A)','FontSize',15,'LineWidth',8)                                              % set the label of  y axis                 
xlabel('Time(s)','FontSize',15,'LineWidth',8)                                           % set the label of  x axis 
set(gca,'FontName','Helvetica');                                           %�������������СΪ18�ţ�����ΪHelverica
set(gca,'linewidth',1.5);                                                  %����ͼ����߿�1.5
set(gcf,'position',[0 0 650 400]);                                         %���û�����СΪ��650*��450
% set(gca,'XLim',[0,0.02])                                                  %����y��ķ�Χ
% set(gca,'xticklabel',{'0.0','0.005','0.01','0.015','0.02'});      %����x���label
% set(gca,'yticklabel',{'1.0','1.5','2.0','2.5','3.0','3.5'});             %����y���label
% set(gca,'ytick',0:100:2500)
grid on                                                                    %����������                                   


