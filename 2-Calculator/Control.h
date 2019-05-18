#ifndef CONTROL_H
#define CONTROL_H

#include <string>

#include "PNumber.h"
#include "Editor.h"
#include "Proc.h"
#include "Memory.h"

// Класс для управления работой калькулятора
class Control {
public:
	Control() : base(10) {}

	// Задать основание редактируемых чисел
	void setNumberBase(std::uint8_t base);

	// Выбор команды для управления калькулятором
	void selectCommand(std::uint8_t command_num);

	// Получить строковое представление редактируемого числа
	std::string getNumber() const;

private:
	// Выбор команды редактора
	void selectEditorCommand(std::uint8_t command_num);
	// Выбор команды опаретора
	void selectOperatorCommand(std::uint8_t command_num);
	// Выбор команды функций
	void selectFunctionCommand(std::uint8_t command_num);
	// Выбор команды памяти
	void selectMemoryCommand(std::uint8_t command_num);

	// Проверка числа на вещественное
	static bool isRealNum(const std::string& number);
	// Удаление незначимых нулей числа
	static std::string removeTrailingZeros(const std::string& number);

private:
	std::string number;
	std::uint8_t base;

	Editor number_edit;
	Proc<PNumber> processor;
	Memory<PNumber> memory;
};

#endif
