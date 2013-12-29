#include <Logging.h>

volatile int buzzerOn = 0;
//Interrupts work great for this but they still bounce
//  around.  Let's fix that.
const long BOUNCE_DELAY = 100;

volatile long lastInterruptFire = 0;

void setup(){
  Log.Init(LOG_LEVEL_DEBUG, 9600);
  attachInterrupt(0, toggleStatus, RISING);
  pinMode(7, OUTPUT);
}

///On Pin 2
void toggleStatus(){
  Log.Info("Interrupt Fired"CR);
  if(millis() - lastInterruptFire > BOUNCE_DELAY){
    Log.Info("Bounce Delay Met"CR);
    if(buzzerOn == 0){
      //Turn it on
      buzzerOn = 1;
      digitalWrite(7, HIGH);
    } else {
      //turn it off
      buzzerOn = 0;
      digitalWrite(7, LOW);
    }
  }
  lastInterruptFire = millis();
}

void loop(){
}



