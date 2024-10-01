#include <Arduino.h>
#include <FastLED.h> // for FastLED
#include "OneButton.h" // for OneButton
#include "power_mgt.h" // for set_max_power_in_volts_and_milliamps
#include "led_control/tile_movement.h" // for indicate_move
#include <iostream>

#define NUM_LEDS 44
#define DATA_PIN 13
#define BUTTON1 14

CRGB leds[NUM_LEDS];
OneButton button1{BUTTON1, true, true};

// void getMove(int& from, int& to, int num_leds);
// static void handleClick();

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  set_max_power_in_volts_and_milliamps(5, 120);
  // button1.attachClick(handleClick); 
}

// int from, to = 0;
void loop() {
  // button1.tick();
  led_control::indicate_move(0, 10, CRGB::Yellow);
  led_control::indicate_move(0, 10, CRGB::Yellow);
  led_control::indicate_move(11, 21, CRGB::Green);
  led_control::indicate_move(11, 21, CRGB::Green);
  led_control::indicate_move(22, 32, CRGB::Red);
  led_control::indicate_move(22, 32, CRGB::Red);
  led_control::indicate_move(33, 43, CRGB::Blue);
  led_control::indicate_move(33, 43, CRGB::Blue);
}

// void getMove(int& from, int& to, int num_leds)
// {
//   from = random() % num_leds;
//   to = from + random(std::min(num_leds - from - 1, 12)) + 1;
// }

// static void handleClick() {
//   getMove(from, to, NUM_LEDS);
//   std::cout << "Moving from " << from << " to " << to << std::endl;
//   for (int i = 0; i < 3; i++) {
//     led_control::indicate_move(from, to, CRGB::Blue);
//   }
// }
