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
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

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
std::ostream& operator>>(std::ostream& os, Fraction& obj);