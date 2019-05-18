#ifndef HISTORY_H
#define HISTORY_H

#include <list>
#include <string>

// Структура записи для хранения истории преобразования чисел
struct Record {
	std::pair<std::string, std::uint8_t> input;		// Входное число
	std::pair<std::string, std::uint8_t> result;	// Результат
	std::string date;								// Дата
	std::string time;								// Время
};

// Класс для хранения истории преобразований чисел
class History {
public:
	// Добавить новую запись
	void addRecord(std::string input_num, std::uint8_t input_base,
				   std::string result_num, std::uint8_t result_base);

	// Получить всю историю
	const std::list<Record>& getData() const;

	// Очистить историю
	void clearData();

private:
	// Получить текущую дату и время
	const std::pair<std::string, std::string> getCurrentDateTime() const;

private:
	std::list<Record> data;
};

#endif
