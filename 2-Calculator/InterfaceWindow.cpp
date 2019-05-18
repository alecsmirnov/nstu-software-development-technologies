#include "InterfaceWindow.h"
#include "ui_InterfaceWindow.h"

// Начальное положение чекбокса (основания СС)
constexpr std::uint8_t CHECKBOX_CUR_ITEM = 8;

InterfaceWindow::InterfaceWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::InterfaceWindow) {
	ui->setupUi(this);
	this->statusBar()->setSizeGripEnabled(false);
	on_comboBox_activated(CHECKBOX_CUR_ITEM);
	help_ui = new HelpWindow();

	buttonGroupInit();

	controller = new Control();
}

InterfaceWindow::~InterfaceWindow() {
	delete ui;
	delete help_ui;

	delete button_group;

	delete controller;
}

// Инициализация группы кнопок
void InterfaceWindow::buttonGroupInit() {
	button_group = new QButtonGroup();

	button_group->addButton(ui->pushButton_0,  0);
	button_group->addButton(ui->pushButton_1,  1);
	button_group->addButton(ui->pushButton_2,  2);
	button_group->addButton(ui->pushButton_3,  3);
	button_group->addButton(ui->pushButton_4,  4);
	button_group->addButton(ui->pushButton_5,  5);
	button_group->addButton(ui->pushButton_6,  6);
	button_group->addButton(ui->pushButton_7,  7);
	button_group->addButton(ui->pushButton_8,  8);
	button_group->addButton(ui->pushButton_9,  9);
	button_group->addButton(ui->pushButton_10, 10);
	button_group->addButton(ui->pushButton_11, 11);
	button_group->addButton(ui->pushButton_12, 12);
	button_group->addButton(ui->pushButton_13, 13);
	button_group->addButton(ui->pushButton_14, 14);
	button_group->addButton(ui->pushButton_15, 15);
	button_group->addButton(ui->pushButton_16, 16);
	button_group->addButton(ui->pushButton_17, 17);
	button_group->addButton(ui->pushButton_18, 18);
	button_group->addButton(ui->pushButton_19, 19);
	button_group->addButton(ui->pushButton_20, 20);
	button_group->addButton(ui->pushButton_21, 21);
	button_group->addButton(ui->pushButton_22, 22);
	button_group->addButton(ui->pushButton_23, 23);
	button_group->addButton(ui->pushButton_24, 24);
	button_group->addButton(ui->pushButton_25, 25);
	button_group->addButton(ui->pushButton_26, 26);
	button_group->addButton(ui->pushButton_27, 27);
	button_group->addButton(ui->pushButton_28, 28);
	button_group->addButton(ui->pushButton_29, 29);

	connect(button_group, SIGNAL(buttonClicked(int)), this, SLOT(on_groupButtonClicked(int)));
}

// Вывод на экран истории введённых операций
void InterfaceWindow::printHistory(int button_num) {
	if (18 <= button_num && button_num <= 22 || button_num == 29) {
		history += ui->lineEdit->text().toStdString();

		switch (button_num) {
			case 19: history += " + "; break;
			case 20: history += " - "; break;
			case 21: history += " * "; break;
			case 22: history += " / "; break;
			case 18:
			case 29: history.clear(); break;
			default:;
		}
	}

	ui->label_history->setText(QString::fromStdString(history));
}

// Выбор пункта управления, соответствующего нажатой кнопке
void InterfaceWindow::on_groupButtonClicked(int button_num) {
	printHistory(button_num);
	controller->selectCommand(button_num);
	ui->lineEdit->setText(QString::fromStdString(controller->getNumber()));
}

// Доступ кнопок, соответствующих выбранной СС
void InterfaceWindow::on_comboBox_activated(int index) {
	ui->pushButton_0->setEnabled(false);
	ui->pushButton_1->setEnabled(false);
	ui->pushButton_2->setEnabled(false);
	ui->pushButton_3->setEnabled(false);
	ui->pushButton_4->setEnabled(false);
	ui->pushButton_5->setEnabled(false);
	ui->pushButton_6->setEnabled(false);
	ui->pushButton_7->setEnabled(false);
	ui->pushButton_8->setEnabled(false);
	ui->pushButton_9->setEnabled(false);
	ui->pushButton_10->setEnabled(false);
	ui->pushButton_11->setEnabled(false);
	ui->pushButton_12->setEnabled(false);
	ui->pushButton_13->setEnabled(false);
	ui->pushButton_14->setEnabled(false);
	ui->pushButton_15->setEnabled(false);

	switch (index) {
		case 14: ui->pushButton_15->setEnabled(true);
		case 13: ui->pushButton_14->setEnabled(true);
		case 12: ui->pushButton_13->setEnabled(true);
		case 11: ui->pushButton_12->setEnabled(true);
		case 10: ui->pushButton_11->setEnabled(true);
		case 9:  ui->pushButton_10->setEnabled(true);
		case 8:  ui->pushButton_9->setEnabled(true);
		case 7:  ui->pushButton_8->setEnabled(true);
		case 6:  ui->pushButton_7->setEnabled(true);
		case 5:  ui->pushButton_6->setEnabled(true);
		case 4:  ui->pushButton_5->setEnabled(true);
		case 3:  ui->pushButton_4->setEnabled(true);
		case 2:  ui->pushButton_3->setEnabled(true);
		case 1:  ui->pushButton_2->setEnabled(true);
		case 0:  ui->pushButton_1->setEnabled(true);
				 ui->pushButton_0->setEnabled(true);
		default: break;
	}

	controller->setNumberBase(static_cast<std::uint8_t>(index) + 2);
}

// Выход из программы
void InterfaceWindow::on_pushButton_Exit_clicked() {
	this->close();

	help_ui->close();
}

// Просмотр справки по программе
void InterfaceWindow::on_pushButton_Help_clicked() {
	help_ui->show();
}
