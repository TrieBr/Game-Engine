#-------------------------------------------------
#
# Project created by QtCreator 2014-02-09T11:46:38
#
#-------------------------------------------------

QT       += xml

TARGET = toolkit
TEMPLATE = lib
CONFIG += staticlib

SOURCES += toolkit.cpp \
    SpritePackager.cpp \
    SpriteDefinition.cpp \
    Rectangle.cpp \
    Packer.cpp \
    SpriteCompiler.cpp \
    FileDataStream.cpp \
    AudioTranscoder.cpp

HEADERS += toolkit.h \
    SpritePackager.h \
    SpriteDefinition.h \
    Rectangle.h \
    Packer.h \
    SpriteCompiler.h \
    FileDataStream.h \
    AudioTranscoder.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
