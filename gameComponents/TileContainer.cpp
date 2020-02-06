#include "TileContainer.hpp"

TileContainer::TileContainer()
{
    const std::string pathToAsset = "assets/game/tile";

    std::map<char, std::string> tile = {
        {'s', pathToAsset + "/stone.png"},
        {'m', pathToAsset + "/m.png"}
    };

    for(auto const& [identityTile, path] : tile)
    {
        //Make texture
        std::shared_ptr<sf::Texture> texture(new sf::Texture());
        texture->loadFromFile(path);
        this->tileTexture.push_back(texture);

        //Make sprite
        std::shared_ptr<sf::Sprite> sprite(new sf::Sprite());
        sprite->setTexture(*this->tileTexture[this->tileTexture.size() - 1]);
        this->tileSprite[identityTile] = sprite;
    }
}

bool TileContainer::emptyTile(char tileIdentity)
{
    return tileIdentity == '0';
}

sf::Sprite& TileContainer::getTileByIdentity(char tileIdentity)
{
    return *this->tileSprite[tileIdentity];
}