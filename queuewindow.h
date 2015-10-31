#ifndef QUEUEWINDOW_H
#define QUEUEWINDOW_H

#include <QWidget>
#include <QList>
#include <QLineEdit>
#include <QString>
#include "queue.h"

namespace Ui {
class QueueWindow;
}

class QueueWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QueueWindow();

private slots:
    void onEnqueueButtonClicked();

private:
    Ui::QueueWindow *ui;
    QList<QLineEdit*> lineEditList;
    Queue<QString>* queue;
};

#endif // QUEUEWINDOW_H
