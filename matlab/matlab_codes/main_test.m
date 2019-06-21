%
% @Author: Filipe Ernesto Siegrist Gonçalves
% @Date:   2019-05-12 23:39:39
% @Last Modified by:   filipe-ufsc
% @Last Modified time: 2019-05-12 23:39:39
%
clear; clc;
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

#/* Junta 1 */
# -89< t1 < 91
t1 = -120.00*(pi/180);

#/* Junta 2 */
# -32 < t2 < 112
t2 =  54.481*(pi/180);

#/* Junta 3 */
# -94.5 < t3 < 67.5
t3 =  62.104*(pi/180);

elbow=1;
[nx,ny,nz] = Dir_ARR5(h,a1,a2,a3,t1,t2,t3)
[t1,t2,t3] = Inv_ARR5(h,a1,a2,a3,nx,ny,nz,elbow);


