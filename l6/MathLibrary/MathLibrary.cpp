#include <iostream>
#include "MathFunctions.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b, operation;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    std::cout << "Выберите операцию(1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень) : ";
    std::cin >> operation;

    double result = 0;
    switch (operation) {
        case MyMathFunctions::ADD: result = MyMathFunctions::add(a, b); break;
        case MyMathFunctions::SUBSTRACT: result = MyMathFunctions::sub(a, b); break;
        case MyMathFunctions::MULTIPLY: result = MyMathFunctions::mult(a, b); break;
        case MyMathFunctions::DIVIDE: result = MyMathFunctions::div(a, b); break;
        case MyMathFunctions::POWER: result = MyMathFunctions::pow(a, b); break;
        default: std::cout << "Неизвестная операция " << operation << std::endl; return 1;
    }

    const char operation_sign [] = {'?', '+', '-', '*', '/', '^'};
    std::cout << '(' << a << ')' << operation_sign[operation] << '(' << b << ')' << '=' << result << std::endl;
}