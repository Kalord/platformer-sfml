#include <string>

#include "game/App.hpp"
#include "fileSystem/Settings.hpp"

#include "menu/MainMenu.hpp"
#include "menu/Nav.hpp"
#include "content/MainMenuContent.hpp"

int main()
{
    Settings settings;
    MainMenuContent content;
    
    Nav nav(
        content.get(settings.getLanguage()),
        "assets/font/RussoOne-Regular.ttf"
    );

    MainMenu mainMenu("assets/img/menu/main-background.png", &nav);

    (App(settings)).run(mainMenu);

    return 0;
}