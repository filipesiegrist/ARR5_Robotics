#ifndef __ARR5_WORKING_SPACE_CPP__
#define __ARR5_WORKING_SPACE_CPP__

#include "../ARR5_Data.h"
#include "../ARR5_Angle_Conversions/degreesRadiansConversions.h"
#include "../ARR5_Angle_Conversions/ARR5_Joint_Limits.h"
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
// Funcao que calcula o quadrado.
distance_t SQ(distance_t X);

bool is_point_on_working_space(distance_t d1, distance_t a1, distance_t a2, distance_t a3, position_t point, basic_orientation_t elbow_up_or_down) {

    distance_t pwx = point.x;
	distance_t pwy = point.y;
	distance_t pwz = point.z;

	robot_angles_t angles_out;

	distance_t pwh = sqrt(SQ(pwx)+SQ(pwy)) - a1;
    distance_t pwz1=pwz;
    pwz = pwz - d1;
    

    float c3 = (SQ(pwh) + SQ(pwz) - SQ(a2) - SQ(a3)) / (2*a2*a3);
	if(c3>1 || c3<-1)return false;
    //Verificar se o cosseno esta entre menos um e um!

    float s3 = sqrt(abs(1-SQ(c3)))*elbow_up_or_down; // pode ser negativo
    float rad_th_3 = atan2(s3,c3);


    float cphi = (SQ(pwh) + SQ(pwz) + SQ(a2) - SQ(a3)) / (2*a2*sqrt(SQ(pwh)+SQ(pwz)));
	if(cphi>1 || cphi<-1)return false;
    //Verificar se o cosseno esta entre menos um e um!

    float phi = acos(cphi);
    float beta = atan2(pwz,pwh);
    float rad_th_2 = beta - phi*elbow_up_or_down;
    float rad_th_1 = atan2(pwy,pwx);
    
    angle_t th_1= (angle_t) radiansToDegrees(rad_th_1);
    angle_t th_2= (angle_t) radiansToDegrees(rad_th_2);
    angle_t th_3= (angle_t) radiansToDegrees(rad_th_3);

    angles_out.theta_1 = th_1;
	angles_out.theta_2 = th_2;
	angles_out.theta_3 = th_3;

    if(th_1 > MAX_ANGLE_1 || th_1 < MIN_ANGLE_1)return false;
    if(th_2 > MAX_ANGLE_2 || th_2 < MIN_ANGLE_2)return false;
    if(th_3 > MAX_ANGLE_3 || th_3 < MIN_ANGLE_3)return false;

    cout << "pwh = " << pwh << endl;
    cout << "pwz0 = " << pwz1 << endl;
    cout << "pwz = " << pwz << endl;
    cout << "c3 = " << c3 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "th_3 = " << rad_th_3<< endl;
    cout << "cp = " << cphi << endl;
    cout << "p = " << phi << endl;
    cout << "b = " << beta<< endl;
    cout << "th_2 = " << rad_th_2 << endl;
    cout << "th_1 = " << rad_th_1 << endl;
    cout << "th_1 = " << rad_th_1 << endl;
    cout << "a_th_1 = " << th_1 << endl;
    cout << "a_th_2 = " << th_2 << endl;
    cout << "a_th_3 = " << th_3 << endl;	
	
	return true;
}
// int main(void)
// {
//     distance_t a1 = 14.53;
//     distance_t a2 = 45.00;
//     distance_t a3 = 83.00;
//     distance_t d1 = 85;
//     position_t point;
//     point.x=143;
//     point.y=0;
//     point.z=85;
//     //basic_orientation_t ELBOW_UP ou ELBOW_DOWN
//     if(is_point_on_working_space(d1,a1,a2,a3,point,ELBOW_DOWN))
// 	cout << "true" << endl;
// 	else cout << "false" << endl;

// 	return 0;
// }

#endif