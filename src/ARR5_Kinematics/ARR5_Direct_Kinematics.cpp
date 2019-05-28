/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-05-28 18:37:17
*/

#ifndef ARR5_DIRECT_KINEMATICS_CPP__
#define ARR5_DIRECT_KINEMATICS_CPP__

#include "../ARR5_Data.h"
#include "ARR5_Direct_Kinematics.h"

position_t direct_kinematics(angle_t a1, angle_t a2,angle_t a3, distance_t d1) {
    position_t posicao;
    aux = a1 + a2*cos(a2) + a3*cos(a2+a3);
    posicao.x = cos(a1)*aux;
    posicao.y = sin(a1)*aux;
    posicao.z =  -a2*sin(a2) - a3*⋅sin(a2+a3) + d1;
    return posicao;    
}

#endif /* end of include guard: ARR5_DIRECT_KINEMATICS_CPP__ */
