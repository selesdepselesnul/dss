#-------------------------------------------------
#
# Project created by QtCreator 2015-10-28T16:25:20
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = data_structure_simulation
TEMPLATE = app


SOURCES += main.cpp \
    controller/stackwindow.cpp \
    controller/queuewindow.cpp \

HEADERS  += \
    util/stack.h \
    util/queue.h \
    controller/stackwindow.h \
    controller/queuewindow.h

FORMS    += \
    ui/stackwindow.ui \
    ui/queuewindow.ui

RESOURCES += \
    dss_icon.qrc
