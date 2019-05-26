#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <cstdint>

// Одночлен полинома
class Member {
public:
	Member() : coeff(0), degree(0) {}
	Member(double coeff, std::uint8_t degree = 0);
	Member(std::string str_mem);

	// Задать новое значение одночлена в виде строки
	void setStrMember(std::string str_mem);
	// Установить коэффициент
	void setCoefficient(double coeff);
	// Установить степень
	void setDegree(std::uint8_t degree);

	// Получить одночлен в виде строки
	std::string getStrMember() const;
	// Получить коэффициент
	double getCoefficient() const;
	// Получить степень
	std::uint8_t getDegree() const;

	// Дифференцировать
	Member differentiate() const;
	// Посчитать значение
	double calculate(double x) const;

private:
	using Operation = double (*)(double coef_a, double coef_b);
	// Операции сложения и вычитания для одночлена
	Member memberOperation(const Member& a, const Member& b, Operation operation) const;

	// Проверка одночлена на вещественное число
	static bool isRealNum(const std::string& str_num);
	// Удаление незначащих нулей из строкового представления
	static std::string removeTrailingZeros(const std::string& str_num);

public:
	// Перегруженные операторы
	Member operator-() const;
	Member operator+(const Member& rhs) const;
	Member operator-(const Member& rhs) const;
	Member operator*(const Member& rhs) const;
	bool operator==(const Member& rhs) const;

private:
	double coeff;
	std::uint8_t degree;
};

#endif