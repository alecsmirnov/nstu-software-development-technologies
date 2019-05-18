#include "ComplexNumber.h"

#include <cstdint>
#include <cctype>

constexpr double PI = 3.1415926535897932;

ComplexNumber::ComplexNumber(std::string number, std::uint8_t P) {
	this->number = number;
	this->P = P;

	z = std::complex<double>(findRe(number), findIm(number));
}

ComplexNumber::ComplexNumber(double re, double im) {
	number = fromReImToNumber(re, im);

	z = std::complex<double>(re, im);
}

ComplexNumber::ComplexNumber(std::complex<double> z) {
	number = fromReImToNumber(z.real(), z.imag());

	this->z = z;
}

ComplexNumber::ComplexNumber(const ComplexNumber& rval) {
	number = rval.number;

	z = rval.z;
}

// Задать комплексное число в виде комплексного типа
void ComplexNumber::setComplex(std::complex<double> z) {
	number = fromReImToNumber(z.real(), z.imag());

	this->z = z;
}

// Получить комплексное число в виде комплексного типа
std::complex<double> ComplexNumber::getComplex() const {
	return z;
}

// Получить комплексное число в виде строки
std::string ComplexNumber::getNumber() const {
	return number;
}

// Получить действительную часть числа
std::string ComplexNumber::getReNumber() const {
	return removeTrailingZeros(std::to_string(z.real()));
}

// Получить мнимую часть числа
std::string ComplexNumber::getImNumber() const {
	return removeTrailingZeros(std::to_string(z.imag()));
}

// Получить действительную часть числа
double ComplexNumber::getRe() const {
	return z.real();
}

// Получить мнимую часть числа
double ComplexNumber::getIm() const {
	return z.imag();
}

std::uint8_t ComplexNumber::getP() const {
	return P;
}

// Получить модуль числа
double ComplexNumber::getAbs() const {
	return std::abs(z);
}

double ComplexNumber::getArg() const {
	return std::arg(z);
}

double ComplexNumber::getArgDegree() const {
	return std::arg(z) * PI / 180;
}

// Выделить действительную часть числа
double ComplexNumber::findRe(std::string number) const {
	double value = 0;

	std::string str_value;
	for (auto it = number.begin(); it != number.end() && *it != 'i'; ++it)
		if (std::isdigit(*it) || *it == '.')
			str_value += *it;

	if (!str_value.empty()) {
		value = std::stod(str_value);

		if (number[0] == '-')
			value = -value;
	}

	return value;
}

// Выделить мнимую часть числа
double ComplexNumber::findIm(std::string number) const {
	double value = 0;

	std::string::iterator it;
	if (!number.empty())
		for (it = number.begin() + 1; it != number.end() && *it != 'i'; ++it);

	if (it != number.end()) {
		std::string str_value;

		if (*it == '-')
			str_value.push_back('-');

		for (; it != number.end(); ++it)
			if (std::isdigit(*it) || *it == '.')
				str_value += *it;

		if (!str_value.empty())
			value = std::stod(str_value);
	}

	return value;
}

std::string ComplexNumber::fromReImToNumber(double re, double im) const {
	std::string new_number = removeTrailingZeros(std::to_string(re));

	if (im < 0) {
		new_number += "-i";
		im = -im;
	}
	else
		new_number += "+i";

	new_number += removeTrailingZeros(std::to_string(im));

	return new_number;
}

// Проверка числа на вещественное
bool ComplexNumber::isRealNum(const std::string& number) {
	return number.find('.') != std::string::npos;
}

// Выделить мнимую часть числа
std::string ComplexNumber::removeTrailingZeros(const std::string& number) {
	std::string result(number);

	if (isRealNum(result)) {
		result.erase(result.find_last_not_of('0') + 1, std::string::npos);

		if (result[result.length() - 1] == '.')
			result.pop_back();
	}

	return result;
}

// Получить квадрат комплексного числа
ComplexNumber ComplexNumber::getSquare() const {
	return ComplexNumber(z * z);
}

// Получить обратное комплексное число
ComplexNumber ComplexNumber::getReverse() const {
	return ComplexNumber(z.real() / (z.real() * z.real() + z.imag() * z.imag()),
						-z.imag() / (z.real() * z.real() + z.imag() * z.imag()));
}

ComplexNumber operator+(const ComplexNumber& rhs) {
	return ComplexNumber(rhs);
}

ComplexNumber operator-(const ComplexNumber& rhs) {
	return ComplexNumber(-rhs.getRe(), rhs.getIm());
}

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return ComplexNumber(lhs.getComplex() + rhs.getComplex());
}

ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return ComplexNumber(lhs.getComplex() * rhs.getComplex());
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return ComplexNumber(lhs.getComplex() - rhs.getComplex());
}

ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return ComplexNumber(lhs.getComplex() / rhs.getComplex());
}
