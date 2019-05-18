#include "InterfaceWindow.h"
#include "ui_InterfaceWindow.h"

// Начальное положение чекбокса (основания СС)
constexpr std::uint8_t CHECKBOX_CUR_ITEM = 8;

InterfaceWindow::InterfaceWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::InterfaceWindow) {
	ui->setupUi(this);
	this->statusBar()->setSizeGripEnabled(false);
	on_comboBox_activated(CHECKBOX_CUR_ITEM);

	history_ui = new HistoryWindow();
	connect(history_ui, &HistoryWindow::clearHistory,
			this, &InterfaceWindow::clearHistory);
	help_ui = new HelpWindow();

	buttonGroupInit();

	controller = new Control();
}

InterfaceWindow::~InterfaceWindow() {
	delete ui;
	delete history_ui;
	delete help_ui;

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

	connect(button_group, SIGNAL(buttonClicked(int)),
			this, SLOT(on_groupButtonClicked(int)));
}

// Очистка истории преобразований
void InterfaceWindow::clearHistory() {
	controller->clearHistory();
}

// Выбор пункта управления, соответствующего нажатой кнопке
void InterfaceWindow::on_groupButtonClicked(int button_num) {
	controller->selectCommand(static_cast<std::uint8_t>(button_num));
	ui->lineEdit->setText(QString::fromStdString(controller->getNumber()));

	switch (button_num) {
		case 18: {
			ui->lineEdit_2->setText("");
			break;
		}
		case 19: {
			ui->lineEdit_2->setText(
				QString::fromStdString(controller->convertFromTo(
				static_cast<std::uint8_t>(ui->comboBox->currentText().toInt()),
				static_cast<std::uint8_t>(ui->comboBox_2->currentText().toInt())))
			);
			history_ui->updateTable(controller->getHistory());
			break;
		}
	}
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
}

// Выход из программы
void InterfaceWindow::on_pushButton_Exit_clicked() {
	this->close();
	history_ui->close();
	help_ui->close();
}

// Просмотр истории преобразований
void InterfaceWindow::on_pushButton_History_clicked() {
	history_ui->show();
}

// Просмотр справки по программе
void InterfaceWindow::on_pushButton_Help_clicked() {
	help_ui->show();
}
