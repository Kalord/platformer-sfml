#include "TileMap.hpp"

char TileMap::getTile(int x, int y)
{
    return this->tileMap[x][y];
}

sf::Vector2i TileMap::getSize()
{
    return sf::Vector2i(
        this->tileMap[0].size(),
        this->tileMap.size()
    );
}