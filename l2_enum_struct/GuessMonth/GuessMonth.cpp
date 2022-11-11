// GuessMonth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum class Month : uint8_t {
    INCORRECT_MONTH,
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

const char* month_str[] = { "Неизвестный месяц",
                            "Январь",
                            "Февраль",
                            "Март",
                            "Апрель",
                            "Май",
                            "Июнь",
                            "Июль",
                            "Август",
                            "Сентябрь",
                            "Октыбрь",
                            "Ноябрь",
                            "Декабрь" };


int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер месяца : ";
    while (true) {
        unsigned month;
        std::cin >> month;

        if (month > static_cast<unsigned>(Month::DECEMBER)) {
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }

        if (month == static_cast<unsigned>(Month::INCORRECT_MONTH)) {
            std::cout << "До свидания" << std::endl;
            break;
        }

        std::cout << month_str[static_cast<unsigned>(month)] << std::endl;
    }
}

//Введите номер месяца : 1
//Январь
//Введите номер месяца : 7
//Июль
//Введите номер месяца : 13
//Неправильный номер!
//Введите номер месяца : 0
//До свидания