/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup controller
 * @{
 * @defgroup MpdConnector
 * @{
 ******************************************************************************/
#pragma once

#include <string>
#include <iostream>

/**
 * @brief
 */
class MpdConnector {
public:
    MpdConnector(std::string hostname, unsigned int port);

//    void song_title();
//    void artist();
//    void album();
    void play_next();
    void play_previous();
    void play_stop();
    void play_toggle_pause();
    unsigned int bit_rate();
    unsigned int track_total_time();
    unsigned int track_elapsed_time();
    const char* song_uri();
//    void set_search();
//    void control_capabilities();

private:
    std::string hostname;
    unsigned int port;
    struct mpd_connection *connection = nullptr;

    void connect();
    void disconnect();
};

/**
 * @}
 * @}
 * @} */
