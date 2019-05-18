#ifndef PTODECCONVERTER_H
#define PTODECCONVERTER_H

#include "BaseConverter.h"

// Перевод из P-ичной системы в 10-ичную
class PToDecConverter : public BaseConverter {
public:
	PToDecConverter() = delete;

public:
	// Перевод P-ичного числа в 10-ичное число в указанной точностью вещественной части
	static std::string convert(const std::string& number, std::uint8_t P, std::uint8_t accuracy = 15);

private:
	// Перевод числа типа double в строку с указанной точностью дробной части
	static std::string doubleToStringWithPrecision(double number, std::uint8_t precision);
};

#endif
