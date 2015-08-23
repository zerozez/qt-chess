import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2


ApplicationWindow {
    title: "Qt Chess"
    width: 640
    height: 480
    visible: true

    statusBar: StatusBar {
        RowLayout {
            Label { text: "Status bar here"}
        }
    }

    RowLayout{
        anchors.fill: parent
        spacing: 2

        Board {
            id: board1
            Layout.fillHeight: true
            Layout.fillWidth: true

            anchors.topMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 5
        }

//        History {
//            id: history1
//            Layout.minimumWidth: 200
//            Layout.fillHeight: true
//        }
    }


}

