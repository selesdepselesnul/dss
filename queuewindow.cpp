#include "queuewindow.h"
#include "ui_queuewindow.h"
#include <QDebug>
#include <QStringListModel>
#include <QStringList>
#include <iostream>
#include <QMessageBox>
#include <QComboBox>
#include <algorithm>

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

    this->isShiftingMode = false;

    this->queue = new SimpleQueue<QLineEdit*>(10);

    QStringListModel *stringListModel = new QStringListModel();
    QStringList stringList;
    stringList << "Simple" << "Reset" << "Shifting" << "Circular";
    stringListModel->setStringList(stringList);

    ui->modeComboBox->setModel(stringListModel);

    connect(ui->modeComboBox,static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),
            [&](const QString &text){
        if(text == "Simple") {
            this->queue = new SimpleQueue<QLineEdit*>(10);
        } else if(text == "Reset") {
            this->queue = new ResetQueue<QLineEdit*>(10);
        } else if(text == "Shifting") {
            this->queue = new ShiftingQueue<QLineEdit*>(10);
            this->isShiftingMode = true;
        } else {
            this->queue = new CircularQueue<QLineEdit*>(10);
        }
        ui->headLabel->move(this->initHeadPos);
        ui->tailLabel->move(this->initTailPos);
    });
}

void QueueWindow::onEnqueueButtonClicked() {
    if(!this->queue->isFull()) {
        auto currentItem = this->lineEditList.at(this->queue->getTail() + 1);
        this->queue->enqueue(currentItem);
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
        ui->itemToBeEnqueue->setText(this->queue->dequeue()->text());
        ui->headLabel->move(
                    this->lineEditList.at(
                        this->queue->getHead())->x(),
                        ui->headLabel->y());
        qDebug() << "Current size is = " << this->queue->size();
        if(this->isShiftingMode) {
            qDebug() << "In shifting mode!";
            for (int i = 0; i < this->queue->size(); i++) {
                QLineEdit* lineEdit = this->lineEditList.at(i);
                QLineEdit* nextLineEdit = this->lineEditList.at(i + 1);
                qDebug() << "Change " << lineEdit->text()
                         << " to " << nextLineEdit->text();
                lineEdit->setText(nextLineEdit->text());

            }
        }
    } else {
        showMessage("Queue kosong");
    }

}
