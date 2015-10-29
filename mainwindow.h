#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

private slots:
    void onPushButtonClicked();
    void onPopButtonClicked();
private:
    void showDialog(std::string message);
    Ui::MainWindow *ui;
    Stack<std::string> *stringStack;
    void pushToLineEdit();
};

#endif // MAINWINDOW_H
