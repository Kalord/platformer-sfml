#include "GameEvent.hpp"

void GameEvent::scrollSceneFront(std::shared_ptr<Camera> camera)
{
    camera->moveCenter(1, 0);
}

void GameEvent::scrollSceneBack(std::shared_ptr<Camera> camera)
{
    camera->moveCenter(-1, 0);
}