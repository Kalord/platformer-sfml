#include "FirstLevel.hpp"

FirstLevel::FirstLevel()
{
    int centerX = (Settings{}).getWidthWindow() / TileContainer::TILE_SIZE / 2 + 1;
    int centerY = (Settings{}).getHeightWindow() / TileContainer::TILE_SIZE / 2 + 1;
    
    this->camera = std::shared_ptr<Camera>(new Camera(centerX, centerY));
    this->tileMap = std::shared_ptr<TileMap>(new FirstLevelTile());
    this->tileContainer = std::shared_ptr<TileContainer>(new TileContainer());
}

void FirstLevel::draw(sf::RenderWindow& window)
{
    this->camera->update(window, this->tileMap, this->tileContainer);
}