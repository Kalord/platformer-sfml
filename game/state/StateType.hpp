#pragma once

using StateInt = int;

/**
 * Типы состояний игры
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class StateType
{
public:
    /**
     * Игра не инициализированна
     **/
    static const StateInt NONE = -1;
    /**
     * Игрок находится в главном меню
     **/
    static const StateInt MAIN_MENU = 1;
    /**
     * Игрок находится в меню настроек
     **/
    static const StateInt SETTINGS_MENU = 2;
    /**
     * Игрок находится в новой игре
     **/
    static const StateInt NEW_GAME = 3;
    /**
     * Продолжение начатой игры
     **/
    static const StateInt CONTINUE = 4;
};