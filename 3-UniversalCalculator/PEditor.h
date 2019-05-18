#ifndef PEDITOR_H
#define PEDITOR_H

#include "Editor.h"

// Класс для формирования и работы с числом в виде строки
class PEditor : public Editor {
public:
	PEditor();

	// Получить заданное число
	std::string getNumber() const;
	// Задать число для редактирования
	void setNumber(std::string number);

	// Добавить символ (от 1 до 15)
	void addChr(std::uint8_t numeral);
	// Добавить 0
	void addZero();
	// Добавить .
	void addSeparator();
	// Добавить минус
	void addMinus();

	// Удалить последний символ
	void popChr();

	// Проверка числа на пустоту
	bool isEmpty() const;

	// Удалить всё число
	void clear();

	~PEditor() {}
};

#endif
