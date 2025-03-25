#include <Arduino.h>
#include <cmath> // Required for pow()

#define NUM_PINS 3
const int data_pins[NUM_PINS] = {13,14,15};

void setup() {
  for (int pin : data_pins) {
    pinMode(pin, OUTPUT);
  }
}


void loop() {
  for (int i = 0; i < pow(2,NUM_PINS); i++) {
    for (int j = 0; j < NUM_PINS; j++) {
      if (i & j) {
        digitalWrite(data_pins[j], HIGH);
      } else {
        digitalWrite(data_pins[j], LOW);
      }
    }
  }
}

