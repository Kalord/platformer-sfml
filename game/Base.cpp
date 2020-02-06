#include "Base.hpp"

Base::Base() : event(Event{})
{}

Event* Base::getEventSystem()
{
    return &this->event;
}