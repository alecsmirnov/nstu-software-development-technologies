#include "ComplexEditor.h"
#include "BaseConverter.h"

ComplexEditor::ComplexEditor() {
	separator = false;
	minus = false;
}

// Получить заданное число
std::string ComplexEditor::getNumber() const {
	return number;
}

// Задать число для редактирования
void ComplexEditor::setNumber(std::string number) {
	clear();

	if (!number.empty())
		for (std::string::size_type i = 0; i != number.length() - 1; ++i)
			if (number[i] == '+' && number[i + 1] == 'i')
				separator = true;

	//if (number.find('/') != std::string::npos)
	//	separator = true;

	if (number[0] == '-')
		minus = true;

	this->number = number;
}

// Добавить символ (от 1 до 9)
void ComplexEditor::addChr(std::uint8_t numeral) {
	number.push_back(BaseConverter::numeralToChr(numeral));
}

// Добавить 0
void ComplexEditor::addZero() {
	number.push_back('0');

	// Если 0 первый символ числа
	if (number.length() == 1) {
		number.push_back('+');
		number.push_back('i');
		separator = true;
	}
}

// Добавить разделитель +i
void ComplexEditor::addSeparator() {
	if (!separator) {
		number.push_back('+');
		number.push_back('i');
		separator = true;
	}
}

// Добавить минус
void ComplexEditor::addMinus() {
	if (isEmpty() && !minus) {
		number.push_back('-');
		minus = true;
	}
}

// Удалить последний символ
void ComplexEditor::popChr() {
	if (!isEmpty()) {
		if (number[number.length() - 1] == 'i') {
			number.pop_back();

			separator = false;

			/*if (number[0] == '0' || number[0] == '-' && number[1] == '0')
				number.pop_back();*/
		}

		if (number[number.length() - 1] == '-')
			minus = false;

		number.pop_back();
	}
}

// Проверка числа на пустоту
bool ComplexEditor::isEmpty() const {
	return number.empty();
}

// Удалить всё число
void ComplexEditor::clear() {
	number.clear();

	separator = false;
	minus = false;
}
