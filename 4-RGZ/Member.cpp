#include "Member.h"

#include <cctype>

constexpr std::uint8_t DEC_BASE = 10;	// Основание десятичного числа

Member::Member(double coefficient, std::uint8_t degree) {
	this->coefficient = coefficient;
	this->degree = degree;
}

Member::Member(std::string member) {
	coefficient = 0;
	degree = 0;

	setStrMember(member);
}

// Задать новое значение одночлена в виде строки
void Member::setStrMember(std::string member) {
	// Получение коэффициента
	auto it = member.begin();
	for (; it != member.end() && *it != 'x'; ++it)
		if (std::isdigit(*it))
			coefficient = coefficient * DEC_BASE + *it - '0';

	// Проверка отрицательного коэффициента
	if(member[0] == '-') 
		coefficient = -coefficient;

	// Получение степени
	for (; it != member.end(); ++it)
		if (std::isdigit(*it))
			degree = degree * DEC_BASE + *it - '0';
}

// Установить коэффициент
void Member::setCoefficient(double coefficient) {
	this->coefficient = coefficient;
}

// Установить степень
void Member::setDegree(std::uint8_t degree) {
	this->degree = degree;
}

// Получить одночлен в виде строки
std::string Member::getStrMember() const {
	return removeTrailingZeros(std::to_string(coefficient)) + "x^" + 
							   std::to_string(degree);
}

// Получить коэффициент
double Member::getCoefficient() const {
	return coefficient;
}

// Получить степень
std::uint8_t Member::getDegree() const {
	return degree;
}

// Дифференцировать
Member Member::differentiate() const {
	return degree ? Member(coefficient * degree, degree - 1) : 
					Member(1, 0);
}

// Посчитать значение
double Member::calculate(double x) const {
	return coefficient * std::pow(x, degree);
}

// Операции сложения и вычитания для одночлена
Member Member::memberOperation(const Member& a, const Member& b, Operation operation) const {
	Member new_member;

	// Если степени равны -- выполнить операцию
	if (a.getDegree() == b.getDegree()) {
		new_member.setCoefficient(operation(a.getCoefficient(), b.getCoefficient()));
		new_member.setDegree(a.getDegree());
	}

	return new_member;
}

// Проверка одночлена на вещественное число
bool Member::isRealNum(const std::string& number) {
	return number.find('.') != std::string::npos;
}

// Удаление незначащих нулей из строкового представления
std::string Member::removeTrailingZeros(const std::string& number) {
	std::string result(number);

	if (isRealNum(result)) {
		result.erase(result.find_last_not_of('0') + 1, std::string::npos);
		// Если вся вещественная часть состоит из нулей, удаляем точку
		if (result[result.length() - 1] == '.')
			result.pop_back();
	}

	return result;
}

Member Member::operator-() const {
	return Member (-coefficient, degree);
}

Member Member::operator+(const Member& rhs) const {
	return memberOperation(*this, rhs, [](double a_coef, double b_coef) -> double {
		return a_coef + b_coef;
	});
}

Member Member::operator-(const Member& rhs) const {
	return memberOperation(*this, rhs, [](double a_coef, double b_coef) -> double {
		return a_coef - b_coef;
	});
}

Member Member::operator*(const Member& rhs) const {
	return Member(coefficient * rhs.getCoefficient(), 
				  degree + rhs.getDegree());
}

bool Member::operator==(const Member& rhs) const {
	return coefficient == rhs.getCoefficient() &&
		   degree == rhs.getDegree();
}