QT       += core gui

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
    ccar.cpp \
    cfinish.cpp \
    cfrog.cpp \
    cg_car.cpp \
    cg_finish.cpp \
    cg_frog.cpp \
    cg_lane.cpp \
    cg_log.cpp \
    cg_object.cpp \
    cgame.cpp \
    clane.cpp \
    clog.cpp \
    cmenu.cpp \
    cmoving_object.cpp \
    cobject.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ccar.h \
    cfinish.h \
    cfrog.h \
    cg_car.h \
    cg_finish.h \
    cg_frog.h \
    cg_lane.h \
    cg_log.h \
    cg_object.h \
    cgame.h \
    clane.h \
    clog.h \
    cmenu.h \
    cmoving_object.h \
    cobject.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:\Users\pmazu\Documents\SFML-2.5.0-sources\SFML-2.5.0\include
DEPENDPATH += C:\Users\pmazu\Documents\SFML-2.5.0-sources\SFML-2.5.0\include


LIBS += -LC:\Users\pmazu\Documents\SFML-2.5.0-sources\Frog_build\LIBS

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-system-d -lsfml-network-d -lsfml-main-d -lsfml-window-d -lsfml-graphics-d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-system -lsfml-network -lsfml-main -lsfml-window -lsfml-graphics
