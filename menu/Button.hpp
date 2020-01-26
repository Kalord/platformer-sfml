#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <sys/types.h>

#include "../game/state/StateType.hpp"
#include "../game/IShow.hpp"

/**
 * Сущность кнокпи
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Button : public IShow
{
private:
    /**
     * Заголовок кнопки
     **/
    std::string title;
    /**
     * Ссылка на новое состояние
     **/
    StateInt link;
    /**
     * Шрифт заголовка
     **/
    sf::Font fontOfTitle;
    /**
     * Позиция кнопки
     **/
    sf::Vector2f position;
    /**
     * Кнопка
     **/
    sf::Text button;
    /**
     * Указывает на то, является ли кнопка активной
     **/
    bool active;
public:
    Button(std::string title, StateInt link, std::string pathToFont, u_int32_t sizeOfTitle, sf::Vector2f position);
    StateInt getLink();
    void toggleActive();
    sf::Drawable& show() override;
};