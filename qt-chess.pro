##
#
# Qt Chess game
#
##

TEMPLATE    = app
CONFIG     += c++11
QT         += qml quick widgets svg

INCLUDEPATH += . src/ qml/

SOURCES    += \
        src/chess.cpp \
        src/gameengine.cc \
        src/figureintf.cc \
        src/figureking.cc

HEADERS    += \
        src/gameengine.hpp \
        src/figureintf.hpp \
        src/figureking.hpp


LIBS       +=
RESOURCES  += resouces.qrc


# Default rules for deployment.
include(deployment.pri)
