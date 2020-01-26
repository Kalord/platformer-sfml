#pragma once

#include "IContent.hpp"

/**
 * Контент для главного меню
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class MainMenuContent : public IContent
{
public:
    std::vector<std::string> get(std::string lang) override;
};