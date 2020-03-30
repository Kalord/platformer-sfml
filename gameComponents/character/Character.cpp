#include "Character.hpp"

Character::Character()
{
    this->timer = time(NULL);
}

void Character::bindCollisionComponent(std::shared_ptr<CollisionComponent> collision)
{
    this->collision = collision;
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

bool Character::canMove()
{
    return !this->collision->detectedFront();
}

void Character::beforeMove()
{
    while(!this->collision->detectedBottom()) this->down();
}

void Character::moveFront()
{
    if(!this->canMove()) return;

    this->position.x++;

    this->sprite.setPosition(
        this->position.x * TileContainer::TILE_SIZE,
        this->position.y * TileContainer::TILE_SIZE
    );

    this->beforeMove();
}

void Character::moveBack()
{

}

void Character::down()
{
    Debug::consoleMessage("Down");
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
