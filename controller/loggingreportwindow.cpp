/**
 * author : Moch Deden (https://github.com/selesdepselesnul)
 */
#include "loggingreportwindow.h"
#include "ui_loggingreportwindow.h"
#include "model/teller.h"
#include <QFile>
#include <QDataStream>
#include <QIODevice>
#include <QDebug>
#include <QTextCursor>

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
        ui->loggingText->moveCursor (QTextCursor::End);
        ui->loggingText->insertPlainText ("No. teller = "
                                          + QString::number(teller.tellerNumber)
                                          + '\n');
        ui->loggingText->insertPlainText ("No. queue = "
                                          + QString::number(teller.queueNumber)
                                          + '\n');
        ui->loggingText->insertPlainText ("Tanggal log = " +
                  teller.servedDateTime.toLocalTime().toString()
                                          + "\n\n");
        ui->loggingText->moveCursor(QTextCursor::End);
    }
    file.close();
}

LoggingReportWindow::~LoggingReportWindow()
{
    delete ui;
}
