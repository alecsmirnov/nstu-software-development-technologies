#ifndef FRACTIONEDITOR_H
#define FRACTIONEDITOR_H

#include "Editor.h"

// Класс для формирования и работы с простой дробью в виде строки
class FractionEditor : public Editor {
public:
	FractionEditor();

	// Получить заданное число
	std::string getNumber() const;
	// Задать число для редактирования
	void setNumber(std::string number);

	// Добавить символ (от 1 до 9)
	void addChr(std::uint8_t numeral);
	// Добавить 0
	void addZero();
	// Добавить разделитель
	void addSeparator();
	// Добавить минус
	void addMinus();

	// Удалить последний символ
	void popChr();

	// Проверка числа на пустоту
	bool isEmpty() const;

	// Удалить всё число
	void clear();

	~FractionEditor() {}
};

#endif
