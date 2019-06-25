/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup model
 * @{
 * @defgroup Track_info
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

#include <QObject>
#include "Model_macros.h"

/**
 * @brief Data regarding the currently played track
 */
class Track_info : public QObject {
Q_OBJECT
SIMPLE_Q_PROPERTY(QString, title)
SIMPLE_Q_PROPERTY(QString, artist)
SIMPLE_Q_PROPERTY(QString, album)
SIMPLE_Q_PROPERTY(QString, album_art_uri)
SIMPLE_Q_PROPERTY(QString, track_uri)

public:
    explicit Track_info();
};

/**
 * @}
 * @}
 * @} */
