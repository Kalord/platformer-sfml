#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "../game/IShow.hpp"
#include "../fileSystem/Settings.hpp"

/**
 * Главное меню
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class MainMenu : public IShow
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
public:
    MainMenu(std::string pathToBackground, Settings settings);

    sf::Drawable& show() override;
};