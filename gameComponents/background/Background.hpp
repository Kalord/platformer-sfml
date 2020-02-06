#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

#include "../IComponent.hpp"

/**
 * Базовый класс для фона
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Background
{
protected:
    std::vector<std::shared_ptr<sf::Texture>> backgroundTexture;
    std::vector<std::shared_ptr<sf::Sprite>> backgroundSprite;
public:
    void addLayer(std::string pathToAsset);
    void draw(sf::RenderWindow& window);
};