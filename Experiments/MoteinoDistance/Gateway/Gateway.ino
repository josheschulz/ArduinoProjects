// Hacked up version of the demo gateway from Mr. Rusu.
//    Wanted slightly different info.
// Library and code by Felix Rusu - felix@lowpowerlab.com
// Get the RFM69 and SPIFlash library at: https://github.com/LowPowerLab/

#include <RFM69.h>

#define NODEID        1    //unique for each node on same network
#define NETWORKID     100  //the same on all nodes that talk to each other
#define FREQUENCY     RF69_915MHZ

#define ENCRYPTKEY    0 //This will turn that off other wise exactly the same 16 characters/bytes on all nodes!
#define IS_RFM69HW    //uncomment only for RFM69HW! Leave out if you have RFM69W!

#define LED           9  // Moteinos have LEDs on D9
#define SERIAL_BAUD   115200

typedef struct {
  unsigned int runNumber;
  long sendTime;
  unsigned int sequence;
} Payload;

RFM69 radio;
bool promiscuousMode = false; //set to 'true' to sniff all packets on the same network

void Blink(byte PIN, int DELAY_MS)
{
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN,HIGH);
  delay(DELAY_MS);
  digitalWrite(PIN,LOW);
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(10);
  radio.initialize(FREQUENCY,NODEID,NETWORKID);
#ifdef IS_RFM69HW
  radio.setHighPower(); //uncomment only for RFM69HW!
#endif
  radio.encrypt(ENCRYPTKEY);
  radio.promiscuous(promiscuousMode);
  Serial.println("Run Number,Sequence Number,SendTime,RSSI");
}

void loop() {
   if (radio.receiveDone()){
      if (radio.DATALEN != sizeof(Payload)) {
         Serial.print("Invalid payload received, not matching Payload struct!");
      } else {
         Payload theData = *(Payload*)radio.DATA;

         Serial.print(theData.runNumber);
         Serial.print(",");
         Serial.print(theData.sequence);
         Serial.print(",");
         Serial.print(theData.sendTime);
         Serial.print(",");
         Serial.println(radio.RSSI);
      }

      if (radio.ACK_REQUESTED){
         radio.sendACK();
         delay(10);
      }
      Blink(LED,3);
  }
}


