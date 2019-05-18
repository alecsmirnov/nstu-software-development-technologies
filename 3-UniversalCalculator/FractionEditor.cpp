#include "FractionEditor.h"
#include "BaseConverter.h"

FractionEditor::FractionEditor() {
	separator = false;
	minus = false;
}

// Получить заданное число
std::string FractionEditor::getNumber() const {
	return number;
}

// Задать число для редактирования
void FractionEditor::setNumber(std::string number) {
	clear();

	if (number.find('/') != std::string::npos)
		separator = true;

	if (number[0] == '-')
		minus = true;

	this->number = number;
}

// Добавить символ (от 1 до 9)
void FractionEditor::addChr(std::uint8_t numeral) {
	number.push_back(BaseConverter::numeralToChr(numeral));
}

// Добавить 0
void FractionEditor::addZero() {
	number.push_back('0');

	// Если 0 первый символ числа
	if (number.length() == 1) {
		number.push_back('.');
		separator = true;
	}
}

// Добавить разделитель /
void FractionEditor::addSeparator() {
	if (!isEmpty() && !separator) {
		number.push_back('/');
		separator = true;
	}
}

// Добавить минус
void FractionEditor::addMinus() {
	if (isEmpty() && !minus) {
		number.push_back('-');
		minus = true;
	}
}

// Удалить последний символ
void FractionEditor::popChr() {
	if (!isEmpty()) {
		if (number[number.length() - 1] == '/') {
			separator = false;

			if (number[0] == '0' || number[0] == '-' && number[1] == '0')
				number.pop_back();
		}

		if (number[number.length() - 1] == '-')
			minus = false;

		number.pop_back();
	}
}

// Проверка числа на пустоту
bool FractionEditor::isEmpty() const {
	return number.empty();
}

// Удалить всё число
void FractionEditor::clear() {
	number.clear();

	separator = false;
	minus = false;
}
