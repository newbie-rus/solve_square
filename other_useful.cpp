#include <stdio.h>
#include "sq.h"
#include <math.h>

/**
 * @file
 */

void clear_the_input_buffer (void)
{
    int ch = getchar ();

    while ((ch != '\n') && (ch != EOF))
        ch = getchar ();
}


bool iszero (long double num)
{
    if (my_assert ((isfinite (num) == 0), ERROR_ISFINITE))
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );

    return (fabs (num) < EPSILON);
}


bool equality_double (long double num1, long double num2)
{
    if (my_assert ((isfinite (num1) == 0), ERROR_ISFINITE))
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );

    if (my_assert ((isfinite (num2) == 0), ERROR_ISFINITE))
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );

    long double R = (num1 - num2);

    return (fabs (R) < EPSILON);
}


void color_output (const char* str, int color)
{
    printf ("\033[%dm%s\033[0m\n", color, str);
}
