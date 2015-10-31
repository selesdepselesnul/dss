#-------------------------------------------------
#
# Project created by QtCreator 2015-10-28T16:25:20
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = data_structure_simulation
TEMPLATE = app


SOURCES += main.cpp \
    stackwindow.cpp \
    queuewindow.cpp

HEADERS  += \
    stack.h \
    stackwindow.h \
    queuewindow.h \
    queue.h

FORMS    += \
    stackwindow.ui \
    queuewindow.ui
