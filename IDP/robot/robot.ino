#include<Servo.h>
Servo myservo;
//----------------------------initialise variables-----------------------------
//The length of the test field
const double Lx = 240, Ly = 240;
const double l_arm = 0;

//define timer 
//long t = millis();
double center_range=120*120;

//initialise number of turns
int n = 0;

// defines ultrasonic pins numbers
/*0 is the left sensor, 1 is the right sensor*/
const int ultra_trigPin_0 = 10;
const int ultra_echoPin_0 = 11;
const int ultra_trigPin_1 = 12;
const int ultra_echoPin_1 = 13;

//set the margin distance 
double margin_distance = 30;

bool lastRound = false;

//reference distance list
double ref_distance[13] = {22,23,168,74,117,125,66,176,15};

//define max LDR reading variable
int max_reading = 0;

//----------------------------setup-----------------------------

void setup(){
  Serial.begin(9600);
//  Serial.println(n);
  //Set up left ultrasonic sensor
  pinMode(ultra_trigPin_0, OUTPUT); // Sets the trigPin as an Output
  pinMode(ultra_echoPin_0, INPUT); // Sets the echoPin as an Input

  //Set up right ultrasonic sensor
  pinMode(ultra_trigPin_1, OUTPUT); // Sets the trigPin as an Output
  pinMode(ultra_echoPin_1, INPUT); // Sets the echoPin as an Input

  //set up LED pin mode
  pinMode(52,OUTPUT);
  pinMode(53,OUTPUT);

  //set up servo
  myservo.attach(9);
  myservo.write(90);
}

//------------------------main loop--------------------------------
void loop(){            
   while(true){                       
   move_straight(100);
   detect();
   zigzag();
   go_back();
   }
}
  
