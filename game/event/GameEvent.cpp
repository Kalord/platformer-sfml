#include "GameEvent.hpp"

void GameEvent::scrollSceneFront(std::shared_ptr<Camera> camera, sf::Vector2i sizeTileMap)
{
    camera->moveCenter(1, 0, sizeTileMap);
}

void GameEvent::scrollSceneBack(std::shared_ptr<Camera> camera, sf::Vector2i sizeTileMap)
{
    camera->moveCenter(-1, 0, sizeTileMap);
}