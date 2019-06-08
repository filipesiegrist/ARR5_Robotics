#include <stdio.h>
#include "src/ARR5_Data.h"
#include "src/ARR5_Kinematics/ARR5_Direct_Kinematics.h"

int main(void) {
	angle_t theta_1, theta_2, theta_3;
	distance_t a1, a2, a3, d1;
	position_t pos;
	theta_1 = 0;
	theta_2 = 0;
	theta_3 = 0;
	a1 = 20;
	a2 = 10;
	a3 = 20;
	d1 = 5;
	pos = direct_kinematics(a1, a2, a3, d1, theta_1, theta_2, theta_3);
	printf("Coordinates: %lf, %lf, %lf\n", pos.x, pos.y, pos.z);
	return 0;
}