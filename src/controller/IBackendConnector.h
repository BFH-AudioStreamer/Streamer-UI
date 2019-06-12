/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup controller
 * @{
 * @defgroup IBackendConnector
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

/**
 * @brief
 */
class IBackendConnector {
public:
    //virtual ~IBackendConnector() = default;

    virtual void song_title() = 0;
    virtual void artist() = 0;
    virtual void album() = 0;
    virtual void play_next() = 0;
    virtual void play_previous() = 0;
    virtual void play_stop() = 0;
    virtual void play_toggle_pause() = 0;
    virtual unsigned int bit_rate() = 0;
    virtual unsigned int track_total_time() = 0;
    virtual unsigned int track_elapsed_time() = 0;
    virtual const char* album_art_uri() = 0;
    virtual void set_search() = 0;
    virtual void control_capabilities() = 0;

};

/**
 * @}
 * @}
 * @} */