#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <memory>

#include "Base.hpp"
#include "../fileSystem/Settings.hpp"
#include "state/State.hpp"
#include "../menu/MainMenu.hpp"
#include "event/Event.hpp"
#include "Game.hpp"

/**
 * Сущность игры
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class App : public Base
{
private:
    const std::string TITLE = "Game";
    /**
     * Настройки игры
     **/
    Settings settings;
    /**
     * Объект игры
     **/
    Game game;
public:
    App(Settings settings);
    /**
     * Запуск игры
     **/
    void run(MainMenu& mainMenu);
};