#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include "../fileSystem/GameProgress.hpp"
#include "../gameComponents/scene/Scene.hpp"
#include "state/State.hpp"
#include "../gameComponents/scene/FirstLevel.hpp"

/**
 * Данный класс отвечает за игровой процесс
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Game
{
private:
    /**
     * Объект для работы с игровым прогрессом
     **/
    GameProgress gameProgress;
    /**
     * Объект игровой сцены
     **/
    std::shared_ptr<Scene> scene;
public:
    Game();

    /**
     * Игровой цикл
     **/
    void gameLoop(sf::RenderWindow& window);
    /**
     * Запуск новой игры
     **/
    void newGame(sf::RenderWindow& window);
    /**
     * Продолжение игры
     **/
    void continueGame(sf::RenderWindow& window);
};