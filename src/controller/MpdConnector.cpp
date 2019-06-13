/**
 *******************************************************************************
 * @addtogroup MpdConnector
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

#include "MpdConnector.h"

#include <mpd/client.h>
#include <mpd/status.h>
#include <mpd/entity.h>
#include <mpd/search.h>
#include <mpd/tag.h>
#include <mpd/message.h>

#include <iostream>

MpdConnector::MpdConnector(std::string hostname, unsigned int port):hostname(hostname),port(port){

}

//void MpdConnector::song_title(){

//}

//void MpdConnector::artist(){

//}

//void MpdConnector::album(){

//}

void MpdConnector::play_next(){
    connect();
    std::cout << "MpdBackend: next button clicked" << std::endl;
    mpd_send_next(connection);
    disconnect();
}

void MpdConnector::play_previous(){
    connect();
    std::cout << "MpdBackend: previous button clicked" << std::endl;
    mpd_send_previous(connection);
    disconnect();
}

void MpdConnector::play_stop(){
    connect();
    std::cout << "MpdBackend: stop button clicked" << std::endl;
    mpd_send_stop(connection);
    disconnect();
}

void MpdConnector::play_toggle_pause(){
    connect();
    std::cout << "MpdBackend: play/pause button clicked" << std::endl;
    mpd_send_toggle_pause(connection);
    disconnect();
}

unsigned int MpdConnector::bit_rate(){
    unsigned int bitRate = 0;
    connect();
    mpd_status *status = mpd_status_begin();
    bitRate = mpd_status_get_kbit_rate(status);
    std::cout << "MpdBackend: bitrate: " << bitRate << std::endl;
    disconnect();
    mpd_status_free(status);
    return bitRate;
}


unsigned int MpdConnector::track_total_time(){
    unsigned int totalTime = 0;
    connect();
    mpd_status *status = mpd_status_begin();
    totalTime = mpd_status_get_total_time(status);
    std::cout << "MpdBackend: total time: " << totalTime << std::endl;
    disconnect();
    return totalTime;
}

unsigned int MpdConnector::track_elapsed_time(){
    unsigned int elapsedTime = 0;
    connect();
    mpd_status *status = mpd_status_begin();
    elapsedTime = mpd_status_get_elapsed_time(status);
    std::cout << "MpdBackend: elapsed time: " << elapsedTime << std::endl;
    disconnect();
    return elapsedTime;
}

const char* MpdConnector::song_uri(){
    const struct mpd_song *song;
    const char *uri = nullptr;
    connect();

    /* receive next pair */
    mpd_pair *pair = mpd_recv_pair(connection);
    std::cout << "MpdBackend: pair: " << pair->name << ", " << pair->value <<std::endl;

    /* get entity from pair */
    mpd_entity *entity = mpd_entity_begin(pair);

    /* check if entity is a song (could also be a directory or playlist)*/
    if(mpd_entity_get_type(entity) == MPD_ENTITY_TYPE_SONG){
        /* get song and uri of the song */
        song = mpd_entity_get_song(entity);
        uri = mpd_song_get_uri(song);

        /* check for nullptr */
        if(uri != nullptr){
            std::cout << "MpdBackend: uri: " << uri << std::endl;
        }else{
            std::cout << "Error: MpdBackend: Get nullptr instead of uri " << std::endl;
        }
    }else{
        std::cout << "Error: MpdBackend: entity is not a song" << std::endl;
    }

    disconnect();
    return uri;
}

//void MpdConnector::set_search(){

//}

//void MpdConnector::control_capabilities(){

//}

void MpdConnector::connect(){
    connection = mpd_connection_new(hostname.c_str(), port, 30000);
    if (mpd_connection_get_error(connection) != MPD_ERROR_SUCCESS) {
        int i;
        for(i=0;i<3;i++) {
            printf("version[%i]: %i\n",i,
                   mpd_connection_get_server_version(connection)[i]);
        }
    }else{
        std::cout << "Error: MpdBackend: Connecting failed " << std::endl;
    }
}

void MpdConnector::disconnect(){
    mpd_connection_free(connection);
}

/** @} */
