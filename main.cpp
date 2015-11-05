#include "controller/stackwindow.h"
#include "controller/queuewindow.h"
#include "controller/bankqueuewindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

void handleStackWindow(auto stackWindowPushButton) {
    QObject::connect(stackWindowPushButton, &QPushButton::clicked,
                     []() {
        auto stackWindow = new StackWindow();
        stackWindow->setWindowTitle("STACK");
        stackWindow->setWindowModality(Qt::ApplicationModal);
        stackWindow->setFixedSize(419, 429);
        stackWindow->show();
    });
}

void handleQueueWindow(auto queueWindowPushButton) {
    QObject::connect(queueWindowPushButton, &QPushButton::clicked,
                     []() {
        auto queueWindow = new QueueWindow();
        queueWindow->setWindowTitle("QUEUE");
        queueWindow->setWindowModality(Qt::ApplicationModal);
        queueWindow->setFixedSize(695, 373);
        queueWindow->show();
    });
}

void hadleBankQueueWindow(auto bankQueueWindowPushButton) {
    QObject::connect(bankQueueWindowPushButton, &QPushButton::clicked,
                     []() {
        auto bankQueueWindow = new BankQueueWindow();
        bankQueueWindow->setWindowTitle("Bank QUEUE -QUEUE in Action-");
        bankQueueWindow->setWindowModality(Qt::ApplicationModal);
        bankQueueWindow->setFixedSize(600, 346);
        bankQueueWindow->show();
    });
}


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto mainWindow = new QWidget();

    auto stackWindowPushButton = new QPushButton();
    stackWindowPushButton->setText("Stack Simulation");

    auto queueWindowPushButton = new QPushButton();
    queueWindowPushButton->setText("Queue Simulation");

    auto bankQueueWindowPushButton = new QPushButton();
    bankQueueWindowPushButton->setText("Bank Queue Simulation");

    auto vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(stackWindowPushButton);
    vBoxLayout->addWidget(queueWindowPushButton);
    vBoxLayout->addWidget(bankQueueWindowPushButton);

    handleStackWindow(stackWindowPushButton);

    handleQueueWindow(queueWindowPushButton);

    hadleBankQueueWindow(bankQueueWindowPushButton);

    mainWindow->setLayout(vBoxLayout);
    mainWindow->setWindowTitle("DSS");
    mainWindow->setFixedHeight(300);
    mainWindow->setFixedWidth(300);
    mainWindow->show();

    return app.exec();
}
