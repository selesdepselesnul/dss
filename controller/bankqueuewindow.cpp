#include "ui_bankqueuewindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <algorithm>
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

    connect(ui->teller1Button, &QPushButton::clicked,
            [=](){
        dequeue(1, "background-color: rgb(170, 170, 0);");
    });

    connect(ui->teller2Button, &QPushButton::clicked,
            [=](){
        dequeue(2, "background-color: rgb(85, 0, 127)");
    });

    connect(ui->teller3Button, &QPushButton::clicked,
            [=](){
        dequeue(3, "background-color: rgb(85, 255, 255)");
    });

    connect(ui->teller4Button, &QPushButton::clicked,
            [=](){
        dequeue(4, "background-color: rgb(255, 170, 0)");
    });
}

void BankQueueWindow::dequeue(int tellerNumber, QString color) {
    if(this->circularQueue->isEmpty()) {
        showMessage("Antrian Kosong !");
    } else {
        this->lineEditList.at(this->circularQueue->getHead())->
                setStyleSheet(color);
        const auto currentQueueNumber = this->circularQueue->dequeue();
        ui->queueLcdNumber->display(currentQueueNumber);
        ui->tellerLcdNumber->display(tellerNumber);
        ui->tellerLcdNumber->setStyleSheet(color);
        ui->queueLcdNumber->setStyleSheet("background-color: red");
        ui->headLabel->move(this->lineEditList.at(this->circularQueue->getHead())->x(),
                            ui->headLabel->y());
        ui->queueSizeLcdNumber->display(this->circularQueue->size());
    }
}

void BankQueueWindow::onGetQueueNumberButtonClicked() {
    if(!this->circularQueue->isFull()) {

        const auto itemToBeEnqueue = this->queueNumber++;
        this->circularQueue->enqueue(itemToBeEnqueue);

        const auto currentItem = this->lineEditList.at(this->circularQueue->getTail() - 1);
        currentItem->setStyleSheet("background-color: green");
        currentItem ->setText(QString::number(itemToBeEnqueue));

        if(this->circularQueue->getTail() == this->lineEditList.length()) {
            ui->tailLabel->move(ui->getQueueNumberButton->x(), ui->tailLabel->y());
        } else {

            const auto tailItem = this->lineEditList.at(this->circularQueue->getTail());
            ui->tailLabel->move(tailItem ->x(), ui->tailLabel->y());
        }

        ui->queueSizeLcdNumber->display(this->circularQueue->size());

    } else {

        showMessage("Queue penuh");

    }
}

void BankQueueWindow::showMessage(QString message) {
    QMessageBox::information(this, "Tidak Valid", message);
}
