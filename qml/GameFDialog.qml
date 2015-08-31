import QtQuick 2.0
import QtQuick.Dialogs 1.2


FileDialog {
    id: fileDialog
    title: "Please choose a file"
    nameFilters: [ "Game files (*.sav)", "All files (*)" ]
}
