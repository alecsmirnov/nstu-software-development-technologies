#include "Control.h"

#include "DecToPConverter.h"
#include "PToDecConverter.h"

// Выбор команды (от 0 до 18) для ввода числа
void Control::selectCommand(std::uint8_t command_num) {
	if (1 <= command_num && command_num <= 15)		// Ввод символов от 1 до 9, от A до F
		number_edit.addChr(command_num);
	else
		switch (command_num) {
			case  0: number_edit.addZero(); break;	// Ввод 0
			case 16: number_edit.addDot();  break;	// Ввод .
			case 17: number_edit.popChr();  break;	// Удаление последнего символа
			case 18: number_edit.clear();   break;	// Удаление всего числа
			default:;
		}
}

// Преобразовать число из указанной системы в новую систему счисления
std::string Control::convertFromTo(std::uint8_t base, std::uint8_t new_base) {
	std::string new_number(number_edit.getNumber());

	if (!new_number.empty()) {
		if (base != 10)				// Если основание числа не равно 10, переводи в 10
			new_number = PToDecConverter::convert(new_number, base);
		if (new_base != 10)			// Если новое основание не равно 10,переводим в P
			new_number = DecToPConverter::convert(new_number, new_base);

		//Удаление низначащих нулей, если они есть
		new_number = removeTrailingZeros(new_number);

		// Запись проделанного преобразования в историю
		conversion_history.addRecord(number_edit.getNumber(), base, new_number, new_base);
	}

	return new_number;
}

// Получить заданное число
std::string Control::getNumber() const {
	return number_edit.getNumber();
}

// Получить историю преобразования чисел
const std::list<Record>& Control::getHistory() const {
	return conversion_history.getData();
}

// Очистить историю преобразования чисел
void Control::clearHistory() {
	conversion_history.clearData();
}

// Проверка числа на вещественное
bool Control::isRealNum(const std::string& number) {
	return number.find('.') != std::string::npos;
}

// Удаление незначимых нулей числа
std::string Control::removeTrailingZeros(const std::string& number) {
	std::string result(number);

	if (isRealNum(result)) {
		result.erase(result.find_last_not_of('0') + 1, std::string::npos);
		// Если вся вещественная часть состоит из нулей, удаляем точку
		if (result[result.length() - 1] == '.')
			result.pop_back();
	}

	return result;
}
