TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Labs2.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Labs2.h

