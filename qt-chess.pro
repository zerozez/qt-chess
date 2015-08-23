##
#
# Qt Chess game
#
##

TEMPLATE = app

QT += qml quick widgets svg

SOURCES += \
    src/chess.cpp \

HEADERS += \

LIBS+=
RESOURCES += resouces.qrc


# Default rules for deployment.
include(deployment.pri)
