/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-05-26 15:37:39
*/

#ifndef ARR5_DATA_H__
#define ARR5_DATA_H__

typedef float angle_t;
typedef float distance_t;

typedef  enum{JOINT_1,JOINT_2,JOINT_3} joints_t;

// Se quero o cotovelo pra cima, uso 1, senao uso -1.
typedef enum basic_orientation{
	ELBOW_UP = -1,
	ELBOW_DOWN = 1
} basic_orientation_t;

typedef struct position {
    distance_t x;
    distance_t y;
    distance_t z;
} position_t;

typedef struct robot_angles {
	angle_t theta_1;
	angle_t theta_2;
	angle_t theta_3;
} robot_angles_t;


#endif /* end of include guard: ARR5_DATA_H__ */