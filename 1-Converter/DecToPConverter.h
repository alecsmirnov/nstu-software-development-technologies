#ifndef DECTOPCONVERTER_H
#define DECTOPCONVERTER_H

#include "BaseConverter.h"

// Перевод из 10-ичной системы в P-ичную
class DecToPConverter : public BaseConverter {
public:
	DecToPConverter() = delete;

public:
	// Перевод 10-ичного числа в число с указанным основанием и указанной точностью вещественной части
	static std::string convert(const std::string& number, std::uint8_t P, std::uint8_t accuracy = 15);
};

#endif
