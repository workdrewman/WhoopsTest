// =======================================================
// Description: This header file contains the implementation
//              of helper functions to illuminate tiles
//              when indicating a move.
// =======================================================

#include "led_control/tile_movement.h"

#include "FastLED.h"

void indicate_move(int from, int to, CRGB color)
{
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
  FastLED.show();
  FastLED.delay(150);
  FastLED.clear();
  FastLED.show();
}
