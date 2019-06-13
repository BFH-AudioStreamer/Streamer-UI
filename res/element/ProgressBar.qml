import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.1

ProgressBar {
    id: control
    value: 0.5

    property int barHeight: 5

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: barHeight
        color: Qt.darker(Material.primary, 2)
        radius: barHeight / 2
    }

    contentItem: Item {
        implicitWidth: 200
        implicitHeight: barHeight

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            radius: barHeight / 2
            color: Material.primary
        }
    }
}
