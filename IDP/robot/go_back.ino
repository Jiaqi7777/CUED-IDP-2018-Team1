void go_back(){
   if (n>=4 && n%2==0 && (ultra_distance(1)<=40)){
    if(ultra_distance(0)<=25){
      while(true){
          move_forward(0,0);
          delay(10000);}
      }
   }

   else if(n >=4 && n%2 ==1 && ((Lx - ultra_distance(1)) <=75)){
      move_forward(0,0);
      delay(200);
      move_forward(-150,-150);
      delay(30000);
      move_forward(0,0);
      delay(200000);       
    }  
}
