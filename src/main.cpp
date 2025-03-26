#include <Arduino.h>
#include <cmath> // Required for pow()

#define NUM_PINS 3
const int data_pins[NUM_PINS] = {32,25,26};

void setup() {
  for (int pin : data_pins) {
    pinMode(pin, OUTPUT);
  }
}


void loop() {
  for (int i = 0; i < pow(2,NUM_PINS); i++) {
    for (int j = 0; j < NUM_PINS; j++) {
      if (i & (1 << j)) {
        digitalWrite(data_pins[j], HIGH);
      } else {
        digitalWrite(data_pins[j], LOW);
      }
    }
    delay(1000);
  }

}

// hi drew this is the computer talking youve been hacked give me 3 dollars
