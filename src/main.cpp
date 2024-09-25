#include <Arduino.h>
#include <FastLED.h> // for FastLED
#include "power_mgt.h" // for set_max_power_in_volts_and_milliamps
#include "led_control/tile_movement.h" // for indicate_move

#define NUM_LEDS 60
#define DATA_PIN 13

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  set_max_power_in_volts_and_milliamps(5, 40); 
}

void loop() {
  indicate_move(0, 15, CRGB::Blue);
}
