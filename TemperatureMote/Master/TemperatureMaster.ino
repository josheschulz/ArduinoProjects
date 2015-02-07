// Hacked up version of the demo gateway from Mr. Rusu at http://www.lowpoerlab.com, the moteino's come from there
// and i highly recomend them.

#include <RFM69.h>
#define SERIAL_BAUD   115200
#define NETWORKID     2  //the same on all nodes that talk to each other
#define GATEWAYID     1
#define FREQUENCY     RF69_915MHZ
#define NODEID        1


#define NODEID        1    //unique for each node on same network

RFM69 radio;

void setup() {
  Serial.begin(SERIAL_BAUD);
  radio.initialize(FREQUENCY,NODEID,NETWORKID);
  radio.setHighPower();
  radio.encrypt(0);//Don't bother encrypting it
  radio.promiscuous(false); //We dont' want the master listening to everything.  That's kind of pointless
  delay(10);
}

void Blink(byte PIN, int DELAY_MS)
{
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN,HIGH);
  delay(DELAY_MS);
  digitalWrite(PIN,LOW);
}

void loop() {
   //Anybody have anything for us?
   if (radio.receiveDone()){
      for (byte i = 0; i < radio.DATALEN; i++)
         Serial.print((char)radio.DATA[i]);

      Serial.println();
      if (radio.ACK_REQUESTED){
         radio.sendACK();
         delay(10);
     }
     Blink(9, 100);
   }
   delay(250);
   Blink(9, 100);
   
}


