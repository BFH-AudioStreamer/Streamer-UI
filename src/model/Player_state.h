/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup model
 * @{
 * @defgroup PlayerState
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
SIMPLE_Q_PROPERTY(int, bitrate)
SIMPLE_Q_PROPERTY(int, time_total)
SIMPLE_Q_PROPERTY(int, time_elapsed)

};



/**
 * @}
 * @}
 * @} */