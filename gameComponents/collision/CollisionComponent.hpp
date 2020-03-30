#pragma once

#include <vector>
#include <algorithm>

#include "../IComponent.hpp"
#include "../tileMap/TileMap.hpp"
#include "ICollisionTarget.hpp"

/**
 * Класс для работы со столкновениями
 *
 * Для работы с данным компонентом, необходимо привязать целевой объект
 * на котором будут просчитываться коллизии
 *
 * Типы коллизий:
 *    1)Front collision
 *    2)Back collision
 *    3)Bottom collision
 *    4)Top collision
 *
 * Также необходимо указать идентификаторы тайлов для каждого типа коллизий
 *
 * Пример:
 * ```C++
 *    std::shared_ptr<ICollisionTarget> mainCharacter(new MainCharacter());
 *
 *    CollisionComponent collision = Make::CollisionComponent(mainCharacter.get())->
 *                                   setTileMap(tileMap)->
 *                                   setFrontCollisionTiles(std::vector<char>({'c'}))->
 *                                   setBackCollisionTiles(std::vector<char>({'t'}))->
 *                                   setTopCollisionTiles(std::vector<char>({'t'}))->
 *                                   setBottomCollisionTiles(std::vector<char>({'b'}))->
 *                                   make();
 * ```
 *
 * gameComponents/collision
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class CollisionComponent : public IComponent
{
private:
    /**
     * Целевой объект над которым отслеживаются столкновения
     **/
    ICollisionTarget* target;

    TileMap* tileMap;

    /**
     * Тайлы для обнаружения столкновений
     **/
    std::vector<char> frontTiles;
    std::vector<char> backTiles;
    std::vector<char> bottomTiles;
    std::vector<char> topTiles;

    /**
     * Обнаружение коллизий
     **/
    bool detected(const std::vector<char>& tiles, char tile);
public:
    /**
     * Установка целевого элемента для отслеживания столкновений
     **/
    void setTarget(ICollisionTarget* target);

    /**
     * Установка тайловой карты
     **/
    void setTileMap(TileMap* tileMap);

    /**
     * Установка набора тайлов для обнаружения столкновения впереди
     **/
    void setFrontCollisionTiles(const std::vector<char> tiles);

    /**
     * Установка набора тайлов для обнаружения столкновения сзади
     **/
    void setBackCollisionTiles(const std::vector<char> tiles);

    /**
     * Установка набора тайлов для обнаружения столкновения сверху
     **/
    void setTopCollisionTiles(const std::vector<char> tiles);

    /**
     * Установка набора тайлов для обнаружения столкновения снизу
     **/
    void setBottomCollisionTiles(const std::vector<char> tiles);

    /**
     * Обнаружение столкновения впереди
     **/
    bool detectedFront();

    /**
     * Обнаружение столкновние сзади
     **/
    bool detectedBack();

    /**
     * Обнаружение столкновения снизу
     */
    bool detectedBottom();

    /**
     * Обнаружение столкновения сверху
     **/
    bool detectedTop();
};
