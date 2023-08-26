#include <stdio.h>
#include "sq.h"
#include <math.h>

/**
 * @file
 *
 * @brief Решает квадратные уравнения вида ax^2 +bx +c
 *
 * @param [in]  a    a -  коэффициент уравнения
 * @param [in]  b    b -  коэффициент уравнения
 * @param [in]  c    c -  коэффициент уравнения
 *
 * @param [out] x1   x1 - первый корень уравнения
 * @param [out] x2   x2 - второй корень уравнения
 *
 * @return int  Количество корней в пользовательском режиме и количество успешно пройденных тестов в тестовом режиме
 *
 * @note  В случае бесконечного количества корней в пользовательском режиме возвращает INFINITY_ROOTS
 */
int main()
{
    #ifdef TEST
        color_output(hello_t, YELLOW);
        if (test() == -1)
        {
            printf ("Аварийное завершение функции");
            return -1;
        }
        return 0;
    #else
        color_output(hello_u, YELLOW);
        printf ("Ваше уравнение имеет вид аx^2 + bx + c = 0, если нет, то приведите к данному виду.\n");

        long double coefficients[AMOUNT_COEFFS] = {NAN, NAN, NAN};
        long double roots       [AMOUNT_ROOTS]  = {NAN, NAN};

        input_coefficient ('a', coefficients);
        input_coefficient ('b', coefficients);
        input_coefficient ('c', coefficients);

        int solutions = NO_VALID_ROOTS;
            solutions = solve_equation (coefficients, roots);
        if (solutions == -1)
        {
            printf ("Аварийное завершение функции");
            return -1;
        }

        if (output_roots (solutions, roots) == -1)
        {
            printf ("Аварийное завершение функции");
            return -1;
        }
        return solutions;
    #endif
}
