#-------------------------------------------------
#
# Project created by QtCreator 2019-04-27T20:47:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UniversalCalculator
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

CONFIG += c++11

SOURCES += \
        BaseConverter.cpp \
        ComplexEditor.cpp \
        ComplexNumber.cpp \
        DecToPConverter.cpp \
        FractionEditor.cpp \
        FractionNumber.cpp \
        HelpWindow.cpp \
        PEditor.cpp \
        PNumber.cpp \
        PToDecConverter.cpp \
        main.cpp \
        InterfaceWindow.cpp

HEADERS += \
        BaseConverter.h \
        ComplexEditor.h \
        ComplexNumber.h \
        Control.h \
        Control.hpp \
        DecToPConverter.h \
        Editor.h \
        FractionEditor.h \
        FractionNumber.h \
        HelpWindow.h \
        InterfaceWindow.h \
        Memory.h \
        Memory.hpp \
        PEditor.h \
        PNumber.h \
        PToDecConverter.h \
        Proc.h \
        Proc.hpp

FORMS += \
        HelpWindow.ui \
        InterfaceWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    UniversalCalculator.pro.user

RC_FILE += UniversalCalculator.rc
