#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <memory>

#include "../fileSystem/Settings.hpp"
#include "state/State.hpp"
#include "../menu/MainMenu.hpp"
#include "event/Event.hpp"

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
    /**
     * Система событий
     */
    Event event;
public:
    Game(Settings settings);
    /**
     * Запуск игры
     **/
    void run(MainMenu& mainMenu);
};