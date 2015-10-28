#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle(
                QApplication::translate("toplevel", "Stack Simulation"));

    return a.exec();
}
