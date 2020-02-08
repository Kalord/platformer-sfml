#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include <iostream>

#include "../IComponent.hpp"
#include "../tileMap/TileMap.hpp"
#include "../TileContainer.hpp"
#include "../character/Character.hpp"

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
    /**
     * Объект, к которому привязана камера
     **/
    std::shared_ptr<Character> targetObject;
public:
    Camera(int x, int y);
    virtual ~Camera() {}

    /**
     * Привязка объекта за которым должна следить камера
     **/
    void bindTargetObject(std::shared_ptr<Character> targetObject);

    /**
     * Перемещение центра камеры
     **/
    void moveCenter(int x, int y, sf::Vector2i border);

    /**
     * Обновляет центр камера на основе привязанного объекта
     **/
    void updateCenter(sf::Vector2i border);

    /**
     * Отображение уровня
     **/
    void renderLevel(
        sf::RenderWindow& window,
        std::shared_ptr<TileMap> tileMap,
        std::shared_ptr<TileContainer> tileContainer
    );

    /**
     * Отображение игровых персонажей
     **/
    void renderActors(std::vector<std::shared_ptr<Character>> actors, sf::RenderWindow& window);

    /**
     * Обновление viewport'а игры
     **/
    void update(
        sf::RenderWindow& window,
        std::shared_ptr<TileMap> tileMap,
        std::shared_ptr<TileContainer> tileContainer,
        std::vector<std::shared_ptr<Character>> actors
    );
};