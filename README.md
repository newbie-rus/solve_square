# :muscle: Решатель квадратных уравнений :muscle:
#### Это одна из возможных реализаций программы с данным функционалом
![](https://github.com/newbie-rus/solve_square/blob/main/kod_test.png?raw=true)

![](https://github.com/newbie-rus/solve_square/blob/main/kod_user.png?raw=true)
## Как установить
1) Откройте терминал из папки, в которую вы хотите установить программу

2) Введите команду
   ```
   git clone https://github.com/newbie-rus/solve_square.git
   ```
3) Введите команду
   ```
   cd solve_square
   ```
4) Для компиляции программы тестирования введите команду
    ```
    g++ -DTEST square.cpp solve_square_func.cpp square_io_func.cpp square_test_func.cpp equality_num.cpp clear_the_input_buffer.cpp my_assert.cpp
    ```
5) Для компиляции программы в пользовательском режиме введите команду
   ```
    g++ square.cpp solve_square_func.cpp square_io_func.cpp square_test_func.cpp equality_num.cpp clear_the_input_buffer.cpp my_assert.cpp
   ```
6) У вас создатся испольняемый файл, для его запуска введите команду(<filename> - имя файла, который создался)
   ```
    ./<filename>
   ```
## Создание документации
1) В первую очередь для создания документации у вас должен быть установлен Doxygen
2) Если он установлен, то в терминале, запущенном из папки с файлами программы, введите команду
   ```
    doxygen Doxyfile
   ```
3) После этого у вас должна создаться папка html, чтобы просмотреть документацию, запустите файл index.html, находящийся в этой папке
## Добавление тестов
Для того чтобы добавить новые конфигурации тестов откройте файл input_data_test.
В левом верхнем углу находится количество тестов.
Ниже, в каждой строке находятся входные данные в формате

`a  b  c  x1_ref  x2_ref  solutions_ref`
