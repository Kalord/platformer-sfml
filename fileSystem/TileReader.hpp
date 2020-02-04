#pragma once

#include <vector>
#include <string>
#include <fstream>

/**
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class TileReader
{
public:
    /**
     * Загрузка тайловой карты из файла
     **/
    static void load(std::string pathToFile, std::vector<std::vector<char>>& tileMap);
};