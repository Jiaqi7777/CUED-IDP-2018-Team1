//--------------set the colour sensor range -------------------------
int black_min = 0, black_max =700;
int red_min =700, red_max =920;
int yellow_min = 920 , yellow_max =1000;

//---------------------old object detected ----------------------------
bool object_detected(int max_reading){
  if(max_reading <= black_max or ultra_distance(1) <= 35 or Lx - ultra_distance(1) <= 35){
    return false;
    }
  else{return true;}
  }

//-------------------new object detected ------------------------------
bool new_object_detected(){
  bool isObject = false;
  double ave;
  int LDR_reading;
  //check is the robot is on the white line

  if((ultra_distance(1) <= 30) or (ultra_distance(0)<30) or ((Lx - ultra_distance(1)) <= 75)){
    // if the robot is on the white line, it is not detecting anything
    return false;}

  // if the robot is not on the white line
  else{ 
//    ave = (analogRead(0) + analogRead(1) + analogRead(2) + (analogRead(3)+70))/4; 
     /*this is the ideal case*/

    ave = (analogRead(0) + analogRead(1) + analogRead(2))/3;  /*ignore LDR 3 coz it 
    is a faulty one and we don't have time to change it without fucking up other sensors*/
    
    for(int i = 0; i < 3; i++){
      if(i == 3){LDR_reading = analogRead(3) +70;}
      else{LDR_reading = analogRead(i); }
    if(abs(LDR_reading - ave) > 18){
      //if there is an anomaly reading, we know there is a different color detected
      isObject = true;
         }  
      }
    return isObject;
  }
}


  
//-----------------------color code---------------------------------------
int colour_code(int max_reading){
  //Red is 1
  if( max_reading < red_max){
    return 1;
    }
  //Yellow is 2
  else if(max_reading >= yellow_min and max_reading <= yellow_max){
    return 2;
    }
  else{
    return 0;
    }
  }
  
//-----------------------------bypass function --------------------------------  
void bypass(){
  turn_right(120,120); //turn right
  delay(1500);
  move_forward(0,0); //stop
  delay(500);
  move_forward(150,150);
  delay(1000);  
  move_forward(50,190); //move straight
  delay(5000);
  move_forward(0,0); //stop
  delay(500);
  turn_right(200,50);
  delay(1500);
  move_forward(0,0); //stop
  delay(500);
  digitalWrite(52,LOW);
  }
  
//-----------------detect function-------------------------------
void detect(){
  bool isRed = false;
  bool isObject;
  int max_reading = 0; 
  int LDR_reading;
    if(new_object_detected()){
    
      
      // if object is detected, move forward a little bit to check the reading
      move_forward(30,30);
      delay(100);
      move_forward(0,0);
      delay(1000);

      for(int pos = 60; pos <140; pos +=1){
          //get max_reading
          myservo.write(pos);
          delay(50);
          for(int i = 0; i < 3; i++){

              //offset LDR 3
              if(i ==3){LDR_reading = analogRead(3) +70;}
              else{LDR_reading = analogRead(i);}

              //update max LDR reading
              if(max_reading < LDR_reading){
              max_reading = LDR_reading;  
              }
          }
         myservo.write(90);  //move servo back to original position
       }
     
      if(colour_code(max_reading) == 1){
        digitalWrite(52,HIGH);
        Serial.println("light RED");
        get_coordinate(1);
        isRed = true;
        }
       else if(colour_code(max_reading) == 2){
        //if yellow
        digitalWrite(53,HIGH);
        Serial.println("light YELLOW");//light up YELLOW LED        
        get_coordinate(2);
        move_forward(100,100);
        delay(1000);
        digitalWrite(53,LOW);       
        }
     //check if there is red 
     if(isRed){
      move_forward(-100,-100); //move backward a little bit
      delay(800);      
      bypass();   //go around the red mine
      }      
  }
}
