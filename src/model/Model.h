/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup model
 * @{
 * @defgroup Model
 * @{
 ******************************************************************************/
#pragma once

#include <QObject>
#include "Player_state.h"
#include "Track_info.h"

/**
 * @brief bla
 */
class Model : public QObject {
Q_OBJECT
public:
    explicit Model();
    Player_state player_state;
    Track_info track_info;

private:
    void register_qml();
};



/**
 * @}
 * @}
 * @} */
