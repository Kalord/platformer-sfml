#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <sys/types.h>
#include <time.h>

#include "../IComponent.hpp"
#include "../animation/Animation.hpp"

/**
 * Базовый класс для персонажа
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Character : public IComponent
{
protected:
    /**
     * Текущие количество жизней
     **/
    u_int32_t life;
    /**
     * Скорость персонажа
     **/
    u_int32_t speedBase;
    u_int32_t speedMove;
    u_int32_t speedJump;

    u_int32_t timer;

    sf::Texture texture;
    sf::Sprite sprite;
    /**
     * Позиция персонажа
     **/
    sf::Vector2i position;
    /**
     * Анимации
     **/
    std::shared_ptr<Animation> baseAnimation;
    std::shared_ptr<Animation> moveAnimation;
    std::shared_ptr<Animation> jumpAnimation;
    std::shared_ptr<Animation> attackAnimation;
public:
    Character();
    virtual ~Character() {}

    u_int32_t getLife();
    
    void baseState();
    void moveFront();
    void moveBack();
    void jump();
    void attack();

    void draw(sf::RenderWindow& window);
};