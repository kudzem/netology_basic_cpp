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
        std::cout << "Enter command('+', '-', '=' ��� 'x') : " << std::endl;
        char command;
        std::cin >> command;
        switch (command) {
            case 'x': {
                 std::cout << "�� ��������!" << std::endl;
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

//�� ������ ������� ��������� �������� �������� ? ������� �� ��� ��� : ��
//������� ��������� �������� �������� : 6
//������� �������('+', '-', '=' ��� 'x') : +
//������� �������('+', '-', '=' ��� 'x') : +
//������� �������('+', '-', '=' ��� 'x') : =
//8
//������� �������('+', '-', '=' ��� 'x') : -
//������� �������('+', '-', '=' ��� 'x') : =
//7
//������� �������('+', '-', '=' ��� 'x') : x
//�� ��������!