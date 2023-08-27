#include <stdio.h>
#include "sq.h"

/**
 * @file
 */
bool my_assert(bool data, const char* error)
{
    if (data)
    {
        printf("Сбой в программе ошибка: %s\n", error);
        return true;
    }
    else
        return false;
}
