/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup model
 * @{
 * @defgroup Track_info
 * @{
 ******************************************************************************/
#pragma once

#include <QObject>
#include "Model_macros.h"

/**
 * @brief
 */
class Track_info : public QObject {
Q_OBJECT
SIMPLE_Q_PROPERTY(QString, title)
SIMPLE_Q_PROPERTY(QString, artist)
SIMPLE_Q_PROPERTY(QString, album_art_uri)
SIMPLE_Q_PROPERTY(QString, track_uri)
SIMPLE_Q_PROPERTY(QString, image_uri)

public:
    explicit Track_info();
};

/**
 * @}
 * @}
 * @} */
