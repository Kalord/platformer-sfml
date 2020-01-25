#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "../fileSystem/Settings.hpp"
#include "State.hpp"
#include "Event.hpp"
#include "../menu/MainMenu.hpp"
#include "pool/VisibleElementsPool.hpp"

/**
 * Сущность игры
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Game
{
private:
    const std::string TITLE = "Game";

    /**
     * Настройки игры
     **/
    Settings settings;
public:
    Game(Settings settings);
    /**
     * Запуск игры
     **/
    void run(MainMenu& mainMenu);
};