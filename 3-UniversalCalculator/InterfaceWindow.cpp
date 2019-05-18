#include "InterfaceWindow.h"
#include "ui_InterfaceWindow.h"

constexpr std::uint8_t COMBOBOX_CUR_EDITOR = 0;		// Начальное положение комбобокса (редактор)
constexpr std::uint8_t COMBOBOX_CUR_P	   = 8;		// Начальное положение комбобокса (основания СС)

constexpr std::uint8_t CONTROLLER_CLEAR = 18;		// Очистить контроллер
constexpr std::uint8_t MEMORY_CLEAR     = 28;		// Очистить память

constexpr std::uint16_t BUTTON_HEIGHT = 31;			// Высота кнопки
constexpr std::uint16_t BUTTON_WIDTH  = 61;			// Ширина кнопки
constexpr std::uint16_t DBUTTN_WIDHT  = 121;		// Ширина двойной кнопки

constexpr std::uint16_t LINE_1 = 240;				// Начало линии 1
constexpr std::uint16_t LINE_2 = 270;				// Начало линии 2
constexpr std::uint16_t LINE_3 = 300;				// Начало линии 3

constexpr std::uint16_t COLUMN_1 = 16;				// Начало столбца 1
constexpr std::uint16_t COLUMN_2 = 76;				// Начало столбца 2
constexpr std::uint16_t COLUMN_3 = 136;				// Начало столбца 3
constexpr std::uint16_t COLUMN_4 = 196;				// Начало столбца 4
constexpr std::uint16_t COLUMN_5 = 256;				// Начало столбца 5

InterfaceWindow::InterfaceWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::InterfaceWindow) {
	ui->setupUi(this);
	this->statusBar()->setSizeGripEnabled(false);
	on_selectEditorComboBox_activated(COMBOBOX_CUR_EDITOR);
	on_comboBox_activated(COMBOBOX_CUR_P);
	help_ui = new HelpWindow();

	p_controller = new Control<PNumber>();
	fraction_controller = new Control<FractionNumber>();
	complex_controller = new Control<ComplexNumber>();

	buttonGroupInit();
}

InterfaceWindow::~InterfaceWindow() {
	delete ui;
	delete help_ui;

	delete p_controller;
	delete fraction_controller;
	delete complex_controller;

	delete button_group;
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

	connect(button_group, SIGNAL(buttonClicked(int)),
			this, SLOT(on_groupButtonClicked(int)));
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
		}
	}

	ui->label_history->setText(QString::fromStdString(history));
}

// Выбор пункта управления, соответствующего нажатой кнопке
void InterfaceWindow::on_groupButtonClicked(int button_num) {
	printHistory(button_num);

	switch (controller_type) {
		case ControlType::PController:
			p_controller->selectCommand(static_cast<std::uint8_t>(button_num));
			ui->lineEdit->setText(QString::fromStdString(p_controller->getNumber()));
			break;
		case ControlType::FractionController:
			fraction_controller->selectCommand(static_cast<std::uint8_t>(button_num));
			ui->lineEdit->setText(QString::fromStdString(fraction_controller->getNumber()));
			break;
		case ControlType::ComplexController:
			complex_controller->selectCommand(static_cast<std::uint8_t>(button_num));
			ui->lineEdit->setText(QString::fromStdString(complex_controller->getNumber()));
			break;
	}
}

void InterfaceWindow::on_selectEditorComboBox_activated(int index) {
	on_groupButtonClicked(CONTROLLER_CLEAR);
	on_groupButtonClicked(MEMORY_CLEAR);
	on_comboBox_activated(COMBOBOX_CUR_P);

	ui->label->setVisible(false);
	ui->comboBox->setVisible(false);

	ui->pushButton_10->setVisible(false);
	ui->pushButton_11->setVisible(false);
	ui->pushButton_12->setVisible(false);
	ui->pushButton_13->setVisible(false);
	ui->pushButton_14->setVisible(false);
	ui->pushButton_15->setVisible(false);

	ui->pushButton_23->setGeometry(COLUMN_3, LINE_1, BUTTON_WIDTH, BUTTON_HEIGHT);
	ui->pushButton_24->setGeometry(COLUMN_4, LINE_1, BUTTON_WIDTH, BUTTON_HEIGHT);

	ui->pushButton_16->setGeometry(COLUMN_1, LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT);
	ui->pushButton_17->setGeometry(COLUMN_2, LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT);
	ui->pushButton_18->setGeometry(COLUMN_3, LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT);
	ui->pushButton_29->setGeometry(COLUMN_4, LINE_2, DBUTTN_WIDHT, BUTTON_HEIGHT);

	switch (index) {
		case 0: {
			controller_type = ControlType::PController;
			ui->pushButton_16->setText(".");

			ui->label->setVisible(true);
			ui->comboBox->setVisible(true);

			ui->pushButton_10->setVisible(true);
			ui->pushButton_11->setVisible(true);
			ui->pushButton_12->setVisible(true);
			ui->pushButton_13->setVisible(true);
			ui->pushButton_14->setVisible(true);
			ui->pushButton_15->setVisible(true);

			ui->pushButton_23->setGeometry(COLUMN_5, LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT);
			ui->pushButton_24->setGeometry(COLUMN_5, LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT);

			ui->pushButton_16->setGeometry(COLUMN_1, LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT);
			ui->pushButton_17->setGeometry(COLUMN_2, LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT);
			ui->pushButton_18->setGeometry(COLUMN_3, LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT);
			ui->pushButton_29->setGeometry(COLUMN_4, LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT);
			break;
		}
		case 1: {
			controller_type = ControlType::FractionController;
			ui->pushButton_16->setText("/");
			break;
		}
		case 2: {
			controller_type = ControlType::ComplexController;
			ui->pushButton_16->setText("+i");
			break;
		}
	}

	ui->lineEdit->setText("");
	ui->label_history->setText("");
	history.clear();
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

	switch (controller_type) {
		case ControlType::PController: {
			p_controller->setNumberBase(static_cast<std::uint8_t>(index + 2));
			break;
		}
		case ControlType::FractionController: {
			fraction_controller->setNumberBase(static_cast<std::uint8_t>(index + 2));
			break;
		}
		case ControlType::ComplexController: {
			complex_controller->setNumberBase(static_cast<std::uint8_t>(index + 2));
			break;
		}
	}
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
