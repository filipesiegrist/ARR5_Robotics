/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-08 15:11:12
*/

#ifndef ARR5_DIRECT_KINEMATICS_CPP__
#define ARR5_DIRECT_KINEMATICS_CPP__

#include <math.h>
#include "../ARR5_Data.h"
#include "ARR5_Direct_Kinematics.h"
#include "../ARR5_Angle_Conversions/degreesRadiansConversions.h"

position_t direct_kinematics(distance_t a1, distance_t a2, distance_t a3, distance_t d1, angle_t theta_1, angle_t theta_2, angle_t theta_3) {
    position_t posicao;
    distance_t aux;

    // Converting the angles to radians
    float rad_t1 = degreesToRadians(theta_1);
    float rad_t2 = degreesToRadians(theta_2);
    float rad_t3 = degreesToRadians(theta_3);

    aux = a1 + a2*cos(rad_t2) + a3*cos(rad_t2+rad_t3);
    posicao.x = cos(rad_t1)*aux;
    posicao.y = sin(rad_t1)*aux;
    posicao.z =  -1*a2*sin(rad_t2) - a3*sin(rad_t2+rad_t3) + d1;
    return posicao;    
}

#endif /* end of include guard: ARR5_DIRECT_KINEMATICS_CPP__ */
