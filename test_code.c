#include <stdio.h>
#include "src/ARR5_Data.h"
#include "src/ARR5_Kinematics/ARR5_Direct_Kinematics.h"
#include "src/ARR5_Kinematics/ARR5_Inverse_Kinematics.h"
#include "src/ARR5_Angle_Conversions/degreesRadiansConversions.h"

int main(void) {

	// Main para teste do código

	angle_t theta_1, theta_2, theta_3;
	distance_t a1, a2, a3, d1;
	position_t pos;
	robot_angles_t angles;

	// Parametros do robô:
	a1 = 15;
	a2 = 45;
	a3 = 83;
	
	d1 = 85;
	
	// Ponto que quero alcancar
	distance_t objetivo_x = 60;
	distance_t objetivo_y = 20;
	distance_t objetivo_z = 60;

	pos.x = objetivo_x;
	pos.y = objetivo_y;
	pos.z = objetivo_z;

	printf("Coordinates 1: %lf, %lf, %lf\n", pos.x, pos.y, pos.z);
	angles = inverse_kinematics(d1, a1, a2, a3, pos, ELBOW_DOWN);
	printf("Angles: %lf, %lf, %lf\n", angles.theta_1, angles.theta_2, angles.theta_3);

	pos = direct_kinematics(a1, a2, a3, d1, angles.theta_1, angles.theta_2, angles.theta_3);
	printf("Coordinates 2: %lf, %lf, %lf\n", pos.x, pos.y, pos.z);
	return 0;
}