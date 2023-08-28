#include <stdio.h>
#include <math.h>
#include "square_func_prototype.h"

/**
 * @file
 */

int solve_equation (COEFFS_AND_ROOTS *data)
{
    long double a = data -> a,
                b = data -> b,
                c = data -> c;

    if (my_assert(isfinite (a) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (b) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (c) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(        data == NULL,   PATH_NULL, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    if (iszero (a) || iszero (c))
        return solution_of_a_linear_equation (data);
    else
        return solution_of_a_quadratic_equation (data);
}


int solution_of_a_linear_equation (COEFFS_AND_ROOTS *data)
{
    long double a = data -> a,
                b = data -> b,
                c = data -> c;

    if (my_assert(isfinite (a) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (b) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (c) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(        data == NULL,   PATH_NULL, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    if (iszero (c))
    {
        if (iszero (a))
        {
            if (iszero (b))
                return INFINITY_ROOTS;
            else
            {
            (*data).x1 = 0;
            return ONE_ROOT;
            }
        }
        else
        if (iszero (b))
        {
            (*data).x1 = 0;
            return ONE_ROOT;
        }
        else
        {
            (*data).x1 = 0;
            (*data).x2 = -b / a;
            return TWO_ROOTS;
        }
    }
    else
    {
        if (!iszero (b))
        {
            (*data).x1 = -c / b;
            return ONE_ROOT;
        }
        else
        {
            if (iszero (c))
                return INFINITY_ROOTS;
            else
                return NO_ROOTS;
        }
    }
}


int solution_of_a_quadratic_equation (COEFFS_AND_ROOTS *data)
{
    long double a = data -> a,
                b = data -> b,
                c = data -> c;

    if (my_assert(isfinite (a) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (b) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (c) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(        data == NULL,   PATH_NULL, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    long double D = b * b - 4 * a * c;

    if (iszero (D))
    {
        (*data).x1 = -b / (2 * a);
        return ONE_ROOT;
    }

    else if (D >= EPSILON)
    {
        long double sqrtD = sqrt (D);
                (*data).x1 = (-b + sqrtD) / (2 * a);
                (*data).x2 = (-b - sqrtD) / (2 * a);
        return TWO_ROOTS;
    }

    else
        return NO_ROOTS;
}
