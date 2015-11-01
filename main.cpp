#include "stackwindow.h"
#include "queuewindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

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
        stackWindow->setWindowTitle("STACK");
        stackWindow->show();
    });

    QObject::connect(queueWindowPushButton, &QPushButton::clicked,
                     []() {
        auto queueWindow = new QueueWindow();
        queueWindow->setWindowTitle("QUEUE");
        queueWindow->show();
    });


    mainWindow->setLayout(vBoxLayout);
    mainWindow->setWindowTitle("DSS");
    mainWindow->setFixedHeight(300);
    mainWindow->setFixedWidth(300);
    mainWindow->setWindowModality(Qt::WindowModal);
    mainWindow->show();

    return app.exec();
}
