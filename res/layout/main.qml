import QtQuick 2.11
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("MPD Client")
    property int margin: 40

    ColumnLayout {
        spacing: 10
        anchors.margins: margin
        anchors.fill: parent

        RowLayout {
            spacing: 20

            ColumnLayout {
                Layout.fillWidth: true

                Item {
                    Layout.preferredHeight: 30
                }
                Label {
                    objectName: "song_title"
                    Layout.fillWidth: true
                    Layout.preferredWidth: 300
                    wrapMode: Text.WordWrap
                    text: "Title"
                    font.pointSize: 26
                }
                Label {
                    objectName: "artist"
                    Layout.fillWidth: true
                    Layout.preferredWidth: 300
                    wrapMode: Text.WordWrap
                    text: "Artist"
                    font.pointSize: 18
                }

                // fill space
                Item {
                    Layout.fillHeight: true
                }

                RowLayout {
                    spacing: 5
                    Item {
                        Layout.fillWidth: true
                    }
                    Button {
                            text: "Previous"
                            Layout.preferredWidth: 90
                            font.capitalization: Font.MixedCase
                    }
                    Button {
                            text: "Play/Pause"
                            Layout.preferredWidth: 90
                            font.capitalization: Font.MixedCase
                    }
                    Button {
                            text: "Next"
                            Layout.preferredWidth: 90
                            font.capitalization: Font.MixedCase
                    }
                    Item {
                        Layout.fillWidth: true
                    }
                }
                ProgressBar {
                    Layout.fillWidth: true
                }
            }

            ColumnLayout {

                // fill space
                Item {
                    Layout.fillHeight: true
                }
                Image {
                    source: "/img/cd-icon.png"
                    fillMode: Image.PreserveAspectFit
                    Layout.fillWidth: true
                    Layout.maximumHeight: 400
                    Layout.preferredHeight: 400
                }
            }


        }
    }
}
