#include <iostream>
#include "Counter.h"

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