#include "queuewindow.h"
#include "ui_queuewindow.h"
#include <QDebug>
#include <QStringListModel>
#include <QStringList>
#include <iostream>
#include <QMessageBox>
#include <QComboBox>

QueueWindow::QueueWindow() :
    ui(new Ui::QueueWindow) {
    ui->setupUi(this);
    this->lineEditList << ui->item0 << ui->item1 << ui->item2 << ui->item3
                       << ui->item4 << ui->item5 << ui->item6 << ui->item7
                       << ui->item8 << ui->item9;

    connect(ui->enqueueButton, &QPushButton::clicked,
            this, &QueueWindow::onEnqueueButtonClicked);

    connect(ui->dequeueButton, &QPushButton::clicked,
            this, &QueueWindow::onDequeueButtonClicked);

    this->initHeadPos = ui->headLabel->pos();
    this->initTailPos = ui->tailLabel->pos();


    this->queue = new SimpleQueue<QString>(10);

    QStringListModel *stringListModel = new QStringListModel();
    QStringList stringList;
    stringList << "Simple" << "Reset" << "Shifting" << "Circular";
    stringListModel->setStringList(stringList);

    ui->modeComboBox->setModel(stringListModel);

    connect(ui->modeComboBox,static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),
            [&](const QString &text){
        if(text == "Simple") {
            this->queue = new SimpleQueue<QString>(10);
        } else if(text == "Reset") {
            this->queue = new ResetQueue<QString>(10);
        } else if(text == "Shifting") {
        } else {
            this->queue = new CircularQueue<QString>(10);
        }
        ui->headLabel->move(this->initHeadPos);
        ui->tailLabel->move(this->initTailPos);
    });
}

void QueueWindow::onEnqueueButtonClicked() {
    if(!this->queue->isFull()) {
        this->queue->enqueue(ui->itemToBeEnqueue->text());
        auto currentItem = this->lineEditList.at(this->queue->getTail());
        currentItem->setText(ui->itemToBeEnqueue->text());
        ui->tailLabel->move(currentItem->x(), ui->tailLabel->y());
    } else {
        showMessage("Queue penuh");
    }
    qDebug() << "curent size is = " << this->queue->size();
}

void QueueWindow::showMessage(QString message) {
    QMessageBox::information(this, "Tidak valid", message);
}

void QueueWindow::onDequeueButtonClicked() {
    if(!this->queue->isEmpty()) {
        ui->itemToBeEnqueue->setText(this->queue->dequeue());
        ui->headLabel->move(
                    this->lineEditList.at(
                        this->queue->getHead())->x(),
                        ui->headLabel->y());
        qDebug() << "Current size is = " << this->queue->size();
    } else {
        showMessage("Queue kosong");
    }

}
