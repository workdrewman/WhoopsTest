// =======================================================
// Description: This header file contains the declaration
//              of the Controller class. This class is 
//              used to control the pawn and tile movements
// =======================================================

#ifndef GAME_BOARD_CONTROLLER_H
#define GAME_BOARD_CONTROLLER_H

#include "game_board/whoops_color.hpp" // for WhoopsColor
#include "game_board/pawn/pawn.hpp" // for Pawn
#include "game_board/tile/base_tile.hpp" // for Tile
#include "game_board/tile/tile_container.hpp" // for TileContainer

#include <vector> // for std::vector
#include <memory> // for std::shared_ptr

namespace game_board
{

class Controller
{
 public:
  Controller();
  Pawn* GetPawnFromSensor(int sensor_idx);
  std::vector<Pawn*> GetCurrentColorPawns();
 private:
  Pawn* GetPawnFromTile(std::shared_ptr<Tile> tile);
 
  std::shared_ptr<TileContainer> tiles_;
  std::vector<Pawn*> pawns_;
  WhoopsColor current_color_{WhoopsColor::kNone};
};
} // namespace game_board
#endif // GAME_BOARD_CONTROLLER_H
