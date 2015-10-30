#include "stackwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StackWindow mainWindow;
    mainWindow.show();
    mainWindow.setWindowTitle("Stack");

    return a.exec();
}
