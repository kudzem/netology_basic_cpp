#include <iostream>
#include "GreetingLib.h"
#include <clocale>

int main()
{
	std::setlocale(LC_ALL, "rus");
	std::cout << "What's your name?" << std::endl;
	std::string your_name;
	std::cin >> your_name;
    MyGreetingLib::greet(your_name);
}