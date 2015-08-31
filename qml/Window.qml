import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

import com.znocpmp.chess 1.0

ApplicationWindow {
    title: "Title"
    width: 640
    height: 480
    visible: true

    ColumnLayout {
        id: columnLayout1
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        RowLayout {
            id: rowLayout1
            x: 311
            y: 56
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true

            Button {
                id: button1
                x: 145
                y: 93
                text: "Start"
                onClicked: {
                        console.log("Setup board figures ")
                        GameEngine.setupBoard()
                }

            }

            Button {
                id: button2
                x: 243
                y: 93
                text: "Load"
                onClicked: {
                    console.log("Clicked load button")
                    dialog.visible = true

                    GameEngine.load(dialog.fileUrl)
                }


               GameFDialog {
                   id: dialog
               }
            }

            Button {
                id: button3
                x: 345
                y: 93
                text: "exit"
                onClicked: Qt.quit()
            }
        }

        RowLayout {
            id: rowLayout2
            x: 333
            y: 222
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true


            Board {
                id: board1
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.fill: parent

                Layout.column: 0;
                onFigureClicked: GameEngine.itemClicked(x, y)
            }
        }

        Component.onCompleted: {
             console.log("Loaded")
             board1.figures = GameEngine.figures()
             //history1.model = GameEngine.history()
         }
    }
}

