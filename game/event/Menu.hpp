#pragma once

#include "../../menu/interfaces/INavContainer.hpp"

/**
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Menu
{
public:
    void moveActiveToTop(INavContainer* container);
    void moveActiveToBotton(INavContainer* container);
};