#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "../IComponent.hpp"

/**
 * Базовый класс для игровых фонов
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Background : public IComponent
{
protected:
    /**
     * Текстуры фона
     **/
    std::vector<sf::Texture> backgroundTexture;
    /**
     * Спрайт фона
     **/
    std::vector<sf::Sprite> backgroundSprite;
public:
    virtual ~Background() {}

    std::vector<sf::Texture>& getBackground();
};