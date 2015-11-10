/**
 * author : Moch Deden (https://github.com/selesdepselesnul)
 */
#include "controller/queuewindow.h"
#include "ui_queuewindow.h"
#include <QDebug>
#include <QStringListModel>
#include <QStringList>
#include <iostream>
#include <QMessageBox>
#include <QComboBox>
#include <algorithm>
#include <QRegExp>

void QueueWindow::moveFlagToInit() {
    ui->headLabel->move(this->initHeadPos);
    ui->tailLabel->move(this->initTailPos);
}

void QueueWindow::makeQueueBasedOn(const auto choice) {

    this->isShiftingMode = false;
    if(choice == "Basic") {
        this->queue = new Queue<QString>(10);
    } else if(choice == "Reset") {
        this->queue = new ResetQueue<QString>(10);
    } else if(choice == "Shifting") {
        this->queue = new ShiftingQueue<QString>(10);
        this->isShiftingMode = true;
    } else {
        this->queue = new CircularQueue<QString>(10);
    }

}


void QueueWindow::connectOnSelectedModeComboBox() {

    connect(ui->modeComboBox,static_cast<void(QComboBox::*)
            (const QString &)>(&QComboBox::activated),
            [&](const QString &choice){

        makeQueueBasedOn(choice);

        std::for_each(this->lineEditList.begin(), this->lineEditList.end(),
              [](QLineEdit *x) {
            x->setStyleSheet("background-color: black");
        });

        moveFlagToInit();

        std::for_each(this->lineEditList.begin(), this->lineEditList.end(),
                      [](QLineEdit *x) {
            x->clear();
        });

    });

}

QueueWindow::QueueWindow() :
    ui(new Ui::QueueWindow) {

    ui->setupUi(this);
    this->lineEditList << ui->item0 << ui->item1 << ui->item2 << ui->item3
                       << ui->item4 << ui->item5 << ui->item6 << ui->item7
                       << ui->item8 << ui->item9;

    const auto stringListModel = new QStringListModel();
    QStringList stringList;
    stringList << "Basic" << "Reset" << "Shifting" << "Circular";
    stringListModel->setStringList(stringList);
    ui->modeComboBox->setModel(stringListModel);

    connect(ui->enqueueButton, &QPushButton::clicked,
            this, &QueueWindow::onEnqueueButtonClicked);

    connect(ui->dequeueButton, &QPushButton::clicked,
            this, &QueueWindow::onDequeueButtonClicked);

    connectOnSelectedModeComboBox();

    this->initHeadPos = ui->headLabel->pos();
    this->initTailPos = ui->tailLabel->pos();

    this->isShiftingMode = false;

    this->queue = new Queue<QString>(10);

}

void QueueWindow::tryToEnqueueItem() {
    const auto item = ui->itemToBeEnqueue->text();
    const auto regXp = new QRegExp("\\d+");
    if (regXp->exactMatch(item)) {
        this->queue->enqueue(item);

        const auto currentItem = this->lineEditList.at(this->queue->getTail() - 1);
        currentItem->setStyleSheet("background-color: green");
        currentItem ->setText(ui->itemToBeEnqueue->text());

        if(this->queue->getTail() == this->lineEditList.length()) {
            ui->tailLabel->move(ui->enqueueButton->x(), ui->tailLabel->y());
        } else {

            const auto tailItem = this->lineEditList.at(this->queue->getTail());
            ui->tailLabel->move(tailItem ->x(), ui->tailLabel->y());
        }

        ui->queueSizeLcdNumber->display(this->queue->size());
    } else {
        showMessage("Masukan hanya integer !");
    }
}

void QueueWindow::onEnqueueButtonClicked() {
    if(!this->queue->isFull())
        tryToEnqueueItem();
    else
        showMessage("Queue penuh");
    ui->itemToBeEnqueue->clear();
}

void QueueWindow::showMessage(QString message) {
    QMessageBox::information(this, "Tidak valid", message);
}

void QueueWindow::shiftVisualQueue() {
    for (int i = 0; i < this->queue->size() - 1; i++) {
        auto lineEdit = this->lineEditList.at(i);
        auto nextLineEdit = this->lineEditList.at(i + 1);
        lineEdit->setText(nextLineEdit->text());
    }
}

void QueueWindow::checkIfShiftingQueue() {
    const auto queuedLineEdit = this->lineEditList.at(this->queue->getHead());
    if(this->isShiftingMode) {
        shiftVisualQueue();
        const auto item = this->lineEditList.at(this->queue->getTail() - 1);
        item->setStyleSheet("background-color: red");
        ui->tailLabel->move(item->x(), ui->tailLabel->y());
    } else {
        queuedLineEdit->setStyleSheet("background-color: red");
    }
}

void QueueWindow::onDequeueButtonClicked() {
    if(!this->queue->isEmpty()) {
        checkIfShiftingQueue();
        const auto item = this->queue->dequeue();
        ui->dequeuedItemLcdNumber->display(item);
        if(this->queue->getHead() == this->lineEditList.length())
            ui->headLabel->move(ui->enqueueButton->x(), ui->headLabel->y());
        else
            ui->headLabel->move(
                        this->lineEditList.at(
                            this->queue->getHead())->x(),
                        ui->headLabel->y());
        ui->queueSizeLcdNumber->display(this->queue->size());
    } else {
        showMessage("Queue kosong");
    }
}
