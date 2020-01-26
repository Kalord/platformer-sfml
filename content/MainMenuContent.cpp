#include "MainMenuContent.hpp"

std::vector<std::pair<std::string, StateInt>> MainMenuContent::get(std::string lang)
{
    if(lang == "ru")
    {
        return std::vector<std::pair<std::string, StateInt>>{
            {"Продолжить", 3},
            {"Новая игра", 3},
            {"Настройки", 2},
            {"Выход", -1}
        };
    }

    return std::vector<std::pair<std::string, StateInt>>{
        {"Continue", 3},
        {"New game", 3},
        {"Settings", 2},
        {"Exit", -1}
    };
}