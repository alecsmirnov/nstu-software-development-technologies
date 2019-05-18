#include "Polynom.h"

#include <algorithm>

Polynom::Polynom(double coefficient, std::uint8_t degree) {
	polynom.push_back({ coefficient, degree });
}

Polynom::Polynom(const Polynom& polynom) {
	this->polynom = polynom.polynom;

	arrange();
	simmilar();
}

Polynom::Polynom(const data_t& polynom) {
	this->polynom = polynom;

	arrange();
	simmilar();
}

Polynom::Polynom(std::string polynom) {
	setStrPolynom(polynom);
}

// Задать новое значение полинома в виде строки
void Polynom::setStrPolynom(std::string polynom) {
	clear();

	if (!polynom.empty()) {
		// Обработка первого одночлена (без знака, если положительный)
		if (polynom[0] != '-')
			polynom = "+" + polynom;

		// Выделение одночленов из многочлена в виде стркои
		std::string::size_type found = 0;
		std::string::size_type pos = 1;
		while (found != std::string::npos && pos != std::string::npos) {
			found = polynom.find_first_of("+-", pos);
			this->polynom.push_back(polynom.substr(pos - 1, found + 1 - pos));

			pos = found + 1;
		}

		arrange();
		simmilar();
	}
}

// Получить полином в виде строки
std::string Polynom::getStrPolynom() const {
	std::string new_poly;

	if (!polynom.empty()) {
		data_t::size_type i = 0;
		for (; i != polynom.size() - 1; ++i) {
			// Получение одночлена в виде строки
			new_poly += polynom[i].getStrMember();

			// Формирование полинома из одночленов
			if (0 < polynom[i + 1].getCoefficient())
				new_poly += "+";
		}

		new_poly += polynom[i].getStrMember();
	}

	return new_poly;
}

// Получить полинмо в виде структуры хранения
Polynom::data_t Polynom::getPolynom() const {
	return polynom;
}

// Получить коэффициент при степени
double Polynom::getCoefficient(std::uint8_t degree) const {
	double coeff = 0;

	// Поиск коэффициента при степени
	for (auto& member : polynom)
		if (member.getDegree() == degree)
			coeff = member.getCoefficient();

	return coeff;
}

// Получить степень полинома
std::uint8_t Polynom::getDegree() const {
	std::uint8_t max_degree = 0;

	// Поиск наибольшей степени
	for (auto& member : polynom)
		if (max_degree < member.getDegree())
			max_degree = member.getDegree();

	return max_degree;
}

// Дифференцировать
Polynom Polynom::differentiate() const {
	data_t new_poly;

	for (auto member : polynom)
		if (member.getDegree())
			new_poly.push_back(member.differentiate());
	
	return new_poly.empty() ? Polynom(0, 0) : Polynom(new_poly);
}

// Посчитать значение
double Polynom::calculate(double x) const {
	double poly_res = 0;

	for (auto member : polynom)
		poly_res += member.calculate(x);

	return poly_res;
}

// Очистить полином
void Polynom::clear() {
	data_t().swap(polynom);
}

Polynom::~Polynom() {
	clear();
}

// Упорядочить полином 
void Polynom::arrange() {
	std::sort(polynom.begin(), polynom.end(), 
		[](const elem_t& a, const elem_t& b) -> bool {
			return a.getDegree() > b.getDegree();
		});
}

// Привести подобные в упорядоченном полиноме
void Polynom::simmilar() {
	if (!polynom.empty()) {
		data_t new_polynom;

		for (data_t::size_type i = 0; i != polynom.size(); ) {
			Member member(polynom[i].getCoefficient(), polynom[i].getDegree());

			// Поиск подобных для i-го элемента
			data_t::size_type steps = 0;
			for (data_t::size_type j = i + 1; j != polynom.size(); ++j)
				if (member.getDegree() == polynom[j].getDegree()) {
					member = member + polynom[j];			// Сумма подобных
					++steps;								// Кол-во подобных
				}

			// Запись суммы подобных в новый полином
			new_polynom.push_back(member);

			// Пропуск найденных подобных
			i += steps + 1;
		}
		
		polynom = new_polynom;
	}
}

// Операции сложения и вычитания для полинома
Polynom Polynom::polynomOperation(const Polynom& lhs, const Polynom& rhs, Operation operation) const {
	auto lhs_member = lhs.getPolynom();
	auto rhs_member = rhs.getPolynom();

	data_t new_poly;

	for (auto it_lhs = lhs_member.begin(); it_lhs != lhs_member.end(); ) {
		bool search = true;

		// Поиск одночленов с одинаковыми степенями
		for (auto it_rhs = rhs_member.begin(); it_rhs != rhs_member.end() && search; )
			if (it_lhs->getDegree() == it_rhs->getDegree()) {
				// Если в результате операции не 0 коэффициент -- записываем в новый полином
				if (auto new_member = operation(*it_lhs, *it_rhs); new_member.getCoefficient())
					new_poly.push_back(new_member);

				// Удаление использованных в операции одночленов
				it_lhs = lhs_member.erase(it_lhs);
				it_rhs = rhs_member.erase(it_rhs);

				search = false;
			}
			else
				++it_rhs;

		if (search)
			++it_lhs;
	}

	// Запись в новый полином неиспользованных одночленов lhs полинома
	for (auto member : lhs_member)
		new_poly.push_back(member);
	// Запись в новый полином неиспользованных одночленов rhs полинома
	for (auto member : rhs_member)
		new_poly.push_back(operation(Member(0, member.getDegree()), member));

	return new_poly.empty() ? Polynom(0, 0) : Polynom(new_poly);
}

Polynom Polynom::operator+(const Polynom& rhs) const {
	return polynomOperation(*this, rhs, [](const elem_t& a, const elem_t& b) -> elem_t {
		return a + b;
	});
}

Polynom Polynom::operator-(const Polynom& rhs) const {
	return polynomOperation(*this, rhs, [](const elem_t& a, const elem_t& b) -> elem_t {
		return a - b;
	});
}

Polynom Polynom::operator*(const Polynom& rhs) const {
	data_t new_poly;

	for (auto l_member : polynom)
		for (auto r_member : rhs.polynom)
			new_poly.push_back(l_member * r_member);

	return Polynom(new_poly);
}

bool Polynom::operator==(const Polynom& rhs) const {
	return polynom.size() == rhs.size() && polynom == rhs.polynom;
}

// Формирование начального итератора
Polynom::iterator Polynom::begin() noexcept {
	return polynom.begin();
}

// Формирование начального константного итератора
Polynom::const_iterator Polynom::cbegin() const noexcept {
	return polynom.cbegin();
}

// Формирование конечного итератора
Polynom::iterator Polynom::end() noexcept {
	return polynom.end();
}

// Формирование конечного константного итератора
Polynom::const_iterator Polynom::cend() const noexcept {
	return polynom.cend();
}

// Получить размер
Polynom::data_t::size_type Polynom::size() const {
	return polynom.size();
};

// Перегрузка операции взятия из скобок
Member& Polynom::operator[](Polynom::data_t::size_type i) {
	return polynom[i];
}

// Перегрузка операции присвоения скобкам
Member Polynom::operator[](Polynom::data_t::size_type i) const {
	return polynom[i];
}
