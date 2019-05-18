// Задать левый операнд/результат
template <typename TNumber>
void Proc<TNumber>::setLopRes(TNumber lop_res) {
	this->lop_res = lop_res;
}

// Задать правый операнд
template <typename TNumber>
void Proc<TNumber>::setRop(TNumber rop) {
	this->rop = rop;
}

// Получить левый операнд/результат
template <typename TNumber>
TNumber Proc<TNumber>::getLopRes() const {
	return lop_res;
}

// Получить правый операнд
template <typename TNumber>
TNumber Proc<TNumber>::getRop() const {
	return rop;
}

// Задать операцию для выполнения
template <typename TNumber>
void Proc<TNumber>::setOperation(ProcOperation operation) {
	this->operation = operation;
}

// Получить заданну операцию
template <typename TNumber>
ProcOperation Proc<TNumber>::getOperation() const {
	return operation;
}

// Выполнить заданную операцию
template <typename TNumber>
void Proc<TNumber>::execOperation() {
	switch (operation) {
		case ProcOperation::ADD:  lop_res = lop_res + rop; break;
		case ProcOperation::SUB:  lop_res = lop_res - rop; break;
		case ProcOperation::MULT: lop_res = lop_res * rop; break;
		case ProcOperation::DIV:  lop_res = lop_res / rop; break;
		default:;
	}
}

// Выполнить функцию
template <typename TNumber>
void Proc<TNumber>::execFunction(ProcFunction function) {
	switch (function) {
		case ProcFunction::REV: rop = operation == ProcOperation::NONE ? lop_res = lop_res.getReverse() : rop.getReverse(); break;
		case ProcFunction::SQR: rop = operation == ProcOperation::NONE ? lop_res = lop_res.getSquare() : rop.getSquare(); break;
	}
}

// Очистить заданную операцию
template <typename TNumber>
void Proc<TNumber>::resetOperation() {
	operation = ProcOperation::NONE;
}

// Очистить процессор
template <typename TNumber>
void Proc<TNumber>::clear() {
	lop_res = TNumber();
	rop = TNumber();

	resetOperation();
}
