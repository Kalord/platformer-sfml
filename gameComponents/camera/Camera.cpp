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
 * Обновление viewport'а игры
 **/
void Camera::update(
    sf::RenderWindow& window,
    std::shared_ptr<TileMap> tileMap,
    std::shared_ptr<TileContainer> tileContainer,
    std::vector<std::shared_ptr<Character>> actors
)
{
    int i = this->center.y - this->offset.y;
    sf::Vector2f tilePosition(0.0f, 0.0f);
    const float tileOffset = TileContainer::TILE_SIZE;

    for(const auto& actor: actors)
    {
        actor->draw(window);
    }    

    for(i; i < this->center.y + this->offset.y; i++)
    {
        int j = this->center.x - this->offset.x;
        for(j; j < this->center.x + this->offset.x; j++)
        {
            char identityTile = tileMap->getTile(i, j);

            //@tmp
            if(tileContainer->emptyTile(identityTile))
            {
                tilePosition.x += tileOffset;
                continue;
            }
            //@tmp

            sf::Sprite tile = tileContainer->getTileByIdentity(identityTile);
            tile.setPosition(tilePosition);
            window.draw(tile);

            tilePosition.x += tileOffset;
        }

        tilePosition.y += tileOffset;
        tilePosition.x = 0;
    }
}