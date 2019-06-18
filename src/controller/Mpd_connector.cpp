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

#include "Mpd_connector.h"

#include <mpd/client.h>
#include <mpd/status.h>
#include <mpd/entity.h>
#include <mpd/search.h>
#include <mpd/tag.h>
#include <mpd/message.h>

#include <iostream>

Mpd_connector::Mpd_connector(std::string hostname, unsigned int port):hostname(hostname),port(port){
    /* initialy not connected to server */
}

void Mpd_connector::play_control(PlayCommand playCommand){
    struct mpd_connection *connection = nullptr;

    if(connect(&connection) == 0){

        switch (playCommand) {
        case NEXT:
            mpd_send_next(connection);
            break;
        case PREVIOUS:
            mpd_send_previous(connection);
            break;
        case STOP:
            mpd_send_stop(connection);
            break;
        case TOGGLE_PAUSE:
            mpd_send_toggle_pause(connection);
            break;
        }

    }else{
        std::cout << "Error: MpdBackend: play next: not connected" << std::endl;
    }

    disconnect(connection);
}

//void Mpd_connector::set_search(){

//}

//void Mpd_connector::control_capabilities(){

//}

Data_player_state Mpd_connector::player_state(){
    struct mpd_connection *connection = nullptr;
    struct mpd_status *status;
    Data_player_state playerState;

    /* connect to server */
    if(connect(&connection) == 0){
        //connection = mpd_connection_new(hostname.c_str(), port, 30000);

        /* send necessary commands */
        //mpd_command_list_begin(connection, true);
        mpd_send_status(connection);
        //mpd_send_current_song(connection);
        //mpd_command_list_end(connection);

        /* get status and check it */
        status = mpd_recv_status(connection);

        if (mpd_status_get_error(status) != nullptr){
            printf("error: %s\n", mpd_status_get_error(status));
        }else{
            /* if status is valid, get actual player state */
            mpd_state state = mpd_status_get_state(status);
            switch (state) {
            case MPD_STATE_UNKNOWN:
                playerState.state = Player_state::UNKNOWN;
                break;
            case MPD_STATE_PLAY:
                playerState.state = Player_state::PLAY;
                break;
            case MPD_STATE_PAUSE:
                playerState.state = Player_state::PAUSE;
                break;
            case MPD_STATE_STOP:
                playerState.state = Player_state::STOP;
                break;
            }

            /* check if song is present, if yes get time information */
            if (mpd_status_get_state(status) == MPD_STATE_PLAY ||
                    mpd_status_get_state(status) == MPD_STATE_PAUSE) {
                playerState.time_elapsed = mpd_status_get_elapsed_time(status);
                playerState.time_total = mpd_status_get_total_time(status);
                playerState.bitRate =  mpd_status_get_kbit_rate(status);
            }

            /* free status */
            mpd_status_free(status);
        }
    }

    /* free connection */
    disconnect(connection);

    return playerState;
}

Data_track_info Mpd_connector::track_info(){
    struct mpd_connection *connection = nullptr;
    struct mpd_song *song;
    Data_track_info trackInfo;

    /* connect to server */
    if(connect(&connection) == 0){

        /* send necessary commands */
        mpd_command_list_begin(connection, true);
        mpd_send_status(connection);
        mpd_send_current_song(connection);
        mpd_command_list_end(connection);

        mpd_response_next(connection);
        if ((song = mpd_recv_song(connection)) != nullptr) {
            if(mpd_song_get_tag(song, MPD_TAG_TITLE, 0) != nullptr){
                std::string songTitle = mpd_song_get_tag(song, MPD_TAG_TITLE, 0);
                trackInfo.songTitle = songTitle;
                std::string artist = mpd_song_get_tag(song, MPD_TAG_ARTIST, 0);
                trackInfo.artist = artist;
                std::string album = mpd_song_get_tag(song, MPD_TAG_ALBUM, 0);
                trackInfo.album = album;
                std::string songUri = mpd_song_get_uri(song);
                trackInfo.songUri = songUri;
                mpd_song_free(song);
            }
        }else{
            std::cout << "Error: MpdBackend: no song found" << std::endl;
        }
    }

    disconnect(connection);

    return trackInfo;
}

void Mpd_connector::get_cover(){
    system("sacad \"Prism\" \"Katy Perry\" 600 /home/rafael/Pictures/Prism.jpg");
}

int Mpd_connector::connect(struct mpd_connection **connection){
    *connection = mpd_connection_new(hostname.c_str(), port, 30000);
    int status = 0;

    if (mpd_connection_get_error(*connection) != MPD_ERROR_SUCCESS) {
        std::cout << "Error: MpdBackend: Not able to connect " << std::endl;
        for(int i=0;i<3;i++) {
            printf("version[%i]: %i\n",i,
                   mpd_connection_get_server_version(*connection)[i]);
        }
        status = -1;
    }else{
        //std::cout << "MpdBackend: Connected " << std::endl;
        status = 0;
    }

    return status;
}

void Mpd_connector::disconnect(struct mpd_connection *connection){
    mpd_connection_free(connection);
    //std::cout << "MpdBackend: Disconnected " << std::endl;
}

/** @} */
