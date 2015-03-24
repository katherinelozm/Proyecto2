#-------------------------------------------------
#
# Project created by QtCreator 2015-03-21T20:28:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    meal.cpp \
    drink.cpp \
    alcoholic.cpp \
    nonalcoholic.cpp \
    clients.cpp \
    addclient.cpp \
    client.cpp \
    coorporateclient.cpp \
    premiumclient.cpp \
    regularclient.cpp \
    bill.cpp \
    newbill.cpp \
    editclient.cpp \
    deleteclient.cpp \
    reports.cpp

HEADERS  += mainwindow.h \
    meal.h \
    drink.h \
    alcoholic.h \
    nonalcoholic.h \
    clients.h \
    addclient.h \
    client.h \
    coorporateclient.h \
    premiumclient.h \
    regularclient.h \
    bill.h \
    newbill.h \
    editclient.h \
    deleteclient.h \
    reports.h

FORMS    += mainwindow.ui \
    clients.ui \
    addclient.ui \
    newbill.ui \
    editclient.ui \
    deleteclient.ui \
    reports.ui

RESOURCES += \
    pictures.qrc

DISTFILES +=
