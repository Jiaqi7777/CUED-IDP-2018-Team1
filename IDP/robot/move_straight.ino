//////-----------------------derivative control --------------------------
void move_straight(double straight_speed){
  
  //get error
  double right_distance1,right_distance2;
  double e;
  right_distance1 = ultra_distance(1); //read right distance
  delay(80);
  right_distance2 = ultra_distance(1); //read the right distance after t = 80
  e = (right_distance2 - right_distance1);
  
  double PID;
  double kd = 10;
  
  //calculate PID
  if(abs(e) > 4){PID = 0;}
  else{PID = kd * e;}
    
  //control motors
  move_forward(straight_speed + PID , straight_speed - PID);                                                    
  delay(80);
  }

// //--------------------------proportional control ----------------------------------

//void move_straight(int straight_speed){
//  int kp = 2;
//  double d,e, PID;
//  d = ref_distance[n];
//  e = ultra_distance(1) -d;
////  Serial.println(e);
//  if (e>15){PID=0;}
//  else {PID = kp * e;}
//    
////  PID = kp * e;
//  move_forward(straight_speed + PID , straight_speed - PID);  
//  delay(50);
//  }
