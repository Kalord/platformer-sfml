#include "Game.hpp"

Game::Game() : event(Event{})
{
}

void Game::gameLoop(sf::RenderWindow& window)
{
    while(window.isOpen())
    {
        StateInt currentState = State::globalState()->getState();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->event.common()->close(window);
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::D)
                {
                    this->event.game()->scrollSceneFront(this->scene->getCamera());
                }
                if(event.key.code == sf::Keyboard::A)
                {
                    this->event.game()->scrollSceneBack(this->scene->getCamera());
                }
            }
        }

        window.clear();
        this->scene->draw(window);
        window.display();
    }
}

void Game::newGame(sf::RenderWindow& window)
{
    this->scene = std::shared_ptr<Scene>(new FirstLevel());
    gameLoop(window);
}

void Game::continueGame(sf::RenderWindow& window)
{
    //if(!this->gameProgress->exists()) this->newGame(window);
}