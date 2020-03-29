#pragma once

#include <iostream>

#define DEBUG 1

/**
 * Класс для работы с отладкой
 *
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 */
class Debug
{
public:
    static void consoleMessage(std::string message);
};
