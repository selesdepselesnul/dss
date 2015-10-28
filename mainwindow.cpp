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

void MainWindow::on_pushButton_clicked() {
    if(this->itemStack.size() != 10) {
        const QString item = ui->itemToPushedLineEdit->text();
        switch (this->itemStack.size()) {
            case 0:
            ui->item0->setText(item);
            break;
            case 1:
            ui->item1->setText(item);
            break;
            case 2:
            ui->item2->setText(item);
            break;
            case 3:
            ui->item3->setText(item);
            break;
            case 4:
            ui->item4->setText(item);
            break;
            case 5:
            ui->item5->setText(item);
            break;
            case 6:
            ui->item6->setText(item);
            break;
            case 7:
            ui->item7->setText(item);
            break;
            case 8:
            ui->item8->setText(item);
            break;
            case 9:
            ui->item9->setText(item);
            break;
            default:
            break;
        }
        this->itemStack.push(ui->itemToPushedLineEdit->text().toStdString());
        ui->itemToPushedLineEdit->clear();
    }
}
