#ifndef BASECONVERTER_H
#define BASECONVERTER_H

#include <string>

// Класс базовых операций для перевода чисел и символов
class BaseConverter {
public:
	BaseConverter() = delete;

public:
	// Получить из цифры (от 0 до 15) символ P-ичной системы
	static char getPDigit(std::uint8_t val);
	// Получить из символа P-ичной системы (от 0 до 9, от A до F) цифру
	static std::uint8_t getDecDigit(char chr);

	// Перевод цифры в символ 10-ичной системы
	static char numeralToChr(std::uint8_t numeral);
	// Перевод цифры в символ 16-ичной системы
	static char numeralToHex(std::uint8_t numeral);

	// Перевод символа 10-ичной системы в цифру
	static std::uint8_t chrToNumeral(char chr);
	// Перевод символа 16-ичной системы в цифру
	static std::uint8_t hexToNumeral(char chr);
};

#endif
