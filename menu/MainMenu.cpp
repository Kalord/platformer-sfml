#include "MainMenu.hpp"

MainMenu::MainMenu(std::string pathToBackground, Settings settings)
{
    this->backgroundTexture.loadFromFile(pathToBackground);
    this->background.setTexture(this->backgroundTexture);

    this->background.setScale(
        settings.getWidthWindow()  / this->background.getLocalBounds().width,
        settings.getHeightWindow() / this->background.getLocalBounds().height
    );
}

sf::Drawable& MainMenu::show()
{
    return this->background;
}