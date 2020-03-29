#include "Character.hpp"

Character::Character()
{
    this->timer = time(NULL);
}

u_int32_t Character::getLife()
{
    return this->life;
}

sf::Vector2i Character::getTilePosition()
{
    return this->position;
}

bool Character::getInCenter()
{
    return this->inCenter;
}

void Character::setInCenter(bool value)
{
    this->inCenter = value;
}

void Character::baseState()
{
    if(time(NULL) - this->timer >= this->speedBase)
    {
        this->sprite = this->baseAnimation->getFrame();
        this->timer = time(NULL);
    }
}

void Character::moveFront()
{
    this->position.x++;

    this->sprite.setPosition(
        this->position.x * TileContainer::TILE_SIZE,
        this->position.y * TileContainer::TILE_SIZE
    );
}

void Character::moveBack()
{

}

void Character::jump()
{

}

void Character::attack()
{

}

void Character::draw(sf::RenderWindow& window)
{
    window.draw(this->sprite);
}
