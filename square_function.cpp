#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square.h"

void solve_equation(double a, double b, double c, double* px1, double* px2, int* p_solutions)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (px1 != NULL);
    assert (px2 != NULL);
    assert (p_solutions != NULL);
    assert(px1 != px2);

    if (iszero (a))
        *p_solutions = solution_of_a_linear_equation (b, c, px1);
    else
        *p_solutions = solution_of_a_quadratic_equation ( a, b, c, px1, px2);
}

int solution_of_a_linear_equation (double b, double c, double* px1)
{
    assert (isfinite (b));
    assert (isfinite (c));
    assert (px1 != NULL);

    if (!iszero (b))
    {
        *px1 = -c / b;
        return ONE_ROOT;
    }
    else
    {
        if (iszero (c))
            return INFINITY_ROOTS;
        else
            return TWO_ROOTS;
    }
}

int solution_of_a_quadratic_equation (double a, double b, double c, double* px1, double* px2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (px1 != NULL);
    assert (px2 != NULL);
    assert(px1 != px2);

    double D = b * b - 4 * a * c;    //объявление дискриминанта
    if (iszero (D))
    {
        *px1 = -b / (2 * a);
        return ONE_ROOT;
    }
    else if (D >= EPSILON)
    {
        double sqrtD = sqrt (D);
        *px1 = (-b + sqrtD) / (2 * a);
        *px2 = (-b - sqrtD) / (2 * a);
        return TWO_ROOTS;
    }
    else
        return NO_ROOTS;
}

double input_coefficient (char name)
{
    printf ("Введите значение коэффициента \'%c\': \n", name);

    double coeff;
    while (scanf ("%lf", &coeff) == 0 || isfinite (coeff) == 0)
    {
        clear_the_input_buffer ();
        printf ("Введено некоректное значение, попробуйте ввести коэффициент \'%c\' заново:\n", name);
    }

    return coeff;
}

void output_roots (int solutions, double x1, double x2)
{
    assert (isfinite (x1));
    assert (isfinite (x2));

    switch (solutions)
    {
        case NO_ROOTS:
            printf ("Уравнение не имеет корней\n");
            break;
        case ONE_ROOT:
            printf ("Уравнение имеет один корень\nx = %lf\n", x1);
            break;
        case TWO_ROOTS:
            printf ("Уравнение имеет два корня\nx1 = %lf\nx2 = %lf\n", x1, x2);
            break;
        case INFINITY_ROOTS:
            printf ("Уравнение имеет бесконечное множество решений\n");
            break;
        default:
            printf ("ERROR. Произошел какой-то сбой\n");
    }
}

void clear_the_input_buffer (void)    //очистка буфера scanf
{
    int ch = getchar ();
    while ((ch != '\n') && (ch != EOF))
        ch = getchar ();
}

bool iszero (double num)
{
    assert (isfinite (num));

    if (fabs (num) < EPSILON)
        return true;
    else
        return false;
}

void test(void)
{
    FILE* fp = fopen("input_data_test", "r");
    int amount_test= NO_NUM_TEST;
    fscanf(fp, "%d", &amount_test);
    for(int test_idx = 1; test_idx <= amount_test; test_idx++)
    {
        double a, b, c, x1, x2, x1_ref, x2_ref;
        a = b = c = x1 = x2 = x1_ref = x2_ref = NAN;
        int solutions = NO_VALID_ROOTS;
        int solutions_ref = NO_VALID_ROOTS;

        printf("\033[35mtest %d:  \033[0m", test_idx);
        fscanf(fp, "%lf %lf %lf %lf %lf %d", &a, &b, &c, &x1_ref, &x2_ref, &solutions_ref);

        solve_equation(a, b, c, &x1, &x2, &solutions);

        dispatcher(&a, &b, &c, &x1_ref, &x2_ref, &solutions_ref, &x1, &x2, &solutions);
    }

    fclose(fp);
}

void dispatcher (double* a, double* b, double* c, double* x1_ref, double* x2_ref, int* solutions_ref,
                double* x1, double* x2, int* solutions)
{
    if (*solutions_ref == *solutions)
    {
        switch(*solutions_ref)
        {
            case NO_ROOTS:
                if ((isnan(*x1) != 0) && (isnan(*x2) != 0) && (isnan(*x1_ref) != 0) && (isnan(*x2_ref) != 0))
                    printf("\033[32m**Завершен успешно**\033[0m\n");
                break;
            case ONE_ROOT:
                if (equality_double(*x1_ref, *x1) && (isnan(*x2) != 0) && (isnan(*x2_ref) != 0))
                    printf("\033[32m**Завершен успешно**\033[0m\n");
                break;
            case TWO_ROOTS:
                if (equality_double(*x1_ref, *x1) && equality_double(*x2_ref, *x2))
                    printf("\033[32m**Завершен успешно**\033[0m\n");
                break;
            case INFINITY_ROOTS:
                if ((isnan(*x1) != 0) && (isnan(*x2) != 0) && (isnan(*x1_ref) != 0) && (isnan(*x2_ref) != 0))
                    printf("\033[32m**Завершен успешно**\033[0m\n");
                break;
            default:
                test_finished_error(a, b, c, x1_ref, x2_ref, solutions_ref, x1, x2, solutions);
        }
    }
    else
        test_finished_error(a, b, c, x1_ref, x2_ref, solutions_ref, x1, x2, solutions);
}

void test_finished_error(double* a, double* b, double* c, double* x1_ref, double* x2_ref, int* solutions_ref,
                         double* x1, double* x2, int* solutions)
{
    printf("\033[31m**Завершен c ошибкой**\033[0m\n");
    printf("коэффициенты: a = %lf  b = %lf  c = %lf\n", *a, *b, *c);
    printf("полученное количество корней: %d\nправильное количество корней: %d\n", *solutions, *solutions_ref);
    printf("полученные корни: x1 = %lf  x2 = %lf\n", *x1, *x2);
    printf("правильные корни: x1 = %lf  x2 = %lf\n", *x1_ref, *x2_ref);
}

bool equality_double(double num1, double num2)
{
    assert(isfinite(num1));
    assert(isfinite(num2));
    double R = (num1 - num2);
    if (fabs(R) < EPSILON)
        return true;
    else
        return false;
}
