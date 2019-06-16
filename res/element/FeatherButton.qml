import QtQuick 2.0
import QtQuick.Controls.Material 2.1

import "../element" as Elements

Item {
    id: button

    property bool checked: false
    property color color: Material.primary
    property color hoverColor: Qt.darker(Material.primary, 1.5)
    property color pressColor: Qt.darker(Material.primary, 2)
    property int iconCode: 0
    property string text: ""

    width: 60
    height: 60
    onEnabledChanged: state = ""
    signal clicked

    // Text and its color
    Elements.Feather {
        id: textIcon
        color: button.enabled ? button.color : "grey"
        icon: iconCode
        minimumPointSize: 10
        font.pointSize: 100
        fontSizeMode: Text.Fit
        anchors.centerIn: parent
        width: button.width
        height: button.height
    }
    Text {
        id: buttonText
        text: text
        color: button.enabled ? button.color : "grey"
        font.pointSize: 15
        anchors.top: textIcon.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: textIcon.Center
        width: button.width
        height: button.height
    }

    //change the color of the button in differen button states
    states: [
        State {
            name: "Hovering"
            PropertyChanges {
                target: button
                color: hoverColor
            }
        },
        State {
            name: "Pressed"
            PropertyChanges {
                target: button
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
