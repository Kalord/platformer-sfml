#include "Game.hpp"

void Game::gameLoop(sf::RenderWindow& window)
{
    Debug::consoleMessage("2)Start game loop");

    while(window.isOpen())
    {
        StateInt currentState = State::globalState()->getState();
        bool updateCenter = false;
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
                    Debug::consoleMessage("3)Press D:");

                    if(this->scene->getCamera()->targetInCenter())
                    {
                        this->scene->getMainCharacter()->setInCenter(true);
                    }

                    if(!this->scene->getMainCharacter()->getInCenter())
                    {
                        Debug::consoleMessage("   - Target is not in center");
                        Debug::consoleMessage("   - Move character front");
                        this->getEventSystem().game()->moveCharacterFront(this->scene->getMainCharacter());
                    }
                    else
                    {
                        updateCenter = true;
                    }
                }
                if(event.key.code == sf::Keyboard::A)
                {
                    this->getEventSystem().game()->scrollSceneBack(this->scene->getCamera(), this->scene->getSizeTileMap());
                }
            }
        }

        window.clear();
        this->scene->draw(window, updateCenter);
        window.display();
    }
}

/**
 * Запуск новой игры
 **/
void Game::newGame(sf::RenderWindow& window)
{
    Debug::consoleMessage("1)Start new game");

    this->scene = std::shared_ptr<Scene>(new FirstLevel());
    gameLoop(window);
}

void Game::continueGame(sf::RenderWindow& window)
{
    //if(!this->gameProgress->exists()) this->newGame(window);
}
