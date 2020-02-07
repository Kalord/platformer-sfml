#include "Main.hpp"

Main::Main()
{
    this->texture.loadFromFile("assets/game/character/main.png");
    this->sprite.setTexture(this->texture);
    this->sprite.scale(2.0f, 2.0f);

    this->life = 10;
    this->speedBase = 1;
    this->position.x = 0;
    this->position.y = 1;

    this->sprite.setPosition(
        this->position.x * TileContainer::TILE_SIZE,
        this->position.y * TileContainer::TILE_SIZE 
    );

    this->baseAnimation = std::shared_ptr<MainBaseAnimation>(
        new MainBaseAnimation()
    );
}