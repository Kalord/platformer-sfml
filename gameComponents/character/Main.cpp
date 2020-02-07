#include "Main.hpp"

Main::Main()
{
    this->texture.loadFromFile("assets/game/character/main.png");
    this->sprite.setTexture(this->texture);
    this->sprite.scale(2.0f, 2.0f);

    this->life = 10;
    this->speedBase = 1;
    this->position.x = 3;
    this->position.y = 3;
    this->baseAnimation = std::shared_ptr<MainBaseAnimation>(
        new MainBaseAnimation()
    );
}