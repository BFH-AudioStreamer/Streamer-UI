/**
 *******************************************************************************
 * @addtogroup MopidyMpdConnector
 * @{
 * @brief Brief descriptions
 *
 * Elaborate Description
 *
 * @authors stefan
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

#include "MopidyMpdConnector.h"

MopidyMpdConnector::MopidyMpdConnector(){
    mpdConnector = new MpdConnector("Audio-Streamer", 6600);
}

//void MpdConnector::song_title(){

//}

//void MpdConnector::artist(){

//}

//void MpdConnector::album(){

//}

void MopidyMpdConnector::play_next(){
    mpdConnector->play_next();

}

void MopidyMpdConnector::play_previous(){
    mpdConnector->play_previous();
}

void MopidyMpdConnector::play_stop(){
    mpdConnector->play_stop();
}

void MopidyMpdConnector::play_toggle_pause(){
    mpdConnector->play_toggle_pause();
}

//unsigned int MopidyMpdConnector::bit_rate(){
//    unsigned int bitRate = 0;
//    connect();
//    bitRate = mpd_status_get_kbit_rate(status);
//    cout << "MpdBackend: bitrate: " << bitRate << endl;
//    disconnect();
//    return bitRate;
//}


//unsigned int MopidyMpdConnector::track_total_time(){
//    unsigned int totalTime = 0;
//    connect();
//    totalTime = mpd_status_get_total_time(status);
//    cout << "MpdBackend: total time: " << totalTime << endl;
//    disconnect();
//    return totalTime;
//}

//unsigned int MopidyMpdConnector::track_elapsed_time(){
//    unsigned int elapsedTime = 0;
//    connect();
//    elapsedTime = mpd_status_get_elapsed_time(status);
//    cout << "MpdBackend: elapsed time: " << elapsedTime << endl;
//    disconnect();
//    return elapsedTime;
//}

//const char* MopidyMpdConnector::album_art_uri(){
//    const struct mpd_song *song;
//    const char *uri = nullptr;
//    connect();
//    if(mpd_entity_get_type(entity) == MPD_ENTITY_TYPE_SONG){
//        song = mpd_entity_get_song(entity);
//        uri = mpd_song_get_uri(song);
//        cout << "MpdBackend: uri: " << uri << endl;
//    }else{
//        cout << "Error: MpdBackend: entity is not a song" << endl;
//    }
//    disconnect();
//    return uri;
//}

//void MopidyMpdConnector::set_search(){

//}

//void MopidyMpdConnector::control_capabilities(){

//}

/** @} */
