/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup controller
 * @{
 * @defgroup Websocket
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

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

/**
 * @brief Connects websocket to mopidy server
 */
class Websocket : public QObject {
Q_OBJECT
public:
    explicit Websocket(const std::string& url);
    void register_on_connected(std::function<void()> _callback_on_connected);
    void register_on_message_received(std::function<void(std::string)> _callback_on_message_received);
    void send_message(std::string message);
    void open();
    void close();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void on_connected();
    void on_message_received(QString message);

private:
    QWebSocket m_web_socket;
    std::string m_url;
    std::function<void()> callback_on_connected;
    std::function<void(std::string)> callback_on_message_received;
};

/**
 * @}
 * @}
 * @} */
