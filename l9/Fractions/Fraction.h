#pragma once
#include <string>

int nod(int a, int b);

class Fraction
{
private:
	int numerator_;
	int denominator_;

	void normalise();

public:

	static int counter;
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	//Fraction(Fraction& other) {
	//	numerator_ = other.numerator_;
	//	denominator_ = other.denominator_;
	//}

	//Fraction(Fraction&& other) noexcept {
	//	numerator_ = other.numerator_;
	//	denominator_ = other.denominator_;
	//}

	//Fraction operator=(Fraction& other) {
	//	numerator_ = other.numerator_;
	//	denominator_ = other.denominator_;
	//	return *this;
	//}

	//Fraction operator=(Fraction&& other) noexcept {
	//	numerator_ = other.numerator_;
	//	denominator_ = other.denominator_;
	//	return *this;
	//}



	inline bool operator==(const Fraction& other) const {
		return other.numerator_ * denominator_ == other.denominator_ * numerator_;
	}

	inline bool operator!=(const Fraction& other) const {
		return !(*this == other);
	}

	inline bool operator<(const Fraction & other) const {
		return other.denominator_ * numerator_ < other.numerator_ * denominator_;
	}

	inline bool operator>(const Fraction& other) const {
		return other.denominator_ * numerator_ > other.numerator_* denominator_;
	}

	inline bool operator<=(const Fraction& other) const {
		return !(*this > other);
	}

	inline bool operator>=(const Fraction& other) const {
		return !(*this < other);
	}

	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;

	Fraction& operator++();
	Fraction operator++(int);

	Fraction& operator--();
	Fraction operator--(int);

	operator int();
	explicit operator double();

	friend Fraction operator-(const Fraction& obj);
	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
	friend std::istream& operator>>(std::istream& os, Fraction& obj);

	std::string str() const;
	std::string operator() () const;
};

Fraction operator-(const Fraction& obj);

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& os, Fraction& obj);