// =======================================================
// Description: This header file contains the declaration
//              of the HomeTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_HOME_H
#define GAME_BOARD_TILE_HOME_H

#include "base_tile.hpp" // For Tile
#include "game_board/pawn/pawn.hpp" // for Pawn

namespace game_board
{
class HomeTile : public Tile
{
 public:
  bool CanBeWhoopsed() override { return false; };
};
} // namespace game_board
#endif // GAME_BOARD_TILE_HOME_H
