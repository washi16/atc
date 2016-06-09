#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T17:59:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hokuyo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hokuyo_class/hokuyo.cpp \
    dados/dados.cpp \
    ponto/ponto.cpp

HEADERS  += \
    hokuyo_class/hokuyo.h \
    dados/dados.h \
    ponto/ponto.h \
    mainwindow.h

FORMS    += mainwindow.ui

###########Bibliotecas para Lidar#####################

LIBS += -lurg -lurg_system -lurg_common -lurg_connection -lurg_coordinate -lurg_geometry -lurg_monitor

######################################################
