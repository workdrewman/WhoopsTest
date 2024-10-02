// =======================================================
// Description: This header file contains the declaration
//              of the SlideTile class.
// =======================================================

#ifndef GAME_BOARD_TILE_SLIDE_H
#define GAME_BOARD_TILE_SLIDE_H

#include "base_tile.hpp" // For Tile

namespace game_board
{
class SlideTile : public Tile
{
 public:
  bool CanBeWhoopsed() override { return true; };

  /// @brief Method that determines if a piece will slide
  /// @return True if the tile is the start of a slide
  bool IsSlideStart();
  void MoveTo() override;
  void MoveFrom() override;

 private:
  bool is_slide_start_{false};
};
} // namespace game_board
#endif // GAME_BOARD_TILE_SLIDE_H
