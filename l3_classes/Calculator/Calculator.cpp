// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Calculator {
private:
    double num1, num2;

public:
    Calculator() = default;
    Calculator(double num1, double num2) : num1(num1), num2(num2) {}

    inline double add() const { return num1 + num2; }
    inline double multiply() const { return num1 * num2; }
    inline double subtract_1_2() const { return num1 - num2; }
    inline double subtract_2_1() const { return num2 - num1; }
    inline double divide_1_2() const { return num1 / num2; }
    inline double divide_2_1() const { return num2 / num1; }

    bool set_num1(double num1) {
        if (num1 == 0) return false;
        this->num1 = num1;
        return true;
    }
    bool set_num2(double num2) {
        if (num2 == 0) return false;
        this->num2 = num2;
        return true;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Calculator calc;
    for (int i = 0; i < 3; ++i) {

        double number;
        while (true) {
            std::cout << "Введите num1 : ";
            std::cin >> number;
            if (calc.set_num1(number)) break;
            std::cout << "Неверный ввод!" << std::endl;
        };

        while (true) {
            std::cout << "Введите num2 : ";
            std::cin >> number;
            if (calc.set_num2(number)) break;
            std::cout << "Неверный ввод!" << std::endl;
        };

        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num2 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }
}