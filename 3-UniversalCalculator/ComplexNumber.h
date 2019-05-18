#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <complex>
#include <string>

// Класс, реализующий комплексное число
class ComplexNumber {
public:
	ComplexNumber() = default;
	ComplexNumber(std::string number, std::uint8_t P = 10);
	ComplexNumber(double re, double im);
	ComplexNumber(std::complex<double> z);
	ComplexNumber(const ComplexNumber& rval);

	// Задать комплексное число в виде комплексного типа
	void setComplex(std::complex<double> z);
	// Получить комплексное число в виде комплексного типа
	std::complex<double> getComplex() const;

	// Получить комплексное число в виде строки
	std::string getNumber() const;
	// Получить действительную часть числа
	std::string getReNumber() const;
	// Получить мнимую часть числа
	std::string getImNumber() const;

	// Получить действительную часть числа
	double getRe() const;
	// Получить мнимую часть числа
	double getIm() const;
	std::uint8_t getP() const;

	// Получить модуль числа
	double getAbs() const;
	double getArg() const;
	double getArgDegree() const;

	// Получить квадрат комплексного числа
	ComplexNumber getSquare() const;
	// Получить обратное комплексное число
	ComplexNumber getReverse() const;

private:
	// Выделить действительную часть числа
	double findRe(std::string number) const;
	// Выделить мнимую часть числа
	double findIm(std::string number) const;

	std::string fromReImToNumber(double re, double im) const;

	// Проверка числа на вещественное
	static bool isRealNum(const std::string& number);
	// Удаление незначимых нулей числа
	static std::string removeTrailingZeros(const std::string& number);

private:
	std::string number;
	std::uint8_t P;

	std::complex<double> z;
};

ComplexNumber operator+(const ComplexNumber& rhs);
ComplexNumber operator-(const ComplexNumber& rhs);
ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);

#endif
