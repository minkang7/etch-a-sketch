#define SENSORPINA A0 // x axis
#define SENSORPINB A1 // y axis


unsigned long targetTime=0;
const unsigned long interval=100; //TODO: How fast should we read
int x = 100;
int y = 100;
int prev_x = 100;
int prev_y = 100;
void setup(){
  pinMode(SENSORPINA, INPUT);
  pinMode(SENSORPINB, INPUT);
  Serial.begin(115200);
}


void loop(){
  if(millis()>=targetTime){
    targetTime= millis()+interval;
    //Add other sensor read outs
    x = analogRead(SENSORPINA);
    y = analogRead(SENSORPINB);
    if (x != prev_x || y != prev_y) {
      // convert values into a string, combine them into a string that can be understood by server.js
      // send the string over serial
      String newPosition = String(x, DEC) + "," + String(y, DEC);      
      Serial.println(newPosition);
      prev_x = x;
      prev_y = y;
    }

  }


}
