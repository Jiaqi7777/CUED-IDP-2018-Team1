void zigzag(){
  double lf=ultra_distance(0);
  double rt=ultra_distance(1);
  if(n==0){
    if(lf<=30 && lf>= 15){
      move_forward(0,0);
      delay(500);
      turn_left(0,220);
      delay(2000);
//      Serial.println("first turn");
      n++;
      }
    }
    else if(n%2==1){
      if(lf<=36 && lf>= 15){
      push_back();
      move_forward(0,0);
      delay(500);
      turn_left(0,230);
      delay(4100);
      move_forward(-150,-150);
      delay(1000);
      move_forward(0,0);
      delay(200);
//      Serial.println("turn left");
      n++;
      }
    }
    else{
      if(lf<=36 && lf>= 15){ 
      push_back(); 
      move_forward(0,0);
      delay(500);
      turn_right(230,0);
      delay(4100);
      move_forward(-150,-150);
      delay(1000);
      move_forward(0,0);
      delay(200);
//      Serial.println("turn right");
      n++;
     }
    }
  }

void push_back(){
  move_forward(0,0);
  delay(200);
  move_forward(160,160);
  delay(1500);
  move_forward(0,0);
  delay(200);
  move_forward(-200,-200);
  delay(1300);
//   move_forward(0,0);
//  delay(200);
  }
