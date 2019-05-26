#include "Polynom.h"

#include <algorithm>
#include <regex>
#include <map>

Polynom::Polynom(double coeff, std::uint8_t degree) {
	data.push_back({ coeff, degree });
}

Polynom::Polynom(const Polynom& poly) {
	data = poly.data;
}

Polynom::Polynom(const data_t& data) {
	this->data = adjust(data);
}

Polynom::Polynom(std::string str_poly) {
	setStrPolynom(str_poly);
}

// Задать новое значение полинома в виде строки
void Polynom::setStrPolynom(std::string str_poly) {
	clear();

	if (!str_poly.empty()) {
		const std::regex regular("([+-]?\\d+\\.?\\d*x\\^\\d+)");

		for (std::smatch match; std::regex_search(str_poly, match, regular); str_poly = match.suffix())
			data.push_back(match[0].str());

		data = adjust(data);
	}
}

// Получить коэффициент при степени
double Polynom::getCoefficient(std::uint8_t degree) const {
	double coeff = 0;

	// Поиск коэффициента при степени
	for (auto& member : data)
		if (member.getDegree() == degree)
			coeff = member.getCoefficient();

	return coeff;
}

// Получить степень полинома
std::uint8_t Polynom::getDegree() const {
	std::uint8_t max_degree = 0;

	// Поиск наибольшей степени
	for (auto& member : data)
		if (max_degree < member.getDegree())
			max_degree = member.getDegree();

	return max_degree;
}

// Получить полинмо в виде структуры хранения
Polynom::data_t Polynom::getData() const {
	return data;
}

// Получить полином в виде строки
std::string Polynom::getStrPolynom() const {
	std::string new_poly;

	if (!data.empty()) {
		data_t::size_type i = 0;
		for (; i != data.size() - 1; ++i) {
			// Получение одночлена в виде строки
			new_poly += data[i].getStrMember();

			// Формирование полинома из одночленов
			if (0 < data[i + 1].getCoefficient())
				new_poly += "+";
		}

		new_poly += data[i].getStrMember();
	}

	return new_poly;
}

// Дифференцировать
Polynom Polynom::differentiate() const {
	data_t new_poly;

	for (auto member : data)
		if (member.getDegree())
			new_poly.push_back(member.differentiate());
	
	return new_poly.empty() ? Polynom() : Polynom(new_poly);
}

// Посчитать значение
double Polynom::calculate(double x) const {
	double poly_res = 0;

	for (auto member : data)
		poly_res += member.calculate(x);

	return poly_res;
}

// Очистить полином
void Polynom::clear() {
	data_t().swap(data);
}

Polynom::~Polynom() {
	clear();
}

// Привести подобные и упорядочить полином
Polynom::data_t Polynom::adjust(const data_t& data) {
	data_t new_data;

	if (!data.empty()) {
		std::map<std::uint8_t, double, std::greater<std::uint8_t>> sorted_data;
		for (auto member : data)
			sorted_data[member.getDegree()] += member.getCoefficient();

		for (auto member : sorted_data)
			if (member.second)
				new_data.push_back({ member.second, member.first });

		if (new_data.empty())
			new_data.push_back(Member());
	}

	return new_data;
}

// Операции сложения и вычитания для полинома
Polynom Polynom::polynomSum(const Polynom& lhs, const Polynom& rhs) {
	data_t new_data;

	std::map<std::uint8_t, double, std::greater<std::uint8_t>> sorted_data;
	for (auto member : lhs.getData())
		sorted_data[member.getDegree()] = member.getCoefficient();
	for (auto member : rhs.getData())
		sorted_data[member.getDegree()] += member.getCoefficient();

	for (auto member : sorted_data)
		if (member.second)
			new_data.push_back({ member.second, member.first });

	return new_data.empty() ? Polynom() : Polynom(new_data);
}

Polynom Polynom::operator-() const {
	data_t new_data;

	for (auto member : data)
		new_data.push_back(-member);

	return Polynom(new_data);
}

Polynom Polynom::operator+(const Polynom& rhs) const {
	return polynomSum(*this, rhs);
}

Polynom Polynom::operator-(const Polynom& rhs) const {
	return polynomSum(*this, -rhs);
}

Polynom Polynom::operator*(const Polynom& rhs) const {
	data_t new_poly;

	for (auto l_member : data)
		for (auto r_member : rhs.data)
			new_poly.push_back(l_member * r_member);

	return Polynom(new_poly);
}

bool Polynom::operator==(const Polynom& rhs) const {
	return data.size() == rhs.data.size() && data == rhs.data;
}

// Формирование начального итератора
Polynom::iterator Polynom::begin() noexcept {
	return data.begin();
}

// Формирование начального константного итератора
Polynom::const_iterator Polynom::cbegin() const noexcept {
	return data.cbegin();
}

// Формирование конечного итератора
Polynom::iterator Polynom::end() noexcept {
	return data.end();
}

// Формирование конечного константного итератора
Polynom::const_iterator Polynom::cend() const noexcept {
	return data.cend();
}

// Получить размер
Polynom::data_t::size_type Polynom::size() const {
	return data.size();
};

// Перегрузка операции взятия из скобок
Member& Polynom::operator[](Polynom::data_t::size_type i) {
	return data[i];
}

// Перегрузка операции присвоения скобкам
Member Polynom::operator[](Polynom::data_t::size_type i) const {
	return data[i];
}
