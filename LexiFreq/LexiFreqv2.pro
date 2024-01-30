#-------------------------------------------------
#
# Project created by QtCreator 2024-01-24T05:35:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LexiFreqv2
TEMPLATE = app
CONFIG += C++11

SOURCES += main.cpp\
        widget.cpp \
    menu1.cpp \
    menu2.cpp \
    menu3.cpp \
    menu4.cpp \
    menu.cpp \
    binarytree.cpp \
    hashtableadd.cpp \
    hashtablechanied.cpp \
    linearlist.cpp \
    linkedlist.cpp \
    text.cpp

HEADERS  += widget.h \
    menu1.h \
    menu2.h \
    menu3.h \
    menu4.h \
    menu.h \
    binarytree.h \
    hashtableadd.h \
    hashtablechanied.h \
    linearlist.h \
    linkedlist.h \
    text.h

FORMS    += widget.ui \
    menu1.ui \
    menu2.ui \
    menu3.ui \
    menu4.ui \
    text.ui
