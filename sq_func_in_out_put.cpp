#include <stdio.h>
#include "sq.h"
#include <math.h>

/**
 * @file
 */

void input_coefficient (char name, long double* coefficient)
{
    printf ("Введите значение коэффициента \'%c\': \n", name);

    long double coeff = NAN;
    while (scanf ("%Lf", &coeff) == 0 || isfinite(coeff) == 0)
    {
        clear_the_input_buffer ();

        printf ("Введено некоректное значение, попробуйте ввести коэффициент \'%c\' заново:\n", name);
    }

    clear_the_input_buffer ();

    switch(name)
    {
        case 'a':
            coefficient[A_COEFF] = coeff;
            break;

        case 'b':
            coefficient[B_COEFF] = coeff;
            break;

        case 'c':
            coefficient[C_COEFF] = coeff;
            break;

        default:
            printf("Функции input_coefficient() передано неправильное имя коэффициента");
    }
}

int output_roots (int solutions, long double* roots)
{
    if (my_assert ((roots == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }

    long double x1 = roots[X1],
                x2 = roots[X2];

    switch (solutions)
    {
        case NO_ROOTS:
            printf ("Уравнение не имеет корней\n");
            break;

        case ONE_ROOT:
            printf ("Уравнение имеет один корень\nx = %Lf\n", x1);
            break;

        case TWO_ROOTS:
            printf ("Уравнение имеет два корня\nx1 = %Lf\nx2 = %Lf\n", x1, x2);
            break;

        case INFINITY_ROOTS:
            printf ("Уравнение имеет бесконечное множество решений\n");
            break;

        default:
            printf ("ERROR. Произошел сбой: solutions = %d\n", solutions);
    }

    return 0;
}
