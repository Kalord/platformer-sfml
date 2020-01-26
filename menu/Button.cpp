#include "Button.hpp"

Button::Button(std::string title, StateInt link, std::string pathToFont, u_int32_t sizeOfTitle, sf::Vector2f position)
{
    this->title = title;
    this->link = link;
    this->position = position;
    this->fontOfTitle.loadFromFile(pathToFont);
    this->button.setPosition(this->position);
    this->button.setFont(this->fontOfTitle);
    this->button.setCharacterSize(sizeOfTitle);
    this->button.setString(this->title);
    this->button.setFillColor(sf::Color::White);
    this->active = false;
}

void Button::toggleActive()
{
    if(this->active)
    {
        this->active = false;
        this->button.setFillColor(sf::Color::White);
        return;
    }
    this->active = true;
    this->button.setFillColor(sf::Color::Blue);
}

sf::Drawable& Button::show()
{
    return this->button;
}