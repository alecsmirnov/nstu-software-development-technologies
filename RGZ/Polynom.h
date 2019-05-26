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
	Polynom(double coeff = 0, std::uint8_t degree = 0);
	Polynom(const Polynom& polynom);
	Polynom(const data_t& data);
	Polynom(std::string str_poly);

	// Задать новое значение полинома в виде строки
	void setStrPolynom(std::string str_poly);

	// Получить полином в виде строки
	std::string getStrPolynom() const;
	// Получить полинмо в виде структуры хранения
	data_t getData() const;
	
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
	// Привести подобные и упорядочить полином
	static data_t adjust(data_t data);

	// Операции сложения и вычитания для полинома
	static Polynom polynomSum(const Polynom& lhs, const Polynom& rhs);

public:
	Polynom operator-() const;
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
	data_t data;
};

#endif