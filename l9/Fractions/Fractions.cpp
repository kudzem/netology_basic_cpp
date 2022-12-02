#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << f1.str() << ((f1 == f2) ? " == " : " not == ") << f2.str() << '\n';
	std::cout << f1.str() << ((f1 != f2) ? " != " : " not != ") << f2.str() << '\n';
	std::cout << f1.str() << ((f1 < f2) ? " < " : " not < ") << f2.str() << '\n';
	std::cout << f1.str() << ((f1 > f2) ? " > " : " not > ") << f2.str() << '\n';
	std::cout << f1.str() << ((f1 <= f2) ? " <= " : " not <= ") << f2.str() << '\n';
	std::cout << f1.str() << ((f1 >= f2) ? " >= " : " not >= ") << f2.str() << '\n';
	return 0;
}