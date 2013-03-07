#-------------------------------------------------
#
# Project created by QtCreator 2013-03-01T00:50:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectform.cpp \
    network.cpp \
    client.cpp \
    utils.cpp \
    readthread.cpp

HEADERS  += mainwindow.h \
    connectform.h \
    network.h \
    client.h \
    utils.h \
    readthread.h

FORMS    += mainwindow.ui \
    connectform.ui
