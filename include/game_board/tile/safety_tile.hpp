// =======================================================
// Description: This header file contains the declaration
//              of the SafetyTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_SAFETY_H
#define GAME_BOARD_TILE_SAFETY_H

#include "base_tile.hpp" // For Tile

namespace game_board
{
class SafetyTile : public Tile
{
 public:
  bool CanBeWhoopsed() override { return false; };
  void MoveTo() override;
  void MoveFrom() override;
};
} // namespace game_board
#endif // GAME_BOARD_TILE_SAFETY_H
