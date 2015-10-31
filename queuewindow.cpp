#include "queuewindow.h"
#include "ui_queuewindow.h"
#include <QDebug>
#include <QStringListModel>
#include <QStringList>
#include <iostream>
#include <QMessageBox>
#include <QComboBox>

QueueWindow::QueueWindow() :
    ui(new Ui::QueueWindow)
{
    ui->setupUi(this);
    this->lineEditList << ui->item0 << ui->item1 << ui->item2 << ui->item3
                       << ui->item4 << ui->item5 << ui->item6 << ui->item7
                       << ui->item8 << ui->item9;

    connect(ui->enqueueButton, &QPushButton::clicked,
            this, &QueueWindow::onEnqueueButtonClicked);

    connect(ui->dequeueButton, &QPushButton::clicked,
            this, &QueueWindow::onDequeueButtonClicked);


    this->queue = new SimpleQueue<QString>(10);
    currentMode = "Simple";
    this->headCounter = 0;
    this->tailCounter = -1;

    QStringListModel *stringListModel = new QStringListModel();
    QStringList stringList;
    stringList << "Simple" << "Reset" << "Shifting" << "Circular";
    stringListModel->setStringList(stringList);

    ui->modeComboBox->setModel(stringListModel);

    connect(ui->modeComboBox,static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),
            [&](const QString &text){
        clearState();
        if(text == "Simple") {
            this->queue = new SimpleQueue<QString>(10);
        } else if(text == "Reset") {
            this->queue = new ResetQueue<QString>(10);
            currentMode = "Reset";
        }
    });

    this->headInitPos = ui->headLabel->pos();
    this->tailInitPos = ui->tailLabel->pos();
}

void QueueWindow::onEnqueueButtonClicked() {
    qDebug() << "curent size is = " << this->queue->getSize();
    if(!this->queue->isFull()) {
        auto currentItem = this->lineEditList.at(++this->tailCounter);
        currentItem->setText(ui->itemToBeEnqueue->text());
        ui->tailLabel->move(currentItem->x(), ui->tailLabel->y());
        this->queue->enqueue(ui->itemToBeEnqueue->text());
    } else {
        showMessage("Queue penuh");
    }
}

void QueueWindow::showMessage(QString message) {
    QMessageBox::information(this, "Tidak valid", message);
}

void QueueWindow::onDequeueButtonClicked() {
    if(!this->queue->isEmpty()) {
        ui->headLabel->move(
                    this->lineEditList.at(
                        this->headCounter++)->x(),
                        ui->headLabel->y());
        ui->itemToBeEnqueue->setText(this->queue->dequeue());
    } else {
        if(currentMode == "Reset") clearState();
        showMessage("Queue kosong");
    }

}



void QueueWindow::clearState() {
    ui->headLabel->move(this->headInitPos);
    ui->tailLabel->move(this->tailInitPos);
    this->headCounter = 0;
    this->tailCounter = -1;
}
