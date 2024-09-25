#include <Arduino.h>
#include <FastLED.h>
#include "platforms/esp/32/led_strip/led_strip.h"
#include "pixelset.h"
#include "power_mgt.h"

#define NUM_LEDS 60
#define DATA_PIN 13

CRGB leds[NUM_LEDS];

volatile std:: string Port_F = "Initialized";

// Time scaling factors for each component
#define TIME_FACTOR_HUE 60
#define TIME_FACTOR_SAT 100
#define TIME_FACTOR_VAL 100

void indicate_move(int from, int to, CRGB color);

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  set_max_power_in_volts_and_milliamps(5, 40); 
}

void loop() {
  indicate_move(0, 15, CRGB::Blue);

  FastLED.show();
}

void indicate_move(int from, int to, CRGB color) {
  FastLED.leds()[to] = color;
  for (int i = from; i < to; ++i) {
    if (i - 2 >= from) {
      FastLED.leds()[i-2].fadeLightBy(230);
      FastLED.leds()[i-1].fadeLightBy(200);
    }
    FastLED.leds()[i] = color;
    FastLED.show();
    FastLED.delay(75);
  }
  FastLED.clear();
  FastLED.leds()[to] = color;
  FastLED.leds()[to] *= 2;
  FastLED.show();
  FastLED.delay(150);
  FastLED.clear();
  FastLED.show();
}