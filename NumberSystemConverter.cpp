#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

std::vector<int> ConvertToVector(std::string number, int system) {
	if (number.size() == 1 && number[0] == '-') {
		return {};
	}
	std::vector<int> result;
	for (int i = 0; i < number.size(); ++i) {
		if (i == 0 && number[0] == '-') {
			result.push_back(-1);
			continue;
		}
		else if (i == 0) {
			result.push_back(1);
		}
		int x;
		if (number[i] >= '0' && number[i] <= '9') {
			x = number[i] - '0';
		}
		else if (number[i] == 'A') {
			x = 10;
		}
		else if (number[i] == 'B') {
			x = 11;
		}
		else if (number[i] == 'C') {
			x = 12;
		}
		else if (number[i] == 'D') {
			x = 13;
		}
		else if (number[i] == 'E') {
			x = 14;
		}
		else if (number[i] == 'F') {
			x = 15;
		}
		else {
			return {};
		}
		if (x < 0 || x >= system) {
			return {};
		}
		result.push_back(x);
	}
	return result;
}

long long ConvertTo10(std::vector<int> number, int original_system) {
	long long result = 0;
	long long multiplier = 1;
	for (int i = number.size() - 1; i > 0; --i) {
		result += number[i] * multiplier;
		multiplier *= original_system;
	}
	if (number[0] == 1) {
		return result;
	}
	return -result;
}

std::string ConvertToTarget(long long number, int target_system) {
	std::string result;
	long long cur = abs(number);
	while (cur > 0) {
		int x = cur % target_system;
		if (x == 10) {
			result.push_back('A');
		}
		else if (x == 11) {
			result.push_back('B');
		}
		else if (x == 12) {
			result.push_back('C');
		}
		else if (x == 13) {
			result.push_back('D');
		}
		else if (x == 14) {
			result.push_back('E');
		}
		else if (x == 15) {
			result.push_back('F');
		}
		else {
			result += std::to_string(x);
		}
		cur /= target_system;
	}
	if (number < 0) {
		result.push_back('-');
	}
	std::reverse(result.begin(), result.end());
	return result;
}

void NumberSystemConverter() {
	int issue_number;
	do {
		std::cout << "\n== КОНВЕРТЕР СИСТЕМ СЧИСЛЕНИЯ ==\n";
		int original_system;
		do {
			std::cout << "Введите исходную систему счисления (от 2 до 16):\n";
			std::cin >> original_system;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				original_system = -1;
				std::cout << "ОШИБКА: Введено некорректное число\n";
				continue;
			}
			if (original_system < 2 || original_system > 16) {
				std::cout << "ОШИБКА: Введено некорректное число\n";
				continue;
			}
			break;
		} while (true);
		int target_system;
		do {
			std::cout << "Введите целевую систему счисления (от 2 до 16):\n";
			std::cin >> target_system;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				target_system = -1;
				std::cout << "ОШИБКА: Введено некорректное число\n";
				continue;
			}
			if (target_system < 2 || target_system > 16) {
				std::cout << "ОШИБКА: Введено некорректное число\n";
				continue;
			}
			break;
		} while (true);
		std::string number_cin;
		std::vector<int> number;
		do {
			std::cout << "Введите число в исходной системе счисления:\n";
			std::cin >> number_cin;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				number_cin = -1;
				std::cout << "ОШИБКА: Введено некорректное число\n";
				continue;
			}
			number = ConvertToVector(number_cin, original_system);
			if (number.size() == 0) {
				std::cout << "ОШИБКА: Введено некорректное число\n";
				continue;
			}
			break;
		} while (true);
		std::string number_result = ConvertToTarget(ConvertTo10(number, original_system), target_system);
		std::cout << "Число " << number_cin << " в системе счисления " << original_system << " = " << number_result << " в системе счисления " << target_system << "\n";
		do
		{
			std::cout << "\nЗадача завершена\n";
			std::cout << "1. Выполнить задачу еще раз\n";
			std::cout << "0. Выход\n\n";
			std::cout << "Выберите действие:\n";
			std::cin >> issue_number;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				issue_number = -1;
			}
			if (issue_number != 1 && issue_number != 0)
			{
				std::cout << "ОШИБКА: Введено некорректное число\n";
			}
		} while (issue_number != 1 && issue_number != 0);
	} while (issue_number != 0);
}