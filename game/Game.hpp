#pragma once

#include <SFML/Graphics.hpp>
#include "../fileSystem/GameProgress.hpp"
#include "../gameComponents/scene/Scene.hpp"
#include "state/State.hpp"

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
    Scene* scene;
public:
    Game();

    void gameLoop(sf::RenderWindow& window);
    void newGame(sf::RenderWindow& window);
    void continueGame(sf::RenderWindow& window);
};