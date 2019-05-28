#ifndef ROBOTARR5_H__
#define ROBOTARR5_H__

#include "../ARR5_Data.h"

typedef speed_t int;

class RobotARR5 {
public:
	RobotARR5(position_t initPos, int servoPins[3], int clawPin);
	void setClawClosingAngle(angle_t closingAngle);
	void closeClaw(void);
	void openClaw(void);
	position_t getCurrentPosition(void);
	void setJointSpeed(joint_t joint, speed_t speed);
	speed_t getJointSpeed(void);
	void setClawSpeed(speed_t clawSpeed);
	speed_t getClawSpeed(void);

	// Returna falso se nao consegue ir para a posicao
	bool goTo(position_t coordinates);

	// Aplica a cinematica direta
	position_t toolPosition(void);

private:
	angle_t clawClosingAngle;
	// angulo atual dos servos
	angle_t servoAngle[3];
	position_t currentCoordinates;
	// velocidades angulares das juntas
	speed_t jointSpeed[3];
	speed_t clawSpeed;
};

#endif /* end of include guard: ROBOTARR5_H__ */