#include "ui_bankqueuewindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "util/queue.h"
#include "controller/bankqueuewindow.h"

BankQueueWindow::BankQueueWindow() :
    ui(new Ui::BankQueueWindow) {
    ui->setupUi(this);
    this->queueNumber = 1;
    this->circularQueue = new CircularQueue<int>(10);

    this->lineEditList << ui->item0 << ui->item1 << ui->item2 << ui->item3
                       << ui->item4 << ui->item5 << ui->item6 << ui->item7
                       << ui->item8 << ui->item9;

    connect(ui->getQueueNumberButton, &QPushButton::clicked,
            this, &BankQueueWindow::onGetQueueNumberButtonClicked);
}

void BankQueueWindow::onGetQueueNumberButtonClicked() {
    if(this->circularQueue->isFull()) {
        QMessageBox::information(this, "Tidak Valid", "Antrian Penuh !");
    } else {
        const int currentQueueNumber = this->queueNumber++;
        const auto currentLineEdit = this->lineEditList.at(this->circularQueue->size());
        currentLineEdit->setStyleSheet("background-color : green");
        this->circularQueue->enqueue(currentQueueNumber);
        if(this->lineEditList.length() != this->circularQueue->size()) {
            ui->tailLabel->move(this->lineEditList.at(
                                this->circularQueue->size())->x(),
                                ui->tailLabel->y());
        } else {
            ui->tailLabel->move(ui->getQueueNumberButton->x(), ui->tailLabel->y());
        }
    }
}
