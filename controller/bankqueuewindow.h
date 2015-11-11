/**
 * author : Moch Deden (https://github.com/selesdepselesnul/)
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QLineEdit>
#include <QPushButton>
#include "util/queue.h"
namespace Ui {
class BankQueueWindow;
}

class BankQueueWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BankQueueWindow();
private slots:
    void onGetQueueNumberButtonClicked();
    void onSeeingLogButtonClicked();
private:
    Ui::BankQueueWindow *ui;
    int queueNumber;
    QList<QLineEdit*> lineEditList;
    CircularQueue<qint32> *circularQueue;
    void showMessage(QString message);
    void onDequeue(QPushButton *tellerButton, qint32 tellerNumber);
};

#endif // MAINWINDOW_H
