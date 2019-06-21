/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-09 22:09:07
*/

#ifndef ARR5_INVERSE_KINEMATICS_CPP__
#define ARR5_INVERSE_KINEMATICS_CPP__

#include <stdio.h>

#include <cmath>
#include "../ARR5_Data.h"
#include "../ARR5_Angle_Conversions/degreesRadiansConversions.h"

#include <iostream>
using namespace std;

// Funcao que calcula o quadrado.
distance_t SQ(distance_t X){
    return pow(X, 2);
}

robot_angles_t inverse_kinematics(distance_t d1, distance_t a1, distance_t a2, distance_t a3, position_t point, basic_orientation_t elbow_up_or_down=ELBOW_DOWN) {
	// ELBOW_UP = -1,
	// ELBOW_DOWN = 1
    // elbow_up_or_down=ELBOW_DOWN;

    distance_t pwx = point.x;
	distance_t pwy = point.y;
	distance_t pwz = point.z;

	robot_angles_t angles_out;
    angles_out.theta_1 = 0;
	angles_out.theta_2 = 0;
	angles_out.theta_3 = 0;

	distance_t pwh = sqrt(abs(SQ(pwx)+SQ(pwy))) - a1;
    distance_t pwz1=pwz;
    pwz = pwz - d1;
    

    float c3 = (SQ(pwh) + SQ(pwz) - SQ(a2) - SQ(a3)) / (2*a2*a3);
    //Verificar se o cosseno esta entre menos um e um!
    if(c3 > 1 || c3 < -1){
        cout << "Erro: Fora do espaço de trabalho do robo." << endl;
    }


    float s3 = sqrt(abs(1-SQ(c3)))*elbow_up_or_down; // pode ser negativo
    float rad_th_3 = atan2(s3,c3);


    float cphi = (SQ(pwh) + SQ(pwz) + SQ(a2) - SQ(a3)) / (2*a2*sqrt(abs(SQ(pwh)+SQ(pwz))));
    //Verificar se o cosseno esta entre menos um e um!
    if(cphi > 1 || cphi < -1){
        cout << "Erro: Fora do espaço de trabalho do robo." << endl;
    } 

    if(cphi>1)cphi=1;
    if(cphi<-1)cphi=-1;
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

    // cout << "pwh = " << pwh << endl;
    // cout << "pwz0 = " << pwz1 << endl;
    // cout << "pwz = " << pwz << endl;
    // cout << "c3 = " << c3 << endl;
    // cout << "s3 = " << s3 << endl;
    // cout << "th_3 = " << rad_th_3<< endl;
    // cout << "cp = " << cphi << endl;
    // cout << "p = " << phi << endl;
    // cout << "b = " << beta<< endl;
    // cout << "th_2 = " << rad_th_2 << endl;
    // cout << "th_1 = " << rad_th_1 << endl;
    // cout << "th_1 = " << rad_th_1 << endl;
    // cout << "a_th_1 = " << th_1 << endl;
    // cout << "a_th_2 = " << th_2 << endl;
    // cout << "a_th_3 = " << th_3 << endl;

	return angles_out;
}

// int main(void)
// {
//     distance_t a1 = 14.53;
//     distance_t a2 = 45.00;
//     distance_t a3 = 83.00;
//     distance_t d1 = 85;
//     position_t point;
//     // !! fora da área de espaco !!
//     // point.x=143;
//     // point.y=0;
//     // point.z=85;

//     // point.x =  43.044;
//     // point.y = -118.26;
//     // point.z =  149.00;
    
//     // point.x = -7.2405;
//     // point.y = -82.759;
//     // point.z =  134.52;

//     // !! esses estão certos !!
//     // point.x = 2.1656;
//     // point.y = -12.282;
//     // point.z = -9.3801;

//     // point.x =  59.999;
//     // point.y =  59.999;
//     // point.z =  60.002;
//     //basic_orientation_t ELBOW_UP ou ELBOW_DOWN
//     robot_angles_t angles_out=inverse_kinematics(d1,a1,a2,a3,point,ELBOW_DOWN);

// 	return 0;
// }

#endif /* end of include guard: ARR5_INVERSE_KINEMATICS_H_CPP */
