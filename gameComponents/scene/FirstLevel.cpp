#include "FirstLevel.hpp"

FirstLevel::FirstLevel()
{
    int centerX = (Settings{}).getWidthWindow() / TileContainer::TILE_SIZE / 2 + 1;
    int centerY = (Settings{}).getHeightWindow() / TileContainer::TILE_SIZE / 2 + 1;
    
    this->camera = std::shared_ptr<Camera>(new Camera(centerX, centerY));
    this->tileMap = std::shared_ptr<TileMap>(new FirstLevelTile());
    this->tileContainer = std::shared_ptr<TileContainer>(new TileContainer());
    this->background = std::shared_ptr<Default>(new Default());
    this->mainCharacter = std::shared_ptr<Character>(new Main());

    this->camera->bindTargetObject(this->mainCharacter);
}

void FirstLevel::draw(sf::RenderWindow& window)
{
    this->background->draw(window);
    this->camera->update(
        window, 
        this->tileMap, 
        this->tileContainer,
        std::vector<std::shared_ptr<Character>>{mainCharacter}
    );
}