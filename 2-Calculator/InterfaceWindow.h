#ifndef INTERFACEWINDOW_H
#define INTERFACEWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

#include "HelpWindow.h"
#include "Control.h"

namespace Ui {
class InterfaceWindow;
}

// Класс основного окна калькулятора
class InterfaceWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit InterfaceWindow(QWidget* parent = nullptr);
	~InterfaceWindow();

private:
	// Инициализация группы кнопок
	void buttonGroupInit();
	// Вывод на экран истории введённых операций
	void printHistory(int button_num);

private slots:
	// Выбор пункта управления, соответствующего нажатой кнопке
	void on_groupButtonClicked(int button_num);

	// Доступ кнопок, соответствующих выбранной СС
	void on_comboBox_activated(int index);

	// Выход из программы
	void on_pushButton_Exit_clicked();
	// Просмотр справки по программе
	void on_pushButton_Help_clicked();

private:
	Ui::InterfaceWindow* ui;
	HelpWindow* help_ui;

	QButtonGroup* button_group;

	std::string history;
	Control* controller;
};

#endif
