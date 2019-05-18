#include "Editor.h"
#include "BaseConverter.h"

// Получить заданное число
std::string Editor::getNumber() const {
	return number;
}

// Добавить символ (от 1 до 15)
void Editor::addChr(std::uint8_t numeral) {
	number.push_back(BaseConverter::getPDigit(numeral));
}

// Добавить 0
void Editor::addZero() {
	number.push_back('0');

	// Если 0 первый символ числа
	if (number.length() == 1)
		number.push_back('.');
}

// Добавить .
void Editor::addDot() {
	// Если . не первый символ числа и она отсутствует
	if (!number.empty() && !dot) {
		number.push_back('.');
		dot = true;
	}
}

// Удалить последний символ
void Editor::popChr() {
	if (!number.empty()) {
		if (number[number.length() - 1] == '.')
			dot = false;

		number.pop_back();
	}
}

// Удалить всё число
void Editor::clear() {
	number.clear();

	dot = false;
}
