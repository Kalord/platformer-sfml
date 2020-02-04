#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include "../IComponent.hpp"
#include "../tileMap/TileMap.hpp"
#include "../TileContainer.hpp"

/**
 * Игровая камера
 * 
 * Данная камера являются viewport'ом для сцены
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Camera : public IComponent
{
private:
    /**
     * Текущие положение камеры
     **/
    sf::Vector2i center;
    /**
     * Сдвиг от центра камеры, зона видимости
     **/
    sf::Vector2i offset;
public:
    Camera(int x, int y);
    virtual ~Camera() {}

    /**
     * Обновление viewport'а игры
     **/
    void update(
        sf::RenderWindow& window,
        std::shared_ptr<TileMap> tileMap,
        std::shared_ptr<TileContainer> tileContainer
    );
};