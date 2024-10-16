// =======================================================
// Description: This header file contains the declaration
//              of helper functions to illuminate tiles
//              when indicating a move.
// =======================================================

#ifndef LED_CONTROL_TILE_MOVEMENT_H
#define LED_CONTROL_TILE_MOVEMENT_H

#include <CRGB.h> // for CRGB
#include <vector> // for vector

namespace led_control
{

/// @brief Method to indicate a move from one tile to another
/// @param from Index of the current tile
/// @param to Index of the tile to move to
/// @param color Color to illuminate the path with
void indicate_move(int from, int to, CRGB color);

/// @brief Method to indicate a move from one tile to another
/// @param indexes Indexes in order of where to move
/// @param color Color to illuminate the path with
void indicate_move(std::vector<int> indexes, CRGB color);

} //namespace led_control
#endif // LED_CONTROL_TILE_MOVEMENT_H
