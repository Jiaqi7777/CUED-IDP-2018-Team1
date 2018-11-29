void get_coordinate(int colorcode){//get the coordinates of the robot
 //double coor[2]={0,0};
 double lf=ultra_distance(0);
 double rt=ultra_distance(1);//0 is left sensor, 1 is the right sensor
 double x,y;//coordinates
 if (n%2==0){//facing y-
  x=rt+5;
  y=lf;
  }
  else {//facing y+
   x=Lx-rt-5;
   y=Ly-lf;
 }
  
  if (colorcode==2){//yellow
     
     Serial.print("yellow mine:  ");
     Serial.println(String(x)+","+String(y));
     
  }
  if(colorcode==1){ //red
    Serial.print("red mine:  ");
    Serial.println(String(x)+","+String(y));
    }
}
