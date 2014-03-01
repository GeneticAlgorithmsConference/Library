#-------------------------------------------------
#
# Project created by QtCreator 2014-02-16T17:57:46
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_FunctionSearcherWith
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../Sources/geneticsettings.cpp \
    ../../Sources/linearbinarydna.cpp \
    ../../Sources/linearrealdna.cpp \
    ../../Sources/minsearchindividual.cpp \
    ../../Sources/treeexpressiondna.cpp \
    ../../Sources/treeexpressionindividual.cpp \
    ../../Sources/parser.cpp

HEADERS  += mainwindow.h \
    ../../Sources/treeintegerdna.h \
    ../../Sources/treeindividual.h \
    ../../Sources/treeexpressiontexdna.h \
    ../../Sources/treeexpressionindividual.h \
    ../../Sources/treeexpressiondna.h \
    ../../Sources/testindividual.h \
    ../../Sources/population.h \
    ../../Sources/minsearchindividual.h \
    ../../Sources/log.h \
    ../../Sources/linearrealdna.h \
    ../../Sources/linearindividual.h \
    ../../Sources/linearbinarydna.h \
    ../../Sources/individual.h \
    ../../Sources/genetic.h \
    ../../Sources/generation.h \
    ../../Sources/dnatypes.h \
    ../../Sources/dna.h \
    ../../Sources/carindividual.h \
    ../../Sources/basetreedna.h \
    ../../Sources/baselineardna.h \
    ../../Sources/parser.h \
    ../../Sources/geneticsettings.h

FORMS    += mainwindow.ui
