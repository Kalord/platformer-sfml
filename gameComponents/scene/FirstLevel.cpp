#include "FirstLevel.hpp"

FirstLevel::FirstLevel()
{
    this->background = std::make_shared<Background>(new Default());
    this->camera = std::make_shared<Camera>(new Camera());
}

void FirstLevel::draw(sf::RenderWindow& window)
{
    //this->camera->update(background, tailMap)
    //
    //
}