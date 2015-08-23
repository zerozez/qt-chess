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

Rectangle {
    id: historyNavigation

    ColumnLayout {
        id: mainLayout

        ListView {
            anchors.fill: parent
        }

        RowLayout {
            id: buttonLayout

            anchors.fill: parent
            spacing: 0
            Button {
                id: prev
                enabled: false

                Layout.fillWidth: true
                Layout.fillHeight: true

                text: "Prev"
            }

            Button {
                id: next
                enabled: true

                Layout.fillWidth: true
                Layout.fillHeight: true

                text: "Next"
            }
        }
    }
}


