#include <iostream>
#include "Fraction.h"
#include <assert.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	Fraction f1(1, 2);
	Fraction f2(1, 3);
	Fraction f3(1, 4);

	//std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	//std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	//std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	//std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	//std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	//std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';

	//if (f1 + f2 + f3 != Fraction(13,12)) { std::cerr << "Incorrect add"; }
	//if (f1 - f2 - f3 != Fraction(-1, 12)) { std::cerr << "Incorrect sub"; }
	//if (f1 * f2 * f3 != Fraction(1, 24)) { std::cerr << "Incorrect mult"; }
	//if (f1 / f2 / f3 != Fraction(6, 1)) { std::cerr << "Incorrect div"; }
	//if (-f1 + f2 != f2 - f1) { std::cerr << "Incorrect unary minus"; }
	//if (f1++ * f2++ != Fraction(1,6)) { std::cerr << "Incorrect postfix increment"; }
	//if (f1 * f2 != Fraction(2, 1)) { std::cerr << "Incorrect postfix increment"; }
	//if (--f1 * --f2 != Fraction(1, 6)) { std::cerr << "Incorrect prefix decrement"; }
	//if (++f1 * ++f2 != Fraction(2, 1)) { std::cerr << "Incorrect prefix increment"; }
	//if (f1-- * f2-- != Fraction(2, 1)) { std::cerr << "Incorrect prefix decrement"; }
	//if (f1 * f2 != Fraction(1, 6)) { std::cerr << "Incorrect prefix decrement"; }

	//if ((double)f1 != 0.5) { std::cerr << "Incorrect explicit type casting to double"; }
	//if ((int)Fraction(5,2) != 2) { std::cerr << "Incorrect explicit type casting to int"; }
	//if (Fraction(5, 2) != 2) { std::cerr << "Incorrect implicit type casting to int"; }

	Fraction fc((-f1 * f2 + f2 / --f3 - f1 / f3++)--);
	std::cout << fc << '\n';

	return 0;

	//Fraction f4 = f1 + Fraction(1, 2);
	//std::cout << fc() << '\n';

	std::cout << "Введите первую дробь. Поставьте пробел между числ и знаменателем" << std::endl;
	std::cin >> f1;
	std::cout << "Введите вторую дробь" << std::endl;
	std::cin >> f2;

	//std::cout << f1 << "+" << f2 << "=" << f1 + f2 << '\n';
	//std::cout << f1 << "-" << f2 << "=" << f1 - f2 << '\n';
	//std::cout << f1 << "*" << f2 << "=" << f1 * f2 << '\n';
	//std::cout << f1 << "/" << f2 << "=" << f1 / f2 << '\n';
	//std::cout << "++" << f1 << "*" << f2 << "=" << ++f1 * f2 << '\n';
	//std::cout << "f1=" << f1 << '\n';
	//std::cout << f1 << "--" << "*" << f2 << "=" << f1-- * f2 << '\n';
	//std::cout << "f1=" << f1 << '\n';

	std::cout << "f1*--f1" << f1*--f1 << '\n';

	return 0;
}