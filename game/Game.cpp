#include "Game.hpp"

Game::Game() : gameProgress(GameProgress())
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
            //...
        }

        window.clear();
        this->scene->draw(window);
        window.display();
    }
}

void Game::newGame(sf::RenderWindow& window)
{
    this->scene = std::make_shared<Scene>(new FirstLevel());
    gameLoop(window);
}

void Game::continueGame(sf::RenderWindow& window)
{
    //if(!this->gameProgress->exists()) this->newGame(window);
}