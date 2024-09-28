#include <Arduino.h>
#include <FastLED.h> // for FastLED
#include <ezButton.h> // for ezButton
#include "power_mgt.h" // for set_max_power_in_volts_and_milliamps
#include "led_control/tile_movement.h" // for indicate_move

#define NUM_LEDS 60
#define DATA_PIN 13
#define BUTTON1 14
#define DEBOUNCE_TIME 50

CRGB leds[NUM_LEDS];
ezButton button1(BUTTON1);

void setup() {
  Serial.begin(9600);
  button1.setDebounceTime(DEBOUNCE_TIME);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  set_max_power_in_volts_and_milliamps(5, 40); 
}

void loop() {
  button1.loop();
  if (button1.isPressed()) {
    led_control::indicate_move(0, 15, CRGB::Blue);
  }
}
