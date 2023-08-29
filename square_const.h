/**
 * @file
 *
 * @brief Объявление констант
 */

#define COLOR_MORE(color, str, ...) printf("\033[%dm" #str "\033[0m", color, __VA_ARGS__)
#define COLOR(color, str) printf("\033[%dm%s\033[0m\n", color, str)

#define my_assert(condition, error_code)                \
  if (condition)                                        \
  {                                                     \
    printf("Сбой в программе ошибка: %s\n"              \
           "файл: %s, функция: %s, строка: %d\n",       \
           error_code, __FILE__, __func__, __LINE__);   \
    return ERROR_OUTPUT;                                \
  }

const        long double EPSILON = 1e-6;

const     int AMOUNT_COEFFS = 3;
const      int AMOUNT_ROOTS = 2;

const       char  hello_t[] = "**HELLO TEST MODE**";
const        char hello_u[] = "**HELLO USER MODE**";

const         char test_y[] = "**Завершен успешно**";
const         char test_n[] = "**Завершен c ошибкой**";

const char ERROR_ISFINITE[] = "Бесконечное число или NAN";
const      char PATH_NULL[] = "Нулевой указатель";
const     char SAME_PATHS[] = "Одинаковые пути на разные массивы";
const   char UNREAL_VALUE[] = "Невозможное значение переменной";

const      int ERROR_OUTPUT = -1;

struct COEFFS_AND_ROOTS {
                           long double a, b, c;
                           int solutions_ref;
                           long double x1_correct, x2_correct;
                           long double x1, x2;
                         };

enum COLOR {
                       RED = 31,
                     GREEN = 32,
                    YELLOW = 33,
                    PURPLE = 35
            };

enum NAME_ROOTS {
                        X1 = 0,
                        X2 = 1,
                    X1_CORRECT = 0,
                    X2_CORRECT = 1
                 };

enum NAME_COEFFS {
                    A_COEFF = 0,
                    B_COEFF = 1,
                    C_COEFF = 2
                  };

enum AMOUNT_ROOTS {
                       NO_NUM_TEST = -1,
                          NO_ROOTS = 0,
                          ONE_ROOT = 1,
                         TWO_ROOTS = 2,
                    INFINITY_ROOTS = 100,
                    NO_VALID_ROOTS = 777
                   };

enum TEST_FINISHED {
                      TEST_COMPLETED = 1,
                      TEST_FAILED = 0
                    };
