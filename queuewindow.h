#ifndef QUEUEWINDOW_H
#define QUEUEWINDOW_H

#include <QWidget>

namespace Ui {
class QueueWindow;
}

class QueueWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QueueWindow(QWidget *parent = 0);
    ~QueueWindow();

private:
    Ui::QueueWindow *ui;
};

#endif // QUEUEWINDOW_H
