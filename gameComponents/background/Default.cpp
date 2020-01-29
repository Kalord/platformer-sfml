#include "Default.hpp"

Default::Default()
{
    const std::string assetsPath = "assets/game/background";
    std::vector<std::string> pathToBackground = {
        assetsPath + "/background.png",
        assetsPath + "/middleground-no-fungus.png",
        assetsPath + "/middleground.png"
    };

    for(const auto& path : pathToBackground)
    {
        sf::Texture texture;
        texture.loadFromFile(path);
        this->backgroundTexture.push_back(texture);
        sf::Sprite sprite(texture);
        this->backgroundSprite.push_back(sprite);
    }
}