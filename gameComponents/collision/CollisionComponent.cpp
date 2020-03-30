#include "CollisionComponent.hpp"

/**
 * Обнаружение коллизий
 **/
bool CollisionComponent::detected(const std::vector<char>& tiles, char tile)
{
    return std::find(tiles.begin(), tiles.end(), tile) != tiles.end();
}

/**
 * Установка целевого элемента для отслеживания столкновений
 **/
void CollisionComponent::setTarget(ICollisionTarget* target)
{
    this->target = target;
}

/**
 * Установка тайловой карты
 **/
void CollisionComponent::setTileMap(TileMap* tileMap)
{
    this->tileMap = tileMap;
}

/**
 * Установка набора тайлов для обнаружения столкновения впереди
 **/
void CollisionComponent::setFrontCollisionTiles(const std::vector<char> tiles)
{
    this->frontTiles = tiles;
}

/**
 * Установка набора тайлов для обнаружения столкновения сзади
 **/
void CollisionComponent::setBackCollisionTiles(const std::vector<char> tiles)
{
    this->backTiles = tiles;
}

/**
 * Установка набора тайлов для обнаружения столкновения сверху
 **/
void CollisionComponent::setTopCollisionTiles(const std::vector<char> tiles)
{
    this->topTiles = tiles;
}

/**
 * Установка набора тайлов для обнаружения столкновения снизу
 **/
void CollisionComponent::setBottomCollisionTiles(const std::vector<char> tiles)
{
    this->bottomTiles = tiles;
}

/**
 * Обнаружение столкновения впереди
 **/
bool CollisionComponent::detectedFront()
{
    sf::Vector2i currentPosition = this->target->getTilePosition();
    char tile = this->tileMap->getTile(currentPosition.x + 1, currentPosition.y);

    return this->detected(this->frontTiles, tile);
}

/**
 * Обнаружение столкновние сзади
 **/
bool CollisionComponent::detectedBack()
{
    sf::Vector2i currentPosition = this->target->getTilePosition();
    char tile = this->tileMap->getTile(currentPosition.x - 1, currentPosition.y);

    return this->detected(this->backTiles, tile);
}

/**
 * Обнаружение столкновения снизу
 */
bool CollisionComponent::detectedBottom()
{
    sf::Vector2i currentPosition = this->target->getTilePosition();
    char tile = this->tileMap->getTile(currentPosition.x, currentPosition.y);

    return this->detected(this->bottomTiles, tile);
}

/**
 * Обнаружение столкновения сверху
 **/
bool CollisionComponent::detectedTop()
{
    sf::Vector2i currentPosition = this->target->getTilePosition();
    char tile = this->tileMap->getTile(currentPosition.x, currentPosition.y - 1);

    return this->detected(this->topTiles, tile);
}
