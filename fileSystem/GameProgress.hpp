#pragma once

#include <string>

/**
 * Класс для работы с игровым прогрессом
 * Игровой прогресс, по умолчанию находится в configs/progress.json
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class GameProgress
{
public:
    GameProgress(std::string pathToFileWithProgress = "configs/progress.json");
    /**
     * Проверяет, существует ли прогресс
     **/
    bool exists();  
};