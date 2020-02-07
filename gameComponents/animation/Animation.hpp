#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <memory>

/**
 * Базовый класс для контейнеров с анимацией
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Animation
{
protected:
    /**
     * Текущий кадр
     **/
    int currentFrame;
    /**
     * Кадры
     **/
    std::vector<std::shared_ptr<sf::Texture>> texures;
    std::vector<std::shared_ptr<sf::Sprite>> frames;

    void addFrame(std::string pathToFrame);
public:
    sf::Sprite getFrame();
};