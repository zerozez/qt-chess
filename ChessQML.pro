QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/chess.cpp \
    src/chessmodel.cc \
    src/figurebishop.cc \
    src/figureintf.cc \
    src/figureking.cc \
    src/figureknight.cc \
    src/figurepawn.cc \
    src/figurequeen.cc \
    src/figurerook.cc \
    src/gameengine.cc \
    src/historymanager.cc \
    src/historymodel.cc \
    src/movepawn.cc \
    src/movepoints.cc \
    src/movevectors.cc

RESOURCES += qml.qrc \
    qml.qrc \
    resouces.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ChessQML.pro.user \
    README.md \
    main.qml \
    src/CMakeLists.txt

HEADERS += \
    src/chessmodel.hpp \
    src/figurebishop.hpp \
    src/figureintf.hpp \
    src/figureking.hpp \
    src/figureknight.hpp \
    src/figurepawn.hpp \
    src/figurequeen.hpp \
    src/figurerook.hpp \
    src/gameengine.hpp \
    src/historymanager.hpp \
    src/historymodel.hpp \
    src/movepawn.hpp \
    src/movepoints.hpp \
    src/movevectors.hpp
