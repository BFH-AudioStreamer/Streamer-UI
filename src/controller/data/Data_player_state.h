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
 ******************************************************************************/
#pragma once

#include "model/Player_state.h"

/**
 * @brief
 */
class Data_player_state {
public:
    enum Play_command{NEXT, PREVIOUS, STOP, TOGGLE_PAUSE};

    Player_state::State state;
    unsigned int time_elapsed;
    unsigned int time_elapsed_ms;
    unsigned int time_total;
    unsigned int bit_rate;
};

/**
 * @}
 * @}
 * @}
 * @} */
