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
    std::cout << "������� � ������ ����������" << std::endl;
#elif MODE == 1
    std::cout << "������� � ���������� ������" << std::endl;
    std::cout << "������� ����� 1: " << std::endl; 
    int a = 0;
    std::cin >> a;
    std::cout << "������� ����� 2: " << std::endl;
    int b = 0;
    std::cin >> b;
    std::cout << "��������� ��������: " << add(a,b) << std::endl;
#else
    std::cout << "����������� �����. ���������� ������" << std::endl;
#endif
}