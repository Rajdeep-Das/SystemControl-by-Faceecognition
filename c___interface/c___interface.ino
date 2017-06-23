int ledPin = 13;
//int state=0;
char inByte = ' ';
void setup() {
    pinMode(ledPin, OUTPUT); // pin will be used to for output
    Serial.begin(9600); // same as in your c++ script
}

void loop() {
  if (Serial.available() > 0)
  {
   // state = Serial.read(); // used to read incoming data
    inByte=Serial.read();
    
    switch(inByte)// see what was sent to the board
    {
      case '1': // if the the one was sent
        digitalWrite(ledPin,LOW);
      break;
      case '0': // if 0 was sent
        digitalWrite(ledPin,HIGH);
      break;
      default:
      break; 
    }
  }
}
