#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "pool/VisibleElementsPool.hpp"

/**
 * Класс для работы с событиями
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Event
{
public:
    /**
     * Обработка событий
     **/
    static void handle(sf::RenderWindow& window, sf::Event& event);
};