#include <stdio.h>
#include "square_func_prototype.h"
#include <math.h>

/**
 * @file
 */

bool iszero (long double num)
{
    my_assert(isfinite (num) == 0, ERROR_ISFINITE);

    return (fabs (num) < EPSILON);
}

bool equality_double (long double num1, long double num2)
{
    my_assert(isfinite (num1) == 0, ERROR_ISFINITE);
    my_assert(isfinite (num2) == 0, ERROR_ISFINITE);

    long double R = (num1 - num2);

    return (fabs (R) < EPSILON);
}

