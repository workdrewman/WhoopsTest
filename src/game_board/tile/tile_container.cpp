// =======================================================
// Description: This header file contains the declaration
//              of the TileContainer class. This class is 
//              used to initialize the board with the 
//              correct tile types.
// =======================================================

#include "game_board/tile/tile_container.hpp" // for TileContainer, TileType

#include "game_board/whoops_color.hpp" // for WhoopsColor
#include "game_board/pawn/pawn.hpp" // for Pawn
#include "game_board/tile/home_tile.hpp"
#include "game_board/tile/normal_tile.hpp"
#include "game_board/tile/safety_tile.hpp"
#include "game_board/tile/slide_tile.hpp"
#include "game_board/tile/start_tile.hpp"

#include <vector> // for std::vector
#include <memory> // for std::make_unique

namespace game_board
{

TileContainer::TileContainer(std::vector<TileType> tile_types, std::vector<WhoopsColor> tile_colors)
{
  bool slide_prev = false;
  for (auto idx = 0; idx < tile_types.size(); ++idx) {
    switch (tile_types.at(idx)){
      case TileType::kHome:
        tiles_.emplace_back(std::make_shared<HomeTile>(idx, WhoopsColor::kBlue));
        slide_prev = false;
        break;
      case TileType::kNormal:
        tiles_.emplace_back(std::make_shared<NormalTile>(idx, WhoopsColor::kBlue));
        slide_prev = false;
        break;
      case TileType::kSafety:
        tiles_.emplace_back(std::make_shared<SafetyTile>(idx, WhoopsColor::kBlue));
        slide_prev = false;
        break;
      case TileType::kSlide:
        tiles_.emplace_back(std::make_shared<SlideTile>(idx, WhoopsColor::kBlue, !slide_prev));
        slide_prev = true;
        break;
      case TileType::kStart:
        tiles_.emplace_back(std::make_shared<StartTile>(idx, WhoopsColor::kBlue));
        slide_prev = false;
        break;
    }
  }
}

} // namespace game_board
