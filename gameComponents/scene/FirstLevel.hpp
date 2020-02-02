#pragma once

#include "Scene.hpp"
#include "../tileMap/FirstLevelTile.hpp"

/**
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class FirstLevel : public Scene
{
public:
    FirstLevel();
    void draw(sf::RenderWindow& window) override;
};