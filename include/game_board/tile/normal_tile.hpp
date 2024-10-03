// =======================================================
// Description: This header file contains the declaration
//              of the NormalTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_NORMAL_H
#define GAME_BOARD_TILE_NORMAL_H

#include "base_tile.hpp" // For Tile
#include "game_board/pawn/pawn.hpp" // for Pawn

namespace game_board
{
class NormalTile : public Tile
{
 public:
  bool CanBeWhoopsed() override { return true; };
};
} // namespace game_board
#endif // GAME_BOARD_TILE_NORMAL_H
