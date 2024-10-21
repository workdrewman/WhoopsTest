#include <Arduino.h>
#include <FastLED.h> // for FastLED
#include "OneButton.h" // for OneButton
#include "power_mgt.h" // for set_max_power_in_volts_and_milliamps
#include "led_control/tile_movement.h" // for indicate_move
#include "game_board/pawn/pawn.hpp" // for Pawn
#include "game_board/tile/tile_container.hpp" // for TileContainer
#include "game_board/whoops_color.hpp" // for WhoopsColor
#include <memory> // for make_unique

#define NUM_LEDS 44
#define DATA_PIN 13
#define BUTTON1 14
#define HALL_SENSOR1 25
#define HALL_SENSOR2 26

CRGB leds[NUM_LEDS];
OneButton button1{BUTTON1, true, true};

static void handleClick();

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  set_max_power_in_volts_and_milliamps(5, 120);
  pinMode(HALL_SENSOR1, INPUT);
  pinMode(HALL_SENSOR2, INPUT);
  auto tile_types = {game_board::TileType::kNormal, 
                     game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                     game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                     
                     game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                     game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                     
                     game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                     game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,

                     game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                     game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                     game_board::TileType::kSlide, game_board::TileType::kSlide};

  auto colors = {game_board::WhoopsColor::kNone,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kNone,

                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen,
                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen,
                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen,
                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kNone,

                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed,
                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed,
                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed,
                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed, game_board::WhoopsColor::kNone,
                  
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue,
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue,
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue,
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue};

  auto tile_container{std::make_shared<game_board::TileContainer>(tile_types, colors)};
  auto pawn{std::make_shared<game_board::Pawn>(game_board::WhoopsColor::kBlue, 0)};

  button1.attachClick(handleClick); 
}


void loop() {
  button1.tick();

  int sensorValue1 = analogRead(HALL_SENSOR1);  // Read analog value from Hall sensor
  int sensorValue2 = analogRead(HALL_SENSOR2);  // Read analog value from Hall sensor
  
  Serial.print(sensorValue1);
  Serial.print(",");
  Serial.println(sensorValue2);

  delay(100);                                   // Delay for 200 milliseconds
}


static void handleClick() {
  // do something when button pressed
}
