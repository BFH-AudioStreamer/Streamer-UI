import QtQuick 2.11
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

import "./" as Views

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 480
    title: "Streamer UI"

    StackView {
        id: stackView
        property int margin: 20
        anchors.leftMargin: margin
        anchors.rightMargin: margin
        anchors.topMargin: margin
        anchors.bottomMargin: margin
        anchors.fill: parent

        initialItem: Views.Menu {}
    }
}
