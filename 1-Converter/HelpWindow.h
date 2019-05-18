#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>

namespace Ui {
class HelpWindow;
}

// Класс для окна просмотра справки по пользованию конвертера
class HelpWindow : public QWidget {
	Q_OBJECT

public:
	explicit HelpWindow(QWidget* parent = 0);
	~HelpWindow();

private:
	// Прочитать и вывести файл со справкой
	void readHelp();

private slots:
	// Закрыть окно справки
	void on_pushButton_Close_clicked();

private:
	Ui::HelpWindow* ui;
};

#endif
