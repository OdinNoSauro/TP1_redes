clear
close all
clc

T=50; % período de simulação
x0=[1/3;3/5;5/7;7/9;9/11];
r=4;
x=[x0; x0+1e-4]; % concatenação de vetores coluna

X=x;
for it=1:T-1
    x=r*x.*(1-x);
    X=[X x];
end

tempo = (1:T)-1;
for i=1:size(x0,1)
    subplot(size(x0,1), 2, 2*i - 1)
    stem(tempo,X(i,:))
    title(['x0=' num2str(x0(i))])
    subplot(size(x0,1), 2, 2*i)
    stem(tempo,X(i+size(x0,1),:));
end

print -dpdf simulamapalogistico4
