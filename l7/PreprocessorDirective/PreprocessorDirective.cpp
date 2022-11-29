// PreprocessorDirective.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#ifndef MODE
#error Program mode is not set
#elif MODE == 1
int add(int a, int b) { return a + b; }
#endif

int main()
{
    setlocale(LC_ALL, "Russian");

#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    std::cout << "Работаю в нормальном режиме" << std::endl;
    std::cout << "Введите число 1: " << std::endl; 
    int a = 0;
    std::cin >> a;
    std::cout << "Введите число 2: " << std::endl;
    int b = 0;
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a,b) << std::endl;
#else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
}