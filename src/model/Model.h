/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup model
 * @{
 * @defgroup Streamer_model
 * @{
 ******************************************************************************/
#pragma once

#include <QObject>
#include "Model_macros.h"
#include "Player_state.h"
#include "Track_info.h"

/**
 * @brief bla
 */
class Model : public QObject {
Q_OBJECT
Q_PROPERTY(Track_info* track_info READ track_info CONSTANT)
Q_PROPERTY(Player_state* player_state READ player_state CONSTANT)

public:
    explicit Model();
    Track_info* track_info();
    Player_state* player_state();

private:
    Track_info* m_track_info;
    Player_state* m_player_state;
};


/**
 * @}
 * @}
 * @} */
