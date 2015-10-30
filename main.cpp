#include "stackwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto *mainWindow = new QWidget();

    auto stackWindowPushButton = new QPushButton();
    stackWindowPushButton->setText("Stack Simulation");

    auto queueWindowPushButton = new QPushButton();
    queueWindowPushButton->setText("Queue Simulation");

    auto vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(stackWindowPushButton);
    vBoxLayout->addWidget(queueWindowPushButton);

    QObject::connect(stackWindowPushButton, &QPushButton::clicked,
                     []() {
        auto stackWindow = new StackWindow();
        stackWindow->show();
    });

    mainWindow->setLayout(vBoxLayout);
    mainWindow->setWindowTitle("DSS");
    mainWindow->setFixedHeight(300);
    mainWindow->setFixedWidth(300);
    mainWindow->setWindowModality(Qt::WindowModal);
    mainWindow->show();

    return a.exec();
}
