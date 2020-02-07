#include "Game.hpp"

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
                this->getEventSystem().common()->close(window);
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::D)
                {
                    this->getEventSystem().game()->scrollSceneFront(this->scene->getCamera(), this->scene->getSizeTileMap());
                }
                if(event.key.code == sf::Keyboard::A)
                {
                    this->getEventSystem().game()->scrollSceneBack(this->scene->getCamera(), this->scene->getSizeTileMap());
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