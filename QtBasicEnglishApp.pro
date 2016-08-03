TEMPLATE = app

QT += qml quick widgets
QT += network
QT += core

CONFIG += c++11

SOURCES += main.cpp \
        enetwork.cpp \
    eanswer.cpp \
    equestion.cpp \
    eui.cpp \
    etextwork.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    enetwork.h \
    eanswer.h \
    equestion.h \
    eui.h \
    etextwork.h

DISTFILES += \
    node.html \
    data.html
