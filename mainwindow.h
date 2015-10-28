#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>
#include <QLineEdit>
#include <QStack>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    std::stack<std::string> itemStack;
    QStack<QLineEdit> widgetStack;

};

#endif // MAINWINDOW_H
