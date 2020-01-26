#include "Game.hpp"

Game::Game(Settings settings) : settings(settings), event(Event{})
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

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->event.common()->close(window);
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(State::globalState()->getState() == StateType::MAIN_MENU)
                {
                    if(event.key.code == sf::Keyboard::Up)
                    {
                        this->event.menu()->moveActiveToTop(&mainMenu);
                    }
                    if(event.key.code == sf::Keyboard::Down)
                    {
                        this->event.menu()->moveActiveToBotton(&mainMenu);
                    }                    
                }
            }
        }

        window.clear();

        if(State::globalState()->getState() == StateType::MAIN_MENU)
        {
            window.draw(mainMenu.show());
            std::vector<std::shared_ptr<Button>> buttons = mainMenu.getNav()->getButtons();
            for(const auto& button : buttons)
            {
                window.draw(button->show());
            }
        }

        window.display();
    }
}