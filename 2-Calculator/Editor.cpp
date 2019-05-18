#include "Editor.h"
#include "BaseConverter.h"

// Получить заданное число
std::string Editor::getNumber() const {
	return number;
}

// Задать число для редактирования
void Editor::setNumber(std::string number) {
	clear();

	if (number.find('.') != std::string::npos)
		dot = true;

	if (number[0] == '-')
		minus = true;

	this->number = number;
}

// Добавить символ (от 1 до 15)
void Editor::addChr(std::uint8_t numeral) {
	number.push_back(BaseConverter::getPDigit(numeral));
}

// Добавить 0
void Editor::addZero() {
	number.push_back('0');

	// Если 0 первый символ числа
	if (number.length() == 1) {
		number.push_back('.');
		dot = true;
	}
}

// Добавить .
void Editor::addDot() {
	if (!isEmpty() && !dot) {
		number.push_back('.');
		dot = true;
	}
}

// Добавить минус
void Editor::addMinus() {
	if (isEmpty() && !minus) {
		number.push_back('-');
		minus = true;
	}
}

// Удалить последний символ
void Editor::popChr() {
	if (!isEmpty()) {
		if (number[number.length() - 1] == '.') {
			dot = false;

			if (number[0] == '0' || number[0] == '-' && number[1] == '0')
				number.pop_back();
		}

		if (number[number.length() - 1] == '-')
			minus = false;

		number.pop_back();
	}
}

// Проверка числа на пустоту
bool Editor::isEmpty() const {
	return number.empty();
}

// Удалить всё число
void Editor::clear() {
	number.clear();

	dot = false;
	minus = false;
}
