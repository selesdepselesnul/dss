#ifndef QUEUEWINDOW_H
#define QUEUEWINDOW_H

#include <QWidget>
#include <QList>
#include <QLineEdit>
#include <QString>
#include <QPoint>
#include "util/queue.h"

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
    void onDequeueButtonClicked();
private:
    Ui::QueueWindow *ui;
    QList<QLineEdit*> lineEditList;
    Queue<QString>* queue;
    QPoint initHeadPos;
    QPoint initTailPos;
    bool isShiftingMode;
    void showMessage(QString message);
};

#endif // QUEUEWINDOW_H
