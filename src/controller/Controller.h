/**
*******************************************************************************
* @addtogroup Streamer-UI
* @{
* @addtogroup controller
* @{
* @defgroup Controller
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
#include <memory>
#include "src/model/Model.h"
#include "Backend_connector.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief
 */
class Controller : public QObject {
Q_OBJECT

public:
    explicit Controller(Model& _model, const json& app_config);
    Q_INVOKABLE void play_next();
    Q_INVOKABLE void play_previous();
    Q_INVOKABLE void play_toggle_pause();
    Q_INVOKABLE void update_model();

private:
    Model& model;
    std::unique_ptr<I_backend_connector> backend_connector = nullptr;

    QString title = "test";
};

/**
 * @}
 * @}
 * @} */
