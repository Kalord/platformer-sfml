#include "Camera.hpp"

Camera::Camera(int x, int y) : center({x, y}), offset(center)
{
}

/**
 * Привязка объекта за которым должна следить камера
 **/
void Camera::bindTargetObject(std::shared_ptr<Character> targetObject)
{
    this->targetObject = targetObject;
}

/**
 * Проверяет, находится ли объект, за которым следит камера в центре
 **/
bool Camera::targetInCenter()
{
    return this->targetObject->getTilePosition().x >= this->center.x + 1;
}

/**
 * Перемещение центра камеры
 **/
void Camera::moveCenter(int x, int y, sf::Vector2i border)
{
    if(x > 0 && this->center.x + this->offset.x < border.x) this->center.x += x;
    if(y > 0 && this->center.y + this->offset.y < border.y) this->center.y += y;
    if(x < 0 && this->center.x - this->offset.x > 0) this->center.x += x;
    if(y < 0 && this->center.y - this->offset.y > 0) this->center.y += y;
}

/**
 * Обновляет центр камера на основе привязанного объекта
 **/
void Camera::updateCenter(sf::Vector2i border)
{
    if(this->targetObject->getInCenter())
    {
        this->moveCenter(1, 0, border);
    }
}

/**
 * Отображение уровня
 **/
void Camera::renderLevel(
    sf::RenderWindow& window,
    std::shared_ptr<TileMap> tileMap,
    std::shared_ptr<TileContainer> tileContainer,
    bool updateCenter
)
{
    if(updateCenter) this->updateCenter(tileMap->getSize());

    int i = this->center.y - this->offset.y;
    sf::Vector2f tilePosition(0.0f, 0.0f);
    const float tileOffset = TileContainer::TILE_SIZE;

    for(i; i < this->center.y + this->offset.y; i++)
    {
        int j = this->center.x - this->offset.x;
        for(j; j < this->center.x + this->offset.x; j++)
        {
            char identityTile = tileMap->getTile(i, j);

            if(tileContainer->emptyTile(identityTile))
            {
                tilePosition.x += tileOffset;
                continue;
            }

            sf::Sprite tile = tileContainer->getTileByIdentity(identityTile);
            tile.setPosition(tilePosition);
            window.draw(tile);

            tilePosition.x += tileOffset;
        }

        tilePosition.y += tileOffset;
        tilePosition.x = 0;
    }
}

/**
 * Отображение игровых персонажей
 **/
void Camera::renderActors(std::vector<std::shared_ptr<Character>> actors, sf::RenderWindow& window)
{
    for(const auto& actor: actors)
    {
        actor->draw(window);
    }
}

/**
 * Обновление viewport'а игры
 **/
void Camera::update(
    sf::RenderWindow& window,
    std::shared_ptr<TileMap> tileMap,
    std::shared_ptr<TileContainer> tileContainer,
    std::vector<std::shared_ptr<Character>> actors,
    bool updateCenter
)
{
    this->renderLevel(window, tileMap, tileContainer, updateCenter);
    this->renderActors(actors, window);
}
