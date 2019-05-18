#ifndef INTERFACEWINDOW_H
#define INTERFACEWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

#include "HelpWindow.h"
#include "Control.h"

namespace Ui {
class InterfaceWindow;
}

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

	// Выбор типа калькулятора
	void on_selectEditorComboBox_activated(int index);

	// Доступ кнопок, соответствующих выбранной СС
	void on_comboBox_activated(int index);

	// Выход из программы
	void on_pushButton_Exit_clicked();
	// Просмотр справки по программе
	void on_pushButton_Help_clicked();

private:
	enum class ControlType {	// Тип калькулятора/контроллера
		PController,			// P-ичное число
		FractionController,		// Простая дробь
		ComplexController		// Комплексное число
	};

private:
	Ui::InterfaceWindow* ui;
	HelpWindow* help_ui;

	Control<PNumber>* p_controller;
	Control<FractionNumber>* fraction_controller;
	Control<ComplexNumber>* complex_controller;

	ControlType controller_type;

	QButtonGroup* button_group;

	std::string history;
};

#endif
