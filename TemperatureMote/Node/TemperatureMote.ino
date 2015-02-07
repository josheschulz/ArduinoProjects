#include <RFM69.h>
#include <LowPower.h>
#include "MCP9700A.h"

#define SERIAL_BAUD   115200
#define NETWORKID     2  //the same on all nodes that talk to each other
#define GATEWAYID     1
#define FREQUENCY     RF69_915MHZ
#define NODEID        2
#define SENSOR_PIN    4
RFM69 radio;
MCP9700A tSensor = MCP9700A(SENSOR_PIN);

char buff[20];

void setup(){
//   Serial.begin(SERIAL_BAUD);
   radio.initialize(FREQUENCY,NODEID,NETWORKID);

   radio.setHighPower();
   radio.promiscuous(false); //listen to everything!  Is this wise?  Rx is low power but the master has a much
                           //more reliable power rating... yes it is.  Because you want the one with the reliable
                           //power broadcasting, not listening
   radio.encrypt(0);

   delay(1000);
}

void loop(){
   float temp = tSensor.tempReadFarenheit();

   //Scale it out to 100
   int final = temp * 100; 
   sprintf(buff, "%d", final);
   byte buffLen=strlen(buff);
   radio.sendWithRetry(GATEWAYID, buff, buffLen);
 
   //Need to do this every 5 minutes.
   for(int x=0; x< 37 ;x++){
      LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF,TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF);
   }
   LowPower.idle(SLEEP_4S, ADC_OFF, TIMER2_OFF,TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF);
}
