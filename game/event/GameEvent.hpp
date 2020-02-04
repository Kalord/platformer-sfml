#pragma once

#include <memory>

#include "../../gameComponents/camera/Camera.hpp"

/**
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class GameEvent
{
public:
    void scrollSceneFront(std::shared_ptr<Camera> camera);
    void scrollSceneBack(std::shared_ptr<Camera> camera);
};