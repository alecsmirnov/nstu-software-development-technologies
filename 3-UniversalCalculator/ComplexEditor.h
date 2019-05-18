#ifndef COMPLEXEDITOR_H
#define COMPLEXEDITOR_H

#include "Editor.h"

class ComplexEditor : public Editor {
public:
	ComplexEditor();

	// Получить заданное число
	std::string getNumber() const;
	// Задать число для редактирования
	void setNumber(std::string number);

	// Добавить символ (от 1 до 9)
	void addChr(std::uint8_t numeral);
	// Добавить 0
	void addZero();
	// Добавить /
	void addSeparator();
	// Добавить минус
	void addMinus();

	// Удалить последний символ
	void popChr();

	// Проверка числа на пустоту
	bool isEmpty() const;

	// Удалить всё число
	void clear();

	~ComplexEditor() {}
};

#endif
