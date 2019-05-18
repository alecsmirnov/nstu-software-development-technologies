#include "HelpWindow.h"
#include "ui_HelpWindow.h"

#include <QFile>
#include <QTextStream>

HelpWindow::HelpWindow(QWidget* parent) : QWidget(parent), ui(new Ui::HelpWindow) {
	ui->setupUi(this);

	readHelp();
}

HelpWindow::~HelpWindow() {
	delete ui;
}

// Прочитать и вывести файл со справкой
void HelpWindow::readHelp() {
	QFile file("Help.txt");

	if(!file.open(QIODevice::ReadOnly))
		ui->textEdit->setText("Справка отсутствует!");
	else {
		QTextStream in(&file);

		auto text = in.readAll();
		ui->textEdit->setText(text);

		file.close();
	}
}

// Закрыть окно справки
void HelpWindow::on_pushButton_Close_clicked() {
	this->hide();
}
