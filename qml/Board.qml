/**
 * Board.qml
 *
 * Chess board object
 *
 *
 * @author Petr Orlov <zfmeze@gmail.com>
 * @date 22.08.2018
 */
import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2


Rectangle {
    id: gameField
    property var figures

    Grid {
        id: chessGrid
        rows: 8;
        columns: 8;
        spacing: 0

        anchors.fill: parent

        // ChessBoard
        Repeater {
            model: 8 * 8

            Rectangle {
                height: chessGrid.height / 8
                width: height

                color: {
                    var row = Math.floor(index / 8);
                    var column = index % 8
                    if ((row + column) % 2 == 1)
                        "#8B4513";
                    else
                        "#FFE4B5";
                }
            }
        }
    }

    GridView {
        id: chessFigures

        anchors.fill: parent

        model: gameField.figures

        delegate: Item {
                x: X - 1
                y: Y - 1
                Image {
                    source: image
                }
            }
    }
}

