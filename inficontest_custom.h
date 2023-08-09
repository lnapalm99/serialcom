#include "esphome.h"

unsigned long lastmeasure = 0;
String inString = "";  // string to hold input
int valor;

class MyCustomSensor : public PollingComponent, public Sensor {
 public:
  // constructor
  MyCustomSensor() : PollingComponent(15000) {}

  void setup() override {
  Serial.begin(9600);
      while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  
  
  }
  void update() override {
  
 if (millis() - lastmeasure > 1000) {
    lastmeasure = millis();

    Serial.write("%");

  }

  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    //if (inChar == '\n') {
    if (inString.length() == 5) {
       valor = inString.toInt();
       publish_state(valor);
    
    
    }

 // publish_state(42.0);
    // This will be called every "update_interval" milliseconds.
  }
  }
};
