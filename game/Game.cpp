#include "Game.hpp"

Game::Game(Settings settings) : settings(settings)
{
    State::globalState()->setState(StateType::MAIN_MENU);
}

/**
 * Запуск игры
 **/
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
        while (window.pollEvent(event)) Event::handle(window, event);

        window.clear();
        window.display();
    }
}