#include "Game.hpp"

Game::Game(Settings settings) : settings(settings)
{
    State::globalState()->setState(StateType::MAIN_MENU);
}

void Game::run()
{
    sf::RenderWindow window(
        sf::VideoMode(
            this->settings.getWidthWindow(), 
            this->settings.getHeightWindow()
        ), 
        "Game"
    );

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        window.display();
    }
}