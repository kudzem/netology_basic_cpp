#pragma once
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

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

	std::string str() const {
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}

};