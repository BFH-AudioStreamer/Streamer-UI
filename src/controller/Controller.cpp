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
#include <QTimer>
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
    QString title = QString::fromStdString( backend_connector->song_title() );
    QString album = QString::fromStdString( backend_connector->album() );
    QString artist = QString::fromStdString( backend_connector->artist() );

    model.track_info()->set_title(title);
    model.track_info()->set_artist(artist);

    //model.track_info()->set_track_uri();
    //model.track_info()->set_album_art_uri(cover);

    model.player_state()->set_bitrate(backend_connector->bit_rate());
    model.player_state()->set_time_total(backend_connector->track_total_time());
    model.player_state()->set_time_elapsed(backend_connector->track_elapsed_time());
}

/** @} */

