#pragma once

#include "StateType.hpp"

/**
 * Глобальное состояние игры
 * 
 * Данный класс хранит текущие состояние игры,
 * представленное константным целым числом.
 * 
 * Константные числа состояний хранятся в game/StateType.hpp
 * Все состояния:
 *      - NONE          Игра не инициализированна
 *      - MAIN_MENU     Игрок находится в главном меню
 *      - SETTING_MENU  Игрок находится в меню настроек
 *      - GAME          Игрок находится в игре
 * 
 * Данный класс реализует паттерн проектирования "Одиночка"
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class State
{
private:
    /**
     * Объект игрового состояния
     **/
    static inline State* state = nullptr;
    /**
     * Текущие состояние игры
     **/
    StateInt currentState = StateType::NONE;
public:
    /**
     * Получение доступа к глобальному состоянию игры
     **/
    static State* globalState();
    /**
     * Получение состояния игры
     **/
    StateInt getState();
    /**
     * Изменение состояния
     **/
    void setState(StateInt state);
};