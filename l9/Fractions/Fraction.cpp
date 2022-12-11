#include "Fraction.h"
#include <iostream>

int Fraction::counter = 0;

void
Fraction::normalise() {
	if (denominator_ < 0) {
		denominator_ *= -1;
		numerator_ *= -1;
	}

	int n = nod(denominator_, abs(numerator_));
	denominator_ /= n;
	numerator_ /= n;
}

Fraction 
Fraction::operator+(const Fraction& other) const {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "add(" << counter << ")" << other.numerator_ << "/" << other.denominator_ << std::endl;
	Fraction f(this->numerator_ * other.denominator_ + this->denominator_ * other.numerator_,
		other.denominator_ * this->denominator_);
	f.normalise();
	return f;
}

Fraction
Fraction::operator-(const Fraction& other) const {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "sub(" << counter << ")" << other.numerator_ << "/" << other.denominator_ << std::endl;
	Fraction f(this->numerator_ * other.denominator_ - this->denominator_ * other.numerator_,
		other.denominator_ * this->denominator_);
	f.normalise();
	return f;
}

Fraction
Fraction::operator*(const Fraction& other) const {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "mult(" << counter << ")" << other.numerator_ << "/" << other.denominator_ << std::endl;
	Fraction f(other.numerator_ * this->numerator_, other.denominator_ * this->denominator_);
	f.normalise();
	return f;
}

Fraction
Fraction::operator/(const Fraction& other) const {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "div(" << counter << ")" << other.numerator_ << "/" << other.denominator_ << std::endl;
	Fraction f(this->numerator_ * other.denominator_, this->denominator_ * other.numerator_);
	f.normalise();
	return f;
}

Fraction&
Fraction::operator++() {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "pre++(" << counter << ")" << std::endl;
	numerator_ += this->denominator_;
	normalise();
	return *this;
}

Fraction
Fraction::operator++(int) {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "post++(" << counter << ")" << std::endl;
	Fraction prev = *this;
	numerator_ += denominator_;
	return prev;
}

Fraction&
Fraction::operator--() {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "pre--(" << counter << ")" << std::endl;
	this->numerator_ -= this->denominator_;
	normalise();
	return *this;
}

Fraction
Fraction::operator--(int) {
	counter++;
	std::cout << this->numerator_ << "/" << denominator_ << "post--(" << counter << ")" << std::endl;

	Fraction prev = *this;
	numerator_ -= denominator_;
	return prev;
}

Fraction::operator int() {
	return numerator_ / denominator_;
}

Fraction::operator double() {
	return (double)numerator_ / denominator_;
}

std::string
Fraction::str() const {
	return std::to_string(numerator_) + "/" + std::to_string(denominator_);
}

std::string
Fraction::operator() () const {
	return str();
}

std::ostream&
operator<<(std::ostream& os, const Fraction& obj)
{
	os << obj.str();
	return os;
}

std::istream&
operator>>(std::istream& os, Fraction& obj)
{
	os >> obj.numerator_ >> obj.denominator_;
	return os;
}

Fraction operator-(const Fraction& obj) {
	Fraction f(-obj.numerator_, obj.denominator_);
	f.normalise();
	return f;
}

int nod(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}

	return a + b;
}