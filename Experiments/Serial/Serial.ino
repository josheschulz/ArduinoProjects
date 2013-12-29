#include <Logging.h>

/*
   Learning how to work with the Serial
   port, specifically logging to it so
   I can debug.
   
   This works, fine.  You can get to it 
   from the ID tools or do the following:
   
   screen -d -m -L /dev/tty.usbmodem1431 9600

  Now it's logging to a file.   
*/

int number = 0;
unsigned long currentMillis = 0;


void setup(){
   Log.Init(LOG_LEVEL_DEBUG, 9600);
   Serial.begin(9600);
   Log.Info("Starting our run \n");
}

void loop(){
   currentMillis = millis();
   Log.Error("This is an Error @ %l \n", currentMillis);
   delay(500); // delay half second between numbers
   number++; // to the next number
}
