#include "queuewindow.h"
#include "ui_queuewindow.h"

QueueWindow::QueueWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueueWindow)
{
    ui->setupUi(this);
}

QueueWindow::~QueueWindow()
{
    delete ui;
}
