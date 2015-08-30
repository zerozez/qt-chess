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
        src/figureking.cc \
    src/chessmodel.cc \
    src/movepoints.cc \
    src/movevectors.cc

HEADERS    += \
        src/gameengine.hpp \
        src/figureintf.hpp \
        src/figureking.hpp \
    src/chessmodel.hpp \
    src/movepoints.hpp \
    src/movevectors.hpp


LIBS       +=
RESOURCES  += resouces.qrc


# Default rules for deployment.
include(deployment.pri)
