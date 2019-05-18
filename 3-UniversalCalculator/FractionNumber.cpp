#include "FractionNumber.h"
#include "BaseConverter.h"

#include <cstdint>
#include <cctype>

constexpr std::uint8_t DEC_BASE = 10;		// Основание 10-й СС

FractionNumber::FractionNumber(std::string number, std::uint8_t P) {
	auto temp_numerator = findNumerator(number);
	auto temp_denominator = findDenominator(number);

	auto gcd_value = temp_numerator ? GCD(std::abs(temp_numerator), temp_denominator) : 1;

	temp_numerator /= gcd_value;
	temp_denominator /= gcd_value;

	this->numerator = temp_numerator;
	this->denominator = temp_denominator;

	this->number = fromNumDenToNumber(temp_numerator, temp_denominator);
	this->P = P;
}

FractionNumber::FractionNumber(int numerator, int denominator) {
	auto gcd_value = numerator ? GCD(std::abs(numerator), denominator) : 1;

	this->numerator = numerator / gcd_value;
	this->denominator = denominator / gcd_value;

	number = fromNumDenToNumber(this->numerator, this->denominator);
}

FractionNumber::FractionNumber(const FractionNumber& rval) {
	number = rval.number;

	numerator = rval.numerator;
	denominator = rval.denominator;
}

// Получить комплексное число в виде строки
std::string FractionNumber::getNumber() const {
	return number;
}

// Получить числитель числа
std::string FractionNumber::getNumeratorNumber() const {
	return std::to_string(numerator);
}

// Получить знаменатель числа
std::string FractionNumber::getDenominatorNumber() const {
	return std::to_string(denominator);
}

// Получить числитель числа
int FractionNumber::getNumerator() const {
	return numerator;
}

// Получить знаменатель числа
int FractionNumber::getDenominator() const {
	return denominator;
}

std::uint8_t FractionNumber::getP() const {
	return P;
}

// Получить квадрат комплексного числа
FractionNumber FractionNumber::getSquare() const {
	return FractionNumber(numerator * numerator, denominator * denominator);
}

// Получить обратное комплексное число
FractionNumber FractionNumber::getReverse() const {
	FractionNumber result(numerator, denominator);

	if (numerator != 0)
		result = numerator < 0 ? FractionNumber(-denominator, -numerator) :
								 FractionNumber(denominator, numerator);

	return result;
}

// Выделить числитель из числа
int FractionNumber::findNumerator(std::string number) const {
	int value = 0;

	for (auto it = number.begin(); it != number.end() && *it != '/'; ++it)
		if (std::isdigit(*it))
			value = value * DEC_BASE + BaseConverter::chrToNumeral(*it);
	
	if (value && number[0] == '-')
		value = -value;

	return value;
}

// Выделить знаменатель из числа
int FractionNumber::findDenominator(std::string number) const {
	int value = 0;

	std::string::iterator it;
	for (it = number.begin(); it != number.end() && *it != '/'; ++it);

	for (; it != number.end(); ++it)
		if (std::isdigit(*it))
			value = value * DEC_BASE + BaseConverter::chrToNumeral(*it);

	return value == 0 ? 1 : value;
}

std::string FractionNumber::fromNumDenToNumber(int numerator, int denominator) const {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

// Найти НОД
int FractionNumber::GCD(int a, int b) {
	while (a != b) {
		if (b < a)
			std::swap(a, b);

		b -= a;
	}

	return a;
}

FractionNumber operator+(const FractionNumber& rhs) {
	return FractionNumber(rhs);
}

FractionNumber operator-(const FractionNumber& rhs) {
	return FractionNumber(-rhs.getNumerator(), rhs.getDenominator());
}

FractionNumber operator+(const FractionNumber& lhs, const FractionNumber& rhs) {
	return FractionNumber(lhs.getNumerator() * rhs.getDenominator() + lhs.getDenominator() * rhs.getNumerator(),
						  rhs.getDenominator() * lhs.getDenominator());
}

FractionNumber operator*(const FractionNumber& lhs, const FractionNumber& rhs) {
	return FractionNumber(lhs.getNumerator() * rhs.getNumerator(),
						  lhs.getDenominator() * rhs.getDenominator());
}

FractionNumber operator-(const FractionNumber& lhs, const FractionNumber& rhs) {
	return FractionNumber(lhs.getNumerator() * rhs.getDenominator() - lhs.getDenominator() * rhs.getNumerator(),
						  rhs.getDenominator() * lhs.getDenominator());
}

FractionNumber operator/(const FractionNumber& lhs, const FractionNumber& rhs) {
	return FractionNumber(lhs.getNumerator() * rhs.getDenominator(),
						  rhs.getNumerator() * lhs.getDenominator());
}
