#-------------------------------------------------
#
# Project created by QtCreator 2015-03-07T15:29:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LabGame
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    player.cpp \
    spell.cpp \
    spellbutton.cpp \
    spelllabel.cpp \
    spelldesc.cpp

HEADERS  += widget.h \
    player.h \
    spell.h \
    spellbutton.h \
    spelllabel.h \
    spelldesc.h

FORMS    +=

RESOURCES += \
    sources.qrc

DISTFILES += \
    img/Огненный смерч.jpg \
    img/Огненный смерч-min.jpg
