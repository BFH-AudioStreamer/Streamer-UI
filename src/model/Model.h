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

/**
 * @brief bla
 */
class Model : public QObject {
Q_OBJECT
public:
    explicit Model();

private:
    void register_qml();
};



/**
 * @}
 * @}
 * @} */