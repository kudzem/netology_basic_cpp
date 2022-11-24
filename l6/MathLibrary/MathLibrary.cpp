#include <iostream>
#include "MathFunctions.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b, operation;
    std::cout << "������� ������ �����: ";
    std::cin >> a;
    std::cout << "������� ������ �����: ";
    std::cin >> b;
    std::cout << "�������� ��������(1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������) : ";
    std::cin >> operation;

    double result = 0;
    switch (operation) {
        case MyMathFunctions::ADD: result = MyMathFunctions::add(a, b); break;
        case MyMathFunctions::SUBSTRACT: result = MyMathFunctions::sub(a, b); break;
        case MyMathFunctions::MULTIPLY: result = MyMathFunctions::mult(a, b); break;
        case MyMathFunctions::DIVIDE: result = MyMathFunctions::div(a, b); break;
        case MyMathFunctions::POWER: result = MyMathFunctions::pow(a, b); break;
        default: std::cout << "����������� �������� " << operation << std::endl; return 1;
    }

    const char operation_sign [] = {'?', '+', '-', '*', '/', '^'};
    std::cout << '(' << a << ')' << operation_sign[operation] << '(' << b << ')' << '=' << result << std::endl;
}