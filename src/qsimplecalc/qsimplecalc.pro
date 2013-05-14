#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T13:18:28
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = QSimpleCalc
TEMPLATE = app
SOURCES += main.cpp

QSIMPLECALC_PATH = .
include(frontend/frontend.pri)
include(backend/backend.pri)
include(mathlib/mathlib.pri)

