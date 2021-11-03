QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    banzaibill.cpp \
    castle.cpp \
    character.cpp \
    coin.cpp \
    gameend.cpp \
    gamescene.cpp \
    groundbloc.cpp \
    main.cpp \
    mainwindow.cpp \
    score.cpp \
    song.cpp \
    warp.cpp

HEADERS += \
    banzaibill.h \
    castle.h \
    character.h \
    coin.h \
    gameend.h \
    gamescene.h \
    groundbloc.h \
    mainwindow.h \
    score.h \
    song.h \
    warp.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    secondProject_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/blocMario.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/castle.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/clock.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/coinMario.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/coinMario2.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/creditsMarioBg.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/creditsbg.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/gameOver3.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/leaderboardMarioBg.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/mario2_50fixe.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/mariobg.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/menuMarioBg.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/missile.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/pauseMarioBg.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/quitMarioBg.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/redMissile.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/settingsMarioBg.jpg \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/warp.png \
    ../build-secondProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/images/winMarioBg.jpg \
    images/7680x768.png \
    images/gamebg.jpg \
    images/mario.gif \
    images/mario2.gif \
    images/mario2_25.gif \
    images/mariobg.png \
    images/menubg.jpg \
    images/plane_green.png \
    images/quitbg.jpg \
    images/settingsbg.jpg

RESOURCES += \
    src.qrc

RC_FILE = icone.rc
