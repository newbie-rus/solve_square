#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square.h"

//---------------------------------------------------------------------------
//!Решает квадратное уравнение ax^2 + bx + c = 0
//!
/// @param [in]  a  a - коеффициент
/// @param [in]  b  b - коеффициент
/// @param [in]  c  c - коеффициент
/// @param [out] x1  x1 - значение первого корня уравнения
/// @param [out] x2  x2 - значение второго корня уравнения
/// @return количество корней
/// @note В случае бесконечного количества корней возвращает INFINITY_ROOTS
//---------------------------------------------------------------------------

int main()
{
    // TODO move colors to lib
    // #define RED_COLOR() ...

    #ifdef TEST
        printf("\033[33m**HELLO TEST MODE**\033[0m\n");
        test();
    #else
        printf("\033[33m**HELLO USER MODE**\033[0m\n");
        printf ("Ваше уравнение имеет вид аx^2 + bx + c = 0, если нет, то приведите к данному виду.\n");

        double coefficients[AMOUNT_COEFFS] = {NAN, NAN, NAN};
        double roots       [AMOUNT_ROOTS]  = {NAN, NAN};

        input_coefficient ('a', coefficients);
        input_coefficient ('b', coefficients);
        input_coefficient ('c', coefficients);

        int solutions = NO_VALID_ROOTS;
        solutions = solve_equation (coefficients, roots);

        output_roots (solutions, roots);
    #endif
    return 0;
}
