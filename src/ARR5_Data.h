/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-05-26 15:37:39
*/

#ifndef ARR5_DATA_H__
#define ARR5_DATA_H__

typedef angle_t float;
typedef distance_t float;

typedef struct position {
    distance_t x;
    distance_t y;
    distance_t z;
} position_t;

position_t direct_kinematics(angle_t a1,angle_t a2,angle_t a3) {
    
}


#endif /* end of include guard: ARR5_DATA_H__ */