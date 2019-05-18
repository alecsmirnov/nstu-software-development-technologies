#-------------------------------------------------
#
# Project created by QtCreator 2019-02-14T16:42:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Converter
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
InterfaceWindow.cpp \
main.cpp \
    BaseConverter.cpp \
    Control.cpp \
    DecToPConverter.cpp \
    Editor.cpp \
    History.cpp \
    PToDecConverter.cpp \
    HelpWindow.cpp \
    HistoryWindow.cpp

HEADERS += \
    BaseConverter.h \
    Control.h \
    DecToPConverter.h \
    Editor.h \
    History.h \
    InterfaceWindow.h \
    PToDecConverter.h \
    HelpWindow.h \
    HistoryWindow.h

FORMS += \
    HelpWindow.ui \
    HistoryWindow.ui \
    InterfaceWindow.ui
