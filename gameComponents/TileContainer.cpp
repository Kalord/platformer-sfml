#include "TileContainer.hpp"

TileContainer::TileContainer()
{
    const std::string pathToAsset = "assets/game/tile";

    std::map<char, std::string> tile = {
        {'p', pathToAsset + "/platform.png"},
        {'m', pathToAsset + "/mushroom.png"},
        {'r', pathToAsset + "/rock.png"},
        {'l', pathToAsset + "/rock_2.png"}
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

sf::Sprite& TileContainer::getTileByIdentity(char tileIdentity)
{
    return *this->tileSprite[tileIdentity];
}