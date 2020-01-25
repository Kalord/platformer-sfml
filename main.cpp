#include <string>

#include "game/Game.hpp"
#include "fileSystem/Settings.hpp"

#include "menu/MainMenu.hpp"

int main()
{
    Settings settings;
    MainMenu mainMenu("assets/img/menu/main-background.png", settings);    

    (Game(settings)).run(mainMenu);
    
    return 0;
}