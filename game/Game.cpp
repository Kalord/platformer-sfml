#include "Game.hpp"

Game::Game(Settings settings) : settings(settings)
{
    State::globalState()->setState(StateType::MAIN_MENU);
}

/**
 * Запуск игры
 **/
void Game::run(MainMenu& mainMenu)
{
    sf::RenderWindow window(
        sf::VideoMode(
            this->settings.getWidthWindow(), 
            this->settings.getHeightWindow()
        ), 
        TITLE
    );

    VisibleElementsPool::getPool()->insert(VisibleIndex::MAIN_MENU, &mainMenu);

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) Event::handle(window, event);

        window.clear();

        if(State::globalState()->getState() == StateType::MAIN_MENU)
        {
            window.draw(mainMenu.show());
        }

        window.display();
    }
}