/**
 * Chess figure object
 *
 */
import QtQuick 2.0


Item {
    id: chessFigure

    property string ImagePath

    signal clicked()

    Image {
        id: figImage

        asynchronous: true  // we are loading svg
        source: ImagePath

        sourceSize.width: parent.width
        sourceSize.height: parent.height
    }

    onClicked: {
        // Inform about user interruct
        clicked()
    }
}

