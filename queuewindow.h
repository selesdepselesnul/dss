#ifndef QUEUEWINDOW_H
#define QUEUEWINDOW_H

#include <QWidget>
#include <QList>
#include <QLineEdit>
#include <QString>
#include <QPoint>
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
    void onDequeueButtonClicked();
private:
    Ui::QueueWindow *ui;
    QList<QLineEdit*> lineEditList;
    Queue<QString>* queue;
    QPoint headInitPos;
    QPoint tailInitPos;
    QString currentMode;
    int headCounter;
    int tailCounter;
    void showMessage(QString message);
    void clearState();
};

#endif // QUEUEWINDOW_H
