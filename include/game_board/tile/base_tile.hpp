// =======================================================
// Description: This header file contains the declaration
//              of the Tile base class. This will define
//              the base members for each of the game
//              of the game tiles.
// =======================================================

#ifndef GAME_BOARD_TILE_BASE_H
#define GAME_BOARD_TILE_BASE_H

#include "game_board/whoops_color.hpp" // for WhoopsColor
#include "game_board/pawn/pawn.hpp" // for Pawn

namespace game_board
{
class Tile
{
 public:
  /// @brief Constructor of the Tile class
  /// @param index Index of the LED associated with the tile
  /// @param tile_color Color of the tile
  Tile(int index, WhoopsColor tile_color) : led_index_{index}, tile_color_{tile_color} {}
  
  /// @brief Call to determine if a tile can be whoopsed
  /// @return True if a game piece can be whoopsed
  virtual bool CanBeWhoopsed() = 0;

  /// @brief Updates the color of the pawn occupying the space
  /// @param pawn Pointer to the pawn that is moving to the space
  void MoveTo(Pawn* pawn) { color_occupied_ = pawn->GetColor(); }

  /// @brief Updates the color of the pawn occupying to none
  void MoveFrom() { color_occupied_ = WhoopsColor::kNone; }

  /// @brief Returns bool to tell if a piece is on the tile or not
  /// @return True if a piece is occupying
  bool IsVacant() { return (color_occupied_ != WhoopsColor::kNone); }

 protected:
  int led_index_{-1};
  WhoopsColor tile_color_{WhoopsColor::kNone};
  WhoopsColor color_occupied_{WhoopsColor::kNone};
};
} // namespace game_board
#endif // GAME_BOARD_TILE_BASE_H
