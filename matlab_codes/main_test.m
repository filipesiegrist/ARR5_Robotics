%
% @Author: Filipe Ernesto Siegrist Gonçalves
% @Date:   2019-05-12 23:39:39
% @Last Modified by:   filipe-ufsc
% @Last Modified time: 2019-05-12 23:39:39
%
clear;
warning('off','all');

% Main para teste do código

%Parametros do robô:
a1 = 15; % mm
a2 = 45; % mm
a3 = 83; % mm

h = 85; % mm

objetivo_x = 60; % mm
objetivo_y = 60; % mm
objetivo_z = 60; % mm

[t1,t2,t3] = Inv_ARR5(h,a1,a2,a3,objetivo_x,objetivo_y,objetivo_z)

[nx,ny,nz] = Dir_ARR5(h,a1,a2,a3,t1,t2,t3)

