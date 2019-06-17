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
class Mpd_connector {
public:
    Mpd_connector(std::string hostname, unsigned int port);

    std::string song_title();
    std::string artist();
    std::string album();
    void play_next();
    void play_previous();
    void play_stop();
    void play_toggle_pause();
    unsigned int bit_rate();
    unsigned int track_total_time();
    unsigned int track_elapsed_time();
    std::string song_uri();
    //    void set_search();
    //    void control_capabilities();

private:
    std::string hostname;
    unsigned int port;

    const char*  update();
    struct mpd_connection *connect();
    void disconnect(struct mpd_connection *connection);
};

/**
 * @}
 * @}
 * @} */
