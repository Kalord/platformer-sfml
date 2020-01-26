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

void Menu::updateState(INavContainer* container)
{
    Nav* nav = container->getNav();
    std::shared_ptr<Button> button = nav->getButton(nav->getActive());
    State::globalState()->setState(button->getLink());
}