#ifndef MEMORY_H
#define MEMORY_H

enum class MemoryState {ON, OFF};

// Класс, реализующий память калькулятора
template <typename TNumber>
class Memory {
public:
	Memory() : state(MemoryState::OFF) {}

	// Добавить число в память калькулятора
	void addNumber(TNumber new_number);
	// Взять число из памяти калькулятора
	TNumber getNumber() const;
	// Очистить память калькулятора
	void clear();

private:
	MemoryState state;
	TNumber number;
};

#include "Memory.hpp"

#endif
