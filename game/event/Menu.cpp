#include "Menu.hpp"

void Menu::moveActiveToTop(INavContainer* container)
{
    Nav* nav = container->getNav();
    nav->setActive(nav->getActive() - 1);
}

void Menu::moveActiveToBotton(INavContainer* container)
{
    Nav* nav = container->getNav();
    nav->setActive(nav->getActive() + 1);
}