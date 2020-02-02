#include "TileContainer.hpp"

TileContainer::TileContainer()
{
    const std::string pathToAsset = "assets/game/tile";

    std::map<char, std::string> tile = {
        {'p', pathToAsset + "/platform.png"},
        {'m', pathToAsset + "/mushroom.png"}
        //{'r', pathToAsset + "/rock.png"},
        //{'l', pathToAsset + "/rock_2.png"}
    };

    for(auto const& [identityTile, path] : tile)
    {
        sf::Texture texture;
        texture.loadFromFile(path);
        this->tileTexture.push_back(sf::Texture(texture));
        this->tileSprite[identityTile] = sf::Sprite(this->tileTexture[this->tileTexture.size() - 1]);
    }
}

sf::Sprite& TileContainer::getTileByIdentity(char tileIdentity)
{
    return this->tileSprite[tileIdentity];
}