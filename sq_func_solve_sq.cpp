#include <stdio.h>
#include <math.h>
#include "sq.h"

/**
 * @file
 */

int solve_equation (long double* coeff, long double* roots)
{
    long double a = coeff[A_COEFF],
           b = coeff[B_COEFF],
           c = coeff[C_COEFF];

    if (my_assert ((isfinite (a) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((isfinite (b) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((isfinite (c) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((coeff == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == coeff), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }

    if (iszero (a) || iszero (c))
        return solution_of_a_linear_equation (coeff, roots);
    else
        return solution_of_a_quadratic_equation (coeff, roots);
}


int solution_of_a_linear_equation (long double* coeff, long double* roots)
{
    long double a = coeff[A_COEFF],
                b = coeff[B_COEFF],
                c = coeff[C_COEFF];

    if (my_assert ((isfinite (a) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((isfinite (b) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((isfinite (c) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((coeff == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == coeff), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }

    if (iszero (c))
    {
        if (iszero (a))
        {
            if (iszero (b))
                return INFINITY_ROOTS;
            else
            {
            roots[X1] = 0;
            return ONE_ROOT;
            }
        }
        else
        if (iszero (b))
        {
            roots[X1] = 0;
            return ONE_ROOT;
        }
        else
        {
            roots[X1] = 0;
            roots[X2] = -b / a;
            return TWO_ROOTS;
        }
    }
    else
    {
        if (!iszero (b))
        {
            roots[X1] = -c / b;
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


int solution_of_a_quadratic_equation (long double* coeff, long double* roots)
{
    long double a = coeff[A_COEFF],
                b = coeff[B_COEFF],
                c = coeff[C_COEFF];

    if (my_assert ((isfinite (a) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((isfinite (b) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((isfinite (c) == 0), ERROR_ISFINITE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((coeff == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == coeff), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }

    long double D = b * b - 4 * a * c;
    if (iszero (D))
    {
        roots[X1] = -b / (2 * a);
        return ONE_ROOT;
    }
    else if (D >= EPSILON)
    {
        long double sqrtD = sqrt (D);
                roots[X1] = (-b + sqrtD) / (2 * a);
                roots[X2] = (-b - sqrtD) / (2 * a);
        return TWO_ROOTS;
    }
    else
        return NO_ROOTS;
}
