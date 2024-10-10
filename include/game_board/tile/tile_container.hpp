// =======================================================
// Description: This header file contains the declaration
//              of the TileContainer class. This class is 
//              used to initialize the board with the 
//              correct tile types.
// =======================================================

#ifndef GAME_BOARD_TILE_CONTAINER_H
#define GAME_BOARD_TILE_CONTAINER_H

#include "game_board/whoops_color.hpp" // for WhoopsColor
#include "game_board/pawn/pawn.hpp" // for Pawn
#include "game_board/tile/base_tile.hpp" // for BaseTile

#include <vector> // for std::vector
#include <memory> // for std::shared_ptr

namespace game_board
{
enum class TileType{
  kHome,
  kNormal,
  kSafety,
  kSlide,
  kStart
};

class TileContainer
{
 public:
  TileContainer(std::vector<TileType> tile_types, std::vector<WhoopsColor> tile_colors);
 
 private:
  std::vector<std::shared_ptr<Tile>> tiles_;
};
} // namespace game_board
#endif // GAME_BOARD_TILE_CONTAINER_H
