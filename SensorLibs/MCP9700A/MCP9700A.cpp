#include "Arduino.h"
#include "MCP9700A.h"

MCP9700A::MCP9700A(int pin){
   _pin = pin;
}

float MCP9700A::tempReadFarenheit(){
   float tempC = tempReadCelcius();
   return (tempC * 1.8) + 32;
}

float MCP9700A::tempReadCelcius(){
   float base = readVoltage();
   return (base - .5) / .01 ;
}

float MCP9700A::readVoltage(){
   return (analogRead(_pin) * 5) / 1024.0;
   
   
}

