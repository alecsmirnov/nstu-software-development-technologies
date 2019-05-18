#include "BaseConverter.h"

constexpr std::uint8_t DEC_RADIX = 9;					// Основание 10-ичной СС
constexpr std::uint8_t HEX_ASCIICODE_BEGINING = 64;		// Граница ASCII кода HEX СС

// Получить из цифры (от 0 до 15) символ P-ичной системы
char BaseConverter::getPDigit(std::uint8_t numeral) {
	return DEC_RADIX < numeral ? numeralToHex(numeral) : numeralToChr(numeral);
}

// Получить из символа P-ичной системы (от 0 до 9, от A до F) цифру
std::uint8_t BaseConverter::getDecDigit(char chr) {
	return chr < HEX_ASCIICODE_BEGINING ? chrToNumeral(chr) : hexToNumeral(chr);
}

// Перевод цифры в символ 10-ичной системы
char BaseConverter::numeralToChr(std::uint8_t numeral) {
	return numeral + '0';
}

// Перевод цифры в символ 16-ичной системы
char BaseConverter::numeralToHex(std::uint8_t numeral) {
	return numeral - DEC_RADIX + HEX_ASCIICODE_BEGINING;
}

// Перевод символа 10-ичной системы в цифру
std::uint8_t BaseConverter::chrToNumeral(char chr) {
	return chr - '0';
}

// Перевод символа 16-ичной системы в цифру
std::uint8_t BaseConverter::hexToNumeral(char chr) {
	return chr + DEC_RADIX - HEX_ASCIICODE_BEGINING;
}
