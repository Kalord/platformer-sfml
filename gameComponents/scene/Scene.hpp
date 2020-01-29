#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <map>

#include "../IComponent.hpp"
#include "../tileMap/TileMap.hpp"
#include "../camera/Camera.hpp"
#include "../background/Background.hpp"

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
     * Игровой фон
     **/
    std::shared_ptr<Background> background;
public:
    virtual ~Scene() {}
    virtual void draw(sf::RenderWindow& window) = 0;
};