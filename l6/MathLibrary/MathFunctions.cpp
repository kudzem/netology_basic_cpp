namespace MyMathFunctions {
	int add(int a, int b) {
		return a + b;
	}

	int sub(int a, int b) {
		return a - b;
	}

	int mult(int a, int b) {
		return a * b;
	}

	int div(int a, int b) {
		return a / b;
	}

	int pow(int a, int b) {
		int result = 1;
		for (int i = 0; i < b; ++i) {
			result *= a;
		}
		return result;
	}
}