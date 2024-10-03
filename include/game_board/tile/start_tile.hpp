// =======================================================
// Description: This header file contains the declaration
//              of the StartTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_START_H
#define GAME_BOARD_TILE_START_H

#include "base_tile.hpp" // For Tile
#include "game_board/pawn/pawn.hpp" // for Pawn

namespace game_board
{
class StartTile : public Tile
{
 public:
  bool CanBeWhoopsed() override { return false; };
};
} // namespace game_board
#endif // GAME_BOARD_TILE_START_H
