#ifndef EDITOR_H
#define EDITOR_H

#include <string>

// Класс для формирования и работы с числом в виде строки
class Editor {
public:
	Editor() : dot(false), minus(false) {}

	// Получить заданное число
	std::string getNumber() const;
	// Задать число для редактирования
	void setNumber(std::string number);

	// Добавить символ (от 1 до 15)
	void addChr(std::uint8_t numeral);
	// Добавить 0
	void addZero();
	// Добавить .
	void addDot();
	// Добавить минус
	void addMinus();

	// Удалить последний символ
	void popChr();

	// Проверка числа на пустоту
	bool isEmpty() const;

	// Удалить всё число
	void clear();

private:
	std::string number;

	bool dot;
	bool minus;
};

#endif
