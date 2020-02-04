#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <memory>
#include <string>

#include "IComponent.hpp"

class TileContainer : public IComponent
{
private:
    /**
     * Текстуры тайлов
     **/
    std::vector<std::shared_ptr<sf::Texture>> tileTexture;
    /**
     * Спрайты тайлов
     **/
    std::map<char, std::shared_ptr<sf::Sprite>> tileSprite;
public:
    TileContainer();

    sf::Sprite& getTileByIdentity(char tileIdentity);
};