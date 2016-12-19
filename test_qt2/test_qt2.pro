#-------------------------------------------------
#
# Project created by QtCreator 2016-12-15T11:52:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_qt2
TEMPLATE = app
QMAKE_LFLAGS += -ggdb -ffunction-sections -fdata-sections -Wl,--gc-sections
QMAKE_CXXFLAGS += -std=c++1y

LIBS += -lssl
LIBS += -lcrypto

SOURCES += main.cpp\
		MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui
