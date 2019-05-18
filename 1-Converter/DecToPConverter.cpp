#include "DecToPConverter.h"

#include <cmath>

// Перевод 10-ичного числа в число с указанным основанием и указанной точностью вещественной части
std::string DecToPConverter::convert(const std::string& number, std::uint8_t P, std::uint8_t accuracy) {
	auto new_number(number);

	auto dec_number = std::stod(new_number);					// Получение вещественного числа типа double
	new_number.clear();

	auto int_part = static_cast<std::uint64_t>(dec_number);		// Целая часть числа
	auto fract_part = dec_number - int_part;					// Дробная часть

	for (; int_part; int_part /= P)								// Перевод целой части в P-ичную СС
		new_number = getPDigit(int_part % P) + new_number;

	if (fract_part) {											// Перевод дробной части в P-ичную СС
		if (number[0] == '0')
			new_number.push_back('0');

		new_number.push_back('.');

		for (std::uint8_t i = 0; fract_part && i != accuracy; ++i) {
			fract_part = std::modf(fract_part *= P, &dec_number);
			new_number.push_back(getPDigit(static_cast<uint8_t>(dec_number)));
		}
	}

	return new_number;
}
