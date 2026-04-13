#include <iostream>
#include <string>
#include <map>

int SelectDifficultyLevel()
{
	int difficulty;
	do
	{
		std::cout << "Уровень сложности:\n";
		std::cout << "1. Легкий\n";
		std::cout << "2. Средний\n";
		std::cout << "3. Сложный\n";
		std::cout << "\nВыберите действие:\n";
		std::cin >> difficulty;
		std::cin.ignore(10000, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "ОШИБКА: Введено некорректное число\n";
			difficulty = -1;
			continue;
		}
		if (difficulty < 1 || difficulty > 3)
		{
			std::cout << "ОШИБКА: Введено некорректное число\n";
			continue;
		}
		break;
	} while (true);
	return difficulty;
}

int GetPlayerChoice(int difficulty_level)
{
	int choice;
	do
	{
		std::cout << "\nВаш ход:\n";
		std::cout << "1. Камень\n";
		std::cout << "2. Ножницы\n";
		std::cout << "3. Бумага\n";
		std::cout << "0. Выход\n";
		std::cout << "\nВыберите действие:\n";
		std::cin >> choice;
		std::cin.ignore(10000, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "ОШИБКА: Введено некорректное число\n";
			continue;
		}
		if (choice < 0 || choice > 3)
		{
			std::cout << "ОШИБКА: Введено некорректное число\n";
			continue;
		}
		break;
	} while (true);
	return choice;
}

int GetComputerChoice(int difficulty_level, int player_choice, int score_player, int score_computer)
{
	int computer_choice;
	if (difficulty_level == 1)
	{
		computer_choice = rand() % 3 + 1;
	}
	else if (difficulty_level == 2)
	{
		static int last_player_choice = 0;
		if (last_player_choice == 0 || player_choice == 0)
		{
			computer_choice = rand() % 3 + 1;
		}
		else
		{
			if (last_player_choice == 1) computer_choice = 3;
			else if (last_player_choice == 2) computer_choice = 1;
			else if (last_player_choice == 3) computer_choice = 2;
		}
		last_player_choice = player_choice;
	}
	else
	{
		static std::map<int, int> player_history;
		static int total_moves = 0;
		if (total_moves < 3)
		{
			computer_choice = rand() % 3 + 1;
		}
		else
		{
			int most_frequent_choice = 1;
			int max_count = 0;
			for (int i = 1; i <= 3; i++)
			{
				if (player_history[i] > max_count)
				{
					max_count = player_history[i];
					most_frequent_choice = i;
				}
			}
			if (most_frequent_choice == 1) computer_choice = 3;
			else if (most_frequent_choice == 2) computer_choice = 1;
			else if (most_frequent_choice == 3) computer_choice = 2;
		}
		player_history[player_choice]++;
		total_moves++;
	}
	return computer_choice;
}

void DetermineWinner(int player_choice, int computer_choice, int& score_player, int& score_computer, int& draws)
{
	if (player_choice == computer_choice)
	{
		draws++;
	}
	else if ((player_choice == 1 && computer_choice == 2) ||
		(player_choice == 2 && computer_choice == 3) ||
		(player_choice == 3 && computer_choice == 1))
	{
		score_player++;
	}
	else
	{
		score_computer++;
	}
}

std::string ChoiceToString(int choice)
{
	switch (choice)
	{
		case 1: return "Камень";
		case 2: return "Ножницы";
		case 3: return "Бумага";
		default: return "Неизвестно";
	}
}

void ShowRoundResult(int player_choice, int computer_choice, int score_player, int score_computer, int draws)
{
	if (player_choice == computer_choice)
	{
		std::cout << "Ничья\n";
	}
	else if ((player_choice == 1 && computer_choice == 2) ||
		(player_choice == 2 && computer_choice == 3) ||
		(player_choice == 3 && computer_choice == 1))
	{
		std::cout << "Вы победили\n";
	}
	else
	{
		std::cout << "Компьютер победил\n";
	}
	std::cout << "\nИгрок: " << score_player << " | Компьютер: " << score_computer << " | Ничьи: " << draws << "\n";
}

void ShowFinalStatistics(int score_player, int score_computer, int draws)
{
	std::cout << "\nВсего сыграно раундов: " << (score_player + score_computer + draws) << "\n";
	std::cout << "Победы игрока: " << score_player << "\n";
	std::cout << "Победы компьютера: " << score_computer << "\n";
	std::cout << "Ничьи: " << draws << "\n";
	double win_rate = (score_player + draws > 0) ?
		(static_cast<double>(score_player) / (score_player + score_computer + draws) * 100) : 0;
	std::cout << "Процент побед игрока: " << win_rate << "%\n";
}

void RockScissorsPaper()
{
	int issue_number;
	do
	{
		std::cout << "\n== ИГРА \"КАМЕНЬ, НОЖНИЦЫ, БУМАГА\" ==\n";
		int difficulty_level = SelectDifficultyLevel();
		int score_player = 0;
		int score_computer = 0;
		int draws = 0;
		bool continue_game = true;
		while (continue_game)
		{
			int player_choice = GetPlayerChoice(difficulty_level);
			if (player_choice == 0)
			{
				break;
			}
			int computer_choice = GetComputerChoice(difficulty_level, player_choice, score_player, score_computer);
			std::cout << "\nВаш ход: " << ChoiceToString(player_choice) << "\n";
			std::cout << "Ход компьютера: " << ChoiceToString(computer_choice) << "\n";
			DetermineWinner(player_choice, computer_choice, score_player, score_computer, draws);
			ShowRoundResult(player_choice, computer_choice, score_player, score_computer, draws);
			int continue_choice;
			do
			{
				std::cout << "\n1. Продолжить игру\n";
				std::cout << "0. Выход\n";
				std::cout << "\nВыберите действие:\n";
				std::cin >> continue_choice;
				std::cin.ignore(10000, '\n');
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "ОШИБКА: Введено некорректное число\n";
					continue_choice = -1;
				}
				else if (continue_choice != 1 && continue_choice != 0)
				{
					std::cout << "ОШИБКА: Введено некорректное число\n";
				}
			} while (continue_choice != 1 && continue_choice != 0);
			if (continue_choice == 0)
			{
				continue_game = false;
			}
		}
		ShowFinalStatistics(score_player, score_computer, draws);
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