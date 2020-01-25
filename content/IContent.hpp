#pragma once

#include <vector>
#include <string>

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
    virtual std::vector<std::string> get() = 0;
};