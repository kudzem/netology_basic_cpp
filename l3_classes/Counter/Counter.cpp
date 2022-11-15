// Counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Counter {
public:
    Counter(int init_value = 1) : value(init_value) {}
    Counter& operator++() { this->value++; return *this; }
    Counter& operator--() { this->value--; return *this; }
    inline int get() const { return value; }

private:
    int value;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Do you want to set initial counter value? (yes/no) : ";
    std::string answer;
    std::cin >> answer;

    Counter cnt;
    if (answer == "yes")
    {
        std::cout << "Enter initial counter value : ";
        unsigned init_value = 0;
        std::cin >> init_value;
        cnt = Counter(init_value);
    }

    while (true) {
        std::cout << "Enter command('+', '-', '=' или 'x') : " << std::endl;
        char command;
        std::cin >> command;
        switch (command) {
            case 'x': {
                 std::cout << "До свидания!" << std::endl;
                 return 0;
            }
            case '+': ++cnt; break;
            case '-': --cnt; break;
            case '=': {
                std::cout << cnt.get() << std::endl;
                break;
            }
        }
    }
}

//Вы хотите указать начальное значение счётчика ? Введите да или нет : да
//Введите начальное значение счётчика : 6
//Введите команду('+', '-', '=' или 'x') : +
//Введите команду('+', '-', '=' или 'x') : +
//Введите команду('+', '-', '=' или 'x') : =
//8
//Введите команду('+', '-', '=' или 'x') : -
//Введите команду('+', '-', '=' или 'x') : =
//7
//Введите команду('+', '-', '=' или 'x') : x
//До свидания!