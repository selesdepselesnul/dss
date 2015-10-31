#include "queuewindow.h"
#include "ui_queuewindow.h"
#include <QDebug>
#include <QStringListModel>
#include <QStringList>
#include <iostream>

QueueWindow::QueueWindow() :
    ui(new Ui::QueueWindow)
{
    ui->setupUi(this);
    this->lineEditList << ui->item0 << ui->item1 << ui->item2 << ui->item3
                       << ui->item4 << ui->item5 << ui->item6 << ui->item7
                       << ui->item8 << ui->item9;

    connect(ui->enqueueButton, &QPushButton::clicked,
            this, &QueueWindow::onEnqueueButtonClicked);

    this->queue = new SimpleQueue<QString>(10);

    QStringListModel *stringListModel = new QStringListModel();
    QStringList stringList;
    stringList << "Simple" << "Reset" << "Shifting" << "Circular";
    stringListModel->setStringList(stringList);

    ui->modeComboBox->setModel(stringListModel);
}

void QueueWindow::onEnqueueButtonClicked() {
    switch (ui->modeComboBox->currentIndex()) {
    case 0:
        qDebug() << "Simple";
        break;
    case 1:
        qDebug() << "Reset";
        break;
    case 2:
        qDebug() << "Shifting";
        break;
    default:
        qDebug() << "Circular";
        break;
    }
    if(!this->queue->isFull()) {
    }
}
