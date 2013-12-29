#include <Logging.h>

void setup(){
     Log.Init(LOG_LEVEL_DEBUG, 9600);
}

const int analogInPin = A0;  
const int analogOutPin = 11; 

void loop() {
  int sensorValue = 0;
  int outputValue = 0;
  sensorValue = analogRead(analogInPin);  
  Log.Info("Base Value: %l"CR, sensorValue);
  
  //For reference:  In my kitchen with a 1kohm resistor off the photo cell, with the light above me on
  //  I'm getting 521, mapped to 129.  If I shield that it drops to 215/53 (roughly, bounces around a lot)
  //With a 230ohm resistor I'm seeing 24/5 with the lights on.  Blocking the light with my hand gives it
  //  zero.
  //  I'd try it with a bigger resistor, but I don't have any.
  
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  Log.Info("Mapped Value %l"CR, outputValue);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);           

  delay(200);                     
}
