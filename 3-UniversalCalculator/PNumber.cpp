#include "PNumber.h"

#include "PToDecConverter.h"
#include "DecToPConverter.h"

constexpr std::uint8_t DEC_BASE = 10;	// Основание 10-ичного числа

PNumber::PNumber(std::string number, std::uint8_t P, std::uint8_t accuracy) {
	this->number = number;
	this->P = P;
	this->accuracy = accuracy;

	dec_value = P != DEC_BASE ? PToDecConverter::convert(number, P, accuracy) :
								std::stod(number);
}

PNumber::PNumber(double dec_val, std::uint8_t P, std::uint8_t accuracy) {
	this->dec_value = dec_val;
	this->P = P;
	this->accuracy = accuracy;

	number = P != DEC_BASE ? DecToPConverter::convert(dec_val, P, accuracy) :
							 std::to_string(dec_val);
}

PNumber::PNumber(const PNumber& rval) {
	number = rval.number;
	P = rval.P;
	accuracy = rval.accuracy;

	dec_value = rval.dec_value;
}

// Получить P-ичное числов в виде строки
std::string PNumber::getNumber() const {
	return number;
}

// Получить основание P-ичного числа
std::uint8_t PNumber::getP() const {
	return P;
}

// Получить точность вещественной части числа
std::uint8_t PNumber::getAccuracy() const {
	return accuracy;
}

// Получить 10-ичное представление числа
double PNumber::getDecValue() const {
	return dec_value;
}

// Получить квадрат P-ичного числа
PNumber PNumber::getSquare() const {
	return PNumber(dec_value * dec_value, P, accuracy);
}

// Получить обратное P-ичное число
PNumber PNumber::getReverse() const {
	return PNumber(1 / dec_value, P, accuracy);
}

PNumber operator+(const PNumber& rhs) {
	return PNumber(rhs);
}

PNumber operator-(const PNumber& rhs) {
	return PNumber(-rhs.getDecValue(), rhs.getP(), rhs.getAccuracy());
}

PNumber operator+(const PNumber& lhs, const PNumber& rhs) {
	return PNumber(lhs.getDecValue() + rhs.getDecValue(), lhs.getP(), lhs.getAccuracy());
}

PNumber operator*(const PNumber& lhs, const PNumber& rhs) {
	return PNumber(lhs.getDecValue() * rhs.getDecValue(), lhs.getP(), lhs.getAccuracy());
}

PNumber operator-(const PNumber& lhs, const PNumber& rhs) {
	return PNumber(lhs.getDecValue() - rhs.getDecValue(), lhs.getP(), lhs.getAccuracy());
}

PNumber operator/(const PNumber& lhs, const PNumber& rhs) {
	return PNumber(lhs.getDecValue() / rhs.getDecValue(), lhs.getP(), lhs.getAccuracy());
}
