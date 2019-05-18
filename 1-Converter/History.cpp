#define _CRT_SECURE_NO_WARNINGS
#include "History.h"

#include <ctime>

constexpr std::uint8_t DATE_SIZE = 11;		// Размер массива для хранения даты
constexpr std::uint8_t TIME_SIZE = 9;		// Размер массива для хранения времени

// Добавить новую запись
void History::addRecord(std::string input_num, std::uint8_t input_base,
						std::string result_num, std::uint8_t result_base) {
	auto cur_date = getCurrentDateTime();	// Получить текущее время и дату
	data.push_front(Record{std::make_pair(input_num, input_base),
						   std::make_pair(result_num, result_base),
						   cur_date.first,
						   cur_date.second});
}

// Получить всю историю
const std::list<Record>& History::getData() const {
	return data;
}

// Очистить историю
void History::clearData() {
	std::list<Record>().swap(data);
}

// Получить текущую дату и время
const std::pair<std::string, std::string> History::getCurrentDateTime() const {
	time_t     now = std::time(0);
	struct tm  tstruct;
	char       cur_date[DATE_SIZE];
	char       cur_time[TIME_SIZE];
	tstruct = *std::localtime(&now);

	std::strftime(cur_date, sizeof(cur_date), "%m.%d.%Y", &tstruct);
	std::strftime(cur_time, sizeof(cur_time), "%X", &tstruct);

	return {cur_date, cur_time};
}
