#include "loggingreportwindow.h"
#include "ui_loggingreportwindow.h"
#include "model/teller.h"
#include <QFile>
#include <QDataStream>
#include <QIODevice>
#include <QDebug>

LoggingReportWindow::LoggingReportWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoggingReportWindow) {
    ui->setupUi(this);

    QFile file(Teller::LOG_FILE);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_5);

    while (!in.atEnd()) {
        auto teller = Teller();
        in >> teller;
        qDebug() << teller.tellerNumber << '\n' << teller.queueNumber << '\n'
               << teller.servedDateTime << '\n';
    }
    file.close();
}

LoggingReportWindow::~LoggingReportWindow()
{
    delete ui;
}
