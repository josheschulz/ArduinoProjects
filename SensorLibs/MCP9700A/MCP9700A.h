#ifndef MCP9700A_h
#define MCP9700A_h
#include "Arduino.h"

class MCP9700A{
   public:
      MCP9700A(int pin);
      float tempReadFarenheit();
      float tempReadCelcius();
   private:
      int _pin;
      float readVoltage();
      
};

#endif
