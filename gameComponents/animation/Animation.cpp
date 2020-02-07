#include "Animation.hpp"

void Animation::addFrame(std::string pathToFrame)
{
    this->texures.push_back(
        std::shared_ptr<sf::Texture>(new sf::Texture())
    );
    this->texures[this->texures.size() - 1]->loadFromFile(pathToFrame);

    this->frames.push_back(
        std::shared_ptr<sf::Sprite>(new sf::Sprite())
    );
    this->frames[this->frames.size() - 1]->setTexture(*this->texures[this->texures.size() - 1]);
}

sf::Sprite Animation::getFrame()
{
    if(this->currentFrame >= this->frames.size()) currentFrame = 0;
    currentFrame++;
    return *this->frames[currentFrame - 1];
}