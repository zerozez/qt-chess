/**
 * History.qml
 *
 * Moves history. Can be used to watch a game
 *
 *
 * @author Petr Orlov <zfmeze@gmail.com>
 * @date 22.08.2018
 */

import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

ListView {
    id: historyNavigation

    anchors.fill: parent

    delegate: Rectangle{
        id: row

        Text {
            id: number
            text: historyNavigation.model.Number
        }
        Text {
            id: moveW
            text: historyNavigation.model.RecordW
        }
        Text {
            id: moveB
            text: historyNavigation.model.RecordB
        }
    }
}


