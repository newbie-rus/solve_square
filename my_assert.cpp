#include <stdio.h>
#include "sq.h"

/**
 * @file
 */
bool my_assert(bool data, const char* error) 
// TODO if you made this as a define, not as function, you can use __LINE__, __FILE__ here
// Also, using define, you can avoid checking the result of my_assert by just returning direcly from caller function 
// "data" is a bad name for condition
{
    if (data)
    {
        printf("Сбой в программе ошибка: %s\n", error);
        return true;
    }
    else
        return false;
}
