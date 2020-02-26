#include "State.hpp"

/**
 * Получение доступа к глобальному состоянию игры
 **/
State* State::globalState()
{
    if(!state) state = new State();
    return state;
}

/**
 * Получение состояния игры
 **/
StateInt State::getState()
{
    return this->currentState;
}

/**
 * Изменение состояния
 **/
void State::setState(StateInt state)
{
    this->currentState = state;
}

/**
 * Освобождение ресурса
 **/
void State::freeState()
{
    if(state) delete state;
}