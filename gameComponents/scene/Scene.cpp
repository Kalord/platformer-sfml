#include "Scene.hpp"

sf::Vector2i Scene::getSizeTileMap()
{
    return this->tileMap->getSize();
}

std::shared_ptr<Camera>& Scene::getCamera()
{
    return this->camera;
}