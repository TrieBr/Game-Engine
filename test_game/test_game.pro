QT       += opengl multimedia
TEMPLATE = app

CONFIG += c++11

HEADERS += \
    testScene.h \
    testEntity.h
SOURCES += \
    main.cpp \
    testScene.cpp \
    testEntity.cpp

TARGET = test_game


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../engine/release/ -lengine -lOpengl32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../engine/debug/ -lengine -lOpengl32
else:unix: LIBS += -L$$OUT_PWD/../engine/ -lengine

INCLUDEPATH += $$PWD/../engine
DEPENDPATH += $$PWD/../engine


QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2

QMAKE_CXXFLAGS_RELEASE *= -O2

RESOURCES += \
    assets.qrc
