int switchState = 0;
int pressCount = 0;
int priorState = LOW;

void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop(){
  switchState = digitalRead(2);
  if(switchState == LOW){
    //Switch is open
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    priorState = LOW;
    
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH); 

    //Want to count the number of times we switch states.  
    //  worth looking into how to use functions, because I'm sure this
    //  pattern is reused.
    if(priorState == LOW){
      priorState = HIGH;
      pressCount++;
    }    
    
    if(pressCount % 5 == 0){
       //Every Fifth Press we freak out
        for(int x = 0;x < 20; x++){
          flashOn();
          delay(100);
          flashOff();
          delay(100);
        }
    }
    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }
  
}

void flashOn(){
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

void flashOff(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW); 
}


