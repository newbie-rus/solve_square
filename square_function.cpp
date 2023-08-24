#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square.h"

int solve_equation(double* coeff, double* roots)
{
    double a = coeff[A],
           b = coeff[B],
           c = coeff[C];

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (coeff != NULL);
    assert (roots != NULL);
    assert(roots != coeff);

    if (iszero (a))
        return solution_of_a_linear_equation (coeff, roots);
    else
        return solution_of_a_quadratic_equation (coeff, roots);
}

int solution_of_a_linear_equation (double* coeff, double* roots)
{
    double b = coeff[B],
           c = coeff[C];

    assert (isfinite (b));
    assert (isfinite (c));
    assert (coeff != NULL);
    assert (roots != NULL);
    assert(roots != coeff);

    if (!iszero (b))
    {
        roots[X1] = -c / b;
        return ONE_ROOT;
    }
    else
    {
        if (iszero (b))
            return INFINITY_ROOTS;
        else
            return TWO_ROOTS;
    }
}

int solution_of_a_quadratic_equation (double* coeff, double* roots)
{
    double a = coeff[A],
           b = coeff[B],
           c = coeff[C];

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (coeff != NULL);
    assert (roots != NULL);
    assert(roots != coeff);

    double D = b * b - 4 * a * c;    //объявление дискриминанта
    if (iszero (D))
    {
        roots[X1] = -b / (2 * a);
        return ONE_ROOT;
    }
    else if (D >= EPSILON)
    {
        double sqrtD = sqrt (D);
        roots[X1] = (-b + sqrtD) / (2 * a);
        roots[X2] = (-b - sqrtD) / (2 * a);
        return TWO_ROOTS;
    }
    else
        return NO_ROOTS;
}

void input_coefficient (char name, double* coefficient)
{
    printf ("Введите значение коэффициента \'%c\': \n", name);

    double coeff;
    while (scanf ("%lf", &coeff) == 0 || isfinite (coeff) == 0)
    {
        clear_the_input_buffer ();
        printf ("Введено некоректное значение, попробуйте ввести коэффициент \'%c\' заново:\n", name);
    }
    clear_the_input_buffer ();
    switch(name)
    {
        case 'a':
            coefficient[A] = coeff;
            break;
        case 'b':
            coefficient[B] = coeff;
            break;
        case 'c':
            coefficient[C] = coeff;
            break;
        default:
            break;
    }
}

void output_roots (int solutions, double* roots)
{
    double x1 = roots[X1],
           x2 = roots[X2];

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
    FILE * fp = fopen("input_data_test", "r");
    int amount_test= NO_NUM_TEST;
    fscanf(fp, "%d", &amount_test);
    for(int test_idx = 1; test_idx <= amount_test; test_idx++)
    {
        double coeffs[AMOUNT_COEFFS] = {NAN, NAN, NAN};
        double roots_ref[AMOUNT_ROOTS] = {NAN, NAN};
        double roots[AMOUNT_ROOTS] = {NAN, NAN};
        int solutions = NO_VALID_ROOTS;
        int solutions_ref = NO_VALID_ROOTS;

        printf("\033[35mtest %d:  \033[0m", test_idx);
        fscanf(fp, "%lf %lf %lf %lf %lf %d", &coeffs[A], &coeffs[B], &coeffs[C], &roots_ref[X1_REF], &roots_ref[X2_REF], &solutions_ref);

        solutions = solve_equation(coeffs, roots);

        dispatcher(coeffs, roots, roots_ref, solutions, solutions_ref);
    }

    fclose(fp);
}

void dispatcher (double* coeffs, double* roots, double* roots_ref, int solutions, int solutions_ref)
{
    double  x1 = roots[X1],
            x2 = roots[X2],
            x1_ref = roots_ref[X1_REF],
            x2_ref = roots_ref[X2_REF];

    if (solutions_ref == solutions)
    {
        switch(solutions_ref)
        {
            case NO_ROOTS:
                if ((isnan(x1) != 0) && (isnan(x2) != 0) && (isnan(x1_ref) != 0) && (isnan(x2_ref) != 0))
                    printf("**Завершен успешно**\n");
                break;
            case ONE_ROOT:
                if (equality_double(x1, x1_ref) && (isnan(x2) != 0) && (isnan(x2_ref) != 0))
                    printf("**Завершен успешно**\n");
                break;
            case TWO_ROOTS:
                if (equality_double(x1, x1_ref) && equality_double(x2, x2_ref))
                    printf("**Завершен успешно**\n");
                break;
            case INFINITY_ROOTS:
                if ((isnan(x1) != 0) && (isnan(x2) != 0) && (isnan(x1_ref) != 0) && (isnan(x2_ref) != 0))
                    printf("**Завершен успешно**\n");
                break;
            default:
                test_finished_error(coeffs, roots, roots_ref, solutions, solutions_ref);
        }
    }
    else
        test_finished_error(coeffs, roots, roots_ref, solutions, solutions_ref);
}

void test_finished_error(double* coeffs, double* roots, double* roots_ref, int solutions, int solutions_ref)
{
    double  a = coeffs[A],
            b = coeffs[B],
            c = coeffs[C],
            x1 = roots[X1],
            x2 = roots[X2],
            x1_ref = roots_ref[X1_REF],
            x2_ref = roots_ref[X2_REF];

    printf("**Завершен c ошибкой**\n");
    printf("коэффициенты: a = %lf  b = %lf  c = %lf\n", a, b, c);
    printf("полученное количество корней: %d\nправильное количество корней: %d\n", solutions, solutions_ref);
    printf("полученные корни: x1 = %lf  x2 = %lf\n", x1, x2);
    printf("правильные корни: x1 = %lf  x2 = %lf\n", x1_ref, x2_ref);
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