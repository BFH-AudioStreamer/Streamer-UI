/**
 *******************************************************************************
 * @addtogroup Mopidy_mpd_connector
 * @{
 * @brief Backend connector combining the MPD and Mopidy connector
 *
 * @authors Rafael Klossner
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
 ******************************************************************************/

#include <utility>
#include "Mopidy_mpd_connector.h"
#include "data/Data_player_state.h"

/**
 * @brief Instantiate mpd and mopidy connector
 * @param app_config Application configuration
 */
Mopidy_mpd_connector::Mopidy_mpd_connector(const json& app_config) {
    mpd_connector = new Mpd_connector(app_config);
    mopidyConnector = new Mopidy_connector(app_config);
}

/**
 * @brief Change to next song
 */
void Mopidy_mpd_connector::play_next() {
    mpd_connector->play_control(Data_player_state::NEXT);
}

/**
 * @brief Change to previous song
 */
void Mopidy_mpd_connector::play_previous() {
    mpd_connector->play_control(Data_player_state::PREVIOUS);
}

/**
 * @brief Stop playing
 */
void Mopidy_mpd_connector::play_stop() {
    mpd_connector->play_control(Data_player_state::STOP);
}

/**
 * @brief Pause currently played song
 */
void Mopidy_mpd_connector::play_toggle_pause() {
    mpd_connector->play_control(Data_player_state::TOGGLE_PAUSE);
}

/**
 * @brief Get player state
 * @return Player state packet in Data_player_state
 */
Data_player_state Mopidy_mpd_connector::player_state() {
    return mpd_connector->player_state();
}

/**
 * @brief Get track info
 * @return Track information packet in Data_track_info
 */
Data_track_info Mopidy_mpd_connector::track_info() {
    Data_track_info trackInfo = mpd_connector->track_info();
    trackInfo.album_art_uri = mopidyConnector->album_art_uri(trackInfo.track_uri);
    return trackInfo;
}

/** @} */
