#include <stdio.h>
#include "sq.h"
#include <math.h>

int test (void)
{
    FILE* fp = fopen ("input_data_test", "r");
    int n_test_y = 0;

    int amount_test = NO_NUM_TEST;
    fscanf (fp, "%d", &amount_test);

    for(int test_idx = 1; test_idx <= amount_test; test_idx++)
    {
          long double coeffs[AMOUNT_COEFFS] = {NAN, NAN, NAN};
        long double roots_ref[AMOUNT_ROOTS] = {NAN, NAN};
            long double roots[AMOUNT_ROOTS] = {NAN, NAN};
                              int solutions = NO_VALID_ROOTS;
                          int solutions_ref = NO_VALID_ROOTS;

        printf ("\033[35mtest %d:  \033[0m", test_idx);
        fscanf (fp, "%Lf %Lf %Lf %Lf %Lf %d", &coeffs[A_COEFF], &coeffs[B_COEFF], &coeffs[C_COEFF], &roots_ref[X1_REF], &roots_ref[X2_REF], &solutions_ref);

        solutions = solve_equation (coeffs, roots);
        if (solutions == -1)
            return -1;

        if (dispatcher (coeffs, roots, roots_ref, solutions, solutions_ref, &n_test_y) == -1)
            return -1;
    }

    fclose (fp);
    return n_test_y;
}


int dispatcher (long double* coeffs, long double* roots, long double* roots_ref, int solutions, int solutions_ref, int* n_test_y)
{
    if (my_assert ((coeffs == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == coeffs), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == roots_ref), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((coeffs == roots_ref), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == roots_ref && roots == coeffs), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((solutions_ref < 0), UNREAL_VALUE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((solutions < 0), UNREAL_VALUE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }

    long double      x1 = roots[X1],
                x2 = roots[X2],
            x1_ref = roots_ref[X1_REF],
            x2_ref = roots_ref[X2_REF];

    if (solutions_ref == solutions)
    {
        switch(solutions_ref)
        {
            case NO_ROOTS:
                if ((isnan (x1) != 0) && (isnan (x2) != 0) && (isnan (x1_ref) != 0) && (isnan (x2_ref) != 0))
                {
                    color_output (test_y, GREEN);
                    n_test_y++;
                }
                break;

            case ONE_ROOT:
                if (equality_double (x1, x1_ref) && (isnan (x2) != 0) && (isnan (x2_ref) != 0))
                {
                   color_output (test_y, GREEN);
                    n_test_y++;
                }
                break;

            case TWO_ROOTS:
                if (equality_double (x1, x1_ref) && equality_double (x2, x2_ref))
                {
                   color_output (test_y, GREEN);
                    n_test_y++;
                }
                break;

            case INFINITY_ROOTS:
                if ((isnan (x1) != 0) && (isnan (x2) != 0) && (isnan (x1_ref) != 0) && (isnan (x2_ref) != 0))
                {
                   color_output (test_y, GREEN);
                    n_test_y++;
                }
                break;

            default:
                return test_finished_error (coeffs, roots, roots_ref, solutions, solutions_ref);
        }
    }
    else
        return test_finished_error (coeffs, roots, roots_ref, solutions, solutions_ref);

    return 0;
}


int test_finished_error (long double* coeffs, long double* roots, long double* roots_ref, int solutions, int solutions_ref)
{
    if (my_assert ((coeffs == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == NULL), PATH_NULL))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == coeffs), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == roots_ref), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((coeffs == roots_ref), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((roots == roots_ref && roots == coeffs), SAME_PATHS))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((solutions_ref < 0), UNREAL_VALUE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }
    if (my_assert ((solutions < 0), UNREAL_VALUE))
    {
        printf ("строка: %d\nфункция: %s\n", __LINE__, __func__ );
        return -1;
    }

    long double  a = coeffs[A_COEFF],
                 b = coeffs[B_COEFF],
                 c = coeffs[C_COEFF],
                x1 = roots[X1],
                x2 = roots[X2],
            x1_ref = roots_ref[X1_REF],
            x2_ref = roots_ref[X2_REF];

    color_output (test_n, RED);

    printf ("коэффициенты: a = %Lf b = %Lf  c = %Lf\n", a, b, c);
    printf ("полученное количество корней: %d\n", solutions);
    printf ("правильное количество корней: %d\n", solutions_ref);
    printf ("полученные корни: x1 = %Lf  x2 = %Lf\n", x1, x2);
    printf ("правильные корни: x1 = %Lf  x2 = %Lf\n", x1_ref, x2_ref);
    return 0;
}
