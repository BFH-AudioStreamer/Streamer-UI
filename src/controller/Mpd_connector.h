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
#include "data/Data_player_state.h"
#include "data/Data_track_info.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief
 */

class Mpd_connector {
public:
    explicit Mpd_connector(const json& app_config);

    void play_control(PlayCommand playCommand);
    Data_player_state player_state();
    Data_track_info track_info();

    //    void set_search();
    //    void control_capabilities();
    void get_cover();

private:
    std::string hostname{};
    unsigned int port;

    PlayCommand playCommand;

    const char*  update();
    int connect(struct mpd_connection **connection);
    void disconnect(struct mpd_connection *connection);
};

/**
 * @}
 * @}
 * @} */
