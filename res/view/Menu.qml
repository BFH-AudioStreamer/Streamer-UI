/*
    Copyright (C) 2019 Audio-Streamer Project Group

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
 */

import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.2

import "../element" as Elements
import "../model" as Model

/*
    Main menu
 */
Page {
    id: menu
    readonly property int itemSpacing: 10
    rightPadding: -2*itemSpacing

    /* Display menu items on grid */
    GridView {
        id: gridView
        anchors.fill: parent
        cellWidth: width / 4
        cellHeight: width / 4


        model: Model.MenuSelection {}
        /* define look and behaviour of menu item */
        delegate: ItemDelegate {
            id: delegateItem
            width: parent.width / 4 - 2*itemSpacing
            height: parent.width / 4 - 2*itemSpacing

            onClicked: menu.StackView.view.push("../view/" + view + ".qml")

            /* Display icon and text */
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

            /* Rounded rectangle, chaning color when mouse hovered */
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
