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

#include "../../model/Player_state.h"

/**
 * @brief
 */
enum PlayCommand{NEXT, PREVIOUS, STOP, TOGGLE_PAUSE};

class Data_player_state {
public:
    Player_state::State state;
    unsigned int time_elapsed;
    unsigned int time_elapsed_ms;
    unsigned int time_total;
    unsigned int bitRate;
};

/**
 * @}
 * @}
 * @}
 * @} */
