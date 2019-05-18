#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>

#include "History.h"

namespace Ui {
class HistoryWindow;
}

// Класс для окна просмотра истории использования конвертера
class HistoryWindow : public QWidget {
	Q_OBJECT

public:
	explicit HistoryWindow(QWidget* parent = 0);
	~HistoryWindow();

	// Обновление таблицы истории
	void updateTable(const std::list<Record>& history);

private:
	// Очистить таблицу истори
	void clearTable();

signals:
	// Сигнал для вызова очистки истории
	void clearHistory();

private slots:
	// Закрыть окно истории
	void on_pushButton_Close_clicked();
	// Вызов очистки таблицы истории
	void on_pushButton_Clear_clicked();

private:
	Ui::HistoryWindow* ui;
};

#endif
