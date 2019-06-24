import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.2

import "../element" as Elements
import "../model" as Model

Page {
    id: menu
    readonly property int itemSpacing: 10
    rightPadding: -2*itemSpacing

    GridView {
        id: gridView
        anchors.fill: parent
        cellWidth: width / 4
        cellHeight: width / 4


        model: Model.MenuSelection {}
        delegate: ItemDelegate {
            id: delegateItem
            width: parent.width / 4 - 2*itemSpacing
            height: parent.width / 4 - 2*itemSpacing

            onClicked: menu.StackView.view.push("../view/" + view + ".qml")

            // Display icon and text
            ColumnLayout {
                anchors.fill: parent

                Elements.Feather {
                    id: textIcon
                    icon: featherCode
                    color: "white"
                    font.pixelSize: 70
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 20
                }
                Label {
                    text: name
                    font.pixelSize: 20
                    Layout.alignment: Qt.AlignHCenter
                    Layout.bottomMargin: 10
                }
            }

            // Rounded rectangle, chaning color when mouse hovered
            background: Rectangle {
                anchors.fill: parent
                radius: 5
                color: delegateItem.pressed ? Qt.lighter(Material.background, 5) :
                                    delegateItem.hovered ?
                                              Qt.lighter(Material.background, 4) :
                                              Qt.lighter(Material.background, 3)
            }
        }
    }
}
