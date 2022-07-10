#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T16:53:19
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomPlot
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    qcustomplot.cpp \
    DuPlot.cpp \
    calculator.cpp \
    in_to_post.cpp \
    operar.cpp

HEADERS  += Widget.h \
    qcustomplot.h \
    DuPlot.h \
    calculator.h \
    in_to_post.h \
    operar.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14
