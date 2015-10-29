#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QMessageBox>
#include <string>
#include <QString>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

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
        switch (this->itemStack.size()) {
            case 0:
            ui->item0->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item1->y());
            break;
            case 1:
            ui->item1->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item2->y());
            break;
            case 2:
            ui->item2->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item3->y());
            break;
            case 3:
            ui->item3->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item4->y());
            break;
            case 4:
            ui->item4->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item5->y());
            break;
            case 5:
            ui->item5->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item6->y());
            break;
            case 6:
            ui->item6->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item7->y());
            break;
            case 7:
            ui->item7->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item8->y());
            break;
            case 8:
            ui->item8->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->item9->y());
            break;
            case 9:
            ui->item9->setText(item);
            ui->topLabel->move(ui->topLabel->x(),
                   ui->popButton->y());
            break;
            default:
            break;
        }
       this->itemStack.push(ui->itemToPushedLineEdit->text().toStdString());
    } else {
        showDialog("item tidak boleh kosong !");
    }
}

void MainWindow::onPushButtonClicked() {
    if(this->itemStack.size() != MainWindow::MAX_SIZE) {
        pushToLineEdit();
    } else {
        showDialog("item penuh !");
    }
    ui->itemToPushedLineEdit->clear();
}

void MainWindow::showDialog(std::string message) {
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(message));
    msgBox.exec();
}

void MainWindow::onPopButtonClicked() {
      if(this->itemStack.size() != 0) {
        switch (this->itemStack.size()) {
        case 10:
            ui->topLabel->move(ui->topLabel->x(), ui->item9->y());
            break;
        case 9:
            ui->topLabel->move(ui->topLabel->x(), ui->item8->y());
            break;
        case 8:
            ui->topLabel->move(ui->topLabel->x(), ui->item7->y());
            break;
        case 7:
            ui->topLabel->move(ui->topLabel->x(), ui->item6->y());
            break;
        case 6:
            ui->topLabel->move(ui->topLabel->x(), ui->item5->y());
            break;
        case 5:
            ui->topLabel->move(ui->topLabel->x(), ui->item4->y());
            break;
        case 4:
            ui->topLabel->move(ui->topLabel->x(), ui->item3->y());
            break;
        case 3:
            ui->topLabel->move(ui->topLabel->x(), ui->item2->y());
            break;
        case 2:
            ui->topLabel->move(ui->topLabel->x(), ui->item1->y());
            break;
        case 1:
            ui->topLabel->move(ui->topLabel->x(), ui->item0->y());
            break;
        default:
            break;
        }
        ui->itemToPushedLineEdit->setText(
                    QString::fromStdString(this->itemStack.top().c_str()));
        this->itemStack.pop();
      } else {
        showDialog("item kosong !");
    }
}
