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

objetivo_x = 143; % mm
objetivo_y = 0; % mm
objetivo_z = 60; % mm

#/* Junta 1 */
#define MAX_ANGLE_1 -89
t1=85*(pi/180);
t1=60*(pi/180);
#define MIN_ANGLE_1 91

#/* Junta 2 */
#define MAX_ANGLE_2 -32
t2=110*(pi/180);
t2=60*(pi/180);
#define MIN_ANGLE_2 112

#/* Junta 3 */
#define MAX_ANGLE_3 -94.5
t3=65*(pi/180);
t3=60*(pi/180);
#define MIN_ANGLE_3 67.5

[nx,ny,nz] = Dir_ARR5(h,a1,a2,a3,t1,t2,t3)
elbow=1;
[t1,t2,t3] = Inv_ARR5(h,a1,a2,a3,nx,ny,nz,elbow);



