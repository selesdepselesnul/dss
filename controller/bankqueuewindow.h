#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QLineEdit>
#include "queue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
private slots:
    void onGetQueueNumberButtonClicked();
private:
    Ui::MainWindow *ui;
    int queueNumber;
    QList<QLineEdit*> lineEditList;
    CircularQueue<int> *circularQueue;
};

#endif // MAINWINDOW_H
