#pragma once

#include <vector>
#include <utility>
#include <string>
#include "../game/state/StateType.hpp"

/**
 * Интерфейс для контент провайдеров
 * Задача контент провайдеров - доставить данные для игровых элементов
 * В зависимости от настроек языка, данные могут меняться
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class IContent
{
public:
    virtual std::vector<std::pair<std::string, StateInt>> get(std::string lang) = 0;
};