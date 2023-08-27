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

        COEFFS_AND_ROOTS data = {
                                   input_coefficient ('a'),
                                   input_coefficient ('b'),
                                   input_coefficient ('c'),
                                   NO_VALID_ROOTS,
                                   NAN, NAN,
                                   NAN, NAN
                                 };

        int solutions = solve_equation (&data);

        if (solutions == -1)
        {
            printf ("Аварийное завершение функции");
            return -1;
        }

        if (output_roots (&data, solutions) == -1)
        {
            printf ("Аварийное завершение функции");
            return -1;
        }
        return solutions;
    #endif
}
