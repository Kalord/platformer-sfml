#pragma once

#include <utility>
#include <vector>
#include <string>
#include <sys/types.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <fstream> 

/**
 * Класс для работы с конфигурацией игры
 * 
 * Данный класс по умолчанию получает конфигурационные данные из файла configs/app.json
 * Пример конфигурационного файла:
 * JSON```
 * {
 *      "screen": 1,            //Индекс разрешения экрана из вектора screenList
 *      "language": 'en',       //Текущий язык
 *      "music": true,          //Указывает, включена ли музыка
 *      "soundEffects": true    //Указывает, включены ли звуковые эффекты
 * }
 * ```
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Settings
{
private:
    /**
     * Конфигурационный файл
     **/
    boost::property_tree::ptree json;
    /**
     * Вектор со всеми возможными разрешениями экрана
     **/ 
    std::vector<std::pair<u_int32_t, u_int32_t>> screenList = {
        {800, 600},
        {1024, 768},
        {1440, 900}
    };
public:
    Settings(const std::string& pathToConfig = "configs/app.json");
    /**
     * Ширина окна
     **/
    u_int32_t getWidthWindow();
    /**
     * Высота окна
     **/
    u_int32_t getHeightWindow();
    /**
     * Получение языка
     **/
    std::string getLanguage();
    /**
     * Определяет, нужно ли включать музыку в игре
     **/
    bool powerMusic();
    /**
     * Определяет, нужно ли включать звуковые эффекты в игре
     **/
    bool powerSoundEffects();
};