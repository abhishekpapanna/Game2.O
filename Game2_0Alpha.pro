QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bullet.cpp \
        enemy.cpp \
        main.cpp \
        olcPixelGameEngine.cpp \
        pixelgeinterface.cpp \
        player.cpp \
        unusedcode.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    bullet.h \
    enemy.h \
    engine/olcPixelGameEngine.h \
    pixelgeinterface.h \
    player.h

unix|win32: LIBS += -lGL

unix|win32: LIBS += -lX11

unix|win32: LIBS += -lpng

LIBS += -lstdc++fs
