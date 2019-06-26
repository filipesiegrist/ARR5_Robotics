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
#include <QueueArray.h>

QueueArray <robot_angles_t> A_queue1;
QueueArray <angle_t> G_queue1;

QueueArray <robot_angles_t> A_queue2;
QueueArray <angle_t> G_queue2;

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

//SERVOS PINS
int jointPin[4] = {8,10,9,7};

distance_t a1 = 15;
distance_t a2 = 45;
distance_t a3 = 83;
distance_t h = 85;
//orientacao cotovelo
basic_orientation_t orientacao = ELBOW_UP;

//angulo objetivo
angle_t Angulo;

//angulo e posicao atual
robot_angles_t Ang_Atual;
position_t Pos_Atual;
angle_t Garra_Atual;


bool Move(angle_t Angulo,joint_t JUNTA){
	int servo_angle;
	if (JUNTA == CLAW)servo_angle = (int)Angulo;
    else {
		servo_angle = jointConversion[JUNTA](Angulo);
    }
	jointServo[JUNTA].slowmove(servo_angle, SPEED);
	return true;
}

void MoveTudo(void){
	int S_Junta1 = Serial.parseInt();
	int S_Junta2 = Serial.parseInt();
	int S_Junta3 = Serial.parseInt();
	int S_Garra  = Serial.parseInt();

	if(S_Junta1>-89 && S_Junta1 <91){
		Move(S_Junta1,JUNTA_1);
		Ang_Atual.theta_1 = S_Junta1;
	}
	else Serial.print("J1 ");

	if(S_Junta2>-32 && S_Junta2 <112){
		Move(S_Junta2,JUNTA_2);
		Ang_Atual.theta_2 = S_Junta2;
	}
	else Serial.print("J2 ");

	if(S_Junta3>-94.5 && S_Junta3 <67.5){
		Move(S_Junta3,JUNTA_3);
		Ang_Atual.theta_3 = S_Junta3;
	}
	else Serial.print("J3 ");

	if(S_Garra>25 && S_Garra <60){
		Move(S_Garra,CLAW);
		Garra_Atual=S_Garra;
	}
	else Serial.print("G");

	Serial.println();
	return;
}
typedef enum cmd {
	Junta1 = 1,
	Junta2 = 2,
	Junta3 = 3,
	Garra = 4,

	Save = 5,
	Start = 6,
	Reset = 7,

	X_more = 8,
	X_less = 9,

	Y_more = 10,
	Y_less = 11,

	Z_more = 12,
	Z_less = 13,

	Print_pos = 55,
	Print_ang = 66,

	MoveAngulos = 88
}cmd_t;

int saves=0;
cmd_t comando;
int stop;

