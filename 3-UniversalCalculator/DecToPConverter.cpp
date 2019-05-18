#include "DecToPConverter.h"

#include <sstream>
#include <cmath>

// Перевод 10-ичного числа в число с указанным основанием и указанной точностью веще-ственной части
std::string DecToPConverter::convert(double number, std::uint8_t P, std::uint8_t accuracy) {
	auto new_number(strValAbs(doubleToString(number, accuracy)));

	// Получение вещественного числа типа double
	auto dec_number = std::stod(new_number);
	new_number.clear();

	// Целая часть числа
	auto int_part = static_cast<std::uint64_t>(dec_number);
	// Дробная часть
	auto fract_part = dec_number - int_part;

	for (; int_part; int_part /= P)		// Перевод целой части в P-ичную СС
		new_number = getPDigit(int_part % P) + new_number;

	if (fract_part) {					// Перевод дробной части в P-ичную СС
		if (std::abs(number) < 1)
			new_number.push_back('0');

		new_number.push_back('.');

		for (std::uint8_t i = 0; fract_part && i != accuracy; ++i) {
			fract_part = std::modf(fract_part *= P, &dec_number);
			new_number.push_back(getPDigit(static_cast<std::uint8_t>(dec_number)));
		}
	}

	if (number < 0)
		new_number = '-' + new_number;

	return new_number;
}

// Получить модуль числа, представленного в виде строки
std::string DecToPConverter::strValAbs(const std::string& number) {
	return number[0] == '-' ? number.substr(1, number.length()) : number;
}

// Перевод числа типа double в строку с указанной точностью дробной части
std::string DecToPConverter::doubleToString(double number, std::uint8_t precision) {
	std::ostringstream out;
	out.precision(precision);
	out << std::fixed << number;

	return out.str();
}
