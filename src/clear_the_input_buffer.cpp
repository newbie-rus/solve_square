#include <stdio.h>
#include "square_func_prototype.h"
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
