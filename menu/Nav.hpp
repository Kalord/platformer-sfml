#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <string>
#include <utility>
#include <sys/types.h>

#include "Button.hpp"
#include "../fileSystem/Settings.hpp"

/**
 * Данный класс выражает сущность меню
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Nav
{
private:
    /**
     * Кнопки
     **/
    std::vector<std::shared_ptr<Button>> buttons;
    /**
     * Индекс активной кнопки
     **/
    u_int32_t indexOfActiveButton;
public:
    Nav(std::vector<std::pair<std::string, StateInt>> content, std::string pathToFont);

    u_int32_t getActive();
    void setActive(u_int32_t index);

    std::vector<std::shared_ptr<Button>> getButtons();
};