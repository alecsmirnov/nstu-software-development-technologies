#ifndef HISTORY_H
#define HISTORY_H

#include <list>
#include <string>

struct Record {
	std::pair<std::string, std::uint8_t> input;
	std::pair<std::string, std::uint8_t> result;
	std::string date;
	std::string time;
};

class History {
public:
	void addRecord(std::string input_num, std::uint8_t input_base, 
				   std::string result_num, std::uint8_t result_base);

	std::list<Record> getData() const;

	void clearData();

private:
	const std::pair<std::string, std::string> getCurrentDateTime() const;

private:
	std::list<Record> data;
};

#endif
