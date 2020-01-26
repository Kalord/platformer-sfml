#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "../game/IShow.hpp"
#include "../fileSystem/Settings.hpp"
#include "Nav.hpp"
#include "interfaces/INavContainer.hpp"

/**
 * Главное меню
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class MainMenu : public IShow, public INavContainer
{
private:
    /**
     * Текстура фона меню
     **/
    sf::Texture backgroundTexture;
    /**
     * Фон меню
     **/
    sf::Sprite background;
    /**
     * Навигация
     **/
    Nav* nav;
public:
    MainMenu(std::string pathToBackground, Nav* nav);

    Nav* getNav() override;

    sf::Drawable& show() override;
};