#include "VisibleElementsPool.hpp"

VisibleElementsPool* VisibleElementsPool::getPool()
{
    if(!elementsPool) elementsPool = new VisibleElementsPool();
    return elementsPool;
}

void VisibleElementsPool::insert(int index, IShow* element)
{
    this->pool[index] = element;
}

IShow* VisibleElementsPool::get(int index)
{
    return this->pool[index];
}

void VisibleElementsPool::remove(int index)
{
    this->pool.erase(index);
}

void VisibleElementsPool::removeAll()
{
    this->pool.erase(this->pool.begin(), this->pool.end());
}