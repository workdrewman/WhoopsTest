// =======================================================
// Description: This header file contains the declaration
//              of the StartTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_START_H
#define GAME_BOARD_TILE_START_H

#include "base_tile.hpp" // For Tile

namespace game_board
{
class StartTile : public Tile
{
 public:
  bool CanBeWhoopsed() override { return false; };
  void MoveTo() override;
  void MoveFrom() override;

 private:
  int pieces_occupying_{-1};
};
} // namespace game_board
#endif // GAME_BOARD_TILE_START_H
