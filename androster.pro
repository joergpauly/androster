#-------------------------------------------------
#
# Project created by QtCreator 2016-01-06T13:04:33
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = androster
TEMPLATE = app


SOURCES += main.cpp\
        cmainwindow.cpp \
    cdownloader.cpp \
    cdatabasemanager.cpp \
    cpersonal.cpp \
    cdutytype.cpp \
    cduty.cpp \
    cpersonallist.cpp \
    cpersonchoice.cpp

HEADERS  += cmainwindow.h \
    cdownloader.h \
    cdatabasemanager.h \
    cpersonal.h \
    cdutytype.h \
    cduty.h \
    cpersonallist.h \
    cpersonchoice.h

FORMS    += cmainwindow.ui \
    cpersonchoice.ui

CONFIG += mobility
MOBILITY = 

