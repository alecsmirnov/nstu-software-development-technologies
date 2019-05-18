#ifndef FRACTIONNUMBER_H
#define FRACTIONNUMBER_H

#include <string>

// Класс, реализующий простую дробь
class FractionNumber {
public:
	FractionNumber() = default;
	FractionNumber(std::string number, std::uint8_t P = 10);
	FractionNumber(int numerator, int denominator);
	FractionNumber(const FractionNumber& rval);

	// Получить комплексное число в виде строки
	std::string getNumber() const;
	// Получить числитель числа
	std::string getNumeratorNumber() const;
	// Получить знаменатель числа
	std::string getDenominatorNumber() const;

	// Получить числитель числа
	int getNumerator() const;
	// Получить знаменатель числа
	int getDenominator() const;
	std::uint8_t getP() const;

	// Получить квадрат комплексного числа
	virtual FractionNumber getSquare() const;
	// Получить обратное комплексное число
	virtual FractionNumber getReverse() const;

private:
	// Выделить числитель из числа
	int findNumerator(std::string number) const;
	// Выделить знаменатель из числа
	int findDenominator(std::string number) const;

	std::string fromNumDenToNumber(int numerator, int denominator) const;

	// Найти НОД
	static int GCD(int a, int b);

private:
	std::string number;
	std::uint8_t P;

	int numerator;
	int denominator;
};

FractionNumber operator+(const FractionNumber& rhs);
FractionNumber operator-(const FractionNumber& rhs);
FractionNumber operator+(const FractionNumber& lhs, const FractionNumber& rhs);
FractionNumber operator*(const FractionNumber& lhs, const FractionNumber& rhs);
FractionNumber operator-(const FractionNumber& lhs, const FractionNumber& rhs);
FractionNumber operator/(const FractionNumber& lhs, const FractionNumber& rhs);

#endif
