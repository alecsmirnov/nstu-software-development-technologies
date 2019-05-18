// Добавить число в память калькулятора
template <typename TNumber>
void Memory<TNumber>::addNumber(TNumber new_number) {
	if (state == MemoryState::OFF) {
		state = MemoryState::ON;
		this->number = new_number;
	}
	else
		number = number + new_number;
}

// Взять число из памяти калькулятора
template <typename TNumber>
TNumber Memory<TNumber>::getNumber() const {
	return number;
}

// Очистить память калькулятора
template <typename TNumber>
void Memory<TNumber>::clear() {
	state = MemoryState::OFF;
	number = TNumber();
}