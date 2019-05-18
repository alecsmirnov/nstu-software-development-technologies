#include "HistoryWindow.h"
#include "ui_HistoryWindow.h"

constexpr std::uint8_t TABLE_COL_SIZE = 6;	// Количество столбцов таблицы

// Корректировки размеров ячеек
constexpr float NUMBER_CELL = -1.75;		// Числовые ячейки
constexpr float BASE_CELL = 2;				// Ячейки с основаниями СС
constexpr float TIME_CELL = 3;				// Ячейка с временем
constexpr float DATE_CELL = 1;				// Ячейки с датой
constexpr float ELEMS_WIDTH = 21;			// Скроллбар и другие элементы

HistoryWindow::HistoryWindow(QWidget* parent) : QWidget(parent), ui(new Ui::HistoryWindow) {
	ui->setupUi(this);

	// Формирование заголовка таблицы истории
	ui->tableWidget->setColumnCount(TABLE_COL_SIZE);
	ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Число"));
	ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Основание"));
	ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Результат"));
	ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Основание"));
	ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Время"));
	ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Дата"));

	// Установка размеров столбцов таблицы истории
	ui->tableWidget->setColumnWidth(0, ui->tableWidget->width() / (TABLE_COL_SIZE + NUMBER_CELL));
	ui->tableWidget->setColumnWidth(1, ui->tableWidget->width() / (TABLE_COL_SIZE + BASE_CELL));
	ui->tableWidget->setColumnWidth(2, ui->tableWidget->width() / (TABLE_COL_SIZE + NUMBER_CELL));
	ui->tableWidget->setColumnWidth(3, ui->tableWidget->width() / (TABLE_COL_SIZE + BASE_CELL));
	ui->tableWidget->setColumnWidth(4, ui->tableWidget->width() / (TABLE_COL_SIZE + TIME_CELL));
	ui->tableWidget->setColumnWidth(5, ui->tableWidget->width() / (TABLE_COL_SIZE + DATE_CELL) - ELEMS_WIDTH);

	ui->tableWidget->setRowCount(1);
}

HistoryWindow::~HistoryWindow() {
	delete ui;
}

// Обновление таблицы истории
void HistoryWindow::updateTable(const std::list<Record>& history) {
	clearTable();

	// Вывод истории в таблицу
	for (auto record : history) {
		auto new_row = ui->tableWidget->currentRow() + 1;

		ui->tableWidget->insertRow(new_row);

		ui->tableWidget->setItem(new_row, 0, new QTableWidgetItem(QString::fromStdString(record.input.first)));
		ui->tableWidget->setItem(new_row, 1, new QTableWidgetItem(QString::number(record.input.second)));
		ui->tableWidget->setItem(new_row, 2, new QTableWidgetItem(QString::fromStdString(record.result.first)));
		ui->tableWidget->setItem(new_row, 3, new QTableWidgetItem(QString::number(record.result.second)));
		ui->tableWidget->setItem(new_row, 4, new QTableWidgetItem(QString::fromStdString(record.time)));
		ui->tableWidget->setItem(new_row, 5, new QTableWidgetItem(QString::fromStdString(record.date)));
	}
}

// Очистить таблицу историю
void HistoryWindow::clearTable() {
	ui->tableWidget->setRowCount(0);
}

// Закрыть окно истории
void HistoryWindow::on_pushButton_Close_clicked() {
	this->hide();
}

// Вызов очистки таблицы истории
void HistoryWindow::on_pushButton_Clear_clicked() {
	if (ui->tableWidget->rowCount()) {
		emit clearHistory();
		clearTable();
		ui->tableWidget->setRowCount(1);
	}
}
