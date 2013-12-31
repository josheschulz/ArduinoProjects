#include <Logging.h>

volatile int redValue = 0;
volatile int blueValue = 0;
volatile int greenValue = 0;
volatile int lastInterruptFire = 0; //TODO: Class this out, going to use this a lot

int builtInLEDState = 0;

const long BOUNCE_DELAY = 100;
const int RED_PIN = 6;
const int BLUE_PIN = 3;
const int GREEN_PIN = 5;
const int BLUE_READ_PIN = 11;
const int GREEN_READ_PIN = 10;
const int STEP_VALUE = 10;

void setup(){
  Log.Init(LOG_LEVEL_DEBUG, 9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT); 
  pinMode(13, OUTPUT);
  pinMode(GREEN_READ_PIN, INPUT);
  pinMode(BLUE_READ_PIN, INPUT);
  //Interrupt 0, not pin 0.
  attachInterrupt(0, adjustColorValues, RISING);
}

void loop(){
  
  //Doing this just so I can see that it's doing something.
  if(builtInLEDState == 0){
    digitalWrite(13, HIGH);
    builtInLEDState = 1;
  } else {
    digitalWrite(13, LOW);
    builtInLEDState = 0;
  }
  Log.Info("Doing Stuff: R %d, G: %d B: %d"CR, redValue, greenValue, blueValue);
  analogWrite(BLUE_PIN, blueValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(RED_PIN, redValue);
  delay(500);
}

/* So... only two interrupts. 
  one switch triggers the interrupt, the other two tell which
  value to adjust.
  
  If 10 and 11 are both low then no switches are pressed and it's RED
  if 10 is high then it's Green
  if 11 is high then it's Blue 
  if 11 and 10 are high then reset everything
*/  
void adjustColorValues(){
//  Log.Info("Interrupt Fired"CR);
  if(millis() - lastInterruptFire > BOUNCE_DELAY){
//    Log.Info("Bounce Delay passed"CR);
    volatile int greenSwitch = 0;
    volatile int blueSwitch = 0;
    
    greenSwitch = digitalRead(GREEN_READ_PIN);
    blueSwitch = digitalRead(BLUE_READ_PIN);

    if(greenSwitch == HIGH && blueSwitch == HIGH){
      //Log.Info("Both Switches HIGH"CR);
      blueValue = 0;
      redValue = 0;
      greenValue = 0;
    } else if(greenSwitch == HIGH){
       //Log.Info("Just Green High"CR);
       greenValue = incrementColorValue(greenValue);
    } else if(blueSwitch == HIGH){
      //Log.Info("Just Blue HIGH"CR);
      blueValue = incrementColorValue(blueValue);
    } else {
     //Must be red 
     //Log.Info("Default to RED"CR);
      redValue = incrementColorValue(redValue);
    }
    lastInterruptFire = millis();
  }
}

int incrementColorValue(int colorValue){
  int tColVal = colorValue + STEP_VALUE;
  if(tColVal > 255){
    tColVal = 0;
  }
  return tColVal;
}
