/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-05-26 15:37:39
*/

#ifndef ARR5_DIRECT_KINEMATICS_H__
#define ARR5_DIRECT_KINEMATICS_H__

#include <math.h>
#include "../ARR5_Data.h"

position_t direct_kinematics(distance_t a1, distance_t a2,distance_t a3, distance_t d1, angle_t theta_1, angle_t theta_2, angle_t theta_3);

#endif /* end of include guard: ARR5_DIRECT_KINEMATICS_H__ */