#-------------------------------------------------
#
# Project created by QtCreator 2013-05-15T11:40:49
#
#-------------------------------------------------

QT       += testlib
QT       -= gui
TARGET = TokenizerTest
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

SOURCES += \
    TokenizerTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

QSIMPLECALC_PATH = ../../qsimplecalc/
include($$QSIMPLECALC_PATH/mathlib/mathlib.pri)

INCLUDEPATH += $$QSIMPLECALC_PATH
