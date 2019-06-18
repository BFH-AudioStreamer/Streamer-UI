/**
 *******************************************************************************
 * @addtogroup Controller
 * @{
 * @brief Brief descriptions
 *
 * Elaborate Description
 *
 * @authors Stefan Lüthi
 ****************************************************************************//*
 * Copyright (C) 2019 Audio-Streamer Project Group
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *******************************************************************************
 */

#include <QQmlApplicationEngine>
#include "Controller.h"
#include "Backend_connector.h"

Controller::Controller(Model& _model)
        :model(_model) {
    backend_connector = BackendConnector::create();
}

void Controller::play_next() {
    backend_connector->play_next();
}

void Controller::play_previous() {
    backend_connector->play_previous();
}

void Controller::play_toggle_pause() {
    backend_connector->play_toggle_pause();
    //model.track_info()->set_title("hello");
}

void Controller::update_model() {
    /* get track and player data */
    Data_player_state playerState = backend_connector->player_state();
    Data_track_info trackInfo = backend_connector->track_info();

    /* track info (title, artist, album, albumArtUri)*/
    QString title = QString::fromStdString(trackInfo.songTitle);
    QString artist = QString::fromStdString(trackInfo.artist);
    QString album = QString::fromStdString(trackInfo.album);
    model.track_info()->set_title(title);
    model.track_info()->set_artist(artist);

    /* player state (bitRate, elapsedTime, totalTime, playState) */
    model.player_state()->set_bitrate(playerState.bitRate);
    model.player_state()->set_time_total(playerState.time_total);
    model.player_state()->set_time_elapsed(playerState.time_elapsed);
    model.player_state()->set_state(playerState.state);
}

/** @} */

