#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <map>

#include "../IComponent.hpp"
#include "../tileMap/TileMap.hpp"
#include "../camera/Camera.hpp"
#include "../TileContainer.hpp"
#include "../../fileSystem/Settings.hpp"
#include "../background/Background.hpp"
#include "../character/Character.hpp"

/**
 * Базовый класс сцен
 * Композиция из игровых компонентов
 *
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Scene : public IComponent
{
protected:
    /**
     * Тайловая карта для уровня
     **/
    std::shared_ptr<TileMap> tileMap;
    /**
     * Камера
     **/
    std::shared_ptr<Camera> camera;
    /**
     * Контейнер с тайлами
     **/
    std::shared_ptr<TileContainer> tileContainer;
    /**
     * Фон
     **/
    std::shared_ptr<Background> background;
    /**
     * Персонаж, которым управляет пользователь
     **/
    std::shared_ptr<Character> mainCharacter;
public:
    virtual ~Scene() {}

    sf::Vector2i getSizeTileMap();
    std::shared_ptr<Camera>& getCamera();
    std::shared_ptr<Character> getMainCharacter();

    virtual void draw(sf::RenderWindow& window, bool updateCenter = false) = 0;
};
