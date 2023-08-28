#include <stdio.h>
#include "square_func_prototype.h"
#include <math.h>

/**
 * @file
 */


bool iszero (long double num)
{
    if (my_assert(isfinite (num) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    return (fabs (num) < EPSILON);
}


bool equality_double (long double num1, long double num2)
{
    if (my_assert(isfinite (num1) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (num2) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    long double R = (num1 - num2);

    return (fabs (R) < EPSILON);
}

