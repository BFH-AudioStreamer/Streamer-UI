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
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import QtGraphicalEffects 1.0

import "../element/" as Elements

/*
    Display info about currently played track
 */
Page {
    id: trackInfo

    /* Timer triggering the controller update process */
    Item {
        Timer {
            id: model_update_timer
            interval: 200
            running: true
            repeat: true
            onTriggered: controller.update_model()
        }
    }

    /* convert seconds (int) to string in "0:00" format */
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

    /* remove '(...)' and everything after ' - ' */
    function clean_song_title(title) {
        return title.replace(/\(.*\)/gm, "").replace(/\s-\s.*/gm, "");
    }

    property int info_width: 340
    ColumnLayout {
        anchors.fill: parent

        /* Row containig information and control elements */
        RowLayout {
            spacing: 20

            ColumnLayout {
                Layout.fillWidth: true

                /* Return to main menu */
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

                /* fill space */
                Item { Layout.fillHeight: true }

                /* Playback control elements */
                RowLayout {
                    spacing: 30
                    Layout.alignment: Qt.AlignVCenter
                    Layout.margins: 20

                    Item { Layout.fillWidth: true }

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

                    Item { Layout.fillWidth: true }
                }

                /* Progress of current song */
                Elements.ProgressBar {
                    Layout.fillWidth: true
                    Layout.minimumWidth: info_width
                    value: model.player_state.time_elapsed_ms /
                           (model.player_state.time_total * 1000)
                }
                /* display elapsed and total time of current song */
                RowLayout {
                    Label {
                        text: seconds_to_string(model.player_state.time_elapsed)
                        color: Material.accent
                    }
                    Item { Layout.fillWidth: true }
                    Label {
                        text: seconds_to_string(model.player_state.time_total)
                        color: Material.accent
                    }
                }
            }

            /* Display cover art */
            ColumnLayout {
                Image {
                    id: cover
                    source: model.track_info.album_art_uri.replace("https", "http")
                    fillMode: Image.PreserveAspectFit
                    Layout.fillWidth: true
                    Layout.minimumWidth: 200
                    Layout.fillHeight: true
                    Layout.minimumHeight: 200
                    Layout.maximumHeight: 800
                    verticalAlignment: Image.AlignVCenter
                }
            }
        }
    }
}
