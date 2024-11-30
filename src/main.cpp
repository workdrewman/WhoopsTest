#include <Arduino.h>
#include <FastLED.h> // for FastLED
#include "OneButton.h" // for OneButton
#include "power_mgt.h" // for set_max_power_in_volts_and_milliamps
#include "led_control/tile_movement.h" // for indicate_move
#include "game_board/controller/controller.hpp" // for Controller
#include "game_board/whoops_color.hpp" // for WhoopsColor
#include <memory> // for make_unique

#define NUM_LEDS 44
#define DATA_PIN 13
#define HALL_SENSOR1 21
#define HALL_SENSOR2 23
#define HALL_SENSOR3 22

CRGB leds[NUM_LEDS];
OneButton button1{HALL_SENSOR1, true, true};
OneButton button2{HALL_SENSOR2, true, true};
OneButton button3{HALL_SENSOR3, true, true};
int sensorToLED[3] = {5,18,19};

static void handleClick(int number);
static void switchReleased(int number);

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  set_max_power_in_volts_and_milliamps(5, 120);
  pinMode(HALL_SENSOR1, INPUT);
  pinMode(HALL_SENSOR2, INPUT);
  pinMode(HALL_SENSOR3, INPUT);
  pinMode(sensorToLED[0], OUTPUT);
  pinMode(sensorToLED[1], OUTPUT);
  pinMode(sensorToLED[2], OUTPUT);
  auto game_controller = std::make_shared<game_board::Controller>();

  
  button1.attachLongPressStart([]() { handleClick(1); }); 
  button1.attachLongPressStop([]() { switchReleased(1); });
  button2.attachLongPressStart([]() { handleClick(2); }); 
  button2.attachLongPressStop([]() { switchReleased(2); });  
  button3.attachLongPressStart([]() { handleClick(3); }); 
  button3.attachLongPressStop([]() { switchReleased(3); });
}


void loop() {
  button1.tick();
  button2.tick();
  button3.tick();
}


static void handleClick(int number) {
  // do something when button pressed
  digitalWrite(sensorToLED[number - 1], HIGH);
  Serial.printf("Triggered sensor %d\n", number);
}

static void switchReleased(int number) {
  // do something when depressed
  digitalWrite(sensorToLED[number - 1], LOW);
  Serial.printf("moved away from sensor %d\n", number);
}
