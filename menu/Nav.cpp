#include "Nav.hpp"

Nav::Nav(std::vector<std::string> titles, std::string pathToFont)
{
    float offsetWidth = (Settings()).getWidthWindow() / 2.5;
    float offsetHeight = (Settings()).getHeightWindow() / 3;
    const float stepHeight = (Settings()).getHeightWindow() / 10;

    for(const auto& title : titles)
    {
        this->buttons.push_back(
            std::shared_ptr<Button>(
                new Button(
                    title,
                    pathToFont,
                    30,
                    sf::Vector2f(offsetWidth, offsetHeight
                )
            )
        ));
        offsetHeight += stepHeight;
    }

    this->indexOfActiveButton = 0;
    this->buttons[this->indexOfActiveButton]->toggleActive();
}

u_int32_t Nav::getActive()
{
    return this->indexOfActiveButton;
}

void Nav::setActive(u_int32_t index)
{
    if(index < 0 || index >= this->buttons.size()) return;

    std::cout << index << std::endl;

    this->buttons[this->indexOfActiveButton]->toggleActive();
    this->indexOfActiveButton = index;
    this->buttons[this->indexOfActiveButton]->toggleActive();
}

std::vector<std::shared_ptr<Button>> Nav::getButtons()
{
    return this->buttons;
}