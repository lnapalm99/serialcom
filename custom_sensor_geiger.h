#include "esphome.h"

class MyCustomSensor : public PollingComponent, public Sensor {
 public:
  // constructor
  MyCustomSensor() : PollingComponent(10000) {}

  void setup() override {
  Serial.begin(9600);
    // This will be called by App.setup()
  }
  void update() override {
  
    Serial.print("%");
 // Serial.write("%");
 // Serial.println("Enviando solicitud de medicion")
  publish_state(42.0);
    // This will be called every "update_interval" milliseconds.
  }
};
