#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>

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
//    void on_pushButton_clicked();
//    void on_popButton_clicked();
    void onPushButtonClicked();
    void onPopButtonClicked();
private:
    static const int MAX_SIZE = 10;
    void showDialog(std::string message);
    Ui::MainWindow *ui;
    std::stack<std::string> itemStack;
    void pushToLineEdit();
};

#endif // MAINWINDOW_H
