#pragma once

#include "IContent.hpp"
#include "../game/state/StateType.hpp"

/**
 * Контент для главного меню
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class MainMenuContent : public IContent
{
public:
    std::vector<std::pair<std::string, StateInt>> get(std::string lang) override;
};