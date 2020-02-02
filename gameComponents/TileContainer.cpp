#include "TileContainer.hpp"

TileContainer::TileContainer()
{
    std::map<char, std::string> tile = {
        {'p', "assets/platform.png"}
    };

    for(auto const& [identityTile, path] : tile)
    {
        sf::Texture texture;
        texture.loadFromFile(path);
        this->tileTexture.push_back(texture);
        this->tileSprite[identityTile] = sf::Sprite(this->tileTexture[this->tileTexture.size() - 1]); 
    }
}

sf::Sprite& TileContainer::getTileByIdentity(char tileIdentity)
{
    return this->tileSprite[tileIdentity];
}