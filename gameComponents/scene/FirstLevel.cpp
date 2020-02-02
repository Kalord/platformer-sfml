#include "FirstLevel.hpp"

FirstLevel::FirstLevel()
{
    this->camera = std::shared_ptr<Camera>(new Camera(5, 2));
    this->tileMap = std::shared_ptr<TileMap>(new FirstLevelTile());
    this->tileContainer = std::shared_ptr<TileContainer>(new TileContainer());
}

void FirstLevel::draw(sf::RenderWindow& window)
{
    this->camera->update(window, this->tileMap, this->tileContainer);
}