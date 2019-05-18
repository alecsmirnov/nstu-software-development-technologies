#ifndef CONTROL_H
#define CONTROL_H

#include "Editor.h"
#include "History.h"

class Control {
public:
	// Выбор команды (от 0 до 18) для ввода числа
	void selectCommand(std::uint8_t command_num);

	// Преобразовать число из указанной системы в новую систему счисления
	std::string convertFromTo(std::uint8_t base, std::uint8_t new_base);

	// Получить заданное число
	std::string getNumber() const;
	// Получить историю преобразования чисел
	const std::list<Record>& getHistory() const;

	// Очистить историю преобразования чисел
	void clearHistory();

private:
	// Проверка числа на вещественное
	static bool isRealNum(const std::string& number);
	// Удаление незначимых нулей числа
	static std::string removeTrailingZeros(const std::string& number);

private:
	Editor number_edit;
	History conversion_history;
};

#endif
