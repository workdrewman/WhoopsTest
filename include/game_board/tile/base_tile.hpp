// =======================================================
// Description: This header file contains the declaration
//              of the Tile base class. This will define
//              the base members for each of the game
//              of the game tiles.
// =======================================================

#ifndef GAME_BOARD_TILE_BASE_H
#define GAME_BOARD_TILE_BASE_H

#include "game_board/whoops_color.hpp" // for WhoopsColor

namespace game_board
{
class Tile
{
 public:
  /// @brief Call to determine if a tile can be whoopsed
  /// @return True if a game piece can be whoopsed
  virtual bool CanBeWhoopsed() = 0;
  virtual void MoveTo() = 0;
  virtual void MoveFrom() = 0;

 private:
  int index_{-1};
  WhoopsColor tile_color_{WhoopsColor::kNone};
  WhoopsColor color_occupied_{WhoopsColor::kNone};
};
} // namespace game_board
#endif // GAME_BOARD_TILE_BASE_H
