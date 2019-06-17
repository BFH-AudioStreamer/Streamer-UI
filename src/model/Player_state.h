/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup model
 * @{
 * @defgroup Player_state
 * @{
 ******************************************************************************/
#pragma once

#include <QObject>
#include "Model_macros.h"

/**
 * @brief
 */
class Player_state : public QObject {
Q_OBJECT
public:
    enum State {UNKNOWN = 0, STOP, PLAY, PAUSE};
    Q_ENUMS(State)

    Player_state() = default;

SIMPLE_Q_PROPERTY(unsigned int, bitrate)
SIMPLE_Q_PROPERTY(unsigned int, time_total)
SIMPLE_Q_PROPERTY(unsigned int, time_elapsed)
SIMPLE_Q_PROPERTY(State, state)
};



/**
 * @}
 * @}
 * @} */
