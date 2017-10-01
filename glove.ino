


int sensorPins[] = {A0, A1, A2, A3};
//Variables:
int Last[] = {0,0,0,0};
int Degree[] = {0,0,0,0};
int Calbriatelow[] = {138,515,420,500} ;
int Calbriatehigh[] = {197,710,670,700} ;
int handstate = 0;

void setup(){
  

  Serial.begin(57600);       //Begin serial communication

}

void loop(){
  for ( int i=0; i<4; i++){
  Degree[i] = analogRead(sensorPins[i]);  

  Degree[i] = map(Degree[i],Calbriatelow[i], Calbriatehigh[i], 180, 0);

 if((Last[i]- Degree[i]>10)||(Last[i]- Degree[i]<-10)){
// Serial.print("Sensor ");
 //Serial.print(i);
 //Serial.println();
  //Serial.println(Degree[i]); 
 Last[i] = Degree[i];
  }}
  
   if(Last[0]>70 && Last[1]>130 && Last[2] >130 && Last[3] > 130){
    //if(handstate==1){
   Serial.println("handclosed");
  // handstate = 0;}
   } else 
   //if(handstate==0){
   {Serial.println("handopen");
  // handstate=1;}
   }
  delay (50);
   }

