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
private:
    Ui::BankQueueWindow *ui;
    int queueNumber;
    QList<QLineEdit*> lineEditList;
    CircularQueue<int> *circularQueue;
    void dequeue(int tellerNumber, QString color);
    void showMessage(QString message);
};

#endif // MAINWINDOW_H
