#ifndef PNUMBER_H
#define PNUMBER_H

#include <string>

// Класс, реализующий P-ичное число
class PNumber {
public:
	PNumber() : P(10), accuracy(15), dec_value(0) {}
	PNumber(std::string number, std::uint8_t P, std::uint8_t accuracy = 15);
	PNumber(double dec_val, std::uint8_t P, std::uint8_t accuracy = 15);
	PNumber(const PNumber& rval);

	// Получить P-ичное числов в виде строки
	std::string getNumber() const;
	// Получить основание P-ичного числа
	std::uint8_t getP() const;
	// Получить точность вещественной части числа
	std::uint8_t getAccuracy() const;
	// Получить 10-ичное представление числа
	double getDecValue() const;

	// Получить квадрат P-ичного числа
	PNumber getSquare() const;
	// Получить обратное P-ичное число
	PNumber getReverse() const;

private:
	std::string number;
	std::uint8_t P;
	std::uint8_t accuracy;

	double dec_value;
};

PNumber operator+(const PNumber& rhs);
PNumber operator-(const PNumber& rhs);
PNumber operator+(const PNumber& lhs, const PNumber& rhs);
PNumber operator*(const PNumber& lhs, const PNumber& rhs);
PNumber operator-(const PNumber& lhs, const PNumber& rhs);
PNumber operator/(const PNumber& lhs, const PNumber& rhs);

#endif
