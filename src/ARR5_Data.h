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

typedef struct position {
    distance_t x;
    distance_t y;
    distance_t z;
} position_t;


#endif /* end of include guard: ARR5_DATA_H__ */