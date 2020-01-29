#pragma once

/**
 * Интерфейс, определяющий семейство игровых компонентов
 * Игровой компонент - это такой компонент, которые непосредственно
 * находится в игровом мире
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class IComponent
{
public:
    virtual IComponent() {}
};