#include <iostream>
#include <vector>

void WithdrawCash(long long& account) {
	int count;
	do {
		std::cout << "Введите количество для снятия:\n";
		std::cin >> count;
		std::cin.ignore(10000, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			count = -1;
			std::cout << "ОШИБКА: Введено некорректное число\n";
			continue;
		}
		if (count < 0 || count > account) {
			std::cout << "ОШИБКА: Введено некорректное число\n";
			continue;
		}
		break;
	} while (true);
	account -= count;
}

void TopUpAccount(long long& account) {
	int count;
	do {
		std::cout << "Введите количество для пополнения:\n";
		std::cin >> count;
		std::cin.ignore(10000, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			count = -1;
			std::cout << "ОШИБКА: Введено некорректное число\n";
			continue;
		}
		if (count < 0) {
			std::cout << "ОШИБКА: Введено некорректное число\n";
			continue;
		}
		break;
	} while (true);
	account += count;
}

void ATMSimulator(long long& account) {
	int issue_number;
	int cnt = 0;
	do {
		std::cout << "\n== СИМУЛЯТОР БАНКОМАТА ==\n";
		std::cout << "Баланс: " << account << "\n";
		std::cout << "1. Снять наличные\n";
		std::cout << "2. Пополнить счет\n";
		std::cout << "0. Выход\n\n";
		do
		{
			std::cout << "Выберите действие:\n";
			std::cin >> issue_number;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				issue_number = -1;
			}
			if (issue_number < 0 || issue_number > 2 || (issue_number == 1 && account == 0))
			{
				std::cout << "ОШИБКА: Введено некорректное число\n";
			}
		} while (issue_number < 0 || issue_number > 2 || (issue_number == 1 && account == 0));
		if (issue_number != 0 && cnt >= 10) {
			std::cout << "Лимит операций за сеанс исчерпан\n";
		}
		else if (issue_number == 1) {
			WithdrawCash(account);
			++cnt;
		}
		else if (issue_number == 2) {
			TopUpAccount(account);
			++cnt;
		}
	} while (issue_number != 0);
}