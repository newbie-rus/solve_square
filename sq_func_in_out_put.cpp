#include <stdio.h>
#include "sq.h"
#include <math.h>

/**
 * @file
 */

long double input_coefficient (char name)
{
    printf ("Введите значение коэффициента \'%c\': \n", name);

    long double coeff = NAN;
    while (scanf ("%Lf", &coeff) == 0 || isfinite(coeff) == 0)
    {
        clear_the_input_buffer ();
        printf ("Введено некоректное значение, попробуйте ввести коэффициент \'%c\' заново:\n", name);
    }

    clear_the_input_buffer ();

    return coeff;
}

int output_roots (COEFFS_AND_ROOTS* data, int solutions)
{
    if (my_assert ((data == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }

    switch (solutions)
    {
        case NO_ROOTS:
            printf ("Уравнение не имеет корней\n");
            break;

        case ONE_ROOT:
            printf ("Уравнение имеет один корень\nx = %Lf\n", data -> x1);
            break;

        case TWO_ROOTS:
            printf ("Уравнение имеет два корня\nx1 = %Lf\nx2 = %Lf\n",data -> x1, data -> x2);
            break;

        case INFINITY_ROOTS:
            printf ("Уравнение имеет бесконечное множество решений\n");
            break;

        default:
            printf ("ERROR. Произошел сбой: solutions = %d\n", solutions);
    }

    return 0;
}
