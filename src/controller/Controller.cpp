/**
 *******************************************************************************
 * @addtogroup Controller
 * @{
 * @brief Brief descriptions
 *
 * Elaborate Description
 *
 * @authors Stefan Lüthi
 * @authors Rafael Klossner
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

#include "Websocket.h"

Controller::Controller(Model& _model, const json& app_config)
        :model(_model) {
    backend_connector = Backend_connector::create(app_config);
}

void Controller::play_next() {
    backend_connector->play_next();
}

void Controller::play_previous() {
    backend_connector->play_previous();
}

void Controller::play_toggle_pause() {
    backend_connector->play_toggle_pause();
}

void Controller::update_model() {
    /* get track and player data */
    Data_player_state playerState = backend_connector->player_state();
    Data_track_info trackInfo = backend_connector->track_info();

    /* track info (title, artist, album, album_art_uri)*/
    model.track_info()->set_title(QString::fromStdString(trackInfo.title));
    model.track_info()->set_artist(QString::fromStdString(trackInfo.artist));
    model.track_info()->set_album(QString::fromStdString(trackInfo.album));
    model.track_info()->set_album_art_uri(
            QString::fromStdString(trackInfo.album_art_uri));

    /* player state (bit_rate, elapsedTime, totalTime, playState) */
    model.player_state()->set_bitrate(playerState.bit_rate);
    model.player_state()->set_time_total(playerState.time_total);
    model.player_state()->set_time_elapsed(playerState.time_elapsed);
    model.player_state()->set_time_elapsed_ms(playerState.time_elapsed_ms);
    model.player_state()->set_state(playerState.state);
}

/** @} */

