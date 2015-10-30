#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include <QList>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class StackWindow : public QMainWindow
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
    Ui::MainWindow *ui;
    QList<QLineEdit*> qLineEditList;
    Stack<std::string> *stringStack;
    void pushToLineEdit();
};

#endif // MAINWINDOW_H
