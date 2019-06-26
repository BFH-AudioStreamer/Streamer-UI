/**
 *******************************************************************************
 * @addtogroup Websocket
 * @{
 * @brief QWebSocket wrapper
 *
 * Example of Websocket usage:
 * @code{.cpp}
 * auto websocket = new Websocket("ws://a-host/some/uri");
 * websocket->register_on_connected(std::bind(&This_class::some_method, this));
 * websocket->open();
 * //...
 * @endcode
 * @authors Stefan Lüthi
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

#include <utility>
#include <iostream>
#include <nlohmann/json.hpp>

#include "Websocket.h"

using json = nlohmann::json;

/**
 * @brief Connects to a WebSocket
 * @param url Complete URL to a WebSocket
 */
Websocket::Websocket(const std::string& url)
        :m_url(url) {
    connect(&m_web_socket, &QWebSocket::connected, this, &Websocket::on_connected);
    connect(&m_web_socket, &QWebSocket::disconnected, this, &Websocket::closed);
}

/**
 * @brief Registers a callback method to be called on connection event
 * @param _callback_on_connected Function binding of callback method
 */
void Websocket::register_on_connected(std::function<void()> _callback_on_connected) {
    callback_on_connected = std::move(_callback_on_connected);
}

/**
 * @brief Registers a callback method to be called on receive event
 * @param _callback_on_message_received Function binding of callback method
 */
void Websocket::register_on_message_received(
        std::function<void(std::string)> _callback_on_message_received) {

    callback_on_message_received = std::move(_callback_on_message_received);
}

/**
 * @brief Sends text message over the WebSocket
 * @param message Text message
 */
void Websocket::send_message(std::string message) {
    m_web_socket.sendTextMessage(QString::fromStdString(message));
}

/**
 * @brief Opens the WebSocket if not already open
 */
void Websocket::open() {
    /* only accept open request if socket is closed */
    if (m_web_socket.state()==QAbstractSocket::UnconnectedState) {
        m_web_socket.open(QUrl(QString::fromStdString(m_url)));
    }
}

/**
 * @brief Closes current WebSocket
 */
void Websocket::close() {
    m_web_socket.close();
}

/**
 * @brief On connected event handler
 */
void Websocket::on_connected() {
    callback_on_connected();
    connect(&m_web_socket,
            &QWebSocket::textMessageReceived,
            this,
            &Websocket::on_message_received);
}

/**
 * @brief On reveiced event handler
 * @param message Text message from the WebSocket
 */
void Websocket::on_message_received(QString message) {
    callback_on_message_received(message.toStdString());
}

/** @} */
