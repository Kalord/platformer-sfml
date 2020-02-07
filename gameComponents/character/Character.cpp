#include "Character.hpp"

Character::Character()
{
    this->timer = time(NULL);
}

u_int32_t Character::getLife()
{
    return this->life;
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