void COMUNICACAO(){
	if (Serial.available() <= 0) return;
	comando = (cmd_t)Serial.parseInt();

	switch(comando){
		case Junta1:
		Angulo = (angle_t)Serial.parseInt();
		if(Angulo<=MAX_ANGLE_1 || Angulo >=MIN_ANGLE_1){
			Serial.println("junta 1 ERROR");
			break;
		}
		Move(Angulo,JUNTA_1);
		Ang_Atual.theta_1 = Angulo;
		Serial.println("junta 1 alterada");
		break;

		case Junta2:
		Angulo = (angle_t)Serial.parseInt();
		if(Angulo<=MAX_ANGLE_2 || Angulo >=MIN_ANGLE_2){
			Serial.println("junta 2 ERROR");
			break;
		}
		Move(Angulo,JUNTA_2);
		Ang_Atual.theta_2 = Angulo;
		Serial.println("junta 2 alterada");
		break;

		case Junta3:
		Angulo = (angle_t)Serial.parseInt();
		if(Angulo<=MAX_ANGLE_3 || Angulo >=MIN_ANGLE_3){
			Serial.println("junta 3 ERROR");
			break;
		}
		Move(Angulo,JUNTA_3);
		Ang_Atual.theta_3 = Angulo;
		Serial.println("junta 3 alterada");
		break;

		case Garra:
		Angulo = (angle_t)Serial.parseInt();
		if(Angulo<=25 || Angulo >=60){
			Serial.println("garra ERROR");
			break;
		}
		Move(Angulo,CLAW);
		Garra_Atual=Angulo;
		Serial.println("garra alterada");
		break;

		case Save:
		if(saves==15){
			Serial.println("fila cheia");
			break;
		}
    	saves++;
    	A_queue1.enqueue(Ang_Atual);
		G_queue1.enqueue(Garra_Atual);
		Serial.print(saves);
    	Serial.println(" movimento(s) salvo(s)");
		break;

		case Start:
    	Serial.println("Start moves");
		while(stop!=404){
			if (Serial.available() > 0){
				stop = Serial.parseInt();
			}
			while (!A_queue1.isEmpty ()){
				if(A_queue1.isEmpty())break;
				// Serial.print("A_queue1.theta_1 = ");
				// Serial.println(A_queue1.front().theta_1);
				// Serial.print("A_queue1.theta_2 = ");
				// Serial.println(A_queue1.front().theta_2);
				// Serial.print("A_queue1.theta_3 = ");
				// Serial.println(A_queue1.front().theta_3);
				// Serial.print("Garra = ");
				// Serial.println(G_queue1.front());
				Move(A_queue1.front().theta_1,JUNTA_1);
				Move(A_queue1.front().theta_2,JUNTA_2);
				Move(A_queue1.front().theta_3,JUNTA_3);
    			A_queue2.enqueue(A_queue1.dequeue());
				Move(G_queue1.front(),CLAW);
    			G_queue2.enqueue(G_queue1.dequeue());
 			}
			while (!A_queue2.isEmpty ()){
    			//Serial.print (queue.front ());
    			A_queue1.enqueue(A_queue2.dequeue());
				G_queue1.enqueue(G_queue2.dequeue());
 			}
 		}
		stop=0;
 		Serial.println("Stop moves");
		break;

		case Reset:
		Serial.println("Reset moves");
		//esvazia queue
		while (!A_queue1.isEmpty ()){
    		A_queue1.dequeue();
			G_queue1.dequeue();
 		}
    	saves=0;
		break;

		case X_more:
		Serial.println("move + X");
		//acrescenta em X
		break;

		case X_less:
		Serial.println("move - X");
		//diminui em X
		break;
		
		case Y_more:
		Serial.println("move + Y");
		//acrescenta em Y
		break;

		case Y_less:
		Serial.println("move -Y");
		//diminui em Y
		break;

		case Z_more:
		Serial.println("move + Z");
		//acrescenta em Z
		break;

		case Z_less:
		Serial.println("move - Z");
		//acrescenta em Z
		break;

		case Print_pos:
		Serial.print("Pos x = ");
		Serial.println(Pos_Atual.x);
		Serial.print("Pos y = ");
		Serial.println(Pos_Atual.y);
		Serial.print("Pos z = ");
		Serial.println(Pos_Atual.z);
		break;

		case Print_ang:
		Serial.print("Junta 1 = ");
		Serial.println(Ang_Atual.theta_1);
		Serial.print("Junta 2 = ");
		Serial.println(Ang_Atual.theta_2);
		Serial.print("Junta 3 = ");
		Serial.println(Ang_Atual.theta_3);
		Serial.print("Garra = ");
		Serial.println(Garra_Atual);
		break;

	case MoveAngulos:
    Serial.print("Erros ");
		MoveTudo();
	break;

    case 404:
    Serial.println("Stop moves");
    break;
    
		default:
		//Serial.println("COMANDO LIBERADO");
		break;
	}
	Pos_Atual = direct_kinematics(a1, a2, a3, h, Ang_Atual.theta_1, Ang_Atual.theta_2, Ang_Atual.theta_3);
	return;
}

void setup() {
	//inisia serial
	Serial.begin(9600);
  	// set the printer of the queue.
  	A_queue1.setPrinter (Serial);
  	A_queue2.setPrinter (Serial);
	//referencia os pinos para as juntas
	jointServo[JUNTA_1].attach(jointPin[JUNTA_1]);
	jointServo[JUNTA_2].attach(jointPin[JUNTA_2]);
	jointServo[JUNTA_3].attach(jointPin[JUNTA_3]);
	jointServo[CLAW].attach(jointPin[CLAW]);
	//posicao inicial
	Ang_Atual.theta_1 = 0;
	Ang_Atual.theta_2 = 0;
	Ang_Atual.theta_3 = 0;
	Garra_Atual=25;
	Move(Ang_Atual.theta_1,JUNTA_1);
	Move(Ang_Atual.theta_2,JUNTA_2);
	Move(Ang_Atual.theta_3,JUNTA_3);
	Move(Garra_Atual,CLAW);
}

void loop() {
  	COMUNICACAO();
	//delay(2);
}
