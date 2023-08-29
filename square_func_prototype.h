#include "square_const.h"

/**
 * @file
 *
 * @brief Объявление прототипов функций
 */

/**
 * @brief  Осуществляет ввод коэффициентов с клавиатуры
 *
 * @param [in]   name                   name - имя коэффициента, значение которого будет введено
 *
 * @param [out]  coefficient     coefficient - массив, хранящий коэффициенты уравнения
 */
long double input_coefficient (char name);

/**
 * @brief Универсальная функция для очистки буфера ввода
 */
void clear_the_input_buffer (void);

/**
 * @brief  Запускает решение квадратного или линейного уравнения в зависимости от значений коэффициентов
 *
 * @param  [in] coeff       coeff - массив, хранящий коэффициенты уравнения
 * @param [out] roots        root - массив, хранящий корни ураванения
 *
 * @return int  Возвращает количество корней
 */
int solve_equation (COEFFS_AND_ROOTS* data);

/**
 * @brief  Решает линейные уравнения
 *
 * @param  [in] coeff       coeff - массив, хранящий коэффициенты уравнения
 * @param [out] roots        root - массив, хранящий корни уравнения
 *
 * @return int  Возвращает количество корней
 */
int solution_of_a_linear_equation (COEFFS_AND_ROOTS *data);

/**
 * @brief Решает квадратные уравнения
 *
 * @param  [in] coeff       coeff - массив, хранящий коэффициенты уравнения
 * @param [out] roots        root - массив, хранящий корни уравнения
 *
 * @return int  Возвращает количество корней
 */
int solution_of_a_quadratic_equation (COEFFS_AND_ROOTS *data);

/**
 * @brief  Выводит в консоль корни уравнения и их количество
 *
 * @param [in] solutions    solutions - количество корней
 * @param [in] roots             root - массив, хранящий корни уравнения
 */
int output_roots (COEFFS_AND_ROOTS* data, int solutions);
/**
 * @brief  Сравнивает число с нулем
 *
 * @param [in] num     num - число, которое необходимо сравнить с нулем
 * @return bool  Возвращает правду если число равно нулю и ложь во всех других случаях
 */
bool iszero (long double num);

/**
 * @brief Запускает тестирование программы, решающей квадратные уравнения
 *
 * @return int  Возвращает количество успешно пройденных тестов
 */
int start_test (void);

/**
 * @brief
 *
 * @param [in]  coeff                      coeff - массив, хранящий коэффициенты уравнения
 * @param [in]  roots                       root - массив, хранящий корни, которые нашла функция, решающая квадратные ураванение
 * @param [in]  roots_ref              roots_ref - массив, хранящий правильные корни уравнения
 * @param [in]  solutions              solutions - количество корней, которое посчитала функция, решающая квадратные ураванение
 * @param [in]  solutions_ref      solutions_ref - правильное количество корней
 * @param [out]  n_test_y               n_test_y - количество успешно пройденных тестов
 */
int dispatcher (int solutions, COEFFS_AND_ROOTS* data_t);

/**
 * @brief  Выводит всю информацию по тесту, который провалился
 *
 * @param [in]  coeff                      coeff - массив, хранящий коэффициенты уравнения
 * @param [in]  roots                       root - массив, хранящий корни, которые нашла функция, решающая квадратные ураванение
 * @param [in]  roots_ref              roots_ref - массив, хранящий правильные корни уравнения
 * @param [in]  solutions              solutions - количество корней, которое посчитала функция, решающая квадратные ураванение
 * @param [in]  solutions_ref      solutions_ref - правильное количество корней
 */
int test_finished_error (int solutions, COEFFS_AND_ROOTS* data_t);

/**
 * @brief Сравнивает два числа с плавающей точкой
 *
 * @param [in] num1    num1 - одно из чисел для сравнения
 * @param [in] num2    num2 - одно из чисел для сравнения
 * @return bool Возвращает правду, если числа равны и ложь во всех других случаях
 */
bool equality_double (long double num1, long double num2);

/**
 * @brief Функция выполняет проверку результатов тестирования
 *
 * @param[in] solutions  Количество корней уравнения, которое нашла программа
 * @param[in] data_t     Структура, содержащая данные для прохождения тестирования
 * @return int           Возвращает TEST_COMPLITED, если тест прошел успешно и TEST_FAILED, если тест провалился
 */
int checking_test_results(int solutions, COEFFS_AND_ROOTS* data_t);
