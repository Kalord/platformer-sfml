#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "../IComponent.hpp"

/**
 * Базовый класс для тайловых карт 
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class TileMap : public IComponent
{
protected:
    /**
     * Тайловая карта
     **/
    std::vector<std::vector<char>> tileMap;
public:
    virtual ~TileMap() {}

    char getTile(int x, int y);
    sf::Vector2i getSize();
};