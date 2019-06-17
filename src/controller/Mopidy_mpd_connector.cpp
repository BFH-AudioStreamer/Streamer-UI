/**
 *******************************************************************************
 * @addtogroup MopidyMpdConnector
 * @{
 * @brief Brief descriptions
 *
 * Elaborate Description
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
 *******************************************************************************
 */

#include <utility>
#include "Mopidy_mpd_connector.h"
#include "data/Data_player_state.h"

MopidyMpdConnector::MopidyMpdConnector(std::string _hostname, unsigned int _port)
        :hostname(std::move(_hostname)), port(_port) {
    mpdConnector = new Mpd_connector(hostname, port);
    mopidyConnector = new Mopidy_connector(hostname, port);
}

void MopidyMpdConnector::play_next() {
    mpdConnector->play_control(NEXT);
}

void MopidyMpdConnector::play_previous() {
    mpdConnector->play_control(PREVIOUS);
}

void MopidyMpdConnector::play_stop() {
    mpdConnector->play_control(STOP);
}

void MopidyMpdConnector::play_toggle_pause() {
    mpdConnector->play_control(TOGGLE_PAUSE);
}

Data_player_state MopidyMpdConnector::player_state(){
    Data_player_state playerState;
    playerState = mpdConnector->player_state();
    return playerState;
}

Data_track_info MopidyMpdConnector::track_info(){
    Data_track_info trackInfo;
    trackInfo = mpdConnector->track_info();

    /* get albumArtUri from Mopidy */
    //trackInfo.albumArtUri = mopidyConnector->album_art_uri(trackInfo.songUri);

    return trackInfo;
}

//void MopidyMpdConnector::set_search(){

//}

//void MopidyMpdConnector::control_capabilities(){

//}

/** @} */
