IL = out.ILsample{1}.Values.Data;
N = length(IL);
T = 4030;
Y=[];
for i=1:T:N
    Mean_IL = mean(IL(i:1:i+T))
    Y = IL-Mean_IL;
end