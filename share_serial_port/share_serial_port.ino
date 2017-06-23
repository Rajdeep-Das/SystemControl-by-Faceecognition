#include <SoftwareSerial.h>
// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial portOne(10, 11);

int ledPin = 13;
//int state=0;
char inByte = ' ';
char inByte1=' ';


// software serial #2: RX = digital pin 8, TX = digital pin 9
// on the Mega, use other pins instead, since 8 and 9 don't work on the Mega
//SoftwareSerial portTwo(8, 9);

void setup() {
  pinMode(ledPin, OUTPUT); // pin will be used to for output
  digitalWrite(ledPin,HIGH);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  // Start each software serial port
  portOne.begin(9600);
  //portTwo.begin(9600);
}

void loop() {
  // By default, the last intialized port is listening.
  // when you want to listen on a port, explicitly select it:
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
 
  // while there is data coming in, read it
  // and send to the hardware serial port:
  while (portOne.available() > 0) {
    inByte1=portOne.read();
     switch(inByte1)// see what was sent to the board
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
