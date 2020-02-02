#include "FirstLevel.hpp"

FirstLevel::FirstLevel()
{
    this->camera = std::make_shared<Camera>(new Camera(5, 2));
    this->tileMap = std::make_shared<TileMap>(new FirstLevelTile());
    this->tileContainer = std::make_shared<TileContainer>(new TileContainer());
}

void FirstLevel::draw(sf::RenderWindow& window)
{
    this->camera->update(window, this->tileMap, this->tileContainer);
}