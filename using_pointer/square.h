
const double EPSILON = 1e-10;

enum {
       NO_NUM_TEST = -1,
       NO_ROOTS = 0,
       ONE_ROOT = 1,
       TWO_ROOTS = 2,
       INFINITY_ROOTS = 100,
       NO_VALID_ROOTS = 777
     };

double input_coefficient (char name);    //объявление функции осуществляющей ввод значений коэффициентов
void clear_the_input_buffer (void);    //объявление функции очищающей буфер scanf
void solve_equation (double a, double b, double c, double* px1, double* px2, int* p_solutions);    //объявление функции определяющей какое уравнение задал пользователь(линейное/квадратное)
int solution_of_a_linear_equation (double b, double c, double* px1);   //объявление функции ищущей корни линейного уравнения
int solution_of_a_quadratic_equation (double a, double b, double c, double* px1, double* px2);   //объявление функции ищущей корни квадратного уравнения
void output_roots (int solutions, double x1, double x2);    //объявление функции осуществляющей вывод корней уравнения
bool iszero (double num);
bool equality_double(double num1, double num2);
void dispatcher (double* a, double* b, double* c, double* x1_ref, double* x2_ref, int* solutions_ref,
                 double* x1, double* x2, int* solutions);
void test_finished_error(double* a, double* b, double* c, double* x1_ref, double* x2_ref, int* solutions_ref,
                         double* x1, double* x2, int* solutions);
void test(void);
