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

MopidyMpdConnector::MopidyMpdConnector(std::string _hostname, unsigned int _port)
        :hostname(std::move(_hostname)), port(_port) {
    mpdConnector = new Mpd_connector(hostname, port);
    mopidyConnector = new Mopidy_connector(hostname, port);
}

//void MpdConnector::song_title(){

//}

//void MpdConnector::artist(){

//}

//void MpdConnector::album(){

//}

void MopidyMpdConnector::play_next() {
    mpdConnector->play_next();
}

void MopidyMpdConnector::play_previous() {
    mpdConnector->play_previous();
}

void MopidyMpdConnector::play_stop() {
    mpdConnector->play_stop();
}

void MopidyMpdConnector::play_toggle_pause() {
    mpdConnector->play_toggle_pause();
    bit_rate();
    track_total_time();
    track_elapsed_time();
}

unsigned int MopidyMpdConnector::bit_rate() {
    unsigned int bitRate = 0;
    bitRate = mpdConnector->bit_rate();
    return bitRate;
}

unsigned int MopidyMpdConnector::track_total_time() {
    unsigned int totalTime = 0;
    totalTime = mpdConnector->track_total_time();
    return totalTime;
}

unsigned int MopidyMpdConnector::track_elapsed_time() {
    unsigned int elapsedTime = 0;
    elapsedTime = mpdConnector->track_elapsed_time();
    return elapsedTime;
}

const char* MopidyMpdConnector::album_art_uri() {
    const char* songUri = nullptr;
    const char* albumUri = nullptr;
    // const char *artUri = nullptr;

    songUri = mpdConnector->song_uri();
    albumUri = mopidyConnector->album_art_uri(songUri);

    return albumUri;
}

//void MopidyMpdConnector::set_search(){

//}

//void MopidyMpdConnector::control_capabilities(){

//}

/** @} */
