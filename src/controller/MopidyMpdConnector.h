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

#include "IBackendConnector.h"
#include "MpdConnector.h"
#include "MopidyConnector.h"

#include <iostream>

/**
 * @brief
 */
class MopidyMpdConnector : public IBackendConnector {
public:
    MopidyMpdConnector(std::string hostname, unsigned int port);

    //void song_title() override;
    //void artist() override;
    //void album() override;
    void play_next() override;
    void play_previous() override;
    void play_stop() override;
    void play_toggle_pause() override;
    unsigned int bit_rate() override;
    unsigned int track_total_time() override;
    unsigned int track_elapsed_time() override;
    const char* album_art_uri() override;
    //void set_search() override;
    //void control_capabilities() override;

private:
    std::string hostname;
    unsigned int port;

    MpdConnector *mpdConnector = nullptr;
    MopidyConnector *mopidyConnector = nullptr;
};

/**
 * @}
 * @}
 * @} */
