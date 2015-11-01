#ifndef STACKWINDOW_H
#define STACKWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include "util/stack.h"

namespace Ui {
class StackWindow;
}

class StackWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StackWindow();
private slots:
    void onPushButtonClicked();
    void onPopButtonClicked();
private:
    void showDialog(QString message);
    Ui::StackWindow *ui;
    QList<QLineEdit*> qLineEditList;
    Stack<QString> *stringStack;
    void pushToLineEdit();
};

#endif // STACKWINDOW_H
