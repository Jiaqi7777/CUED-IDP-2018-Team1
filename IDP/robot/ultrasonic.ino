//// defines ultrasonic pins numbers
//const int ultra_trigPin_0 = 10;
//const int ultra_echoPin_0 = 11;
//const int ultra_trigPin_1 = 12;
//const int ultra_echoPin_1 = 13;

double ultra_distance(int axis){   /*0 is the left sensor, 1 is the right sensor*/

  //define variables that will only be used inside the finction
  long duration;
  int distance;
  //left sensor                                                                                                                                                                    /???????//////                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  if(axis == 0){
  // Clears the trigPin
  digitalWrite(ultra_trigPin_0, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(ultra_trigPin_0, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultra_trigPin_0, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ultra_echoPin_0, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;
  
  // Prints the distance on the Serial Monitor
//  Serial.print("Distance from left sensor: ");
//  Serial.println(distance);
  }

  /*right sensor*/
  else if(axis == 1){
  // Clears the trigPin
  digitalWrite(ultra_trigPin_1, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(ultra_trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultra_trigPin_1, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ultra_echoPin_1, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;
  
  // Prints the distance on the Serial Monitor
//  Serial.print("Distance from right sensor: ");
//  Serial.println(distance);
 }

  else{Serial.println("Check if input is only 1 or 0");distance = 0;}
  
  //return variable
  return distance;
  }
