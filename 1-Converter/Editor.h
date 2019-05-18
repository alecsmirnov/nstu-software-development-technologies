#ifndef EDITOR_H
#define EDITOR_H

#include <string>

// Класс для формирования и работы с числом в виде строки
class Editor {
public:
	Editor() : dot(false) {}

	// Получить заданное число
	std::string getNumber() const;

	// Добавить символ (от 1 до 15)
	void addChr(std::uint8_t numeral);
	// Добавить 0
	void addZero();
	// Добавить .
	void addDot();

	// Удалить последний символ
	void popChr();

	// Удалить всё число
	void clear();

private:
	std::string number;

	bool dot;
};

#endif
