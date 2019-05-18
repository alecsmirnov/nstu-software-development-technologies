#include "PToDecConverter.h"

#include <sstream>
#include <cmath>

// Перевод P-ичного числа в 10-ичное число в указанной точностью вещественной части
std::string PToDecConverter::convert(const std::string& number, std::uint8_t P, std::uint8_t accuracy) {
	auto new_number(number);

	auto dot = new_number.find('.');							// Проверка числа на вещественное
	auto len = dot != std::string::npos ? dot : new_number.length();
	
	long double res = 0;										// Перевод целой части в 10-ую СС
	for (std::uint8_t i = 0; len != 0; ++i, --len)
		res += getDecDigit(new_number[i]) * std::pow(P, len - 1);

	if (dot != std::string::npos)								// Перевод дробной части в 10-ую СС
		for (std::uint8_t i = 1; i != new_number.length() - dot && i != accuracy + 1; ++i)
			res += getDecDigit(new_number[dot + i]) * (1 / std::pow(P, i));

	return doubleToStringWithPrecision(res, accuracy);
}

// Перевод числа типа double в строку с указанной точностью дробной части
std::string PToDecConverter::doubleToStringWithPrecision(double number, std::uint8_t precision) {
	std::ostringstream out;
	out.precision(precision);
	out << std::fixed << number;

	return out.str();
}
