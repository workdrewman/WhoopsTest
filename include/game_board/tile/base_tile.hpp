// =======================================================
// Description: This header file contains the declaration
//              of the Tile base class. This will define
//              the base members for each of the game
//              of the game tiles.
// =======================================================

#ifndef GAME_BOARD_TILE_BASE_H
#define GAME_BOARD_TILE_BASE_H

namespace game_board::tile
{
enum class ColorSide{
  kRed,
  kGreen,
  kBlue,
  kYellow,
  kNone
};

class Tile
{
 public:
  /// @brief Call to determine if a tile can be whoopsed
  /// @return True if a game piece can be whoopsed
  virtual bool CanWhoops() = 0;
  virtual void MoveTo() = 0;
  virtual void MoveFrom() = 0;

 private:
  int index_{-1};
  ColorSide tile_color_{ColorSide::kNone};
  ColorSide color_occupied_{ColorSide::kNone};
};
} // namespace game_board::tile
#endif // GAME_BOARD_TILE_BASE_H
