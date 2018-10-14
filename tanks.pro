TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = $$PWD/bin

SOURCES += \
        src/main.cpp \
    src/player.cpp \
    src/entity.cpp \
    src/input.cpp \
    src/spritesheet.cpp \
    src/entitylist.cpp \
    src/collision.cpp

unix:!macx: LIBS += -lsfml-system -lsfml-window -lsfml-graphics

debug {
  DEFINES += QT_DEBUG
}
release {
  DEFINES += QT_RELEASE
}

HEADERS += \
    src/player.h \
    src/defines.h \
    src/entity.h \
    src/input.h \
    src/spritesheet.h \
    src/entitylist.h \
    src/collision.h

DISTFILES += \
    README.md
