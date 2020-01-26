#include "MainMenu.hpp"

MainMenu::MainMenu(std::string pathToBackground, Nav* nav)
{
    this->backgroundTexture.loadFromFile(pathToBackground);
    this->background.setTexture(this->backgroundTexture);

    this->background.setScale(
        (Settings()).getWidthWindow()  / this->background.getLocalBounds().width,
        (Settings()).getHeightWindow() / this->background.getLocalBounds().height
    );

    this->nav = nav;
}

Nav* MainMenu::getNav()
{
    return this->nav;
}

sf::Drawable& MainMenu::show()
{
    return this->background;
}