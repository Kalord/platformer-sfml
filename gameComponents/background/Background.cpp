#include "Background.hpp"

void Background::addLayer(std::string pathToAsset)
{
    this->backgroundTexture.push_back(std::shared_ptr<sf::Texture>(new sf::Texture()));
    this->backgroundTexture[this->backgroundTexture.size() - 1]->loadFromFile(pathToAsset);
    this->backgroundSprite.push_back(std::shared_ptr<sf::Sprite>(new sf::Sprite()));
    this->backgroundSprite[this->backgroundSprite.size() - 1]->setTexture(*this->backgroundTexture[this->backgroundTexture.size() - 1]);
}

void Background::draw(sf::RenderWindow& window)
{
    //@tmp
    const float offsetX = 240.0f;
    const float offsetY = 176.0f;
    float currentOffsetX = 0.0f;
    float currentOffsetY = 0.0f;

    while(currentOffsetY <= 600)
    {
        for(int i = 0; i < this->backgroundSprite.size(); i++)
        {
            this->backgroundSprite[i]->setPosition(currentOffsetX, currentOffsetY);
            window.draw(*this->backgroundSprite[i]);
        }
        if(currentOffsetX >= 800)
        {
            currentOffsetX = 0;
            currentOffsetY += offsetY;
            continue;
        }
        currentOffsetX += offsetX;
    }
    //@tmp
}