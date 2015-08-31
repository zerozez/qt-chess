import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

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

        state: "init"

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
            }

            Button {
                id: button2
                x: 243
                y: 93

               GameFDialog {
                   id: dialog
               }

               GameFDialog {
                   id: saveDialog
                   title: "Save as"
               }
            }

            Button {
                id: button3
                text: "prev"
                enabled: false
            }

            Button {
                id: button4
                text: "next"
                enabled: false
            }

            Button {
                id: button5
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

        states: [
            State {
                name: "init"
                PropertyChanges {
                    target: button1

                    text: "Start"
                    onClicked: {
                        console.log("Setup board figures ")
                        GameEngine.setupBoard()
                        columnLayout1.state = "game"
                    }
                }
                PropertyChanges {
                    target: button2
                    text: "Load"

                    onClicked: {
                        console.log("Clicked load button")
                        dialog.visible = true

                    }
                }
            },
            State {
                name: "game"

                PropertyChanges {
                    target: button1

                    text: "Stop"
                    onClicked: {
                        console.log("Stop game")
                        GameEngine.clean()
                        columnLayout1.state = "init"
                    }
                }
                PropertyChanges {
                    target: button2
                    text: "Save"

                    onClicked: {
                        console.log("save button")
                        GameEngine.save("")
                        saveDialog.visible = true
                    }
                }
                PropertyChanges {
                    target: button3
                    enabled: false
                }
                PropertyChanges {
                    target: button4
                    enabled: false
                }
            },
            State {
                name: "watch"
                PropertyChanges {
                    target: button3
                    enabled: true
                }
                PropertyChanges {
                    target: button4
                    enabled: true
                }
            }
        ]
    }
}

