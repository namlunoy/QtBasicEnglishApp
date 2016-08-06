TEMPLATE = app

QT += qml quick widgets
QT += network
QT += core
QT +=sql

CONFIG += c++11

SOURCES += main.cpp \
        enetwork.cpp \
    eanswer.cpp \
    equestion.cpp \
    eui.cpp \
    etextwork.cpp \
        edatabase.cpp \
    eutils.cpp

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
    etextwork.h \
    edatabase.h \
    eutils.h

DISTFILES += \
    node.html \
    data.html
