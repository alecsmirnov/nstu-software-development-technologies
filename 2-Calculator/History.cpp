#define _CRT_SECURE_NO_WARNINGS
#include "History.h"

#include <ctime>

constexpr std::uint8_t DATE_SIZE = 11;
constexpr std::uint8_t TIME_SIZE = 9;

void History::addRecord(std::string input_num, std::uint8_t input_base, 
						std::string result_num, std::uint8_t result_base) {
	auto cur_date = getCurrentDateTime();
	data.push_back(Record{std::make_pair(input_num, input_base),
						  std::make_pair(result_num, result_base),
						  cur_date.first,
						  cur_date.second});
}

std::list<Record> History::getData() const {
	return data;
}

void History::clearData() {
	std::list<Record>().swap(data);
}

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
