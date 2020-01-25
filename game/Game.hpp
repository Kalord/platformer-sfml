#pragma once

#include <SFML/Graphics.hpp>
#include "../fileSystem/Settings.hpp"
#include "State.hpp"

/**
 * Сущность игры
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Game
{
private:
    /**
     * Настройки игры
     **/
    Settings settings;
public:
    Game(Settings settings);
    /**
     * Запуск игры
     **/
    void run();
};