#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stack.h"
#include <QList>
#include <QLineEdit>
#include <QWidget>

namespace Ui {
class StackWindow;
}

class StackWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StackWindow();
    ~StackWindow();

private slots:
    void onPushButtonClicked();
    void onPopButtonClicked();
private:
    void showDialog(std::string message);
    Ui::StackWindow *ui;
    QList<QLineEdit*> qLineEditList;
    Stack<std::string> *stringStack;
    void pushToLineEdit();
};

#endif // MAINWINDOW_H
