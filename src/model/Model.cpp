/**
 *******************************************************************************
 * @addtogroup Model
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
#include "Model.h"

Streamer_model::Streamer_model() {
    m_player_state = new Player_state();
    m_track_info = new Track_info();
    register_qml();
}

void Streamer_model::register_qml() {
    qmlRegisterType<Streamer_model>(
            "bfh.audio_streamer.model",
            1, 0,
            "Streamer_model"
    );

    qmlRegisterType<Player_state>(
            "bfh.audio_streamer.player_state",
            1, 0,
            "Player_state"
    );

    qmlRegisterType<Track_info>(
            "bfh.audio_streamer.track_info",
            1, 0,
            "Track_info"
    );
}

Track_info* Streamer_model::track_info() {
    return m_track_info;
}

Player_state* Streamer_model::player_state() {
    return m_player_state;
}
/** @} */
