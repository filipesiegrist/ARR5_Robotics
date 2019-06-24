#include <ARR5_Angle_Conversions.h>
#include <ARR5_Joint_Limits.h>
#include <degreesRadiansConversions.h>
#include <ARR5_Working_Space.h>
#include <ARR5_Direct_Kinematics.h>
#include <ARR5_Data.h>
#include <ARR5_Trajectory_Planning.h>
#include <ARR5_Inverse_Kinematics.h>

#include <VarSpeedServo.h>
#include <ARR5_Angle_Conversions.h>

typedef enum JOINTS {
	JUNTA_1 = 0,
	JUNTA_2 = 1,
	JUNTA_3 = 2,
	CLAW = 3
}joint_t;


//conversor de angulos
int (*jointConversion[3])(angle_t a) = {
	fromJointToServoBase,
	fromJointToServoShoulder,
	fromJointToServoElbow
};

VarSpeedServo jointServo[4];   // create servo object to control a servo



#define SPEED 100

joint_t myJoint;

//SERVOS PINS
int jointPin[4] = {11, 9, 8, 10};
//----------------------------------

distance_t a1 = 15;
distance_t a2 = 45;
distance_t a3 = 83;
distance_t h = 85;
//orientacao cotovelo
basic_orientation_t orientacao = ELBOW_UP;
//angulo e posicao objetivo
robot_angles_t Ang_Objetivo;
position_t Pos_Objetivo;
//angulo e posicao atual
robot_angles_t Ang_Atual;
position_t Pos_Atual;


angle_t Garra;


void setup() {
	//inisia serial
	Serial.begin(19200);
	//referencia os pinos para as juntas
	jointServo[JUNTA_1].attach(jointPin[JUNTA_1]);
	jointServo[JUNTA_2].attach(jointPin[JUNTA_2]);
	jointServo[JUNTA_3].attach(jointPin[JUNTA_3]);
	jointServo[CLAW].attach(jointPin[CLAW]);
	//deley
	delay(15);
	Ang_Objetivo.theta_1=60;
	Ang_Objetivo.theta_2=60;
	Ang_Objetivo.theta_3=60;
	mover(Ang_Atual,Garra);	
}

void mover(robot_angles_t Ang_Atual,angle_t Garra){
	jointServo[JUNTA_1].slowmove((int)Ang_Atual.theta_1, SPEED);
	delay(15);
	jointServo[JUNTA_2].slowmove((int)Ang_Atual.theta_2, SPEED);
	delay(15);
	jointServo[JUNTA_3].slowmove((int)Ang_Atual.theta_3, SPEED);
	delay(15);
	jointServo[ CLAW  ].slowmove((int)Garra, SPEED);
	delay(15);
}


void COMUNICACAO(){
	if (Serial.available()==0) return;
	int cmd;
	distance_t cmdx, cmdy, cmdz;
	cmd  = Serial.parseInt();
	cmdx = (distance_t)Serial.parseInt();
	cmdy = (distance_t)Serial.parseInt();
	cmdz = (distance_t)Serial.parseInt();
	switch (cmd)
	{
		case 0:
			//move pra x y z
			Pos_Objetivo.x = cmdx;
			Pos_Objetivo.y = cmdy;
			Pos_Objetivo.z = cmdz;
		break;

	   	case 1:
			//move x
			Pos_Objetivo.x = cmdx;
		break;

	  	case 2:
			//move y
	  		Pos_Objetivo.y = cmdy;
		break;

		case 3:
			//move z
	  		Pos_Objetivo.z = cmdz;
		break;

		case 4:
			//save
		break;

		case 6:
			//start
		break;	

		case 7:
			//reset
		break;	

	 	default:
			//Instruções;
		break;
	}
  	if(!is_point_on_working_space(h, a1, a2, a3, Pos_Objetivo, orientacao))return;
	Ang_Atual = inverse_kinematics(h, a1, a2, a3, Pos_Objetivo, orientacao);
	Pos_Atual = direct_kinematics(a1, a2, a3, h, Ang_Atual.theta_1, Ang_Atual.theta_2, Ang_Atual.theta_3);
	return;
}

void loop() {
  	COMUNICACAO();
	delay(15);
}
