#include <stdio.h>
#include "square_func_prototype.h"
#include <math.h>

/**
 * @file
 */

int test (void)
{
    FILE* test_file = fopen ("input_data_test", "r");

    int amount_test = NO_NUM_TEST;
    fscanf (test_file, "%d", &amount_test);

    for(int test_idx = 1; test_idx <= amount_test; test_idx++)
    {
        COEFFS_AND_ROOTS data_t = {
                                      NAN, NAN, NAN,
                                      NO_VALID_ROOTS,
                                      NAN, NAN,
                                      NAN, NAN
                                    };

        int solutions = NO_VALID_ROOTS;

        COLOR_MORE(PURPLE, test %d:  , test_idx);
        fscanf (test_file, "%Lf %Lf %Lf %Lf %Lf %d", &data_t.a, &data_t.b, &data_t.c,
                                                     &data_t.x1_correct, &data_t.x2_correct,
                                                     &data_t.solutions_ref);

        solutions = solve_equation (&data_t);

        if (solutions == -1)
            return ERROR_OUTPUT;

        if (dispatcher (solutions, &data_t) == -1)
            return ERROR_OUTPUT;
    }

    fclose (test_file);
    return 0;
}


int dispatcher (int solutions, COEFFS_AND_ROOTS* data_t)
{

    if (my_assert(isfinite (data_t -> a) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (data_t -> b) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (data_t -> c) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(                data_t == NULL,   PATH_NULL, __FILE__, __func__, __LINE__) ||
        my_assert(                solutions < 0, UNREAL_VALUE, __FILE__, __func__, __LINE__) ||
        my_assert((data_t -> solutions_ref) < 0, UNREAL_VALUE, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    switch(testing(solutions, data_t))
    {
        case TEST_COMPLETED:
            COLOR(GREEN, test_y);
            break;

        case TEST_FAILED:
            test_finished_error(solutions, data_t);
            break;

        default:
            break;
    }

    return 0;

}


int test_finished_error (int solutions, COEFFS_AND_ROOTS* data_t)
{

    if (my_assert(isfinite (data_t -> a) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (data_t -> b) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (data_t -> c) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(                data_t == NULL,   PATH_NULL, __FILE__, __func__, __LINE__) ||
        my_assert(                solutions < 0, UNREAL_VALUE, __FILE__, __func__, __LINE__) ||
        my_assert((data_t -> solutions_ref) < 0, UNREAL_VALUE, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    COLOR(RED, test_n);

    printf ("коэффициенты: a = %Lf b = %Lf  c = %Lf\n", data_t -> a, data_t -> b, data_t -> c);
    printf ("полученное количество корней: %d\n", solutions);
    printf ("правильное количество корней: %d\n", (*data_t).solutions_ref);
    printf ("полученные корни: x1 = %Lf  x2 = %Lf\n", data_t -> x1, data_t -> x2);
    printf ("правильные корни: x1 = %Lf  x2 = %Lf\n", (*data_t).x1_correct, (*data_t).x2_correct);
    return 0;
}

int testing(int solutions, COEFFS_AND_ROOTS* data_t)
{
    if (my_assert(isfinite (data_t -> a) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (data_t -> b) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(isfinite (data_t -> c) == 0, ERROR_ISFINITE, __FILE__, __func__, __LINE__) ||
        my_assert(                data_t == NULL,   PATH_NULL, __FILE__, __func__, __LINE__) ||
        my_assert(                solutions < 0, UNREAL_VALUE, __FILE__, __func__, __LINE__) ||
        my_assert((data_t -> solutions_ref) < 0, UNREAL_VALUE, __FILE__, __func__, __LINE__))
        return ERROR_OUTPUT;

    long double x1 = data_t -> x1 ,
                x2 = data_t -> x2,
        x1_correct = data_t -> x1_correct,
        x2_correct = data_t -> x2_correct;

    if ((*data_t).solutions_ref == solutions)
    {
        switch(data_t -> solutions_ref)
        {
            case NO_ROOTS:
                if ((isnan (x1) != 0) && (isnan (x2) != 0) && (isnan (x1_correct) != 0) && (isnan (x2_correct) != 0))
                    return TEST_COMPLETED;
                break;

            case ONE_ROOT:
                if (equality_double (x1, x1_correct) && (isnan (x2) != 0) && (isnan (x2_correct) != 0))
                    return TEST_COMPLETED;
                break;

            case TWO_ROOTS:
                if (equality_double (x1, x1_correct) && equality_double (x2, x2_correct))
                    return TEST_COMPLETED;
                break;

            case INFINITY_ROOTS:
                if ((isnan (x1) != 0) && (isnan (x2) != 0) && (isnan (x1_correct) != 0) && (isnan (x2_correct) != 0))
                    return TEST_COMPLETED;
                break;

            default:
                return TEST_FAILED;
        }
    }
    else
        return TEST_FAILED;

    return 0;
}
