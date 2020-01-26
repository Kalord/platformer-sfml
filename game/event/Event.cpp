#include "Event.hpp"

/**
 * Обработка событий
 **/
void Event::handle(sf::RenderWindow& window, sf::Event& event)
{
    if(event.type == sf::Event::Closed) window.close();
}