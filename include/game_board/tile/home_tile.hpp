// =======================================================
// Description: This header file contains the declaration
//              of the HomeTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_HOME_H
#define GAME_BOARD_TILE_HOME_H

#include "base_tile.hpp" // For Tile

namespace game_board::tile
{
class HomeTile : public Tile
{
 public:
  bool CanWhoops() override { return false; };
  void MoveTo() override;
  void MoveFrom() override;

 private:
  int pieces_occupying_{-1};
};
} // namespace game_board::tile
#endif // GAME_BOARD_TILE_HOME_H
