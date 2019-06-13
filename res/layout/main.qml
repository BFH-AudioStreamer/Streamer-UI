import QtQuick 2.11
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import bfh.audio_streamer.model 1.0
import bfh.audio_streamer.controller 1.0

import "../element/" as Elements

ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: "Streamer UI"
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
                    wrapMode: Text.WordWrap
                    text: model.track_info.title
                    font.pointSize: 26
                    Layout.fillWidth: true
                }
                Label {
                    objectName: "artist"
                    Layout.fillWidth: true
                    wrapMode: Text.WordWrap
                    text: model.track_info.artist
                    font.pointSize: 18
                    color: Material.accent
                }

                // fill space
                Item {
                    Layout.fillHeight: true
                }

                RowLayout {
                    spacing: 20
                    Layout.alignment: Qt.AlignVCenter
                    Layout.margins: 20

                    Item {
                        Layout.fillWidth: true
                    }

                    Elements.ImageButton {
                        iconSource: "/img/skip-back.svg"
                        onClicked: controller.play_next()
                    }
                    Elements.ImageButton {
                        iconSource: "/img/play.svg"
                        onClicked: controller.play_next()
                    }
                    Elements.ImageButton {
                        iconSource: "/img/skip-forward.svg"
                        onClicked: controller.play_next()
                    }

                    Item {
                        Layout.fillWidth: true
                    }
                }

                Elements.ProgressBar {
                    Layout.fillWidth: true
                    Layout.minimumWidth: 300
                    //value: player_state.time_elapsed / player_state.time_elapsed
                    value: 0.5
                }

                RowLayout {
                    Label {
                        text: "00:00"
                        color: Material.accent
                    }
                    Item {
                        Layout.fillWidth: true
                    }
                    Label {
                        text: "00:00"
                         color: Material.accent
                    }
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
                    Layout.minimumWidth: 200
                    Layout.maximumHeight: 400
                    Layout.preferredHeight: 400
                }
            }
        }
    }
}
