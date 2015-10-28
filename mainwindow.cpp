#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    switch (this->itemStack.size()) {
    case 0:
        ui->item0->setText(ui->itemToPushedLineEdit->text());
        break;
    default:
        break;
    }

    this->itemStack.push(ui->itemToPushedLineEdit->text().toStdString());
}
