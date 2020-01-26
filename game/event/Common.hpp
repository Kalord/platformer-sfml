#pragma once

#include <SFML/Graphics.hpp>

/**
 * Обработчик событий, общих для игры
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Common
{
public:
    /**
     * Событие закрытия окна
     **/
    void close(sf::RenderWindow& window);
};