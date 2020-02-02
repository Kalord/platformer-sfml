#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

#include "IComponent.hpp"

class TileContainer : public IComponent
{
private:
    /**
     * Текстуры тайлов
     **/
    std::vector<sf::Texture> tileTexture;
    /**
     * Спрайты тайлов
     **/
    std::map<char, sf::Sprite> tileSprite;
public:
    TileContainer();

    sf::Sprite& getTileByIdentity(char tileIdentity);
};