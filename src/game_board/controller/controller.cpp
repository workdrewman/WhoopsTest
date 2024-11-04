// =======================================================
// Description: This header file contains the implementation
//              of the Controller class. This class is 
//              used to control the pawn and tile movements
// =======================================================

#include "game_board/controller/controller.hpp" // for Controller

#include "game_board/whoops_color.hpp" // for WhoopsColor
#include "game_board/pawn/pawn.hpp" // for Pawn
#include "game_board/tile/base_tile.hpp" // for Tile
#include "game_board/tile/tile_container.hpp" // for TileContainer

#include <vector> // for std::vector
#include <memory> // for std::shared_ptr

namespace game_board
{

auto constexpr kTileTypes = {game_board::TileType::kNormal, 
                  game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                  game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                  
                  game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                  game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                  
                  game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                  game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,

                  game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide, game_board::TileType::kNormal,
                  game_board::TileType::kNormal, game_board::TileType::kSlide, game_board::TileType::kSlide,
                  game_board::TileType::kSlide, game_board::TileType::kSlide};

auto constexpr kTileColors = {game_board::WhoopsColor::kNone,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow,
                  game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kYellow, game_board::WhoopsColor::kNone,

                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen,
                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen,
                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen,
                  game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kGreen, game_board::WhoopsColor::kNone,

                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed,
                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed,
                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed,
                  game_board::WhoopsColor::kRed, game_board::WhoopsColor::kRed, game_board::WhoopsColor::kNone,
                  
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue,
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue,
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue,
                  game_board::WhoopsColor::kBlue, game_board::WhoopsColor::kBlue};

auto constexpr kNumPawns{3};
Controller::Controller() : tiles_{kTileTypes, kTileColors}
{
  for (int i = 0; i < kNumPawns; i++) {
    pawns_.emplace_back(std::make_shared<game_board::Pawn>(game_board::WhoopsColor::kYellow, static_cast<int>(game_board::WhoopsColor::kYellow) + i));
    pawns_.emplace_back(std::make_shared<game_board::Pawn>(game_board::WhoopsColor::kGreen, static_cast<int>(game_board::WhoopsColor::kGreen) + i));
    pawns_.emplace_back(std::make_shared<game_board::Pawn>(game_board::WhoopsColor::kRed, static_cast<int>(game_board::WhoopsColor::kRed) + i));
    pawns_.emplace_back(std::make_shared<game_board::Pawn>(game_board::WhoopsColor::kBlue, static_cast<int>(game_board::WhoopsColor::kBlue) + i));
  } 
}

Pawn* Controller::GetPawnFromTile(std::shared_ptr<Tile> tile)
{
  return tile->GetPawn();
}

Pawn* Controller::GetPawnFromSensor(int sensor_idx)
{
  auto tile = tiles_.GetTileFromSensor(sensor_idx);
  return tile->GetPawn();
}

} // namespace game_board
