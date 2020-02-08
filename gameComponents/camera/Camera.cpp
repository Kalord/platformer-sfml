#include "Camera.hpp"

Camera::Camera(int x, int y) : center({x, y}), offset(center)
{
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
 * Отображение уровня
 **/
void Camera::renderLevel(
    sf::RenderWindow& window,
    std::shared_ptr<TileMap> tileMap,
    std::shared_ptr<TileContainer> tileContainer
)
{
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
    std::vector<std::shared_ptr<Character>> actors
)
{
    this->renderLevel(window, tileMap, tileContainer);
    this->renderActors(actors, window);
}