#pragma once

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
    std::vector<char> tileMap;
public:
    virtual ~TileMap() {}

    std::vector<char>& getTile();
};