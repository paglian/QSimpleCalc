#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T15:29:22
#
#-------------------------------------------------

QT       += testlib
QT       -= gui
TARGET = BackendTest
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

SOURCES += BackendTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

QSIMPLECALC_PATH = ../../qsimplecalc/
include($$QSIMPLECALC_PATH/backend/backend.pri)
include($$QSIMPLECALC_PATH/mathlib/mathlib.pri)

INCLUDEPATH += $$QSIMPLECALC_PATH
