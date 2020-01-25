#pragma once

#include <SFML/Graphics.hpp>

/**
 * Данный интерфейс реализуют те классы, которые будут отображаться
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class IShow
{
public:
    virtual sf::Drawable& show() = 0;
    virtual ~IShow() {}
};