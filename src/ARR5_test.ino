/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/


//include <PWMServo.h>
#include <VarSpeedServo.h>
#include <ARR5_Angle_Conversions.h> 

VarSpeedServo jointServo[4];   // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

int servo = 1;
int joint_angle = 0;
int servo_angle = 0;

typedef enum JOINTS {
  JOINT_1 = 0,
  JOINT_2 = 1,
  JOINT_3 = 2,
  CLAW = 3
} joint_t;

#define SPEED 100

int jointPin[4] = {11, 9, 8, 10};
joint_t myJoint;

int (*jointConversion[3])(angle_t a) = {
  fromJointToServoBase,

  fromJointToServoShoulder,

  fromJointToServoElbow
};

void setup() {
  Serial.begin(19200);
  jointServo[JOINT_1].attach(jointPin[JOINT_1]);
  jointServo[JOINT_2].attach(jointPin[JOINT_2]);
  jointServo[JOINT_3].attach(jointPin[JOINT_3]);
  jointServo[CLAW].attach(jointPin[CLAW]);  
  delay(15);
}

void loop() {
  if (Serial.available() > 0) {
    myJoint = (joint_t) Serial.parseInt();
    joint_angle = Serial.parseInt();
    if (myJoint == CLAW) {
      servo_angle = joint_angle;
    }
    else {
      servo_angle = (jointConversion[myJoint])(joint_angle);
    }
    jointServo[myJoint].slowmove(servo_angle, SPEED);
    Serial.println(myJoint);
    Serial.println(servo_angle);
    Serial.println(joint_angle);
    delay(15);   
  }
  else {
   //myservo.write(angle);
   delay(15); 
  }// waits for the servo to get there
}
