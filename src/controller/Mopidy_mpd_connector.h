/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup controller
 * @{
 * @defgroup MopidyMpdConnector
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

#include "I_backend_connector.h"
#include "Mpd_connector.h"
#include "Mopidy_connector.h"

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief
 */
class Mopidy_mpd_connector : public I_backend_connector {
public:
    explicit Mopidy_mpd_connector(const json& app_config);

    void play_next() override;
    void play_previous() override;
    void play_stop() override;
    void play_toggle_pause() override;
    Data_player_state player_state() override;
    Data_track_info track_info() override;

private:
    Mpd_connector *mpdConnector = nullptr;
    Mopidy_connector *mopidyConnector = nullptr;
};

/**
 * @}
 * @}
 * @} */
