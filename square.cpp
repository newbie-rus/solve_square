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
/// @return Количество корней
/// @note В случае бесконечного количества корней возвращает INFINITY_ROOTS
//---------------------------------------------------------------------------

int main()
{
    #ifdef TEST
        printf("\033[33m**HELLO TEST MODE**\033[0m\n");
        test();
    #else
        printf("\033[33m**HELLO USER MODE**\033[0m\n");
        printf ("Ваше уравнение имеет вид аx^2 + bx + c = 0, если нет, то привидите к данному виду.\n");
        double a = input_coefficient ('a'),
               b = input_coefficient ('b'),
               c = input_coefficient ('c');

        double x1 = NAN,
               x2 = NAN;
        int solutions = NO_VALID_ROOTS;
        solve_equation (a, b, c, &x1, &x2, &solutions);

        output_roots (solutions, x1, x2);
    #endif
    return 0;
}
