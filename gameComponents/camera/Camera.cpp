#include "Camera.hpp"

Camera::Camera(int x, int y) : center({x, y})
{
}

/**
 * Обновление viewport'а игры
 **/
void Camera::update(
    sf::RenderWindow& window,
    std::shared_ptr<TileMap> tileMap,
    std::shared_ptr<TileContainer> tileContainer
)
{
    int i = this->center.y - this->offset.y;
    sf::Vector2f tilePosition(0.0f, 0.0f);
    const float tileOffset = 64.0f;

    for(i; i < this->center.y + this->offset.y; i++)
    {
        int j = this->center.x - this->offset.x;
        for(j; j < this->center.x + this->offset.x; j++)
        {
            char identityTile = tileMap->getTile(i, j);

            //@tmp
            if(identityTile == '0')
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