#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include "../../gameComponents/camera/Camera.hpp"
#include "../../gameComponents/character/Character.hpp"

/**
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class GameEvent
{
public:
    void scrollSceneFront(std::shared_ptr<Camera> camera, sf::Vector2i sizeTileMap);
    void scrollSceneBack(std::shared_ptr<Camera> camera, sf::Vector2i sizeTileMap);

    void moveCharacterFront(std::shared_ptr<Character> character);
};