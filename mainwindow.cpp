#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QMessageBox>
#include <string>
#include <QString>
#include <QPushButton>
#include "stack.h"
#include <QList>

MainWindow::MainWindow() :
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->qLineEditList << ui->item0 << ui->item1 << ui->item2 << ui->item3
                        << ui->item4 << ui->item5 << ui->item6 << ui->item7
                        << ui->item8 << ui->item9;


    this->stringStack = new Stack<std::string>(10);

    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::onPushButtonClicked);
    connect(ui->popButton, &QPushButton::clicked,
            this, &MainWindow::onPopButtonClicked);

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::pushToLineEdit() {
    const QString item = ui->itemToPushedLineEdit->text();
    if(item != "") {
        const int size = this->stringStack->size();
        this->qLineEditList.at(size)->setText(item);
        if(size < this->qLineEditList.size() - 1) {
            ui->topLabel->move(ui->topLabel->x(),
                               this->qLineEditList.at(size + 1)->y());
        } else {
            ui->topLabel->move(ui->topLabel->x(),
                               ui->popButton->y());
        }
        this->stringStack->push(ui->itemToPushedLineEdit->text().toStdString());
    } else {
        showDialog("item tidak boleh kosong !");
    }
}

void MainWindow::onPushButtonClicked() {
    if(this->stringStack->size() != this->stringStack->getLength()) {
        pushToLineEdit();
    } else {
        showDialog("Stack penuh!");
    }
    ui->itemToPushedLineEdit->clear();
}

void MainWindow::showDialog(std::string message) {
    QMessageBox::information(this, "tidak valid",
                             QString::fromStdString(message));
}

void MainWindow::onPopButtonClicked() {
      const int size = this->stringStack->size();
      if(size != 0) {
        ui->topLabel->move(ui->topLabel->x(),
                    this->qLineEditList.at(size - 1)->y());
        ui->itemToPushedLineEdit->setText(
                    QString::fromStdString(this->stringStack->peek()));
        this->stringStack->pop();
      } else {
        showDialog("Stack kosong!");
      }
}
