#pragma once

#include <memory>

#include "../../menu/interfaces/INavContainer.hpp"
#include "../../menu/Button.hpp"
#include "../state/State.hpp"

/**
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Menu
{
public:
    void moveActiveToTop(INavContainer* container);
    void moveActiveToBotton(INavContainer* container);
    void updateState(INavContainer* container);
};