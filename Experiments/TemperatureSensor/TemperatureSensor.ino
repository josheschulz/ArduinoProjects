#include "MCP9700A.h"

MCP9700A tSensor = MCP9700A(4);

void setup(){
   Serial.begin(9600);
   delay(1000);
}

void loop(){
   int iTemp = analogRead(4);///1024.0;
//   Serial.print("Raw Read: " );
//   Serial.println(iTemp);
   float temp = (iTemp * 5) / 1024.0;
//   Serial.print("Scaled temp: ");
//   Serial.println(temp);

   float tempC = (temp - .5) / 0.01;
   Serial.print("Original C: ");
   Serial.print(tempC);

   float tempF = (tempC * 1.8 ) + 32;
   Serial.print(" Original F: ");
   Serial.println(tempF);

   float nTempC = tSensor.tempReadCelcius();
   Serial.print("New C: ");
   Serial.print(nTempC);

   float nTempF = tSensor.tempReadFarenheit();
   Serial.print(" New F:");
   Serial.println(nTempF);
   
   delay(2000);
   Serial.println();
}
