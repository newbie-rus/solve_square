#include <stdio.h>
#include <math.h>
#include "square_func_prototype.h"

/**
 * @file
 */

int solve_equation (COEFFS_AND_ROOTS *data)
{
    my_assert(isfinite (data -> a) == 0, ERROR_ISFINITE);
    my_assert(isfinite (data -> b) == 0, ERROR_ISFINITE);
    my_assert(isfinite (data -> c) == 0, ERROR_ISFINITE);
    my_assert(                data == NULL,   PATH_NULL);

    if (iszero (data -> a) || iszero (data -> c))
        return solution_of_a_linear_equation (data);
    else
        return solution_of_a_quadratic_equation (data);
}


int solution_of_a_linear_equation (COEFFS_AND_ROOTS *data)
{
    my_assert(isfinite (data -> a) == 0, ERROR_ISFINITE);
    my_assert(isfinite (data -> b) == 0, ERROR_ISFINITE);
    my_assert(isfinite (data -> c) == 0, ERROR_ISFINITE);
    my_assert(                data == NULL,   PATH_NULL);

    long double a = data -> a,
                b = data -> b,
                c = data -> c;

    if (iszero (data -> c))
    {
        if (iszero (data -> a))
        {
            if (iszero (data -> b))
                return INFINITY_ROOTS;
            else
            {
            (data -> x1) = 0;
            return ONE_ROOT;
            }
        }
        else
        if (iszero (data -> b))
        {
            (data -> x1) = 0;
            return ONE_ROOT;
        }
        else
        {
            (data -> x1) = 0;
            (data -> x2) = -b / a;
            return TWO_ROOTS;
        }
    }
    else
    {
        if (!iszero (data -> b))
        {
            (data -> x1) = -c / b;
            return ONE_ROOT;
        }
        else
        {
            if (iszero (data -> c))
                return INFINITY_ROOTS;
            else
                return NO_ROOTS;
        }
    }
}


int solution_of_a_quadratic_equation (COEFFS_AND_ROOTS *data)
{
    my_assert(isfinite (data -> a) == 0, ERROR_ISFINITE);
    my_assert(isfinite (data -> b) == 0, ERROR_ISFINITE);
    my_assert(isfinite (data -> c) == 0, ERROR_ISFINITE);
    my_assert(                data == NULL,   PATH_NULL);

    long double a = data -> a,
                b = data -> b,
                c = data -> c;

    long double D = b * b - 4 * a * c;

    if (iszero (D))
    {
        (data -> x1) = -b / (2 * a);
        return ONE_ROOT;
    }

    else if (D >= EPSILON)
    {
        long double sqrtD = sqrt (D);
                (data -> x1) = (-b + sqrtD) / (2 * a);
                (data -> x2) = (-b - sqrtD) / (2 * a);
        return TWO_ROOTS;
    }

    else
        return NO_ROOTS;
}
