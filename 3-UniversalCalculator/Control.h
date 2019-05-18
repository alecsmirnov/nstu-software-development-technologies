#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <type_traits>

#include "PNumber.h"
#include "FractionNumber.h"
#include "ComplexNumber.h"

#include "Editor.h"
#include "PEditor.h"
#include "FractionEditor.h"
#include "ComplexEditor.h"

#include "Proc.h"
#include "Memory.h"

// Класс для управления работой калькулятора
template <typename T>
class Control {
public:
    Control();

    // Задать основание редактируемых чисел
	void setNumberBase(std::uint8_t base);

    // Выбор команды для управления калькулятором
	void selectCommand(std::uint8_t command_num);

    // Получить строковое представление редактируемого числа
    std::string getNumber() const;

    ~Control();

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

    Editor* number_edit;
    Proc<T> processor;
    Memory<T> memory;
};

#include "Control.hpp"

#endif
