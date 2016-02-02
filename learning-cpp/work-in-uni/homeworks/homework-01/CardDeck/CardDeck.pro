TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Card.cpp \
    Deck.cpp \
    Player.cpp \
    Color.cpp

HEADERS += \
    Card.h \
    Deck.h \
    Player.h \
    Color.h
