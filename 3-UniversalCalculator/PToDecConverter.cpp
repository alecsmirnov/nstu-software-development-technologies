#include "PToDecConverter.h"

#include <cmath>

// Перевод P-ичного числа в 10-ичное число в указанной точностью вещественной части
double PToDecConverter::convert(const std::string& number, std::uint8_t P, std::uint8_t accuracy) {
	auto new_number(strValAbs(number));

	// Проверка числа на вещественное
	auto dot = new_number.find('.');
	auto len = dot != std::string::npos ? dot : new_number.length();

	long double res = 0;
	for (std::uint8_t i = 0; len != 0; ++i, --len)				// Перевод целой части в 10-ую СС
		res += getDecDigit(new_number[i]) * std::pow(P, len - 1);

	if (dot != std::string::npos)								// Перевод дробной части в 10-ую СС
		for (std::uint8_t i = 1; i != new_number.length() - dot && i != accuracy + 1; ++i)
			res += getDecDigit(new_number[dot + i]) * (1 / std::pow(P, i));

	if (number[0] == '-')
		res = -res;

	return res;
}

// Получить модуль числа, представленного в виде строки
std::string PToDecConverter::strValAbs(const std::string& number) {
	return number[0] == '-' ? number.substr(1, number.length()) : number;
}

