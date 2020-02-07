#pragma once

#include "Scene.hpp"
#include "../tileMap/FirstLevelTile.hpp"
#include "../background/Default.hpp"
#include "../character/Main.hpp"

/**
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class FirstLevel : public Scene
{
public:
    FirstLevel();
    void draw(sf::RenderWindow& window) override;
};