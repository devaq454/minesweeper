#-------------------------------------------------
#
# Project created by QtCreator 2022-09-10T19:26:22
#
#-------------------------------------------------

QT       += core gui sql
QT += widgets

TARGET = Minesweeper
TEMPLATE = app


SOURCES += main.cpp\
    databasemanager.cpp \
        mainwindow.cpp \
    playwindow.cpp \
    settingswindow.cpp \
    qrightclickbutton.cpp \
    results.cpp

HEADERS  += mainwindow.h \
    databasemanager.h \
    playwindow.h \
    settingswindow.h \
    qrightclickbutton.h \
    results.h

FORMS    += mainwindow.ui \
    playwindow.ui \
    settingswindow.ui \
    results.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    icons/empty_cell.png
