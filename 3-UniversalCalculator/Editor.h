#ifndef EDITOR_H
#define EDITOR_H

#include <string>

// Класс для формирования и работы с числом в виде строки
class Editor {
public:
	Editor() : separator(false), minus(false) {}

	// Получить заданное число
	virtual std::string getNumber() const = 0;
	// Задать число для редактирования
	virtual void setNumber(std::string number) = 0;

	// Добавить символ (от 1 до 15)
	virtual void addChr(std::uint8_t numeral) = 0;
	// Добавить 0
	virtual void addZero() = 0;
	// Добавить разделитель
	virtual void addSeparator() = 0;
	// Добавить минус
	virtual void addMinus() = 0;

	// Удалить последний символ
	virtual void popChr() = 0;

	// Проверка числа на пустоту
	virtual bool isEmpty() const = 0;

	// Удалить всё число
	virtual void clear() = 0;

	virtual ~Editor() {}

protected:
	std::string number;

	bool separator;
	bool minus;
};

#endif
