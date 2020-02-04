#include "Scene.hpp"

std::shared_ptr<Camera>& Scene::getCamera()
{
    return this->camera;
}