import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import QtGraphicalEffects 1.0

import "../element/" as Elements

Page {
    id: trackInfo

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            spacing: 20

            ColumnLayout {
                Layout.fillWidth: true

                Elements.FeatherButton {
                    Layout.bottomMargin: 20
                    width: 50
                    height: 50
                    iconCode: Elements.Feather.Icons.ArrowLeftCircle
                    onClicked: trackInfo.StackView.view.pop()
                }

                Label {
                    objectName: "song_title"
                    wrapMode: Text.WordWrap
                    text: model.track_info.title
                    font.pointSize: 26
                    Layout.fillWidth: true
                    color: Material.primary
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
                    spacing: 30
                    Layout.alignment: Qt.AlignVCenter
                    Layout.margins: 20

                    Item {
                        Layout.fillWidth: true
                    }

                    Elements.FeatherButton {
                        iconCode: Elements.Feather.Icons.SkipBack
                        onClicked: controller.play_previous()
                    }
                    Elements.FeatherButton {
                        iconCode: Elements.Feather.Icons.Pause
                        onClicked: controller.play_toggle_pause()
                    }

                    Elements.FeatherButton {
                        iconCode: Elements.Feather.Icons.SkipForward
                        onClicked: controller.play_next()
                    }

                    Item {
                        Layout.fillWidth: true
                    }
                }

                Elements.ProgressBar {
                    Layout.fillWidth: true
                    Layout.minimumWidth: 340
                    //value: player_state.time_elapsed / player_state.time_elapsed
                    value: 0.2
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
                Image {
                    id: cover
                    source: "/img/cd-icon.png"
                    fillMode: Image.PreserveAspectFit
                    Layout.fillWidth: true
                    Layout.minimumWidth: 200
                    Layout.fillHeight: true
                    Layout.minimumHeight: 200
                    Layout.maximumHeight: 800
                    verticalAlignment: Image.AlignBottom

                    layer.enabled: true
                        layer.effect: OpacityMask {
                            maskSource: Rectangle {
                                x: cover.x; y: cover.y
                                width: cover.width
                                height: cover.height
                                radius: 4
                            }
                        }
                }
            }
        }
    }
}
