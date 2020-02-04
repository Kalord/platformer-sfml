#include "FirstLevelTile.hpp"

FirstLevelTile::FirstLevelTile()
{
    TileReader::load("assets/game/tileMap/firstLevel.txt", this->tileMap);
}