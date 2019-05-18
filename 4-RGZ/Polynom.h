#ifndef POLYNOM_H
#define POLYNOM_H

#include <vector>
#include <cstdint>

#include "Member.h"

// Полином с вещественными коэффициентами
class Polynom {
public:
	using elem_t = Member;					// Тип элемента
	using data_t = std::vector<elem_t>;		// Тип структуры хранения

public:
	Polynom() = default;
	Polynom(double coefficient, std::uint8_t degree = 0);
	Polynom(const Polynom& polynom);
	Polynom(const data_t& polynom);
	Polynom(std::string polynom);

	// Задать новое значение полинома в виде строки
	void setStrPolynom(std::string polynom);

	// Получить полином в виде строки
	std::string getStrPolynom() const;
	// Получить полинмо в виде структуры хранения
	data_t getPolynom() const;
	
	// Получить коэффициент при степени
	double getCoefficient(std::uint8_t degree) const;
	// Получить степень полинома
	std::uint8_t getDegree() const;

	// Дифференцировать
	Polynom differentiate() const;
	// Посчитать значение
	double calculate(double x) const;

	// Очистить полином
	void clear();

	~Polynom();

private:
	// Упорядочить полином 
	void arrange();
	// Привести подобные в упорядоченном полиноме
	void simmilar();

	using Operation = elem_t (*)(const elem_t& a, const elem_t& b);
	// Операции сложения и вычитания для полинома
	Polynom polynomOperation(const Polynom& lhs, const Polynom& rhs, Operation operation) const;

public:
	Polynom operator+(const Polynom& rhs) const;
	Polynom operator-(const Polynom& rhs) const;
	Polynom operator*(const Polynom& rhs) const;
	bool operator==(const Polynom& rhs) const;

public:
	// Формирование STL итераторов
	using iterator = data_t::iterator;
	using const_iterator = data_t::const_iterator;

	// Формирование начального итератора
	iterator begin() noexcept;
	// Формирование начального константного итератора
	const_iterator cbegin() const noexcept;
	// Формирование конечного итератора
	iterator end() noexcept;
	// Формирование конечного константного итератора
	const_iterator cend() const noexcept;

	data_t::size_type size() const;
	// Перегрузка операции взятия из скобок
	elem_t& operator[](data_t::size_type i);
	// Перегрузка операции присвоения скобкам
	elem_t operator[](data_t::size_type i) const;

private:
	data_t polynom;
};

#endif