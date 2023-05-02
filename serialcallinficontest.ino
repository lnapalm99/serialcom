/*
  Serial Call and Response in ASCII
  Language: Wiring/Arduino

  This program sends an ASCII A (byte of value 65) on startup and repeats that
  until it gets some data in. Then it waits for a byte in the serial port, and
  sends three ASCII-encoded, comma-separated sensor values, truncated by a
  linefeed and carriage return, whenever it gets a byte in.

  The circuit:
  - potentiometers attached to analog inputs 0 and 1
  - pushbutton attached to digital I/O 2

  created 26 Sep 2005
  by Tom Igoe
  modified 24 Apr 2012
  by Tom Igoe and Scott Fitzgerald
  Thanks to Greg Shakar and Scott Fitzgerald for the improvements

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/SerialCallResponseASCII
*/
    // digital sensor
int inByte = 0;         // incoming serial byte
int alfa = 0;
#define Passpin 7
#define Failpin 8
void setup() {
  pinMode(13,OUTPUT);
  pinMode(Passpin,OUTPUT);
  pinMode(Failpin,OUTPUT);
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


}
//  establishContact();  // send a byte to establish contact until receiver responds



void loop() {
  //Solicito lectura de punta
  //Serial.write("%");
  
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    // read first analog input:
    alfa = inByte;
    //Serial.print(alfa);
  }
    if (alfa>100) {
      digitalWrite(13,HIGH);
      Serial.println("ALFA > 100");
      digitalWrite(Failpin, HIGH);
       digitalWrite(Passpin,LOW);
    }
    else if(alfa<100) {
      digitalWrite(13,LOW);
      Serial.println("ALFA < 100");
      digitalWrite(Failpin, HIGH);
      digitalWrite(Passpin,LOW);
      }
    else {
      delay(100);
    }
    
      }



void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0,0");   // send an initial string
    delay(300);
  }
}
