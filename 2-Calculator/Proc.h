#ifndef PROC_H
#define PROC_H

enum class ProcOperation {NONE, ADD, SUB, MULT, DIV};
enum class ProcFunction {SQR, REV};

// Класс, реализующий работу процессора по сложению пары чисел
template <typename TNumber>
class Proc {
public:
	Proc() : operation(ProcOperation::NONE) {}

	// Задать левый операнд/результат
	void setLopRes(TNumber lop_res);
	// Задать правый операнд
	void setRop(TNumber rop);

	// Получить левый операнд/результат
	TNumber getLopRes() const;
	// Получить правый операнд
	TNumber getRop() const;

	// Задать операцию для выполнения
	void setOperation(ProcOperation operation);
	// Получить заданну операцию
	ProcOperation getOperation() const;

	// Выполнить заданную операцию
	void execOperation();
	// Выполнить функцию
	void execFunction(ProcFunction function);

	// Очистить заданную операцию
	void resetOperation();

	// Очистить процессор
	void clear();

private:
	TNumber lop_res;
	TNumber rop;

	ProcOperation operation;
};

#include "Proc.hpp"

#endif
