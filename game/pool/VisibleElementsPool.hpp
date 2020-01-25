#pragma once

#include <map>

#include "../IShow.hpp"
#include "VisibleIndex.hpp"

/**
 * Пулл игровых элементов, которые в данный момент находятся
 * в поле зрения игрока
 * 
 * Данный класс реализует паттерны проектирования:
 *      -Объектный пулл
 *      -Одиночка
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class VisibleElementsPool
{
private:
    /**
     * Пулл игровых элементов
     **/
    std::map<int, IShow*> pool;
    /**
     * Объект класса
     **/
    static inline VisibleElementsPool* elementsPool = nullptr;
public:
    static VisibleElementsPool* getPool();
    
    void insert(int index, IShow* element);
    IShow* get(int index);
    void remove(int index);
    void removeAll();
};