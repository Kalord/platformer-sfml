#pragma once

#include "Common.hpp"
#include "Menu.hpp"
#include "GameEvent.hpp"

/**
 * Фасад для событий игры
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class Event
{
private:
    /**
     * События, общие для игры
     **/
    Common* commonEvent;
    /**
     * События, для игрового меню
     **/
    Menu* menuEvent;
    /**
     * События, происходящие в игре
     **/
    GameEvent* gameEvent;
public:
    Event();
    /**
     * Получение общих событий
     **/
    Common* common();

    /**
     * Получение событий игрового меню
     **/
    Menu* menu();

    /**
     * Получение событий игры
     **/
    GameEvent* game();
};