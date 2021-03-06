/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup controller
 * @{
 * @defgroup Mpd_connector
 * @{
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

#pragma once

#include <string>
#include <iostream>
#include "data/Data_player_state.h"
#include "data/Data_track_info.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief Backend connector to an MPD server
 */
class Mpd_connector {
public:
    explicit Mpd_connector(const json& app_config);

    void play_control(Data_player_state::Play_command play_command);
    Data_player_state player_state();
    Data_track_info track_info();

private:
    std::string hostname{};
    unsigned int port;

    int connect(struct mpd_connection** connection);
    void disconnect(struct mpd_connection* connection);
};

/**
 * @}
 * @}
 * @} */
