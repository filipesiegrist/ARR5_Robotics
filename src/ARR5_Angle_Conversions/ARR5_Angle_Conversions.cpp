/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 16:48:02
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-01 20:50:33
*/
#ifndef ARR5_ANGLE_CONVERSIONS_CPP__
#define ARR5_ANGLE_CONVERSIONS_CPP__

#include "../ARR5_Data.h"

int fromJointToServoBase(angle_t baseAngle) {
	return (int) (baseAngle - 89);
}

int fromJointToServoShoulder(angle_t shoulderAngle) {
	return (int) (1.25*shoulderAngle + 40);
}

int fromJointToServoElbow(angle_t elbowAngle) {
	#define B 1.11111111
	#define A 105
	return (int) (B*elbowAngle + A);
}

#endif /* end of include guard: ARR5_ANGLE_CONVERSIONS_CPP__ */