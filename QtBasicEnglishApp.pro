TEMPLATE = app

QT += qml quick widgets
QT += network

CONFIG += c++11

SOURCES += main.cpp \
        equestion.cpp \
        eanswer.cpp \
        eui.cpp \
        enetwork.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
        equestion.h \
        eanswer.h \
        eui.h \
        enetwork.h
