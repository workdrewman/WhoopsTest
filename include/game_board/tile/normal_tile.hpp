// =======================================================
// Description: This header file contains the declaration
//              of the NormalTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_NORMAL_H
#define GAME_BOARD_TILE_NORMAL_H

#include "base_tile.hpp" // For Tile

namespace game_board
{
class NormalTile : public Tile
{
 public:
  bool CanBeWhoopsed() override { return true; };
  void MoveTo() override;
  void MoveFrom() override;
};
} // namespace game_board
#endif // GAME_BOARD_TILE_NORMAL_H
