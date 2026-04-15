#include <iostream>
#include <cmath>
#include <conio.h>
#include <chrono>

void CheckAndNotify(int remaining_seconds, int total_seconds, bool& notified_50, bool& notified_25, bool& notified_10) {
    double percent = (static_cast<double>(remaining_seconds) / total_seconds) * 100;
    if (!notified_50 && percent <= 50.0) {
        std::cout << "Осталось 50% времени\n";
        notified_50 = true;
    }
    else if (!notified_25 && percent <= 25.0) {
        std::cout << "Осталось 25% времени\n";
        notified_25 = true;
    }
    else if (!notified_10 && percent <= 10.0) {
        std::cout << "Осталось 10% времени\n";
        notified_10 = true;
    }
}

bool RunSingleTimer(int total_seconds) {
    int remaining_seconds = total_seconds;
    bool paused = false;
    bool notified_50 = false;
    bool notified_25 = false;
    bool notified_10 = false;
    char user_input;
    std::cout << "\nТаймер запущен на " << total_seconds << " секунд\n";
    std::cout << "Пробел - пауза/продолжение, q - отмена таймера\n\n";
    auto start_time = std::chrono::steady_clock::now();
    auto pause_start_time = start_time;
    int minutes = remaining_seconds / 60;
    int seconds = remaining_seconds % 60;
    std::cout << minutes << "м " << seconds << "с\n";
    while (remaining_seconds > 0) {
        if (!paused) {
            auto current_time = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
            int new_remaining = total_seconds - static_cast<int>(elapsed);
            if (new_remaining != remaining_seconds && new_remaining >= 0) {
                remaining_seconds = new_remaining;
                minutes = remaining_seconds / 60;
                seconds = remaining_seconds % 60;
                std::cout << minutes << "м " << seconds << "с\n";
                CheckAndNotify(remaining_seconds, total_seconds, notified_50, notified_25, notified_10);
            }
        }
        if (_kbhit()) {
            user_input = _getch();
            if (user_input == ' ') {
                if (!paused) {
                    paused = true;
                    pause_start_time = std::chrono::steady_clock::now();
                    std::cout << "Нажмите пробел для продолжения или q для отмены\n";
                }
                else {
                    auto pause_end_time = std::chrono::steady_clock::now();
                    auto pause_duration = std::chrono::duration_cast<std::chrono::seconds>(pause_end_time - pause_start_time).count();
                    start_time += std::chrono::seconds(pause_duration);
                    paused = false;
                }
            }
            else if (user_input == 'q') {
                std::cout << "\nТаймер отменен\n";
                return false;
            }
        }
    }
    std::cout << "\nВРЕМЯ ВЫШЛО\n";
    return true;
}

void RunIntervalTimer() {
    int interval_seconds;
    int repetitions;
    do {
        std::cout << "\nВведите длительность интервала в секундах (от 5 до 600): ";
        std::cin >> interval_seconds;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "ОШИБКА: Введите целое число\n";
            continue;
        }
        if (interval_seconds < 5 || interval_seconds > 600) {
            std::cout << "ОШИБКА: Интервал должен быть от 5 до 600 секунд\n";
            continue;
        }
        break;
    } while (true);
    do {
        std::cout << "Введите количество повторений (от 1 до 20): ";
        std::cin >> repetitions;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "ОШИБКА: Введите целое число\n";
            continue;
        }
        if (repetitions < 1 || repetitions > 20) {
            std::cout << "ОШИБКА: Количество повторений должно быть от 1 до 20\n";
            continue;
        }
        break;
    } while (true);
    std::cout << "Интервал: " << interval_seconds << " секунд\n";
    std::cout << "Количество повторений: " << repetitions << "\n";
    for (int i = 1; i <= repetitions; ++i) {
        std::cout << "\nИнтервал " << i << " из " << repetitions << "\n";
        bool completed = RunSingleTimer(interval_seconds);
        if (!completed) {
            break;
        }
    }
    std::cout << "\nИнтервальный режим завершен\n";
}

void Timer() {
    int issue_number;

    do {
        std::cout << "\n== ТАЙМЕР ОБРАТНОГО ОТСЧЕТА С УВЕДОМЛЕНИЯМИ ==\n";
        int mode;
        do {
            std::cout << "Режим работы:\n";
            std::cout << "1. Обычный таймер\n";
            std::cout << "2. Интервальный таймер\n";
            std::cout << "\nВыберите действие: ";
            std::cin >> mode;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "ОШИБКА: Введите число 1 или 2\n";
                continue;
            }
            if (mode != 1 && mode != 2) {
                std::cout << "ОШИБКА: Режим должен быть 1 или 2\n";
                continue;
            }
            break;
        } while (true);
        if (mode == 1) {
            int total_seconds;
            do {
                std::cout << "\nВведите время в секундах (от 10 до 3600): ";
                std::cin >> total_seconds;
                std::cin.ignore(10000, '\n');
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "ОШИБКА: Введите целое число\n";
                    continue;
                }
                if (total_seconds < 10 || total_seconds > 3600) {
                    std::cout << "ОШИБКА: Время должно быть от 10 до 3600 секунд\n";
                    continue;
                }
                break;
            } while (true);
            RunSingleTimer(total_seconds);
        }
        else if (mode == 2) {
            RunIntervalTimer();
        }
        do {
            std::cout << "\nЗадача завершена\n";
            std::cout << "1. Выполнить задачу еще раз\n";
            std::cout << "0. Выход\n\n";
            std::cout << "Выберите действие: ";
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