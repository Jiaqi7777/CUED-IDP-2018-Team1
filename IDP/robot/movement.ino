#include <Wire.h>
#include <Adafruit_MotorShield.h>
void move_forward(int v_A, int v_B){
  
    Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
    Adafruit_DCMotor *myMotorA = AFMS.getMotor(1);
    Adafruit_DCMotor *myMotorB = AFMS.getMotor(2);
    // create with the default frequency 1.6KHz
    AFMS.begin(); 

  //check if both input speed are positive
  if(v_A >=0 and v_B >=0){
    myMotorA->setSpeed(abs(v_A)); myMotorB->setSpeed(abs(v_B));
    myMotorA->run(FORWARD);myMotorB->run(FORWARD);
    }

  else if(v_A <0 and v_B >=0){
    myMotorA->setSpeed(abs(v_A)); myMotorB->setSpeed(abs(v_B));
    myMotorA->run(BACKWARD);myMotorB->run(FORWARD);
    }
   else if(v_A >=0 and v_B <0){
    myMotorA->setSpeed(abs(v_A)); myMotorB->setSpeed(abs(v_B));
    myMotorA->run(FORWARD);myMotorB->run(BACKWARD);
    }

    else if(v_A <0 and v_B <0){
    myMotorA->setSpeed(abs(v_A)); myMotorB->setSpeed(abs(v_B));
    myMotorA->run(BACKWARD);myMotorB->run(BACKWARD);
    }
  }
 void turn_left(int v_A, int v_B){
  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
  Adafruit_DCMotor *myMotorA = AFMS.getMotor(1);
  Adafruit_DCMotor *myMotorB = AFMS.getMotor(2);
  // create with the default frequency 1.6KHz
  AFMS.begin();  
  myMotorA->setSpeed(abs(v_A)); myMotorB->setSpeed(abs(v_B));
  myMotorA->run(BACKWARD);myMotorB->run(FORWARD);
  }

void turn_right(int v_A, int v_B){
  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
  Adafruit_DCMotor *myMotorA = AFMS.getMotor(1);
  Adafruit_DCMotor *myMotorB = AFMS.getMotor(2);
  // create with the default frequency 1.6KHz
  AFMS.begin();  
  myMotorA->setSpeed(abs(v_A)); myMotorB->setSpeed(abs(v_B));
  myMotorA->run(FORWARD);myMotorB->run(BACKWARD);
  }

void stop_both(){
  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
  Adafruit_DCMotor *myMotorA = AFMS.getMotor(1);
  Adafruit_DCMotor *myMotorB = AFMS.getMotor(2);
  // create with the default frequency 1.6KHz
  AFMS.begin(); 
  myMotorA->run(RELEASE); myMotorB->run(RELEASE);
  }
