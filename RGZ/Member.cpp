#include "Member.h"

#include <cmath>
#include <regex>

constexpr std::uint8_t DEC_BASE = 10;			// Основание десятичного числа

constexpr std::uint8_t COEFF_MATCH_NUM  = 1;	// Часть коэффициента в регулярном выражении
constexpr std::uint8_t DEGREE_MATCH_NUM = 3;	// Часть степени в регулярном выражении

Member::Member(double coeff, std::uint8_t degree) {
	this->coeff = coeff;
	this->degree = degree;
}

Member::Member(std::string str_mem) {
	setStrMember(str_mem);
}

// Установить коэффициент
void Member::setCoefficient(double coeff) {
	this->coeff = coeff;
}

// Установить степень
void Member::setDegree(std::uint8_t degree) {
	this->degree = degree;
}

// Задать новое значение одночлена в виде строки
void Member::setStrMember(std::string str_mem) {
	coeff = 0;
	degree = 0;

	if (!str_mem.empty()) {
		const std::regex regular("([+-]?\\d+\\.?\\d*)(x\\^)(\\d+)");

		if (std::smatch match; std::regex_search(str_mem, match, regular)) {
			coeff = std::stod(match[COEFF_MATCH_NUM].str());
			degree = std::stoi(match[DEGREE_MATCH_NUM].str());
		}
	}
}

// Получить коэффициент
double Member::getCoefficient() const {
	return coeff;
}

// Получить степень
std::uint8_t Member::getDegree() const {
	return degree;
}

// Получить одночлен в виде строки
std::string Member::getStrMember() const {
	return removeTrailingZeros(std::to_string(coeff)) + "x^" + std::to_string(degree);
}

// Дифференцировать
Member Member::differentiate() const {
	return degree ? Member(coeff * degree, degree - 1) : Member(1, 0);
}

// Посчитать значение
double Member::calculate(double x) const {
	return coeff * std::pow(x, degree);
}

// Проверка одночлена на вещественное число
bool Member::isRealNum(const std::string& str_num) {
	return str_num.find('.') != std::string::npos;
}

// Удаление незначащих нулей из строкового представления
std::string Member::removeTrailingZeros(const std::string& str_num) {
	std::string result(str_num);

	if (isRealNum(result)) {
		result.erase(result.find_last_not_of('0') + 1, std::string::npos);
		// Если вся вещественная часть состоит из нулей, удаляем точку
		if (result[result.length() - 1] == '.')
			result.pop_back();
	}

	return result;
}

Member Member::operator-() const {
	return Member(-coeff, degree);
}

Member Member::operator+(const Member& rhs) const {
	return Member(coeff + rhs.coeff, degree);
}

Member Member::operator-(const Member& rhs) const {
	return Member(coeff - rhs.coeff, degree);
}

Member Member::operator*(const Member& rhs) const {
	return Member(coeff * rhs.coeff, degree + rhs.degree);
}

bool Member::operator==(const Member& rhs) const {
	return coeff == rhs.coeff && degree == rhs.degree;
}