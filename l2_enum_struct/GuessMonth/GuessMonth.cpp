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

const char* month_str[] = { "����������� �����",
                            "������",
                            "�������",
                            "����",
                            "������",
                            "���",
                            "����",
                            "����",
                            "������",
                            "��������",
                            "�������",
                            "������",
                            "�������" };


int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "������� ����� ������ : ";
    while (true) {
        unsigned month;
        std::cin >> month;

        if (month > static_cast<unsigned>(Month::DECEMBER)) {
            std::cout << "������������ �����!" << std::endl;
            continue;
        }

        if (month == static_cast<unsigned>(Month::INCORRECT_MONTH)) {
            std::cout << "�� ��������" << std::endl;
            break;
        }

        std::cout << month_str[static_cast<unsigned>(month)] << std::endl;
    }
}

//������� ����� ������ : 1
//������
//������� ����� ������ : 7
//����
//������� ����� ������ : 13
//������������ �����!
//������� ����� ������ : 0
//�� ��������