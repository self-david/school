TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    list.cpp \
    songs.cpp \
	menu.cpp

HEADERS += \
    list.h \
    songs.h \
	menu.h \
    cursor.h
