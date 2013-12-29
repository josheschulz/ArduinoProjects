#include <Logging.h>

int buzzerOn = 0;

void setup(){
  Log.Init(LOG_LEVEL_DEBUG, 9600);
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
}

void loop(){
  delay(250);
  int switchState = 0;
  switchState = digitalRead(4);

  Log.Info("SwitchStatus %d, Buzzer Status", buzzerOn);
  if(switchState == LOW){
      Log.Info("LOW \n");
  } else {
      Log.Info("HIGH \n");
  }

  //The 
  if(switchState == HIGH && buzzerOn ==0 ){
     buzzerOn = 1;
     Log.Debug("Turning it on"CR);
   } else if (switchState == HIGH && buzzerOn == 1){
     buzzerOn = 0;
     Log.Debug("Turning it off"CR);
   }
  
  if(buzzerOn != 0){
    Log.Debug("Buzzer is on \n");
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);   
  }
}



