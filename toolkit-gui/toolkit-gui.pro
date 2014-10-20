#-------------------------------------------------
#
# Project created by QtCreator 2014-02-09T11:48:41
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = toolkit-gui
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../toolkit/release/ -ltoolkit
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../toolkit/debug/ -ltoolkit
else:unix: LIBS += -L$$OUT_PWD/../toolkit/ -ltoolkit

INCLUDEPATH += $$PWD/../toolkit
DEPENDPATH += $$PWD/../toolkit

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../toolkit/release/libtoolkit.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../toolkit/debug/libtoolkit.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../toolkit/release/toolkit.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../toolkit/debug/toolkit.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../toolkit/libtoolkit.a
