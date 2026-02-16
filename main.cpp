#include <iostream>
#include "RandomPasswordGenerator.h"

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int issue_number;
    do
    {
        std::cout << std::endl
            << "=== ЛАБОРАТОРНАЯ РАБОТА 1 ===" << std::endl;
        std::cout << "1. Генератор случайных паролей" << std::endl;
        std::cout << "2. Конвертер систем счисления" << std::endl;
        std::cout << "3. Симулятор банкомата" << std::endl;
        std::cout << "4. Игра \"Камень, ножницы, бумага\"" << std::endl;
        std::cout << "5. Анализатор текста" << std::endl;
        std::cout << "6. Таймер обратного отсчета с уведомлениями" << std::endl;
        std::cout << "0. Выход" << std::endl
            << std::endl;
        std::cout << "Выберите действие: " << std::endl;
        std::cin >> issue_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            issue_number = -1;
        }
        if (issue_number == 1)
        {
            RandomPasswordGenerator();
        }
        else if (issue_number == 2)
        {
        }
        else if (issue_number == 3)
        {
        }
        else if (issue_number == 4)
        {
        }
        else if (issue_number == 5)
        {
        }
        else if (issue_number == 6)
        {
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    } while (issue_number != 0);
    return 0;
}