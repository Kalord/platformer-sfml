#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "Base.hpp"
#include "../fileSystem/GameProgress.hpp"
#include "../gameComponents/scene/Scene.hpp"
#include "state/State.hpp"
#include "../gameComponents/scene/FirstLevel.hpp"
#include "event/Event.hpp"

/**
 * DEBUG
 */
#include "../debug/Debug.hpp"

/**
 * Данный класс отвечает за игровой процесс
 *
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Game : public Base
{
private:
    /**
     * Объект игровой сцены
     **/
    std::shared_ptr<Scene> scene;
public:
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
