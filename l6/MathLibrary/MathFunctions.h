#pragma once

namespace MyMathFunctions {

typedef
enum {
	ADD = 1,
	SUBSTRACT,
	MULTIPLY,
	DIVIDE,
	POWER
} Operation;

	int add(int a, int b);
	int sub(int a, int b);
	int mult(int a, int b);
	int div(int a, int b);
	int pow(int a, int b);
}
