#include <iostream>
#include <vector>

void PasswordAnalysis(std::string& password) {
	bool numbers = false;
	bool uppercase = false;
	bool lowercase = false;
	bool special_characters = false;
	for (char c : password) {
		if (c >= '0' && c <= '9') numbers = true;
		else if (c >= 'a' && c <= 'z') lowercase = true;
		else if (c >= 'A' && c <= 'Z') uppercase = true;
		else special_characters = true;
	}
	int complexity = password.size() + 5 * (numbers + uppercase + lowercase + special_characters);
	if (complexity < 18) {
		std::cout << "Надежность пароля: слабый" << '\n';
	}
	else if (complexity < 30) {
		std::cout << "Надежность пароля: средний" << '\n';
	}
	else {
		std::cout << "Надежность пароля: сильный" << '\n';
	}
}

void PasswordGeneration(int len, std::vector<bool>& types) {
	std::vector<int> types_available;
	for (int i = 0; i < types.size(); ++i) {
		if (types[i]) types_available.push_back(i);
	}
	std::string password;
	for (int i = 0; i < len; ++i) {
		int type = types_available[rand() % (types_available.size())];
		if (type == 0) {
			password.push_back(static_cast<char>(rand() % ('9' - '0' + 1) + '0'));
		}
		else if (type == 1) {
			password.push_back(static_cast<char>(rand() % ('z' - 'a' + 1) + 'a'));
		}
		else if (type == 2) {
			password.push_back(static_cast<char>(rand() % ('Z' - 'A' + 1) + 'A'));
		}
		else {
			password.push_back(static_cast<char>(rand() % ('0' - '!') + '!'));
		}
	}
	std::cout << "Пароль: " << password << '\n';
	PasswordAnalysis(password);
}

void RandomPasswordGenerator() {
	int issue_number;
	do {
		std::cout << '\n'
			<< "== ГЕНЕРАТОР СЛУЧАЙНЫХ ПАРОЛЕЙ ==" << '\n';
		int len;
		do {
			std::cout << "Введите длину пароля (от 6 до 32 символов):" << '\n';
			std::cin >> len;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				len = -1;
				std::cout << "ОШИБКА: Введено некорректное число" << '\n';
				continue;
			}
			if (len < 6 || len > 32) {
				std::cout << "ОШИБКА: Введено некорректное число" << '\n';
				continue;
			}
			break;
		} while (true);
		std::vector<bool> types(4, false);
		do {
			int types_num;
			types.resize(0);
			types.resize(4, false);
			std::cout << "1. Цифры" << '\n' << "2. Прописные буквы" << '\n' << "3. Строчные буквы" << '\n' << "4. Спецсимволы" << '\n';
			std::cout << "Введите типы символов (число длиной от 1 до 4, содержащее неповторяющиеся цифры от 1 до 4):" << '\n';
			std::cin >> types_num;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				types_num = -1;
				std::cout << "ОШИБКА: Введено некорректное число" << '\n';
				continue;
			}
			while (types_num > 0) {
				if (types_num % 10 > 4 || types_num % 10 < 1 || types[types_num % 10 - 1]) {
					std::cout << "ОШИБКА: Введено некорректное число" << '\n';
					break;
				}
				types[types_num % 10 - 1] = true;
				types_num /= 10;
			}
			if (types_num > 0) {
				continue;
			}
			break;
		} while (true);
		PasswordGeneration(len, types);
		do
		{
			std::cout << '\n' << "Задача завершена" << '\n';
			std::cout << "1. Выполнить задачу еще раз" << '\n';
			std::cout << "0. Выход" << '\n'
				<< '\n';
			std::cout << "Выберите действие:" << '\n';
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
				std::cout << "ОШИБКА: Введено некорректное число" << '\n';
			}
		} while (issue_number != 1 && issue_number != 0);
	} while (issue_number != 0);
}