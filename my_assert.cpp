#include <stdio.h>
#include "square_func_prototype.h"

/**
 * @file
 */
bool my_assert(bool condition, const char* error, const char* file, const char* func, int line)
{
    if (condition)
    {
        printf("Сбой в программе ошибка: %s\n"
               "файл: %s, функция: %s, строка: %d\n", error, file, func, line);
        return true;
    }

    else
        return false;
}
