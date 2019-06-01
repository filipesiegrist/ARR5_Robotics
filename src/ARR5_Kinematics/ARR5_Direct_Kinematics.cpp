/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-05-30 15:03:14
*/

#ifndef ARR5_DIRECT_KINEMATICS_CPP__
#define ARR5_DIRECT_KINEMATICS_CPP__

#include "../ARR5_Data.h"
#include "ARR5_Direct_Kinematics.h"

position_t direct_kinematics(distance_t a1, distance_t a2,distance_t a3, distance_t d1, angle_t theta_1, angle_t theta_2, angle_t theta_3) {
    position_t posicao;
    distance_t aux;
    aux = a1 + a2*cos(theta_2) + a3*cos(theta_2+theta_3);
    posicao.x = cos(theta_1)*aux;
    posicao.y = sin(theta_1)*aux;
    posicao.z =  -1*a2*sin(theta_2) - a3*sin(theta_2+theta_3) + d1;
    return posicao;    
}

#endif /* end of include guard: ARR5_DIRECT_KINEMATICS_CPP__ */
