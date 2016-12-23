#-------------------------------------------------
#
# Project created by QtCreator 2016-12-21T16:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tankApp
TEMPLATE = app


SOURCES += main.cpp\
        Point.cpp

HEADERS  += Point.h

# Output
DESTDIR = target/bin
OBJECTS_DIR = target/bin
MOC_DIR = src/tankApp
