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
        anchors.fill: parent

        Rectangle {
            height: 30
            Layout.fillWidth: true

            RowLayout {
                anchors.fill: parent

                ToolButton {
                    id: startButton
                    Layout.fillHeight: true

                    height: parent.height
                    width: height

                    text: "Start"

                    onClicked: {
                        console.log("Setup board figures " + parent.width)
                        GameEngine.setupBoard()
                    }
                }

                ToolButton {
                    id: loadButton
                    Layout.fillHeight: true

                    height: parent.height
                    width: height

                    text: "Load"

                    onClicked: {
                        console.log("Clicked load button")
                        GameEngine.load
                    }
                }

                ToolButton {
                    id: exitButton
                    Layout.fillHeight: true

                    height: parent.height
                    width: height

                    text: "Exit"

                    onClicked: Qt.quit()
                }
            }
        }

        Board {
            id: board1
            Layout.fillHeight: true
            Layout.fillWidth: true

            anchors.topMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 5


        }
        Component.onCompleted: {
            console.log("Loaded")
            board1.figures = GameEngine.figures()
        }

    }
}

