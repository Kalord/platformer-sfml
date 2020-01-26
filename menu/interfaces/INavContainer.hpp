#pragma once

#include "../Nav.hpp"

/**
 * Данный интерфейс реализуют те классы, которые хранят объект навигации
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
class INavContainer
{
public:
    virtual Nav* getNav() = 0;
};