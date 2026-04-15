#include <iostream>
#include "RandomPasswordGenerator.hpp"
#include "NumberSystemConverter.hpp"
#include "ATMSimulator.hpp"
#include "RockScissorsPaper.hpp"
#include "TextAnalyzer.hpp"
#include "Timer.hpp"

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int issue_number;
	long long account = 10000;
	do
	{
		std::cout << "\n=== ЛАБОРАТОРНАЯ РАБОТА 1 ===\n";
		std::cout << "1. Генератор случайных паролей\n";
		std::cout << "2. Конвертер систем счисления\n";
		std::cout << "3. Симулятор банкомата\n";
		std::cout << "4. Игра \"Камень, ножницы, бумага\"\n";
		std::cout << "5. Анализатор текста\n";
		std::cout << "6. Таймер обратного отсчета с уведомлениями\n";
		std::cout << "0. Выход\n\n";
		std::cout << "Выберите действие: \n";
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
			NumberSystemConverter();
		}
		else if (issue_number == 3)
		{
			ATMSimulator(account);
		}
		else if (issue_number == 4)
		{
			RockScissorsPaper();
		}
		else if (issue_number == 5)
		{
			TextAnalyzer();
		}
		else if (issue_number == 6)
		{
			Timer();
		}
		else if (issue_number != 0)
		{
			std::cout << "ОШИБКА: Введено некорректное число\n";
		}
	} while (issue_number != 0);
	return 0;
}