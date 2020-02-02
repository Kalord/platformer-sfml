#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <map>

#include "../IComponent.hpp"
#include "../tileMap/TileMap.hpp"
#include "../camera/Camera.hpp"
#include "../TileContainer.hpp"

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
public:
    virtual ~Scene() {}
    virtual void draw(sf::RenderWindow& window);
};