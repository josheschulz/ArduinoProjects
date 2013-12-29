#include <Logging.h>

const int NUM_LIGHTS = 4;

//Kind of a break down here, but gotta hard code those pin numbers.
int pins[NUM_LIGHTS] = {3, 5, 6, 10};
int currentLight = 0;

void setup(){
  Log.Init(LOG_LEVEL_DEBUG, 9600);

  for(int x=0;x < NUM_LIGHTS; x++){
    pinMode(pins[x], OUTPUT);
  }  
  
}

void loop(){
  int nextLight = currentLight+1;
  if(nextLight >= NUM_LIGHTS){
    nextLight = 0;
  }
  for(int x=0;x < NUM_LIGHTS;x++){
    //The last light shouldn't dim, because it makes it look weird when the two
    //  tail lights are lit.
    if(x == currentLight && x != NUM_LIGHTS -1){
      //Dim the current one
      analogWrite(pins[x], 75);
    } else if(x == nextLight){
     //Light this one up
      analogWrite(pins[x], 255); 
    } else {
      //Otherise turn it off.    
      analogWrite(pins[x], 0);
    }
  }
  currentLight++;
  if(currentLight>= NUM_LIGHTS){
    currentLight = 0; 
  }
  delay(250);
}
