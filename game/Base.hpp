#pragma once

#include "event/Event.hpp"

/**
 * Базовый класс для приложения
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Base
{
protected:
    /**
     * Система событий
     */
    Event event;
public:
    Base();
    virtual ~Base() {}

    Event getEventSystem();
};