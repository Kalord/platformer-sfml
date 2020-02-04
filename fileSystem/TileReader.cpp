#include "TileReader.hpp"

/**
 * Загрузка тайловой карты из файла
 **/
void TileReader::load(std::string pathToFile, std::vector<std::vector<char>>& tileMap)
{
    std::ifstream tileMapFile(pathToFile);

    int identity;
    tileMap.push_back(std::vector<char>());

    while((identity = tileMapFile.get()) != EOF)
    {
        if(identity == '\n')
        {
            tileMap.push_back(std::vector<char>());
            continue;
        }
        tileMap[tileMap.size() - 1].push_back(identity);
    }
}