import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import QtGraphicalEffects 1.0

import "../element/" as Elements

Page {
    id: trackInfo

    Item {
        Timer {
            id: model_update_timer
            interval: 100
            running: true
            repeat: true
            onTriggered: controller.update_model()
        }
    }

    function seconds_to_string(time) {
        var remainder = time % 60;
        var minutes = (time - remainder) / 60;
        var seconds_string = ""
        if (remainder < 10) {
            seconds_string = "0";
        }
        seconds_string += remainder;

        return minutes + ":" + seconds_string;
    }

    function clean_song_title(title) {
        // remove '(...)' and everything after ' - '
        return title.replace(/\(.*\)/gm, "").replace(/\s-\s.*/gm, "");
    }

    property int info_width: 340
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
                    iconCode: Elements.Feather.Icons.ChevronLeft
                    onClicked: {
                        model_update_timer.stop()
                        trackInfo.StackView.view.pop()
                    }
                }

                Label {
                    objectName: "song_title"
                    wrapMode: Text.WordWrap
                    text: clean_song_title(model.track_info.title)
                    font.pointSize: 26
                    Layout.fillWidth: true
                    color: Material.primary
                    Layout.maximumWidth: info_width
                }
                Label {
                    objectName: "artist"
                    Layout.fillWidth: true
                    wrapMode: Text.WordWrap
                    text: model.track_info.artist.replace(/;/g, " | ")
                    font.pointSize: 18
                    color: Material.accent
                    Layout.maximumWidth: info_width
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
                        iconCode: model.player_state.state == 2 ? Elements.Feather.Icons.Pause :
                                                                  Elements.Feather.Icons.Play
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
                    Layout.minimumWidth: info_width
                    value: model.player_state.time_elapsed_ms /
                           (model.player_state.time_total * 1000)
                }

                RowLayout {
                    Label {
                        text: seconds_to_string(model.player_state.time_elapsed)
                        color: Material.accent
                    }
                    Item {
                        Layout.fillWidth: true
                    }
                    Label {
                        text: seconds_to_string(model.player_state.time_total)
                        color: Material.accent
                    }
                }
            }

            ColumnLayout {
                Image {
                    id: cover
                    source: model.track_info.image_uri.replace("https", "http")
                    fillMode: Image.PreserveAspectFit
                    Layout.fillWidth: true
                    Layout.minimumWidth: 200
                    Layout.fillHeight: true
                    Layout.minimumHeight: 200
                    Layout.maximumHeight: 800
                    verticalAlignment: Image.AlignBottom

                    /*layer.enabled: true
                        layer.effect: OpacityMask {
                            maskSource: Rectangle {
                                x: cover.x; y: cover.y
                                width: cover.width
                                height: cover.height
                                radius: 4
                            }
                        }*/
                }
            }
        }
    }
}
