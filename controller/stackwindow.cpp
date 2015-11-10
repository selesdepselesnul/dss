/**
 * author : Moch Deden (https://github.com/selesdepselesnul)
 */
#include "stackwindow.h"
#include "ui_stackwindow.h"
#include <QLineEdit>
#include <QMessageBox>
#include <string>
#include <QString>
#include <QPushButton>
#include "util/stack.h"
#include <QList>
#include <QRegExp>

StackWindow::StackWindow() :
    ui(new Ui::StackWindow) {

    ui->setupUi(this);
    this->stack = new Stack<QString>(10);

    this->qLineEditList << ui->item0 << ui->item1 << ui->item2 << ui->item3
                        << ui->item4 << ui->item5 << ui->item6 << ui->item7
                        << ui->item8 << ui->item9;

    connect(ui->pushButton, &QPushButton::clicked,
            this, &StackWindow::onPushButtonClicked);
    connect(ui->popButton, &QPushButton::clicked,
            this, &StackWindow::onPopButtonClicked);
}

void StackWindow::pushToLineEdit() {
    const QString item = ui->itemToPushedLineEdit->text();
    const auto regXp = new QRegExp("\\d+");
    if(regXp->exactMatch(item)) {
        const int size = this->stack->size();
        auto item = this->qLineEditList.at(size);
        item->setText(ui->itemToPushedLineEdit->text());
        item->setStyleSheet("background-color: green");
        if(size < this->qLineEditList.size() - 1) {
            ui->topLabel->move(ui->topLabel->x(),
                               this->qLineEditList.at(size + 1)->y());
        } else {
            ui->topLabel->move(ui->topLabel->x(),
                               ui->popButton->y());
        }
        this->stack->push(ui->itemToPushedLineEdit->text());
        ui->stackSizeLcdNumber->display(this->stack->size());
    } else {
        showDialog("item harus integer !");
    }
}

void StackWindow::onPushButtonClicked() {
    if(this->stack->size() != this->stack->getLength()) {
        pushToLineEdit();
    } else {
        showDialog("Stack penuh!");
    }
    ui->itemToPushedLineEdit->clear();
}

void StackWindow::showDialog(QString message) {
    QMessageBox::information(this, "tidak valid", message);
}

void StackWindow::onPopButtonClicked() {
    const int size = this->stack->size();
    if(size != 0) {
        auto item = this->qLineEditList.at(size - 1);
        item->setStyleSheet("background-color: red");
        ui->topLabel->move(ui->topLabel->x(),
                           item->y());
        ui->popedItemLcdNumber->display(this->stack->peek());
        this->stack->pop();
        ui->stackSizeLcdNumber->display(this->stack->size());
    } else {
        showDialog("Stack kosong!");
    }
}
