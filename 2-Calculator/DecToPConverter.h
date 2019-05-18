#ifndef DECTOPCONVERTER_H
#define DECTOPCONVERTER_H

#include "BaseConverter.h"

// Перевод из 10-ичной системы в P-ичную
class DecToPConverter : public BaseConverter {
public:
	DecToPConverter() = delete;

public:
	// Перевод 10-ичного числа в число с указанным основанием и указанной точностью вещественной части
	static std::string convert(double number, std::uint8_t P, std::uint8_t accuracy = 15);

private:
	// Получить модуль числа, представленного в виде строки
	static std::string strValAbs(const std::string& number);
	// Перевод вещественного числа в строку
	static std::string doubleToString(double number, std::uint8_t precision);
};

#endif
