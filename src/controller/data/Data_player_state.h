/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup controller
 * @{
 * @addtogroup data
 * @{
 * @defgroup Data_player_state
 * @{
 * @brief Collocation of information regarding the player state
 *
 * @authors Rafael Klossner
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

#include "model/Player_state.h"

/**
 * @brief Collocation of information regarding the player state
 */
class Data_player_state {
public:
    /// @brief Available playback controls
    enum Play_command {
        NEXT, PREVIOUS, STOP, TOGGLE_PAUSE
    };

    Player_state::State state;     ///< @brief Current playback state
    unsigned int time_elapsed;     ///< @brief Elapsed time of current song in seconds
    unsigned int time_elapsed_ms;  ///< @brief Elapsed time of current song in milliseconds
    unsigned int time_total;       ///< @brief Total time of current song in seconds
    unsigned int bit_rate;         ///< @brief Bitrate of current playback in kB/s
};

/**
 * @}
 * @}
 * @}
 * @} */
