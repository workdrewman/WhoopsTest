// =======================================================
// Description: This header file contains the implementation
//              of helper functions to illuminate tiles
//              when indicating a move.
// =======================================================

#include "led_control/tile_movement.h"

#include "FastLED.h"
#include <vector> // for vector

namespace led_control
{

void indicate_move(int from, int to, CRGB color)
{
  FastLED.leds()[to] = color;
  for (int i = from; i < to; ++i) {
    if (i - 2 >= from) {
      FastLED.leds()[i-2].fadeLightBy(230);
      FastLED.leds()[i-1].fadeLightBy(200);
    }
    FastLED.leds()[i] = color;
    FastLED.leds()[i].fadeLightBy(200);
    FastLED.show();
    FastLED.delay(75);
  }
  FastLED.leds()[to-2].fadeLightBy(230);
  FastLED.leds()[to-1].fadeLightBy(200);
  FastLED.delay(75);
  FastLED.show();
  FastLED.clear();
  FastLED.show();
}

void indicate_move(std::vector<int> indexes, CRGB color)
{
  FastLED.leds()[indexes[0]] = color;
  for (int i = 0; i < indexes.size(); ++i) {
    if (i >= 2) {
      FastLED.leds()[indexes[i-2]].fadeLightBy(230);
      FastLED.leds()[indexes[i-1]].fadeLightBy(200);
    }
    FastLED.leds()[indexes[i]] = color;
    FastLED.leds()[indexes[i]].fadeLightBy(200);
    FastLED.show();
    FastLED.delay(75);
  }
  FastLED.leds()[indexes[indexes.size()-2]].fadeLightBy(230);
  FastLED.leds()[indexes[indexes.size()-1]].fadeLightBy(200);
  FastLED.delay(75);
  FastLED.show();
  FastLED.clear();
  FastLED.show();
}

} // namespace led_control
