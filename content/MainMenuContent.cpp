#include "MainMenuContent.hpp"

std::vector<std::string> MainMenuContent::get(std::string lang)
{
    if(lang == "ru")
    {
        return std::vector<std::string>{
            "Продолжить",
            "Новая игра",
            "Настройки",
            "Выход"
        };
    }

    return std::vector<std::string>{
        "Continue",
        "New game",
        "Settings",
        "Exit"
    };
}