#include <stdio.h>
#include "square.h"

/**
 * @file
 */
bool my_assert(bool data, const char* error, const char* file, const char* func, int line)
{
    if (data)
    {
        printf("Сбой в программе ошибка: %s\n"
               "файл: %s, функция: %s, строка: %d\n", error, file, func, line);
        return true;
    }
    else
        return false;
}
