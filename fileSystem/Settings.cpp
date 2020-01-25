#include "Settings.hpp"

Settings::Settings(const std::string& pathToConfig)
{
    std::ifstream config(pathToConfig);
    boost::property_tree::read_json(config, this->json);
}

/**
 * Ширина окна
 **/
u_int32_t Settings::getWidthWindow()
{
    int index = this->json.get<int>("screen");
    return this->screenList[index].first;
}
/**
 * Высота окна
 **/
u_int32_t Settings::getHeightWindow()
{
    int index = this->json.get<int>("screen");
    return this->screenList[index].second;
}

/**
 * Получение языка
 **/
std::string Settings::getLanguage()
{
    return this->json.get<std::string>("language");
}

/**
 * Определяет, нужно ли включать музыку в игре
 **/
bool Settings::powerMusic()
{
    return this->json.get<bool>("music");
}
/**
 * Определяет, нужно ли включать звуковые эффекты в игре
 **/
bool Settings::powerSoundEffects()
{
    return this->json.get<bool>("soundEffects");
}