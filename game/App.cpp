#include "App.hpp"

App::App(Settings settings) : settings(settings), game(Game{})
{
    State::globalState()->setState(StateType::MAIN_MENU);
}

/**
 * Запуск игры
 **/
void App::run(MainMenu& mainMenu)
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
        /**
         * Получаем текущие состояние игры
         **/
        StateInt currentState = State::globalState()->getState();
        sf::Event event;

        /**
         * Обработка событий
         **/
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->getEventSystem().common()->close(window);
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(currentState == StateType::MAIN_MENU)
                {
                    if(event.key.code == sf::Keyboard::Up)
                    {
                        this->getEventSystem().menu()->moveActiveToTop(&mainMenu);
                    }
                    if(event.key.code == sf::Keyboard::Down)
                    {
                        this->getEventSystem().menu()->moveActiveToBotton(&mainMenu);
                    }
                    if(event.key.code == sf::Keyboard::Enter)
                    {
                        this->getEventSystem().menu()->updateState(&mainMenu);
                    }
                }
            }
        }

        window.clear();

        /**
         * Игрок находится в главном меню
         **/
        if(currentState == StateType::MAIN_MENU)
        {
            window.draw(mainMenu.show());
            std::vector<std::shared_ptr<Button>> buttons = mainMenu.getNav()->getButtons();
            for(const auto& button : buttons)
            {
                window.draw(button->show());
            }
        }

        /**
         * Игрок находится в меню настроек
         **/
        if(currentState == StateType::SETTINGS_MENU)
        {
            
        }

        /**
         * Игрок начал новую игру
         **/
        if(currentState == StateType::NEW_GAME)
        {
            this->game.newGame(window);
        }

        /**
         * Игрок находится на стадии выхода из игры
         **/
        if(currentState == StateType::NONE)
        {
            this->event.common()->close(window);
        }

        window.display();
    }
}