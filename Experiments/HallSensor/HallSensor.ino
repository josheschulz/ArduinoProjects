
void setup(){
   Serial.begin(9600);
}

void loop(){
  //while(millis()-lastStatusTimestamp<STATUS_CHANGE_MIN);
  byte reading = digitalRead(A0);
  bool digitalreading = reading == 0;

   Serial.print("Raw [");
   Serial.print(reading);
   Serial.print("] Digital [");
   Serial.print(digitalreading);
   Serial.println("]");
   delay(500);
}
