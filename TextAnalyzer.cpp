#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

void CountCharacters(const std::string& text, int& total_chars, int& chars_without_spaces) {
	total_chars = text.length();
	chars_without_spaces = 0;
	for (char c : text) {
		if (c != ' ') {
			chars_without_spaces++;
		}
	}
}

int CountWords(const std::string& text) {
	if (text.empty()) return 0;
	int word_count = 0;
	bool in_word = false;
	for (char c : text) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') || (c >= '0' && c <= '9') || c == '\'' || c == '-') {
			if (!in_word) {
				in_word = true;
				word_count++;
			}
		}
		else {
			in_word = false;
		}
	}
	return word_count;
}

int CountSentences(const std::string& text) {
	int sentence_count = 0;
	for (char c : text) {
		if (c == '.' || c == '!' || c == '?') {
			sentence_count++;
		}
	}
	if (sentence_count == 0 && !text.empty()) {
		sentence_count = 1;
	}
	return sentence_count;
}

void FindLongestAndShortestWord(const std::string& text, std::string& longest_word, std::string& shortest_word) {
	std::stringstream ss(text);
	std::string word;
	longest_word = "";
	shortest_word = "";
	while (ss >> word) {
		std::string clean_word;
		for (char c : word) {
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') || (c >= '0' && c <= '9') || c == '\'' || c == '-') {
				clean_word.push_back(c);
			}
		}
		if (clean_word.empty()) continue;
		if (longest_word.empty() || clean_word.length() > longest_word.length()) {
			longest_word = clean_word;
		}
		if (shortest_word.empty() || clean_word.length() < shortest_word.length()) {
			shortest_word = clean_word;
		}
	}
}

std::map<char, int> CountLetterFrequency(const std::string& text) {
	std::map<char, int> frequency;
	for (char c : text) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
			char lower_c = c;
			if (c >= 'A' && c <= 'Z') {
				lower_c = c - 'A' + 'a';
			}
			else if (c >= 'А' && c <= 'Я') {
				lower_c = c - 'А' + 'а';
			}
			++frequency[lower_c];
		}
	}
	return frequency;
}

bool IsPalindrome(const std::string& text) {
	std::string cleaned_text;
	for (char c : text) {
		if ((c >= 'a' && c <= 'z') || (c >= 'а' && c <= 'я') || (c >= '0' && c <= '9')) {
			cleaned_text += c;
		}
		else if (c >= 'A' && c <= 'Z') {
			cleaned_text += c - 'A' + 'a';
		}
		else if (c >= 'А' && c <= 'Я') {
			cleaned_text += c - 'А' + 'а';
		}
	}
	if (cleaned_text.empty()) return false;
	int left = 0;
	int right = cleaned_text.length() - 1;
	while (left < right) {
		if (cleaned_text[left] != cleaned_text[right]) {
			return false;
		}
		++left;
		--right;
	}
	return true;
}

void DisplayStatistics(const std::string& text, int total_chars, int chars_without_spaces,
	int word_count, int sentence_count, const std::string& longest_word,
	const std::string& shortest_word, const std::map<char, int>& frequency,
	bool is_palindrome) {
	std::cout << "\nИсходный текст: \"" << text << "\"\n\n";
	std::cout << "Всего символов (с пробелами): " << total_chars << "\n";
	std::cout << "Всего символов (без пробелов): " << chars_without_spaces << "\n";
	std::cout << "Количество слов: " << word_count << "\n";
	std::cout << "Количество предложений: " << sentence_count << "\n\n";
	if (!longest_word.empty()) {
		std::cout << "Самое длинное слово: \"" << longest_word << "\" (длина: " << longest_word.length() << ")\n";
		std::cout << "Самое короткое слово: \"" << shortest_word << "\" (длина: " << shortest_word.length() << ")\n\n";
	}
	else {
		std::cout << "Слова не найдены\n\n";
	}

	std::cout << "Частота букв\n";
	if (frequency.empty()) {
		std::cout << "Буквы не найдены\n";
	}
	else {
		for (const auto& pair : frequency) {
			std::cout << "Буква '" << pair.first << "': " << pair.second << "\n";
		}
	}
	std::cout << "\n";
	if (is_palindrome) {
		std::cout << "Текст является палиндромом\n";
	}
	else {
		std::cout << "Текст не является палиндромом\n";
	}
}

void TextAnalyzer() {
	int issue_number;
	do {
		std::cout << "\n== АНАЛИЗАТОР ТЕКСТА ==\n";
		std::string text;
		bool valid_input = false;
		do {
			std::cout << "Введите текст для анализа (до 1000 символов):\n";
			std::getline(std::cin, text);
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "ОШИБКА: Ошибка ввода текста\n";
				continue;
			}
			if (text.length() > 1000) {
				std::cout << "ОШИБКА: Текст превышает максимальную длину в 1000 символов\n";
				std::cout << "Вы ввели " << text.length() << " символов\n\n";
				continue;
			}
			if (text.empty()) {
				std::cout << "ОШИБКА: Текст не может быть пустым\n";
				continue;
			}
			valid_input = true;
			break;

		} while (true);
		if (!valid_input) {
			continue;
		}
		int total_chars, chars_without_spaces;
		CountCharacters(text, total_chars, chars_without_spaces);
		int word_count = CountWords(text);
		int sentence_count = CountSentences(text);
		std::string longest_word, shortest_word;
		FindLongestAndShortestWord(text, longest_word, shortest_word);
		std::map<char, int> frequency = CountLetterFrequency(text);
		bool is_palindrome = IsPalindrome(text);
		DisplayStatistics(text, total_chars, chars_without_spaces, word_count,
			sentence_count, longest_word, shortest_word, frequency, is_palindrome);
		do {
			std::cout << "\nЗадача завершена\n";
			std::cout << "1. Выполнить задачу еще раз\n";
			std::cout << "0. Выход\n\n";
			std::cout << "Выберите действие:\n";
			std::cin >> issue_number;
			std::cin.ignore(10000, '\n');
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				issue_number = -1;
			}
			if (issue_number != 1 && issue_number != 0) {
				std::cout << "ОШИБКА: Введено некорректное число\n";
			}
		} while (issue_number != 1 && issue_number != 0);
	} while (issue_number != 0);
}