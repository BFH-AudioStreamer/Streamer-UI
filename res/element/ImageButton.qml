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

// Source: https://doc.qt.io/qt-5/qtquick-quick-accessibility-content-button-qml.html

import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtQuick.Controls.Material 2.1

Item {
    id: button

    property bool checked: false
    property color color: Material.primary
    property color hoverColor: Qt.darker(Material.primary, 1.5)
    property color pressColor: Qt.darker(Material.primary, 2)
    property string iconSource: ""

    width: 50
    height: 50
    onEnabledChanged: state = ""
    signal clicked

    // Icon and its color
    Image {
        id: icon
        source: iconSource
        fillMode: Image.PreserveAspectFit
        sourceSize.width: parent.width
        sourceSize.height: parent.height
        antialiasing: true

        ColorOverlay {
            id: iconOverlay
            anchors.fill: icon
            source: icon
            color: button.enabled ? button.color : "grey"
            transform: rotation
            antialiasing: true
        }
    }
    //ColorOverlay {
    //    id: iconOverlay
    //    anchors.fill: icon
    //    source: icon
    //    color: button.enabled ? button.color : "grey"
    //    transform: rotation
    //    antialiasing: true
    //}


    //change the color of the button in differen button states
    states: [
        State {
            name: "Hovering"
            PropertyChanges {
                target: iconOverlay
                color: hoverColor
            }
        },
        State {
            name: "Pressed"
            PropertyChanges {
                target: iconOverlay
                color: pressColor
            }
        }
    ]

    //define transmission for the states
    transitions: [
      Transition {
          from: ""; to: "Hovering"
          ColorAnimation { duration: 200 }
      },
      Transition {
          from: "*"; to: "Pressed"
          ColorAnimation { duration: 10 }
      }
    ]

    //Mouse area to react on click events
    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent
        onEntered: { button.state='Hovering'}
        onExited: { button.state=''}
        onClicked: { button.clicked();}
        onPressed: { button.state="Pressed" }
        onReleased: {
          if (containsMouse)
            button.state="Hovering";
          else
            button.state="";
        }
    }
}
