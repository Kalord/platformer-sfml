#include "Event.hpp"

Event::Event()
{
    this->commonEvent = new Common();
    this->menuEvent = new Menu();
}

/**
 * Получение общих событий
 **/
Common* Event::common()
{
    return this->commonEvent;
}


/**
 * Получение событий игрового меню
 **/
Menu* Event::menu()
{
    return this->menuEvent;
}