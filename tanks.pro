TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = $$PWD/bin

SOURCES += \
        main.cpp \
    player.cpp \
    entity.cpp \
    input.cpp \
    spritesheet.cpp \
    entitylist.cpp \
    collision.cpp

unix:!macx: LIBS += -lsfml-system -lsfml-window -lsfml-graphics

debug {
  DEFINES += QT_DEBUG
}
release {
  DEFINES += QT_RELEASE
}

HEADERS += \
    player.h \
    defines.h \
    entity.h \
    input.h \
    spritesheet.h \
    entitylist.h \
    collision.h

DISTFILES += \
    README.md
