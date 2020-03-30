#pragma once

#include <SFML/Graphics.hpp>

#include "../IComponent.hpp"

/**
 * Данный интерфейс реализует те объект, над которыми происходит отслеживания столкновений
 *
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 * @package gameComponents/ICollisionTarget
 **/
class ICollisionTarget : public IComponent
{
public:
    virtual sf::Vector2i getTilePosition() = 0;
};
